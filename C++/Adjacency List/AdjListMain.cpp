#include "AdjList.h"
#include <iostream>
#include <fstream>

int main() {
    // Create an object of AdjList
    AdjList graph;

    // Add some edges with weights
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 7);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);

    // Output the graph into the console
    std::cout << "Graph adjacency list representation:" << std::endl;
    graph.printGraph();

    // Call problem1: Generate dot file for graph visualization
    std::cout << "Writing problem1 output to 'output_problem1.dot'" << std::endl;
    graph.problem1("output_problem1.dot");

    // Call problem2: Generate dot file with colored edges based on even/odd weights
    std::cout << "Writing problem2 output to 'output_problem2.dot'" << std::endl;
    graph.problem2("output_problem2.dot");

    // Call problem3: Generate dot file with edges colored based on their position
    std::cout << "Writing problem3 output to 'output_problem3.dot'" << std::endl;
    graph.problem3("output_problem3.dot");

    // Call problem4: Generate dot file using DFS with depth-based color assignment
    std::cout << "Writing problem4 output to 'output_problem4.dot'" << std::endl;
    graph.problem4("output_problem4.dot");

    return 0;
}
