// You are using GCC
//header
#include <iostream>
using namespace std;
//middle code
// Initialize all cells to 0
void initializeGraph(bool** adjMatrix, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Add an undirected edge between i and j
void addEdge(bool** adjMatrix, int i, int j) {
    adjMatrix[i-1][j-1] = 1;
    adjMatrix[j-1][i-1] = 1;
}

// Remove an edge between i and j (set cells to 0)
void removeEdge(bool** adjMatrix, int i, int j) {
    adjMatrix[i-1][j-1] = 0;
    adjMatrix[j-1][i-1] = 0;
}

// Print the adjacency matrix
void printGraph(bool** adjMatrix, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
//footer
int main() {
    int V;
    cin >> V;
    bool** adjMatrix = new bool*[V];
    for (int i = 0; i < V; i++) {
        adjMatrix[i] = new bool[V];
    }

    initializeGraph(adjMatrix, V);

    int edge;
    cin >> edge;
    int x, y;
    for (int i = 0; i < edge; i++) {
        cin >> x >> y;
        addEdge(adjMatrix, x, y);
    }

    printGraph(adjMatrix, V);

    for (int i = 0; i < V; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
