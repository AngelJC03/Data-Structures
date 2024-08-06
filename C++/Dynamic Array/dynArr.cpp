#include "dynArr.h"

DynArr::DynArr() {
    this->array = new int[1];
    this->Capacity = 1;
    this->Size = 0;
}

DynArr::DynArr(int capacity) {
    this->array = new int[capacity];
    this->Capacity = capacity;
    this->Size = 0;
}

DynArr::~DynArr() {
    delete[] array;
}

int DynArr::size() {
    return this->Size;
}

int DynArr::capacity() {
    return this->Capacity;
}

void DynArr::push_back(int n) {

    if (this->Size >= this->Capacity) {

        grow();

    }

    array[this->Size] = n;
    this->Size += 1;

}

void DynArr::push_front(int n) {

    if (this->Size >= this->Capacity) {

        grow();

    }

    for (int i = Size; i > 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = n;
    this->Size += 1;
}

void DynArr::removeIndex(int index) {

    if (index >= this->Size) {
        std::cout << "Index " << index << " does not exist, the current last index is " << size() - 1 << '\n';
        return;
    }


    for (int i = index; i < this->Size; i++){
        array[i] = array[i + 1];
    }

    this->Size -= 1;

    if (this->Size <= this->Capacity * 0.5) {
        shrink();
    }

}

void DynArr::removeNum(int n) {

    if (findIndex(n) == -1) {
        std::cout << "Number is not in the array, hooray!" << '\n';
        return;
    }

    int index = findIndex(n);

    for (int i = index; i < this->Size; i++) {
        array[i] = array[i + 1];
    }

    this->Size -= 1;

    if (this->Size <= this->Capacity * 0.5) {
        shrink();
    }
}

bool DynArr::search(int n) {

    for (int i = 0; i < this->Size; i++) {
        if (array[i] == n) {
            return true;
        }
    }

    return false;
}

void DynArr::print() {

    std::cout << "[";

    for (int i = 0; i < this->Size; i++) {

        if (i == this->Size - 1) {
            std::cout << array[i];
            continue;
        }

        std::cout << array[i] << ", ";
    }

    std::cout << "]" << '\n';

    std::cout << '\n';
}

int DynArr::sum() {

    int sum = 0;

    for (int i = 0; i < this->Size; i++) {
        sum += array[i];
    }

    return sum;
}

void DynArr::sort() {
    quickSort(array, 0, this->Size - 1);
}

void DynArr::grow() {

    this->Capacity *= 2;
    int *newArray = new int[this->Capacity];

    for (int i = 0; i < this->Size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

void DynArr::shrink() {

    if (this->Capacity > 1) {

        this->Capacity /= 2;
        int* newArray = new int[this->Capacity];

        for (int i = 0; i < this->Size; i++) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
    }
}
int DynArr::findIndex(int n) {

    for (int i = 0; i < this->Size; i++) {

        if (array[i] == n) {
            return i;
        }

    }

    return -1;
}        
        
void DynArr::quickSort(int *array, int start, int end) {
        
    if (end <= start) {
        return;
    }

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);

}

int DynArr::partition(int *array, int start, int end) {

    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
            
    i++;

    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;

    return i;
}