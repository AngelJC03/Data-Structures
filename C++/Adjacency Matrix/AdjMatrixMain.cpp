#include "AdjMatrix.h"
#include <iostream>

int main() {
    // Create an instance of AdjMatrix
    AdjMatrix graph;

    // Add edges to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 0, 4);

    // // Print the adjacency matrix (uncomment the following lines to print the adjacency matrix)
    //std::cout << "Adjacency Matrix:" << std::endl; // Uncomment this line to print the adjacency matrix
    //graph.printGraph(); // Uncomment this line to print the adjacency matrix

    // Output the adjacency matrix as a .dot file for visualization
    std::string outputFile = "adjacency_matrix.dot";
    graph.outputGraph(outputFile);
    std::cout << "Graph output written to: " << outputFile << std::endl;

    return 0;
}
