#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
#include <vector>

class Data{
    public:
        double W; /*Largura da caixa*/
        std::vector<double> w; /*Largura de cada um dos itens*/

    void readData(const char* filepath);
    int getNumberOfItems();

    Data(){}

    ~Data(){}
};



#endif 