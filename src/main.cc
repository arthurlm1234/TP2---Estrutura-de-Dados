#include <iostream>
#include <getopt.h>
#include "clock.hpp"


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
    input_file >> num_arrays;

    Sort *array = new Sort(0,0);

    while(!input_file.eof()){
        input_file >> tam;
        erroAssert(tam > 0, "Tamanho do array inválido");
        array = new Sort(seed, tam);
        array->randomArrays();
        
        switch(type){
            case 1:
                clockRecursiveQuickSort(*array);
                break;
            case 2:
                clockMedianQuickSort(*array, median);
                break;
            case 3:
                clockSelectionQuickSort(*array, partition);
                break;
            case 4:
                clockNoRecursiveQuickSort(*array);
                break;
            case 5:
                clockStackSmartQuickSort(*array);
                break;
            default:
                erroAssert(false, "Opcão inválida!");
                break;
        }
    }

    input_file.close();

    return 0;
}

