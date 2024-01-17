#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node {

    private:

        int data;
        Node* left;
        Node* right;

    public:

        Node();
        Node(int value);
        ~Node();

    friend class BST;
};

class BST {
    
    private:

        Node* root;
        Node* insert(Node* root, int value);
        Node* remove(Node* root, int value);
        Node* search(Node* root, int value);
        void printPRE(Node* root);
        void printPOST(Node* root);
        void printIN(Node* root);
    
    public: 

        BST();
        BST(int value);
        BST(vector<int> items);
        ~BST();
        void insert(int value);
        void remove(int value);
        bool search(int value);
        void printPRE();
        void printPOST();
        void printIN();

};