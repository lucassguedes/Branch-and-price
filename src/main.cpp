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

    node.id = 0;
    branchAndPrice(data, node);


    delete data;

    return 0;
}
