#include <iostream>
#include <getopt.h>
#include <string.h>
#include "sort.hpp"


int main(int argc, char *argv[]){

    int opt, type, seed, median, partition;
    std::string input, output;

    while((opt = getopt(argc, argv, "v:s:k:m:i:o:")) != -1){
        switch(opt){
            case 'v':
                type = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                break;
            case 'k':
                median = atoi(optarg);
                break;
            case 'm':
                partition = atoi(optarg);
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
        }
    }

    std::ifstream input_file(input);

    erroAssert(input_file.is_open(), "Arquivo de entrada não encontrado");
    
    int num_arrays,tam;
    int i = 0;
    input_file >> num_arrays;

    Sort *arrays[num_arrays];

    while(!input_file.eof()){
        input_file >> tam;
        erroAssert(tam > 0, "Tamanho do array inválido");
        arrays[i] = new Sort(seed, tam);
        arrays[i]->randomArrays();
        i++;
    }

    input_file.close();

    return 0;
}