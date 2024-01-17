#pragma once

#include <iostream>
#include <vector>

using namespace std;

class node {

    private:

        int data;

        node* next;
    
    public:

        node();
        node(int data);
        node(int data, node* next);
        ~node();

    friend class List;

};

class List {

    private:
        node* head;
        int size;

        node* getMid(node* head);
        node* mergeSort(node* head);
        node* merge(node* left, node* right);
        node* getHead();

    public:
        List();
        List(int data);
        List(vector<int> numbers);
        ~List();
        void prepend(int data);
        void append(int data);
        void insert(int data, int index);
        void remove(int data);
        bool search(int data);
        int getsize();
        void print();
        void clear();
        void sort();

};
