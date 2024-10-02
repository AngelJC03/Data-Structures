#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include <fstream>
#include <iostream>

class AdjMatrix {
private:
    static const int width = 150;
    static const int height = 150;
    int List[width][height];

public:
    // Constructors
    AdjMatrix();  // Default constructor

    void addEdge(int fromVertex, int toVertex, int weight);  // Function to add an edge between two vertices
    void printGraph();  // Function to print the adjacency matrix
    void outputGraph(std::string ofname);  // Function to generate .dot file
};

AdjMatrix::AdjMatrix() {
    // Initialize the matrix with zeros
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            List[i][j] = 0;
        }
    }
}

void AdjMatrix::addEdge(int source, int dest, int weight) {
    // Check if the source and destination vertices are within valid range
    if (source >= 0 && source < width && dest >= 0 && dest < height) {
        // Add the edge with the specified weight
        List[source][dest] = weight;
    } else {
        // Handle invalid vertex indices (you might want to throw an exception or handle it in another way)
        std::cerr << "Invalid vertex indices provided." << std::endl;
    }
}

void AdjMatrix::printGraph() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << List[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void AdjMatrix::outputGraph(std::string ofname) {
    std::ofstream file(ofname);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << ofname << std::endl;
        return;
    }

    file << "digraph G {" << '\n';
    file << '\n';

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (List[i][j] != 0) {
                file << i << " -> " << j << ";" << std::endl;
            }
        }
    }

    file << std::endl << "}";
    file.close();
}

#endif