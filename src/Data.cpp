#include "Data.hpp"
#include <fstream>

void Data::readData(const char* instanceName)
{
    std::ifstream file(instanceName);
    double itemWidth;

    if(file.is_open())
    {
        file >> this->W;
        while(file >> itemWidth)this->w.push_back(itemWidth);
    }

    file.close();

}