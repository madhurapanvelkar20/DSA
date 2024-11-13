#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adjMatrix; 

public:
    Graph(int V); 
    void addEdge(int u, int v, int weight); 
    void primMST(); 
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0)); 
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    vector<int> parent(V, -1); 
    vector<int> key(V, INT_MAX); 
    vector<bool> inMST(V, false); 
    int totalWeight = 0; 

    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true; 
        totalWeight += minKey; 

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
    }

    cout << "\nTotal weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}
