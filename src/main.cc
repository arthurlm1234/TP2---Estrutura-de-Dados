#include <iostream>
#include <getopt.h>
#include <cmath>
#include "clock.hpp"

int calculateMedian(int seed, int median, int tam){
    
    int sum = 0;

    srand(seed);

    for(int i = 0; i < median; i++){
        sum += rand() % tam;
    }

    return std::trunc(sum/median);
}

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
    std::ofstream outputFile(output);


    erroAssert(input_file.is_open(), "Arquivo de entrada não encontrado");
    
    int num_arrays,tam;
    input_file >> num_arrays;

    Sort *array = new Sort;

    while(!input_file.eof()){
        input_file >> tam;
        erroAssert(tam > 0, "Tamanho do array inválido");
        array = new Sort(seed, tam, output);
        array->randomArrays();
        //int medianPivot = calculateMedian(seed, median, tam);
        
        switch(type){
            case 1:
                clockRecursiveQuickSort(*array, output);
                break;
            case 2:
                clockMedianQuickSort(*array, median, output);
                break;
            case 3:
                clockSelectionQuickSort(*array, partition, output);
                break;
            case 4:
                clockNoRecursiveQuickSort(*array, output);
                break;
            case 5:
                clockStackSmartQuickSort(*array, output);
                break;
            case 6:
                clockMergeSort(*array, output);
                break;
            case 7:
                clockHeapSort(*array, output);
                break;
            default:
                erroAssert(false, "Opcão inválida!");
                break;
        }
    }

    input_file.close();

    return 0;
}

