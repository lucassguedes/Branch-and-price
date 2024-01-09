#ifndef __COLUMN_GENERATION_H__
#define __COLUMN_GENERATION_H__

#include "Data.hpp"
#include <ilcplex/ilocplex.h>
#include <vector>
#include "Data.hpp"
#include "Model.hpp"
#include "Node.hpp"

class NodeRes{
public:
	Master master;
    double numberOfBins;
    IloAlgorithm::Status status;

    NodeRes(Master master, double numberOfBins, IloAlgorithm::Status status);
	NodeRes(){}
};


NodeRes columnGeneration(Data * data, Master &master, IloEnv &env, NodeInfo nodeInfo);



#endif 
