#ifndef __COLUMN_GENERATION_H__
#define __COLUMN_GENERATION_H__

#include "Data.hpp"
#include <ilcplex/ilocplex.h>
#include <vector>
#include "Data.hpp"
#include "Model.hpp"
#include "Node.hpp"

typedef struct CGResult{
    Master master;
    double numberOfBins;

    CGResult(Master master, double numberOfBins);
};


CGResult columnGeneration(Data * data, NodeInfo nodeInfo);



#endif 