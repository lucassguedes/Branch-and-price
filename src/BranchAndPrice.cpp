#include "BranchAndPrice.hpp"

std::vector<std::vector<double> > getZ(const NodeRes& res, const Master& master, const int nItems)
{
    std::vector<std::vector<double> > z = std::vector<std::vector<double> > (nItems, std::vector<double>(nItems, 0));

    int x, y;
    for(Pattern p : master.patterns)
    {
        for(int i = 0; i < nItems; i++)
        {
            for(int j = i+1; j < nItems; j++)
            {
				if(p.activated_x[i] && p.activated_x[j]){
                    x = i;
                    y = j;
                    if(x > y){
                        std::swap(x, y);
                    }
                    z[x][y] += p.value;
                }
            }
        }
    }

    return z;
}

std::pair<int, int> getTargetPair(const std::vector<std::vector<double> > &z, const NodeInfo &nodeInfo){
    double smallerDist = std::numeric_limits<double>::infinity();
    const int n = z.size();

    double dist;
    std::pair<int, int> target = std::make_pair(-1, -1);
    // bool alreadyTogether, alreadySeparated, pairIsValid;
    // std::cout << nodeInfo << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            dist = fabs(z[i][j] - 0.5);
            // alreadyTogether = (std::find(nodeInfo.mustBeTogether.begin(), nodeInfo.mustBeTogether.end(), std::make_pair(i, j)) != nodeInfo.mustBeTogether.end());
            // alreadySeparated = (std::find(nodeInfo.mustBeSeparated.begin(), nodeInfo.mustBeSeparated.end(), std::make_pair(i, j)) != nodeInfo.mustBeSeparated.end());
            // pairIsValid = (!alreadyTogether && !alreadySeparated);
            if(dist < smallerDist)
            {
                smallerDist = dist;
                target = std::make_pair(i, j);
            }
        }
    }

    return target;
}

void branchAndPrice(Data * data, NodeInfo nodeInfo)
{
    IloEnv env;
    Master master = createMasterModel(data, env);

    env.setOut(env.getNullStream());
    env.setWarning(env.getNullStream());

    env.setName("Bin Packing");

    IloCplex masterSolver(master.model);
    masterSolver.setParam(IloCplex::TiLim, 3600);
    masterSolver.setParam(IloCplex::Threads, 1);
    masterSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-06);


    IloCplex pricingSolver(env);
    pricingSolver.setParam(IloCplex::TiLim, 3600);
    pricingSolver.setParam(IloCplex::Threads, 1);
    pricingSolver.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 1e-06);

    
    NodeRes res;
    std::vector<NodeInfo>nodes = {nodeInfo};
    const int numberOfItems = data->getNumberOfItems();
    double best_integer = std::numeric_limits<double>::infinity();

    double value;
    std::vector<std::vector<double> > z;
    std::pair<int, int> target_pair;
    const std::pair<int, int > invalid_pair = std::make_pair(-1, -1);

    int root_idx = 0;
    double greater_float_solution = -std::numeric_limits<double>::infinity();
    NodeInfo n1, n2;

    double upper_bound = data->getNumberOfItems();
    double lower_bound = 0;

    Master best_master;
    while(true)
    {
        if(root_idx >= nodes.size())
        {
            // showResults(best_master, data, masterSolver);
            break;
        }
        // std::cout << "mainloop - lower_bound = " << lower_bound << "\n";
        // std::cout << "number_of_bins = " << res.numberOfBins << "\n";
        // std::cout << nodes[root_idx] << "\n";
        // std::cout << root_idx << "/" << nodes.size() << "\n";
        res = columnGeneration(data, env, masterSolver, pricingSolver, master, nodes[root_idx]); 
        if(res.status != IloAlgorithm::Infeasible){
            if(isAnIntegerSolution(master, masterSolver))
            {
                // std::cout << "(BB) Encontrou uma solução inteira: " << res.numberOfBins << "\n";
                value = res.numberOfBins;
                //Se a solução inteira encontrada não for tão próxima da melhor solução encontrada
                if(fabs(value - best_integer) > EPSILON){
                    if(value < best_integer){
                        upper_bound = value;
                        best_master = master;
                        best_integer = value;
                    }
                }else{//Se for muito próxima, encerramos o programa
                    break;
                }
            }else if(res.numberOfBins >= lower_bound){ //Se a solução não for inteira, devemos ramificar
                if(res.numberOfBins < data->getNumberOfItems()){
                    lower_bound = res.numberOfBins;
                }
                // std::cout << "lower_bound = " << lower_bound << "\n";
                z = getZ(res, master, numberOfItems);
                target_pair = getTargetPair(z, nodes[root_idx]);

                if(target_pair != invalid_pair){
                    //Criamos dois ramos
                    n1 = nodes[root_idx];
                    n2 = nodes[root_idx];

                    n1.mustBeTogether.push_back(target_pair);
                    n2.mustBeSeparated.push_back(target_pair);

                    nodes.push_back(n1);
                    nodes.push_back(n2);   
                }
            }
        }   
        root_idx++;
    }

    std::cout << "Resultado: " << best_integer << std::endl;
    
    env.end();    
}
