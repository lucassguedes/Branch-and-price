#include <iostream>
#include <ilcplex/ilocplex.h>
#include "Data.hpp"


int main(int argc, char** argv)
{

    if(argc < 2)
    {
        std::cout << "Erro: Argumento inválido.\n\tModo de utilização: ./bp <instance_path>\n";
        return -1;
    }


    Data* data = new Data();

    data->readData(argv[1]);


    delete data;

    return 0;
}