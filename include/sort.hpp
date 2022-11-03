#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <fstream>
#include "msgassert.hpp"

class Sort{
public:
    Sort(int _seed, int _numberElements);
    void randomArrays();
    void recursiveQuickSort(int left, int right);
    void medianQuickSort(int left, int right, int k);
    void selectionQuickSort(int left, int right, int k);
    void noRecursiveQuickSort();
    void stackSmartQuickSort();

private:
    struct Data{
        uint64_t key;
        char strings[15][200];
        int numbers[10];
    };

    Data *elements = nullptr;
    long unsigned int numberElements;
    int seed;
};

#endif