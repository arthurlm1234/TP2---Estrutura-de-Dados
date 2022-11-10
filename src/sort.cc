#include "sort.hpp"

Sort::Sort(int _seed, int _numberElements, std::string _output){
    seed = _seed;
    numberElements = _numberElements;
    output = _output;
    elements = new Data[numberElements];
}

Sort::~Sort(){
    delete[] elements;
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
    struct rusage resources;

    double utime, stime, total_time;

    
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
    
    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec / 1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec / 1000000.0;
    total_time = utime + stime;
    //std::cout << "Tempo de execução: " << total_time << std::endl;

}

void Sort::medianQuickSort(int left, int right, int k, int medianPivot){

    Data pivot = elements[medianPivot];
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

int Sort::partition(int left, int right){
    Data pivot = elements[right];
    int i, j;
    i = left;
    j = left;

    for(int i = left; i < right; i++){
        if(elements[i].key <= pivot.key){
            Data tmp = elements[i];
            elements[i] = elements[j];
            elements[j] = tmp;
            j++;
        }
    }

    Data tmp = elements[j];
    elements[j] = elements[right];
    elements[right] = tmp;

    return j;
}


void Sort::noRecursiveQuickSort(){
    
    struct rusage resources;

    double utime, stime, total_time;

    int left = 0;
    int right = numberElements - 1;
    int stack[right - left + 1];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while(top >= 0){
        right = stack[top--];
        left = stack[top--];

        int p = partition(left, right);

        if(p - 1 > left){
            stack[++top] = left;
            stack[++top] = p - 1;
        }

        if(p + 1 < right){
            stack[++top] = p + 1;
            stack[++top] = right;
        }
    }

    getrusage(RUSAGE_SELF, &resources);
    utime = resources.ru_utime.tv_sec + resources.ru_utime.tv_usec / 1000000.0;
    stime = resources.ru_stime.tv_sec + resources.ru_stime.tv_usec / 1000000.0;
    total_time = utime + stime;
    //std::cout << "Tempo de execução: " << total_time << std::endl;
}
    

void Sort::selectionQuickSort(int left, int right, int k){
    struct rusage resources;

    double utime, stime, total_time;
    
    int i = left, j = right;
    Data tmp;

    if(right - left <= k){
        for(int i = left; i < right; i++){
            int min = i;
            for(int j = i + 1; j <= right; j++){
                if(elements[j].key < elements[min].key)
                    min = j;
            }
            tmp = elements[i];
            elements[i] = elements[min];
            elements[min] = tmp;
        }
        return;
    }

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
        selectionQuickSort(left, j, k);
    if(i < right)
        selectionQuickSort(i, right, k);
}

//dont use time
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

    for(i = 0; i < n1; i++)
        L[i] = elements[left + i];
    for(j = 0; j < n2; j++)
        R[j] = elements[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(L[i].key <= R[j].key){
            elements[k] = L[i];
            i++;
        }else{
            elements[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        elements[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        elements[k] = R[j];
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

    if(l < n && elements[l].key > elements[largest].key)
        largest = l;
    if(r < n && elements[r].key > elements[largest].key)
        largest = r;
    if(largest != i){
        Data tmp = elements[i];
        elements[i] = elements[largest];
        elements[largest] = tmp;
        heapify(n, largest);
    }
}

void Sort::heapSort(int n){
    Data tmp;
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    
    for(int i = n - 1; i >= 0; i--){
        tmp = elements[0];
        elements[0] = elements[i];
        elements[i] = tmp;
        heapify(i, 0);
    }
}

void Sort::printArray(){
    for(int i = 0; i < numberElements; i++){
        std::cout << elements[i].key << std::endl;
    }
}



//iterative quicksort, process first














