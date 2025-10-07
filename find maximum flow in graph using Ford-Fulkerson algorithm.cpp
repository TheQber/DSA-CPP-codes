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
