#ifndef __COLUMN_GENERATION_H__
#define __COLUMN_GENERATION_H__

#include "Data.hpp"
#include <ilcplex/ilocplex.h>
#include <vector>
#include "Data.hpp"
#include "Model.hpp"
#include "Node.hpp"

typedef struct NodeRes{
    Master master;
    double numberOfBins;
    IloAlgorithm::Status status;

    NodeRes(Master master, double numberOfBins, IloAlgorithm::Status status);
};


NodeRes columnGeneration(Data * data, IloEnv &env, IloCplex &masterSolver, IloCplex &pricingSolver, Master &master, NodeInfo nodeInfo);



#endif 
