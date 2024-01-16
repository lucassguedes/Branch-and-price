#include "ColumnGeneration.hpp"


NodeRes::NodeRes(Master master, double numberOfBins, IloAlgorithm::Status status){
  this->master = master;
  this->numberOfBins = numberOfBins;
  this->status = status;
}


NodeRes columnGeneration(Data * data, IloEnv &env, IloCplex &masterSolver, IloCplex &pricingSolver, Master &master, NodeInfo nodeInfo){
    const int n = data->getNumberOfItems(); /**Número total de itens*/

    char varname[100];

    double pricingResult;
    double masterResult;  
    Pricing pricing;


    const int nCons = master.constraints.getSize();


    master.setBounds(nodeInfo);

    /*A única coisa que muda no modelo de pricing são os coeficientes da função objetivo.
      Por isso, inicialmente o modelo é criado uma só vez com os coeficientes todos iguais 
      a 1. Durante a execução do laço, os coeficientes da função objetivo são apenas atualizados.*/
    std::vector<double> pi(nCons, 1.0f);
    std::vector<bool> activated_x(n, false);
    pricing = createPricingModel(data, nodeInfo, pi, nCons, env);


    int newVarIdx, nVar;
    double value;
    while(true){
        solveMaster(master, masterSolver);

        // masterSolver.exportModel("master.lp");

        masterResult = masterSolver.getObjValue();
        /*Obtendo valores das variáveis duais do master*/
        /*Valores das variáveis duais, usadas como pesos no subproblema de pricing*/
        for(int i = 0; i < nCons; i++)
        {
          pi[i] = masterSolver.getDual(master.constraints[i]);
        }

        /*Atualizando coeficientes da função objetivo do subproblema de pricing*/
        updatePricingCoefficients(pricing, nCons, pi);
        solvePricing(pricing, pricingSolver);

        pricingResult = pricingSolver.getObjValue();

        // pricingSolver.exportModel("pricing.lp");
        
        activated_x = std::vector<bool>(n, false);
        // std::cout << "Pricing result: " << pricingResult << "\n";
        if(pricingResult < -1e-6)
        {
          for(int i = 0; i < n; i++)
          {
            if(pricingSolver.getValue(pricing.x[i]))activated_x[i]=true;
          }

          /*Adicionando nova variável no modelo mestre*/
          sprintf(varname, "Lambda(%d)", master.getNumberOfVariables() + 1);
          
          master.addVar(env, varname, activated_x);

          newVarIdx = master.getNumberOfVariables() - 1;
          for(size_t i = 0; i < n; i++)
          {
            if(activated_x[i]){
              master.constraints[i].setExpr(master.constraints[i].getExpr() + master.getVar(newVarIdx));
            }
          }

          /*Adicionando a nova variável na função objetivo*/
          master.objective.setLinearCoef(master.getVar(newVarIdx), 1);
        }else
        {
          
          std::cout << "Result: " << masterResult << "\n";

          nVar = master.getNumberOfVariables();
          std::cout << "Nº of master variables: " << nVar << "\n";
          // std::cout << "Variables: \n";
          for(int i = 0; i < nVar; i++)
          {
            value = masterSolver.getValue(master.getVar(i));
            master.patterns[i].value = value;
            // std::cout << master.getVar(i).getName() << ": " <<  master.patterns[i].value  << "\n";
          }

          break;

        }

    }
    IloAlgorithm::Status status = masterSolver.getStatus();

    return NodeRes(master, masterResult, status);
}