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
    Data aux = elements[i];
    elements[i] = elements[j];
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
    for(int i = 0; i < numberElements; i++){
        elements[i].key = rand() % 1000000;
    }
}

void Sort::recursiveQuickSort(int left, int right){

    int i = left, j = right;
    copies++;
    Data pivot = elements[(left + right) / 2];

    while(i <= j){
        comparisons++;
        while(elements[i].key < pivot.key){
            i++;
            comparisons++;
        }
        while(elements[j].key > pivot.key){
            j--;
            comparisons++;
        }
        comparisons++;
        if(i <= j){
            swap(i, j);
            i++;
            j--;
        }
    }

    comparisons++;
    if(left < j)
        recursiveQuickSort(left, j);
    comparisons++;
    if(i < right)
        recursiveQuickSort(i, right);
}

int Sort::randomPartition(int left, int right, int number){
    
    int sum = 0;
    srand(seed);

    for(int i = 0; i < number; i++){
        comparisons++;
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
    Data pivot = elements[right];
    int i, j;
    i = left;
    j = left;

    for(int i = left; i < right; i++){
        if(elements[i].key <= pivot.key){
            swap(i, j);
            j++;
        }
    }

    swap(j, right);

    return j;
}


void Sort::noRecursiveQuickSort(){

    int *beg, *end, i=0, L, R;
    Data piv;

    beg = new int[numberElements];
    end = new int[numberElements];

    beg[0]=0; end[0]=numberElements;
    while (i>=0) {
    comparisons++;
    copies += 2;
    L=beg[i]; 
    R=end[i]-1;
    comparisons++;
    if (L<R) {
        piv=elements[L];
        copies++;
        while (L<R) {
            comparisons++;
            while (elements[R].key>=piv.key && L<R){
            R--; 
            comparisons++;
            } 
            comparisons++;
            if (L<R){
                elements[L++].key=elements[R].key;
                copies++;
            } 
            while (elements[L].key<=piv.key && L<R){
            L++; 
            comparisons++;
            }
            comparisons++;
            if(L < R){
                elements[R--].key=elements[L].key;
                copies++;
            }
        }
        copies+= 4;
        elements[L]=piv; 
        beg[i+1]=L+1; 
        end[i+1]=end[i]; 
        end[i++]=L; 
    }
    else {
        i--; 
    }}

    delete[] beg;
    delete[] end;
}


void Sort::stackSmartQuickSort(){
    Data pivot;
    int i, j, L, R;

    int *begin = new int[numberElements];
    int *end = new int[numberElements];

    begin[0] = 0;
    end[0] = numberElements;

    while(i>=0){
        L = begin[i];
    }
}
    

void Sort::selectionQuickSort(int left, int right, int k){

    int i = left, j = right;

    comparisons++;
    if(right - left <= k){
        comparisons++;
        for(int i = left; i < right; i++){
            int min = i;
            comparisons++;
            for(int j = i + 1; j <= right; j++){
                comparisons += 2;
                if(elements[j].key < elements[min].key)
                    min = j;
            }
            swap(i, min);
        }
        return;
    }

    comparisons++;
    Data pivot = elements[(left + right) / 2];

    comparisons++;
    while(i <= j){
        comparisons++;
        while(elements[i].key < pivot.key)
            i++;
        comparisons++;
        while(elements[j].key > pivot.key)
            j--;
        comparisons++;
        if(i <= j){
            swap(i, j);
            i++;
            j--;
        }
    }

    comparisons++;
    if(left < j)
        selectionQuickSort(left, j, k);
    comparisons++;
    if(i < right)
        selectionQuickSort(i, right, k);
}

void Sort::mergeSort(int left, int right){
    comparisons++;
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
        comparisons++;
        L[i] = elements[left + i];
        copies++;
    }
    for(j = 0; j < n2; j++){
        comparisons++;
        R[j] = elements[middle + 1 + j];
        copies++;
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        comparisons += 2;
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
        comparisons++;
        elements[k] = L[i];
        copies++;
        i++;
        k++;
    }

    while(j < n2){
        comparisons++;
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

    comparisons += 2;
    if(l < n && elements[l].key > elements[largest].key)
        largest = l;
    comparisons += 2;
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
        comparisons++;
    }
    
    for(int i = n - 1; i >= 0; i--){
        comparisons++;
        swap(0, i);
        heapify(i, 0);
    }
}

void Sort::printArray(){
    for(int i = 0; i < numberElements; i++){
        std::cout << elements[i].key << std::endl;
    }
}














