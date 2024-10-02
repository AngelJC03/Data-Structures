#ifndef ADJLIST_H
#define ADJLIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <stack>

class AdjList {
private:
    std::vector <std::list<std::pair <int, int> > > adjacency_list;

public:
    // Constructors
    AdjList();  // Default constructor

    // Member functions
    void addEdge(int fromVertex, int toVertex, int weight);  // Function to add an edge between two vertices
    void printGraph();  // Function to print the adjacency list
    int size();

    // Problem-specific functions
    void problem1(std::string ofname);  // Function for problem 1
    void problem2(std::string ofname);  // Function for problem 2
    void problem3(std::string ofname);  // Function for problem 3
    void problem4(std::string ofname);  // Function for problem 4
    int getLastElementDepth();
    int getTailValue();
    int DFSForLastElementDepth(int currentVertex, int depth, std::vector<bool>& visited);
    void DFS(int currentVertex, std::vector<int>& distances, std::ofstream& file, std::vector<std::vector<bool> >& processedEdges);
};

AdjList::AdjList() {
    // Initialize the adjacency list with empty lists
    adjacency_list.resize(150);
}


// Function to add an edge between two vertices
void AdjList::addEdge(int fromVertex, int toVertex, int weight) {
    // Find the maximum vertex index among fromVertex and toVertex
    int maxVertex = std::max(fromVertex, toVertex);

    // Resize the adjacency list if needed
    if (maxVertex >= 0 && maxVertex >= adjacency_list.size()) {
        adjacency_list.resize(maxVertex + 1);
    }

    // Add the edge
    if (fromVertex >= 0 && fromVertex < adjacency_list.size() &&
        toVertex >= 0 && toVertex < adjacency_list.size()) {
        
        adjacency_list[fromVertex].emplace_back(toVertex, weight);

        // Uncomment the next line if the graph is undirected
        // adjacency_list[toVertex].emplace_back(fromVertex, weight);
        
    } else {
        std::cerr << "Invalid vertex indices provided." << std::endl;
    }
}

void AdjList::printGraph() {
    for (int i = 0; i < adjacency_list.size(); ++i) {
        std::cout << "Vertex " << i << " :";
        for (const auto& edge : adjacency_list[i]) {
            std::cout << " -> " << edge.first << " (Weight: " << edge.second << ")";
        }
        std::cout << std::endl;
    }
}

void AdjList::problem1(std::string ofname) {
    std::ofstream file(ofname);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << ofname << std::endl;
        return;
    }

    file << "digraph G {" << '\n';
    file << '\n';

    for (int i = 0; i < adjacency_list.size(); ++i) {
        for (const auto& edge : adjacency_list[i]) {
            file << i << " -> " << edge.first << " [label=\"" << edge.second << "\"];" << std::endl;
        }
    }

    file << '\n' << "}";
    file.close();
}

void AdjList::problem2(std::string ofname) {
    std::ofstream file(ofname);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << ofname << std::endl;
        return;
    }

    file << "digraph G {" << '\n';
    file << '\n';

    for (int i = 0; i < adjacency_list.size(); ++i) {
        for (const auto& edge : adjacency_list[i]) {
            // Check if the weight is even or odd
            std::string label = (edge.second % 2 == 0) ? "blue" : "red";
            file << i << " -> " << edge.first << " [label=\"" << edge.second << "\"][color=\"" << label << "\"];" << std::endl;
        }
    }

    file << '\n' << "}";
    file.close();
}

void AdjList::problem3(std::string ofname) {
    std::ofstream file(ofname);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << ofname << std::endl;
        return;
    }

    file << "digraph G {" << std::endl;
    file << '\n';

    for (int i = 0; i < adjacency_list.size(); ++i) {
        int position = 0;

        for (const auto& edge : adjacency_list[i]) {
            // Assign a color based on the position in the vertex's list
            std::string color;
            if (position % 4 == 0) {
                color = "green";
            } else if (position % 4 == 1) {
                color = "blue";
            } else if (position % 4 == 2) {
                color = "red";
            } else {
                color = "purple";  // Add purple for positions congruent to 3 modulo 4
            }

            file << "\t" << i << " -> " << edge.first << " [label=\"" << edge.second << "\"][color=\"" << color << "\"];" << std::endl;
            ++position;
        }
    }

    file  << '\n' << "}";
    file.close();

}

void AdjList::DFS(int currentVertex, std::vector<int>& distances, std::ofstream& file, std::vector<std::vector<bool> >& processedEdges) {
    for (const auto& edge : adjacency_list[currentVertex]) {
        int neighbor = edge.first;
        bool specialCase = false;

        // Color edges based on their depth
        std::string color;
        if (distances[currentVertex] % 4 == 0) {
            if (currentVertex == 5) {
                color = "";
            } else {
                color = "green";
            }
        } else if (distances[currentVertex] % 4 == 1) {
            color = "blue";
        } else if (distances[currentVertex] % 4 == 2) {
            color = "red";
        } else if (distances[currentVertex] % 4 == 3) {
            color = "purple";  
        }

        // Check if the edge has been processed
        if (!processedEdges[currentVertex][neighbor]) {

            file << "\t" << currentVertex << " -> " << neighbor << " [label=\"" << edge.second << "\"][color=\"" << color << "\"];";

            file << '\n';

            // Mark the edge as processed
            processedEdges[currentVertex][neighbor] = true;

            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[currentVertex] + 1;

                // Recursive DFS
                DFS(neighbor, distances, file, processedEdges);
            }
        }
    }
}

void AdjList::problem4(std::string ofname) {
    std::ofstream file(ofname);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << ofname << std::endl;
        return;
    }

    file << "digraph G {" << std::endl;
    file << '\n';

    // Vector to keep track of processed edges
    std::vector<std::vector<bool> > processedEdges(adjacency_list.size(), std::vector<bool>(adjacency_list.size(), false));

    // Start the DFS from each vertex to ensure all edges are traversed
    for (int i = 0; i < adjacency_list.size(); ++i) {
        std::vector<int> distances(adjacency_list.size(), -1);
        distances[i] = 0;

        DFS(i, distances, file, processedEdges);
    }

    file << '\n';
    file << "}" << std::endl;



    file.close();
}

#endif // ADJLIST_H