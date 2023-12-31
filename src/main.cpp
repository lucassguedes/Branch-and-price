#include <iostream>
#include <ilcplex/ilocplex.h>
#include "Data.hpp"
#include <fstream>
#include <bitset>
#include <algorithm>

#include "Model.hpp"

#define BIG_M 1e6

Master createMasterModel(Data *data, IloEnv env)
{
  Master master = Master(env);

  const int n = data->getNumberOfItems(); /**Número total de itens*/
  char varname[100];
  /*Obtendo conjunto inicial de padrões, cada um contendo apenas um item*/
  for(int i = 0; i < n; i++)
  {
    sprintf(varname, "Lambda(%d)", i+1);
    master.addVar(env, varname, std::vector<int>({i+1}));
  }

   /*Função objetivo*/
  for(size_t i = 0; i < n; i++)master.objective += BIG_M*master.getVar(i);


  master.model.add(IloMinimize(env, master.objective));


  /*No modelo mestre, para cada item i existe uma restrição associada.
    Em cada restrição, somente um padrão poderá ser ativado (valor 1).
    Inicialmente, cada um dos padrões selecionados contém somente um item.
  */

  IloRange cst;
  IloExpr exp;
  char cstName[100];
  for(int i = 0; i < n; i++)
  {
    exp = IloExpr(env);
    exp += master.getVar(i);
    cst = (exp == 1);
    sprintf(cstName, "UNIQUE_PATTERN(%d)", i+1);
    cst.setName(cstName);
    master.addConstraint(cst);
  } 

  return master;
}


IloCplex solveMaster(Master & master)
{
  // /*Resolvendo o problema*/
  IloCplex masterSolver(master.model);
  masterSolver.setParam(IloCplex::TiLim, 3600);
  masterSolver.setParam(IloCplex::Threads, 1);
  masterSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);

  masterSolver.solve();
  // std::cout << "===============================STATUS==================================\n";
  // std::cout << masterSolver.getStatus() << std::endl;
  // std::cout << "===============================STATUS==================================\n";

  return masterSolver;
}


Pricing createPricingModel(Data * data, std::vector<double> pi, const int nCons, IloEnv env)
{
  const int n = data->getNumberOfItems();
  char varname[100];
  Pricing pricing = Pricing(env, n);


  /*Criando variáveis*/
  for(int i = 0; i < n; i++)
  {
    sprintf(varname, "X(%d)", i+1);
    pricing.x[i].setName(varname);
    pricing.model.add(pricing.x[i]);
  } 

  /*Definindo função objetivo*/
  pricing.objective += 1;

  for(int i = 0; i < nCons; i++)
  {
    pricing.objective += -pi[i]*pricing.x[i];
  }

  pricing.model.add(IloMinimize(env, pricing.objective));

  /*Definindo restrição*/
  IloExpr pricingConsExpr(env);

  for(int i = 0; i < nCons; i++)
  {
    pricingConsExpr += data->w[i]*pricing.x[i];
  }

  pricing.cons = (pricingConsExpr <= data->W);

  pricing.model.add(pricing.cons);

  return pricing;
}

IloCplex solvePricing(Pricing &pricing)
{
  IloCplex pricingSolver(pricing.model);
  pricingSolver.setParam(IloCplex::TiLim, 3600);
  pricingSolver.setParam(IloCplex::Threads, 1);
  pricingSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);

  pricingSolver.solve();

  return pricingSolver;
}


void bin_packing(Data * data)
{
    IloEnv env;

    env.setOut(env.getNullStream());
    env.setWarning(env.getNullStream());

    env.setName("Bin Packing");

    const int n = data->getNumberOfItems(); /**Número total de itens*/

    char varname[100];

    Master master = createMasterModel(data, env);


    double pricingResult;
    double masterResult;  
    IloCplex masterSolver;
    Pricing pricing;
    IloCplex pricingSolver;
    while(true){

        masterSolver = solveMaster(master);

        masterResult = masterSolver.getObjValue();

        /*Exibindo resultados do master*/
        // masterSolver.exportModel("master.lp");
        std::cout << "Obj: " << masterResult << std::endl;

        getchar();


        /*Obtendo valores das variáveis duais do master*/

        const int nCons = master.constraints.getSize();

        std::vector<double> pi; /*Valores das variáveis duais, usadas como pesos no subproblema de pricing*/
        for(int i = 0; i < nCons; i++)
        {
          // std::cout << "Dual of " << master.constraints[i].getName() << ": ";
          pi.push_back(masterSolver.getDual(master.constraints[i]));
          // std::cout << "dualVal(" << i+1 << ") = " << dualVal << std::endl;
          // std::cout << pi[pi.size()-1] << "\n";
        }


        /*Subproblema de pricing*/
        pricing = createPricingModel(data, pi, nCons, env);

        pricingSolver = solvePricing(pricing);

        // pricingSolver.exportModel("pricingSolver.lp");



        /*Exibindo resultados do pricing*/


        pricingResult = pricingSolver.getObjValue();

        // std::cout << "pricingSolver Obj: " << pricingResult << std::endl;
        // std::cout << "Variáveis: \n";
        std::vector<int> itemsInTheNewPattern;
        
        if(pricingResult < 0)
        {
          double value;
          for(int i = 0; i < n; i++)
          {
            value = pricingSolver.getValue(pricing.x[i]);
            // std::cout << pricing.x[i].getName() << " = " <<  value << std::endl;
            
            
            if(value)itemsInTheNewPattern.push_back(i+1);

          }


          /*Adicionando nova variável no modelo mestre*/
          sprintf(varname, "Lambda(%d)", master.getNumberOfVariables() + 1);
          
          // std::cout << "Nome da nova variável: " << varname << std::endl;
          
          master.addVar(env, varname, itemsInTheNewPattern);

          const int newVarIdx = master.getNumberOfVariables() - 1;
          // std::cout << "newVarIdx = " << newVarIdx << "\n";
          /*Adicionando nova variável nas restrições*/
          for(auto i : itemsInTheNewPattern)
          {
            master.constraints[i-1].setExpr(master.constraints[i-1].getExpr() + master.getVar(newVarIdx));
          }

          /*Adicionando a nova variável na função objetivo*/

          master.objective.setLinearCoef(master.getVar(newVarIdx), 1);

          // master.model.add(master.objective);

          // std::cout << "Itens que o novo padrão deve incluir: ";
          // for(auto item: itemsInTheNewPattern)std::cout << item << " ";
          // std::cout << "\n";
        }else
        {
          std::cout << "Result: " << masterResult << "\n";

          const int nVar = master.getNumberOfVariables();
          std::cout << "Nº of master variables: " << nVar << "\n";
          std::cout << "Variables: \n";
          double value, total;
          total = 0;
          for(int i = 0; i < nVar; i++)
          {
            value = masterSolver.getValue(master.getVar(i));
            std::cout << master.getVar(i).getName() << ": " <<  value  << "\n";
            total+=value;
          }

          std::cout << "Total: " << total << "\n";

          break;

        }

    }

    env.end();  
    
}


int main(int argc, char** argv)
{

    if(argc < 2)
    {
        std::cout << "Erro: Argumento inválido.\n\tModo de utilização: ./bp <instance_path>\n";
        return -1;
    }


    Data* data = new Data();

    data->readData(argv[1]);


    bin_packing(data);


    delete data;

    return 0;
}