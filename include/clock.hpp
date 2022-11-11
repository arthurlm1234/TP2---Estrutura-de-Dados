#include "sort.hpp"

int previousTime(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double utime, stime, total;
    utime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
    stime = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
    total = utime + stime;
    return total;
}

void clockRecursiveQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.recursiveQuickSort(0, array.getNumberElements() - 1);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "QuickSort Recursivo com " << array.getNumberElements() << " elementos " << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockNoRecursiveQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.noRecursiveQuickSort();
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "QuickSort Não Recursivo com " << array.getNumberElements() << " elementos " << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockSelectionQuickSort(Sort array, int k, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.selectionQuickSort(0, array.getNumberElements() - 1, k);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "Tempo de execução do QuickSort Seleção com " << array.getNumberElements() << " elementos e m = " << k << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockMedianQuickSort(Sort array, int k, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.medianQuickSort(0, array.getNumberElements() - 1, k);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "QuickSort Mediana com " << array.getNumberElements() << " elementos e k = " << k << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockStackSmartQuickSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.stackSmartQuickSort();
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "QuickSort Stack Smart com " << array.getNumberElements() << " elementos " << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockMergeSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.mergeSort(0, array.getNumberElements() - 1);
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "MergeSort com " << array.getNumberElements() << " elementos " << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}

void clockHeapSort(Sort array, std::string output){
    std::ofstream outputFile(output, std::ios::app);
    int time = previousTime();
    struct rusage resources;
    double utime, stime, total_time;
    array.heapSort(array.getNumberElements());
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec/1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec/1000000.0;
    total_time = utime + stime - time;
    outputFile << "HeapSort com " << array.getNumberElements() << " elementos " << std::endl;
    outputFile << "Número de comparações: " << array.getComparisons() << std::endl;
    outputFile << "Número de cópias: " << array.getCopies() << std::endl;
    outputFile << "Tempo de execução: " << total_time << std::endl;
    outputFile << std::endl;
}