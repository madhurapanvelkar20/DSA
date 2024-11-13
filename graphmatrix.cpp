#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adjMatrix; 

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));  
    }

    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1; 
        adjMatrix[w][v] = 1;  
    }

    void deleteNode(int node) {
        if (node >= V || node < 0) {
            cout << "Invalid node!" << endl;
            return;
        }

        for (int i = 0; i < V; ++i) {
            adjMatrix[i][node] = 0;  
            adjMatrix[node][i] = 0;  
        }

        adjMatrix.erase(adjMatrix.begin() + node);  
        for (int i = 0; i < V - 1; ++i) {
            adjMatrix[i].erase(adjMatrix[i].begin() + node); 
        }

        --V;

        cout << "Node " << node << " deleted successfully." << endl;
    }

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
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    cout << "Adjacency Matrix before deleting a node:" << endl;
    g.printAdjacencyMatrix();

    g.deleteNode(2);

    cout << "\nAdjacency Matrix after deleting node 2:" << endl;
    g.printAdjacencyMatrix();

    return 0;
}

