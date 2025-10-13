/*
 * Find Number of Connected Networks/Components (Graphs - Daily Challenge)
 * 
 * This program finds the number of connected components in an undirected graph using
 * DFS (Depth-First Search). It builds an adjacency list representation and performs
 * DFS from each unvisited node to identify all connected components. The algorithm
 * marks visited nodes and explores all reachable nodes from each starting point.
 * Input consists of number of vertices followed by edge pairs until -1 -1.
 * Output displays each connected component as a separate line of vertices.
 */

#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj, visited);
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> adj(V);
    int u, v;

    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    vector<bool> visited(V, false);

    cout << "Following are connected components:\n";
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            cout << endl;
        }
    }

    return 0;
}
