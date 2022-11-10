#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/resource.h>
#include <cmath>
#include "data.hpp"
#include "msgassert.hpp"

class Sort{

private:

    Data *elements = nullptr;
    long unsigned int numberElements;
    int seed;
    std::string output;
    int comparisons;
    int copies;

public:
    Sort(int _seed = 1, int _numberElements = 1, std::string _output = "A");
    ~Sort();
    void randomArrays();
    void swap(int i, int j);
    void recursiveQuickSort(int left, int right);
    void medianQuickSort(int left, int right, int medianPivot);
    void selectionQuickSort(int left, int right, int k);
    void noRecursiveQuickSort();
    void stackSmartQuickSort();
    void mergeSort(int left, int right);
    void merge(int left, int middle, int right);
    void heapSort(int n);
    void heapify(int n, int i);
    void printArray();
    int partition(int left, int right);
    int getNumberElements();
    int getComparisons();
    int getCopies();

};

#endif