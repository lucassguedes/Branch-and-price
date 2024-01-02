#ifndef __BRANCH_AND_PRICE_H__
#define __BRANCH_AND_PRICE_H__
#include "Data.hpp"
#include "Model.hpp"
#include "ColumnGeneration.hpp"
#include <vector>

void branchAndPrice(Data * data, NodeInfo nodeInfo);
std::vector<std::vector<double> > getZ(NodeRes res, const int nItems);
std::pair<int, int> getTargetPair(const std::vector<std::vector<double> > &z);

#endif 