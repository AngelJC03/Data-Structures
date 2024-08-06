#pragma once

#include <iostream>
#include <array>
#include <random>


class DynArr {

    private:

        int *array;

        int Size;

        int Capacity;

        void grow();

        void shrink();

        int findIndex(int n);

        int partition(int *array, int start, int end);

        void quickSort(int *array, int start, int end);

    public:

        DynArr();

        DynArr(int capacity);

        ~DynArr();

        int size();

        int capacity();

        void push_front(int n);

        void push_back(int n);

        void removeIndex(int index);

        void removeNum(int n);

        bool search(int n);

        void print();

        int sum();

        void sort();

};