#include <iostream>
#include <ilcplex/ilocplex.h>
#include "Data.hpp"
#include <fstream>
#include <bitset>

#include "Model.hpp"

void bin_packing(Data * data)
{
    IloEnv env;
    IloCplex cplex;

    env.setName("Bin Packing");

    const int n = data->getNumberOfItems(); /**Número total de itens*/

    std::cout << "N = " << n << "\n";
    /*
      - Inicialmente, haverão n variáveis lambda, cada uma representando um padrão.
      - Em cada um dos padrões iniciais, somente um item é considerado.
      - O índice de uma variável lambda indica quais itens estão inclusos no padrão.
        Por exemplo, se o índice for 1, somente o item 1 estará incluso, se for 2,
        somente o item 2, se for 3, somente os itens 1 e 2 (3 em binário é 11) e assim
        por diante.
      */

    char varname[100];
    Master modelData = Master(env);
    cplex = IloCplex(modelData.model);
    /*Obtendo conjunto inicial de padrões, cada um contendo apenas um item*/
    for(int i = 0; i < n; i++)
    {
      sprintf(varname, "Lambda(%d)", i+1);
      modelData.addVar(env, varname, std::vector<int>({i+1}));
    }
    
    
    /*Função objetivo*/
    IloExpr obj(env);

    for(size_t i = 0; i < n; i++)obj += modelData.getVar(i);


    modelData.model.add(IloMinimize(env, obj));


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
      exp += modelData.getVar(i);
      cst = (exp == 1);
      sprintf(cstName, "UNIQUE_PATTERN(%d)", i+1);
      cst.setName(cstName);
      modelData.addConstraint(cst);
    } 

    // /*Resolvendo o problema*/
    IloCplex binPacking(modelData.model);
    binPacking.setParam(IloCplex::TiLim, 3600);
    binPacking.setParam(IloCplex::Threads, 1);
    binPacking.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);

    binPacking.solve();

    binPacking.exportModel("binpacking.lp");


    std::cout << "Obj: " << binPacking.getObjValue() << std::endl;

    IloNumArray duals(env);

    const int nCons = modelData.constraints.getSize();

    std::vector<double> pi; /*Valores das variáveis duais, usadas como pesos no subproblema de pricing*/
    for(int i = 0; i < nCons; i++)
    {
      std::cout << "Dual of " << modelData.constraints[i].getName() << ": ";
      pi.push_back(binPacking.getDual(modelData.constraints[i]));
      std::cout << pi[pi.size()-1] << "\n";
    }


    /*Subproblema de pricing*/
    Pricing pricing = Pricing(env, n);

    /*Criando variáveis*/
    for(int i = 0; i < n; i++)
    {
      sprintf(varname, "X(%d)", i+1);
      pricing.x[i].setName(varname);
      pricing.model.add(pricing.x[i]);
    } 

    pricing.objective += 1;

    for(int i = 0; i < nCons; i++)
    {
      pricing.objective += -pi[i]*pricing.x[i];
    }

    pricing.model.add(IloMinimize(env, pricing.objective));

    IloExpr pricingConsExpr(env);

    for(int i = 0; i < nCons; i++)
    {
      pricingConsExpr += data->w[i]*pricing.x[i];
    }

    pricing.cons = (pricingConsExpr <= data->W);

    pricing.model.add(pricing.cons);


    IloCplex pricingSolver(pricing.model);
    pricingSolver.setParam(IloCplex::TiLim, 3600);
    pricingSolver.setParam(IloCplex::Threads, 1);
    pricingSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);

    pricingSolver.solve();

    pricingSolver.exportModel("pricingSolver.lp");


    std::cout << "pricingSolver Obj: " << pricingSolver.getObjValue() << std::endl;

    std::cout << "Variáveis: \n";
    for(int i = 0; i < n; i++)
    {
      std::cout << pricing.x[i].getName() << " = " << pricingSolver.getValue(pricing.x[i]) << std::endl;
    }

    // std::cout << "Objective value = " << binPacking.getObjValue() << std::endl;

    // env.end();
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