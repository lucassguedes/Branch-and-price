#include <iostream>
#include <ilcplex/ilocplex.h>
#include "Data.hpp"
#include <fstream>
#include <bitset>
#include <algorithm>
#include <string>
#include "Model.hpp"
#include "ColumnGeneration.hpp"
#include "BranchAndPrice.hpp"

int main(int argc, char** argv)
{

    if(argc < 2)
    {
        std::cout << "Erro: Argumento inválido.\n\tModo de utilização: ./bp <instance_path>\n";
        return -1;
    }


    Data* data = new Data();

    data->readData(argv[1]);

    NodeInfo node;

    node.id = 1;
    node.mustBeSeparated.push_back(std::make_pair(1, 2));
    node.mustBeTogether.push_back(std::make_pair(4, 5));

    branchAndPrice(data, NodeInfo());


    delete data;

    return 0;
}