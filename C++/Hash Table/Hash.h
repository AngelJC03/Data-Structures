#pragma once
#include <vector>
#include <list>

class HashTable {
    private:
        int currentSize;
        int mode;
        int NumElements;
        int collisions;
        std::vector<int> hashTable;
        std::vector<std::list<int> > table;
        int hash(int key);
        int hash2(int value);
        void resize();

    public:
        HashTable();
        HashTable(int mode);
        ~HashTable();
        void insert(int value);
        bool search(int value);
        void put(int key, int value);
        void remove(int key);
        void print();
        int get_num_collisions();
        int size();
        int elements();
        HashTable clone();
};