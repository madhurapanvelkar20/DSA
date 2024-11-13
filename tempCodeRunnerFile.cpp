#include <iostream>
#include <vector>
using namespace std;

// Graph class to represent a graph using adjacency matrix
class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adjMatrix;  // 2D vector for adjacency matrix

public:
    // Constructor to initialize graph with V vertices
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));  // Initialize matrix with all 0s
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;  // Add edge from v to w
        adjMatrix[w][v] = 1;  // Since it's an undirected graph, add edge from w to v as well
    }

    // Function to print the adjacency matrix of the graph
    void printAdjacencyMatrix() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    g.printAdjacencyMatrix();

    return 0;
}
