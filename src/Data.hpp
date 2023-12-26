#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
#include <vector>

class Data{
    public:
        double W; /*Width of the box*/
        std::vector<double> w; /*Width of each item*/

    void readData(const char* filepath);

    Data(){}

    ~Data(){}
};



#endif 