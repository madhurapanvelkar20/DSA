#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;  
    vector<int>* adj;  

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);  
        adj[w].push_back(v);  
    }

    void deleteNode(int node) {
        if (node >= V || node < 0) {
            cout << "Invalid node!" << endl;
            return;
        }

        for (int i = 0; i < V; ++i) {
            adj[i].erase(remove(adj[i].begin(), adj[i].end(), node), adj[i].end());
        }

        --V;

        vector<int>* newAdj = new vector<int>[V];

        for (int i = 0, j = 0; i < V + 1; ++i) {
            if (i == node) continue;  
            newAdj[j++] = adj[i];
        }

        delete[] adj;
        adj = newAdj;

        cout << "Node " << node << " deleted successfully." << endl;
    }

    void printAdjacencyList() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " -> ";
            for (auto x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adj;
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

    cout << "Graph before deleting a node:" << endl;
    g.printAdjacencyList();

    g.deleteNode(2);

    cout << "\nGraph after deleting node 2:" << endl;
    g.printAdjacencyList();

    return 0;
}

