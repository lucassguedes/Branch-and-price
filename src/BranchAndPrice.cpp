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
                z[i][j] += p.value;
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
    // std::cout << nodeInfo << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            dist = fabs(z[i][j] - 0.5);
            alreadyTogether = (std::find(nodeInfo.mustBeTogether.begin(), nodeInfo.mustBeTogether.end(), std::make_pair(i, j)) != nodeInfo.mustBeTogether.end());
            alreadySeparated = (std::find(nodeInfo.mustBeSeparated.begin(), nodeInfo.mustBeSeparated.end(), std::make_pair(i, j)) != nodeInfo.mustBeSeparated.end());
            pairIsValid = (!alreadyTogether && !alreadySeparated);
            if(dist < smallerDist && pairIsValid)
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
    
	//Busca em largura - iterativo
	std::vector<NodeInfo> nodes; //Nós da árvore, cada qual com seus pares proibidos e obrigatórios/
	std::vector<std::vector<double> > z; //Verificar se z terá sempre o mesmo tamanho. Se sim, alocar apenas uma vez
	std::pair<int, int> target; //Par de itens que precisam estar juntos/separados
    NodeRes res;

    nodes.push_back(nodeInfo);
	int root = 0;
	nodes[0].id = 0;
	double bestKnownResult = -std::numeric_limits<double>::infinity();
	int numberOfNodes=1;
	std::cout << nodes[root] << "\n";
    while(true){
    	res = columnGeneration(data, nodes[root]); //Obter resultado da geração de colunas
		getchar();
		if(isAnIntegerSolution(res)){//Se a solução for inteira
			std::cout << "Encontrou uma solução inteira!\n";
			if(res.numberOfBins <= data->numberOfItems && res.numberOfBins >= bestKnownResult){
				bestKnownResult = res.numberOfBins;
				std::cout << "Novo melhor resultado = " << bestKnownResult << "\n";
				getchar();
			}
		}
		else{//senão
			z = getZ(res, data->numberOfItems);
        	target = getTargetPair(z, nodes[root]);//Obtendo novo par de itens que devem ficar juntos/separados
			if(target == std::make_pair(-1, -1)){//Se não for ramificar
				root++;
				break;
			}else{
				NodeInfo child1 = nodes[root];
				child1.id = numberOfNodes;
				child1.mustBeTogether.push_back(target);
				std::cout << child1 << "\n";
				NodeInfo child2 = nodes[root];
				child2.id = numberOfNodes+1;
				child2.mustBeSeparated.push_back(target);
				std::cout << child2 << "\n";

				numberOfNodes+=2;

				nodes.push_back(child1);
				nodes.push_back(child2);
				root++;
				std::cout << "root = " << root << "\n";
			}
		}
		
	}
	/*if(res.status == IloAlgorithm::Optimal && isAnIntegerSolution(res)){
        //Podar
        std::cout << "Finalizado!\n";
    }else{
        std::cout << "Status da última execução: " << res.status << "\n";
        std::vector<std::vector<double> > z = getZ(res, data->numberOfItems);
		
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

    }*/
}
