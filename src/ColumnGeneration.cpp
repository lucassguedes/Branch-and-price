#include "ColumnGeneration.hpp"



void columnGeneration(Data * data)
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
    Pricing pricing;


    const int nCons = master.constraints.getSize();


    IloCplex masterSolver(master.model);
    masterSolver.setParam(IloCplex::TiLim, 3600);
    masterSolver.setParam(IloCplex::Threads, 1);
    masterSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);


    IloCplex pricingSolver(env);
    pricingSolver.setParam(IloCplex::TiLim, 3600);
    pricingSolver.setParam(IloCplex::Threads, 1);
    pricingSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-08);


    /*A única coisa que muda no modelo de pricing são os coeficientes da função objetivo.
      Por isso, inicialmente o modelo é criado uma só vez com os coeficientes todos iguais 
      a 1. Durante a execução do laço, os coeficientes da função objetivo são apenas atualizados.*/
    std::vector<double> pi(nCons, 1.0f);
    std::vector<int> itemsInTheNewPattern;
    pricing = createPricingModel(data, pi, nCons, env);
    while(true){
        pi.clear();
        solveMaster(master, masterSolver);

        masterResult = masterSolver.getObjValue();
        /*Obtendo valores das variáveis duais do master*/
        /*Valores das variáveis duais, usadas como pesos no subproblema de pricing*/
        for(int i = 0; i < nCons; i++)
        {
          pi.push_back(masterSolver.getDual(master.constraints[i]));
        }

        /*Atualizando coeficientes da função objetivo do subproblema de pricing*/
        updatePricingCoefficients(pricing, nCons, pi);

        solvePricing(pricing, pricingSolver);
        pricingResult = pricingSolver.getObjValue();
        
        itemsInTheNewPattern.clear();
        if(pricingResult < 0)
        {
          for(int i = 0; i < n; i++)
          {
            if(pricingSolver.getValue(pricing.x[i]))itemsInTheNewPattern.push_back(i+1);
          }

          /*Adicionando nova variável no modelo mestre*/
          sprintf(varname, "Lambda(%d)", master.getNumberOfVariables() + 1);
          
          master.addVar(env, varname, itemsInTheNewPattern);

          const int newVarIdx = master.getNumberOfVariables() - 1;
          for(auto i : itemsInTheNewPattern)
          {
            master.constraints[i-1].setExpr(master.constraints[i-1].getExpr() + master.getVar(newVarIdx));
          }

          /*Adicionando a nova variável na função objetivo*/
          master.objective.setLinearCoef(master.getVar(newVarIdx), 1);
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