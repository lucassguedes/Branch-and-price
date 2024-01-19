#ifndef __BRANCH_AND_PRICE_H__
#define __BRANCH_AND_PRICE_H__
#include "Data.hpp"
#include "Model.hpp"
#include "ColumnGeneration.hpp"
#include <vector>
#include <algorithm>

void branchAndPrice(Data * data, NodeInfo nodeInfo);
std::vector<std::vector<double> > getZ(const NodeRes& res, const Master& master, const int nItems);
std::pair<int, int> getTargetPair(const std::vector<std::vector<double> > &z, const NodeInfo &nodeInfo);
bool isAnIntegerSolution(const Master& master);

#endif 
