/*
 * Maximum Flow in Graph Using Ford-Fulkerson Algorithm (Edmonds-Karp Implementation)
 * 
 * This program finds the maximum flow between a source and sink node in a directed graph
 * using the Ford-Fulkerson algorithm with Edmonds-Karp implementation. It uses BFS to find
 * augmenting paths and updates residual capacities to compute the maximum flow. The algorithm
 * repeatedly finds paths from source to sink and augments flow along these paths until no
 * more augmenting paths exist. Input consists of number of vertices, adjacency matrix
 * representing edge capacities, source node, and sink node. Output displays the maximum flow.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// BFS to find augmenting path and store parent
bool bfs(const vector<vector<long long>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t)
                    return true;
            }
        }
    }

    return false;
}

// Ford-Fulkerson (Edmonds–Karp implementation)
long long fordFulkerson(vector<vector<long long>> graph, int s, int t) {
    int V = graph.size();
    vector<vector<long long>> rGraph = graph; // Residual graph
    vector<int> parent(V);
    long long max_flow = 0;

    // Augment flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent)) {
        long long path_flow = LLONG_MAX;

        // Find minimum residual capacity along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V;
    cin >> V;

    vector<vector<long long>> graph(V, vector<long long>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int s, t;
    cin >> s >> t;

    cout << "Maximum Flow: " << fordFulkerson(graph, s, t) << endl;

    return 0;
}
