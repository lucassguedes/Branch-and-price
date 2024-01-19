#ifndef __COLUMN_GENERATION_H__
#define __COLUMN_GENERATION_H__

#include "Data.hpp"
#include <ilcplex/ilocplex.h>
#include <vector>
#include "Data.hpp"
#include "Model.hpp"
#include "Node.hpp"

#define EPSILON 1e-6

typedef struct NodeRes{
    double numberOfBins;
    IloAlgorithm::Status status;


    NodeRes(){}
    NodeRes(double numberOfBins, IloAlgorithm::Status status);
};


NodeRes columnGeneration(Data * data, IloEnv &env, IloCplex &masterSolver, IloCplex &pricingSolver, Master &master, NodeInfo nodeInfo);
void showResults(Master &master, Data * data, IloCplex &masterSolver);
bool isAnIntegerSolution(const Master& master, IloCplex& masterSolver);



#endif 
