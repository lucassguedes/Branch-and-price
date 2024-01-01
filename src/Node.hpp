#ifndef __NODE_H__
#define __NODE_H__
#include <vector>

class Node{
public:
    int id;
    std::vector<std::pair<int, int> > mustBeTogether;
    std::vector<std::pair<int, int> > mustBeSeparated;
};



#endif 