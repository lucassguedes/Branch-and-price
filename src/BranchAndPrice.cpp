#include "BranchAndPrice.hpp"

#define EPSILON 1e-6

std::vector<std::vector<double> > getZ(NodeRes res, const int nItems)
{
    std::vector<std::vector<double> > z = std::vector<std::vector<double> > (nItems, std::vector<double>(nItems, 0));

    int nPatternItems;
    for(Pattern p : res.master.patterns)
    {
        nPatternItems = p.activated_x.size();
        for(int i = 0; i < nPatternItems; i++)
        {
            for(int j = i+1; j < nPatternItems; j++)
            {
                if(j != i)
                {
                    z[i][j] += p.value;
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
    bool alreadyTogether, alreadySeparated, pairIsValid;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist = fabs(z[i][j] - 0.5);
            alreadyTogether = (std::find(nodeInfo.mustBeTogether.begin(), nodeInfo.mustBeTogether.end(), std::make_pair(i, j)) != nodeInfo.mustBeTogether.end());
            alreadySeparated = (std::find(nodeInfo.mustBeSeparated.begin(), nodeInfo.mustBeSeparated.end(), std::make_pair(i, j)) != nodeInfo.mustBeSeparated.end());
            pairIsValid = (!alreadyTogether && !alreadySeparated);
            if(dist < smallerDist && i != j && pairIsValid)
            {
                smallerDist = dist;
                target = std::make_pair(i, j);
            }
        }
    }

    return target;
}

bool isAnIntegerSolution(const NodeRes &res)
{
    for(Pattern p : res.master.patterns)
    {
        if(fabs(p.value - (int)p.value) > EPSILON)
        {
            return false;
        }
    }
    return true;
}

void branchAndPrice(Data * data, NodeInfo nodeInfo)
{
    // static double bestSolutionEver;
    NodeRes res = columnGeneration(data, nodeInfo);

    std::cout << nodeInfo << std::endl;
    getchar();
    if(res.status == IloAlgorithm::Optimal && isAnIntegerSolution(res)){
        /*Podar*/
        std::cout << "Finalizado!\n";
    }else{
        std::cout << "Status da última execução: " << res.status << "\n";
        getchar();
        /*Obter valores de z_ij*/
        /*Chamar o branchAndPrice novamente
            - Proibindo os itens i e j de ficarem juntos
            - Obrigando os itens i e j a ficarem juntos
            - Importante repassar os dados anteriormente obtidos de nodeInfo para as ramificações
        */
       std::vector<std::vector<double> > z = getZ(res, data->numberOfItems);

       for(int i = 0; i < z.size(); i++)
       {
            for(int j = 0; j < z[i].size(); j++)
            {
                if(z[i][j] > EPSILON)
                {
                    std::cout << "z[" << i << "][" << j << "] = " << z[i][j] << "\n";
                }
            }
       }

       std::pair<int, int> target = getTargetPair(z, nodeInfo);
    
       std::cout << "Target: (" << target.first << ", " << target.second << ")\n";
       if(target != std::make_pair(-1, -1))
       {
            NodeInfo child1 = nodeInfo;
            child1.mustBeTogether.push_back(target);
            branchAndPrice(data, child1);
            NodeInfo child2 = nodeInfo;
            child2.mustBeSeparated.push_back(target);
            branchAndPrice(data, child2);
       }

    }
}