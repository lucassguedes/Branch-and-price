#include <iostream>
#include <ilcplex/ilocplex.h>
#include "Data.hpp"
#include <fstream>

#define COMBINATIONS_FOLDER_PATH "./instances/combinations/"

void bin_packing(Data * data)
{
    IloEnv env;
    IloModel model(env);
    IloCplex cplex(model);

    env.setName("Branch and Price");
    model.setName("Bin Packing");
}


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