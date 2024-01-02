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

std::pair<int, int> getTargetPair(const std::vector<std::vector<double> > &z){
    double smallerDist = std::numeric_limits<double>::infinity();
    const int n = z.size();

    double dist;
    std::pair<int, int> target;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist = fabs(z[i][j] - 0.5);
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
    // static double bestSolutionEver;
    NodeRes res = columnGeneration(data, nodeInfo);

    std::vector<std::vector<double> > z = getZ(res, data->numberOfItems);
       
    for(int i = 0; i < z.size(); i++)
    {
        for(int j = 0; j < z[i].size(); j++)
        {
            std::cout << "z[" << i << "][" << j << "] = " << z[i][j] << "\n";
        }
    }

    std::pair<int, int> target = getTargetPair(z);
    std::cout << "i = " << target.first << ", j = " << target.second << "\n";
    if(res.numberOfBins - (int)res.numberOfBins < EPSILON){
        /*Podar*/
    }else{
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
                std::cout << "z[" << i << "][" << j << "] = " << z[i][j] << "\n";
            }
       }
    }
}