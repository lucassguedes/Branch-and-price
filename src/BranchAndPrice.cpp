#include "BranchAndPrice.hpp"

#define EPSILON 1e-6

void branchAndPrice(Data * data, NodeInfo nodeInfo)
{
    // static double bestSolutionEver;
    CGResult res = columnGeneration(data, nodeInfo);

    if(res.numberOfBins - (int)res.numberOfBins < EPSILON){
        /*Podar*/
    }else{
        /*Obter valores de z_ij*/
        /*Chamar o branchAndPrice novamente
            - Proibindo os itens i e j de ficarem juntos
            - Obrigando os itens i e j a ficarem juntos
            - Importante repassar os dados anteriormente obtidos de nodeInfo para as ramificações
        */
    }
}