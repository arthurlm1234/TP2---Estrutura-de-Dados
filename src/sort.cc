#include "sort.hpp"

Sort::Sort(int _seed, int _numberElements, std::string _output){
    seed = _seed;
    numberElements = _numberElements;
    output = _output;
    elements = new Data[numberElements];
    comparisons = 0;
    copies = 0;
}

Sort::~Sort(){
    delete[] elements;
}

void Sort::swap(int i, int j){
    LEMEMLOG((long int)((&elements[i])), sizeof(Data),0);
    Data aux = elements[i];

    LEMEMLOG((long int)((&elements[j])), sizeof(Data),0);
    ESCREVEMEMLOG((long int)((&elements[i])), sizeof(Data),0);
    elements[i] = elements[j];
    
    ESCREVEMEMLOG((long int)((&elements[j])), sizeof(Data),0);
    elements[j] = aux;
    copies += 3;
}

int Sort::getComparisons(){
    return comparisons;
}

int Sort::getCopies(){
    return copies;
}

int Sort::getNumberElements(){
    return numberElements;
}

void Sort::randomArrays(){
    srand(seed);
    for(long unsigned int i = 0; i < numberElements; i++){
        elements[i].key = rand() % 1000000;
    }
}

void Sort::recursiveQuickSort(int left, int right){
    
    if(left < right){
        int pivot = partition(left, right);
        recursiveQuickSort(left, pivot - 1);
        recursiveQuickSort(pivot + 1, right);
    }
}

int Sort::randomPartition(int left, int right, int number){
    
    int sum = 0;
    srand(seed);

    for(int i = 0; i < number; i++){
        sum += left + rand() % (right - left);
    }

    int random = trunc(sum/number);

    swap(random, right);

    return partition(left, right);
}

void Sort::medianQuickSort(int left, int right, int number){

    comparisons++;
    if(left < right){
        int pi = randomPartition(left, right, number);

        medianQuickSort(left, pi - 1, number);
        medianQuickSort(pi + 1, right, number);
    }    
}

int Sort::partition(int left, int right){

    LEMEMLOG((long int)((&elements[right])), sizeof(Data),0);
    Data pivot = elements[right];
    int j;
    j = left;

    for(int i = left; i < right; i++){
        comparisons++;
        if(elements[i].key <= pivot.key){
            swap(i, j);
            j++;
        }
    }

    swap(j, right);

    return j;
}

void Sort::noRecursiveQuickSort(){

    int left = 0;
    int right = numberElements - 1;
    int stack[right - left + 1];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while(top >= 0){
        copies += 2;
        right = stack[top--];
        left = stack[top--];

        int pi = partition(left, right);

        if(pi - 1 > left){
            copies += 2;
            stack[++top] = left;
            stack[++top] = pi - 1;
        }

        if(pi + 1 < right){
            stack[++top] = pi + 1;
            stack[++top] = right;
        }
    }
}

void Sort::stackSmartQuickSort(){
    int left = 0;
    int right = numberElements - 1;
    int stack[right - left + 1];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while(top >= 0){
        copies += 2;
        right = stack[top--];
        left = stack[top--];

        int pi = partition(left, right);

        if(pi - 1 - left < right - pi + 1){
            if(pi - 1 > left){
                stack[++top] = left;
                stack[++top] = pi - 1;
            }

            if(pi + 1 < right){
                stack[++top] = pi + 1;
                stack[++top] = right;
            }
        
        }else{
            if(pi + 1 < right){
                stack[++top] = pi + 1;
                stack[++top] = right;
            }

            if(pi - 1 > left){
                stack[++top] = left;
                stack[++top] = pi - 1;
            }
        }
    }

}

void Sort::selectionQuickSort(int left, int right, int k){

    if(right - left <= k){
        for(int i = left; i < right; i++){
            int min = i;
            for(int j = i + 1; j <= right; j++){
                if(elements[j].key < elements[min].key)
                    min = j;
            }
            swap(i, min);
        }
        return;
    }

    if(left < right){
        int pi = partition(left, right);

        if(pi > left){
            selectionQuickSort(left, pi - 1, k);
        }

        if(pi < right){
            selectionQuickSort(pi + 1, right, k);
        }
    }
}

void Sort::mergeSort(int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}

void Sort::merge(int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Data *L = new Data[n1];
    Data *R = new Data[n2];

    for(i = 0; i < n1; i++){
        L[i] = elements[left + i];
        copies++;
    }
    for(j = 0; j < n2; j++){
        R[j] = elements[middle + 1 + j];
        copies++;
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        comparisons++;
        if(L[i].key <= R[j].key){
            elements[k] = L[i];
            copies++;
            i++;
        }else{
            elements[k] = R[j];
            copies++;
            j++;
        }
        k++;
    }

    while(i < n1){
        elements[k] = L[i];
        copies++;
        i++;
        k++;
    }

    while(j < n2){
        elements[k] = R[j];
        copies++;
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void Sort::heapify(int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    comparisons++;
    if(l < n && elements[l].key > elements[largest].key)
        largest = l;
    comparisons++;
    if(r < n && elements[r].key > elements[largest].key)
        largest = r;
    comparisons++;
    if(largest != i){
        swap(i, largest);
        heapify(n, largest);
    }
}

void Sort::heapSort(int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(0, i);
        heapify(i, 0);
    }
}













