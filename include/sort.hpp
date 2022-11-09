#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/resource.h>
#include "data.hpp"
#include "msgassert.hpp"

class Sort{

private:

    Data *elements = nullptr;
    long unsigned int numberElements;
    int seed;
    std::string output;

public:
    Sort(int _seed = 1, int _numberElements = 1, std::string _output = "A");
    ~Sort();
    void randomArrays();
    void recursiveQuickSort(int left, int right);
    void medianQuickSort(int left, int right, int k);
    void selectionQuickSort(int left, int right, int k);
    void noRecursiveQuickSort();
    void stackSmartQuickSort();
    void printArray();
    int partition(int left, int right);
    int getNumberElements();

};

#endif