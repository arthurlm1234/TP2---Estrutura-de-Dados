#include "sort.hpp"

void Sort::readFile(std::string file){
    
    std::ifstream input(file);

    erroAssert(input.is_open(), "Arquivo não encontrado");

    int size;
    input >> size;

    while(!input.eof()){
        
    }

  
}