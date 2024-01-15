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


// size_t allocated = 0;
// size_t freed = 0;

// void operator delete(void* p, size_t size){

// 	std::cout << "Freeing: " << size << " bytes\n";
// 	freed += size;
// 	free(p);
// }

// void* operator new(size_t size){

// 	allocated += size;
// 	std::cout << "Allocating: " << size  << " bytes\n";

// 	return malloc(size);
// }



int main(int argc, char** argv)
{

    if(argc < 2)
    {
        std::cout << "Erro: Argumento inválido.\n\tModo de utilização: ./bp <instance_path>\n";
        return -1;
    }


    Data* data = new Data();

    data->readData(argv[1]);

    branchAndPrice(data, NodeInfo());


    delete data;

    return 0;
}
