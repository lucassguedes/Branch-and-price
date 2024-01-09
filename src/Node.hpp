#ifndef __NODE_H__
#define __NODE_H__
#include <vector>
#include <iostream>

class NodeInfo{
public:
    int id;
	int parent_id;
    std::vector<std::pair<int, int> > mustBeTogether;
    std::vector<std::pair<int, int> > mustBeSeparated;
    NodeInfo(){}

    friend std::ostream& operator << (std::ostream& os, const NodeInfo& node);
};



#endif 
