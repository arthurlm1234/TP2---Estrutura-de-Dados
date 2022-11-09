#include "sort.hpp"

void clockRecursiveQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    struct rusage resources;
    double utime, stime, total_time;
    array.recursiveQuickSort(0, array.getNumberElements() - 1);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime;
    outputFile << "Tempo de execução do QuickSort Recursivo com " << array.getNumberElements() << " elementos: " << total_time << std::endl;
}

void clockNoRecursiveQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    struct rusage resources;
    double utime, stime, total_time;
    array.noRecursiveQuickSort();
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime;
    std::cout << "Tempo de execução do QuickSort Não Recursivo com " << array.getNumberElements() << " elementos: " << total_time << std::endl;
}

void clockSelectionQuickSort(Sort array, int k, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    struct rusage resources;
    double utime, stime, total_time;
    array.selectionQuickSort(0, array.getNumberElements() - 1, k);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime;
    std::cout << "Tempo de execução do QuickSort Seleção com " << array.getNumberElements() << " elementos: " << total_time << std::endl;
}

void clockMedianQuickSort(Sort array, int k, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    struct rusage resources;
    double utime, stime, total_time;
    array.medianQuickSort(0, array.getNumberElements() - 1, k);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime;
    std::cout << "Tempo de execução do QuickSort Mediana com " << array.getNumberElements() << " elementos: " << total_time << std::endl;
}

void clockStackSmartQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    struct rusage resources;
    double utime, stime, total_time;
    //array.stackSmartQuickSort();
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime;
    std::cout << "Tempo de execução do QuickSort Stack Smart com " << array.getNumberElements() << " elementos: " << total_time << std::endl;
}