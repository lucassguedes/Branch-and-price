#include "ColumnGeneration.hpp"

NodeRes::NodeRes(double numberOfBins, IloAlgorithm::Status status){
  this->numberOfBins = numberOfBins;
  this->status = status;
}

void showResults(Master &master, Data * data, IloCplex &masterSolver){
    for(auto p : master.patterns)
    {

        if(p.value > EPSILON)
        {
			std::cout << p.var.getName() << " = " << p.value << std::endl;
            double sum = 0;
            std::cout << "Padrão " << p.var.getName() << "\n";
            std::cout << "\tItens: ";
            for(int i = 0; i < p.activated_x.size(); i++){
                if(p.activated_x[i]){
                    std::cout << i + 1 << ", ";
                    sum += data->w[i];
                }
            }
            std::cout << "Comprimento total: " << sum << std::endl;
        }
    }
}

bool isAnIntegerSolution(const Master& master, IloCplex& masterSolver)
{
	double value;
    for(Pattern p : master.patterns)
    {
		value = masterSolver.getValue(p.var);
        if(value > EPSILON && fabs(value - (int)value) > EPSILON)
        {
            return false;
        }
    }
    return true;
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
    
    IloAlgorithm::Status master_status, best_status;
    bool defined_status = false;
    double best_integer = std::numeric_limits<double>::infinity();
    while(true){
		// std::cout << "Executando...\n";
        solveMaster(master, masterSolver);

        // masterSolver.exportModel("master.lp");

        if(masterSolver.getStatus() != IloAlgorithm::Optimal)
        {
          // std::cout << "Solução: " << masterSolver.getStatus() << std::endl;
          if(!defined_status){
            best_status = masterSolver.getStatus();
          }
          return NodeRes(best_integer, best_status);
        }

        masterResult = masterSolver.getObjValue();

        // std::cout << "obj: " << masterResult << "\n";

        master_status = masterSolver.getStatus();

        if(masterResult < best_integer)
		{
			best_integer = masterResult;
			best_status = master_status;
		}
        // if(best_integer < data->getNumberOfItems()){
		// 	std::cout << "Saindo...\n";
        // 	return NodeRes(best_integer, best_status);
        // }


        if(!defined_status){
			defined_status = true;
        }
        /*Obtendo valores das variáveis duais do master*/
        /*Valores das variáveis duais, usadas como pesos no subproblema de pricing*/
        for(int i = 0; i < nCons; i++)
        {
			pi[i] = masterSolver.getDual(master.constraints[i]);
        }

        /*Atualizando coeficientes da função objetivo do subproblema de pricing*/
        updatePricingCoefficients(pricing, nCons, pi);
        solvePricing(pricing, pricingSolver);

        if(pricingSolver.getStatus() == IloAlgorithm::Infeasible)
        {
          std::cout << "Problema de Princing Inviável!\n";
          getchar();
        }

        pricingResult = pricingSolver.getObjValue();

        // pricingSolver.exportModel("pricing.lp");
        
        activated_x = std::vector<bool>(n, false);
        // std::cout << "Pricing result: " << pricingResult << "\n";
        if(pricingResult < -1e-6)
        {
          for(int i = 0; i < n; i++)
          {
            if(pricingSolver.getValue(pricing.x[i]) > 1e-6)activated_x[i]=true;
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
          
          // std::cout << "Result: " << masterResult << "\n";

          nVar = master.getNumberOfVariables();
          // std::cout << "Nº of master variables: " << nVar << "\n";
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
	// std::cout << "Saindo...\n";

    return NodeRes(best_integer, best_status);
}