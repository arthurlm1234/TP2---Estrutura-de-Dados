#include "sort.hpp"

Sort::Sort(int _seed, int _numberElements){
    seed = _seed;
    numberElements = _numberElements;
    elements = new Data[numberElements];
}

void Sort::randomArrays(){
    srand(seed);
    for(int i = 0; i < numberElements; i++){
        elements[i].key = rand();
    }
}

void Sort::recursiveQuickSort(int left, int right){
    int i = left, j = right;
    Data tmp;
    Data pivot = elements[(left + right) / 2];

    while(i <= j){
        while(elements[i].key < pivot.key)
            i++;
        while(elements[j].key > pivot.key)
            j--;
        if(i <= j){
            tmp = elements[i];
            elements[i] = elements[j];
            elements[j] = tmp;
            i++;
            j--;
        }
    }

    if(left < j)
        recursiveQuickSort(left, j);
    if(i < right)
        recursiveQuickSort(i, right);
}

void Sort::medianQuickSort(int left, int right, int k){
    int indexes[k];
    int sum = 0;
    
    srand(seed);

    for(int i = 0; i < k; i++){
        indexes[i] = rand() % numberElements;
        sum+= indexes[i];
    }

    Data pivot = elements[sum / k];
    Data tmp;
    int i = left, j = right;

    while(i <= j){
        while(elements[i].key < pivot.key)
            i++;
        while(elements[j].key > pivot.key)
            j--;
        if(i <= j){
            tmp = elements[i];
            elements[i] = elements[j];
            elements[j] = tmp;
            i++;
            j--;
        }
    }

    if(left < j)
        recursiveQuickSort(left, j);
    if(i < right)
        recursiveQuickSort(i, right);
}

void Sort::noRecursiveQuickSort(){
    int left = 0, right = numberElements - 1;
    int i, j;
    Data tmp;
    Data pivot = elements[(left + right) / 2];

    while(left < right){
        i = left;
        j = right;
        while(i <= j){
            while(elements[i].key < pivot.key)
                i++;
            while(elements[j].key > pivot.key)
                j--;
            if(i <= j){
                tmp = elements[i];
                elements[i] = elements[j];
                elements[j] = tmp;
                i++;
                j--;
            }
        }
        if(i < right)
            left = i;
        if(j > left)
            right = j;
    }
}

//quicksort process first the lowest partition









