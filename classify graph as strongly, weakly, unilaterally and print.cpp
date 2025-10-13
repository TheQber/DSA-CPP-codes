/*
 * Strongly Connected Components (SCC) Finder Using Kosaraju's Algorithm
 * 
 * This program finds all strongly connected components in a directed graph using
 * Kosaraju's algorithm. The algorithm performs two DFS traversals: first on the
 * original graph to fill a stack, then on the transposed graph to identify SCCs.
 * Components are sorted by their smallest element for consistent output. Input consists
 * of number of vertices, number of edges, and edge connections. Output displays
 * all strongly connected components with nodes in each component.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<vector<int>> rev;
vector<bool> visited;
stack<int> st;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);
    st.push(u);
}

void dfs2(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u+1); // 1-indexed output
    for (int v : rev[u])
        if (!visited[v])
            dfs2(v, component);
}

int main() {
    cin >> V >> E;
    adj.resize(V);
    rev.resize(V);
    visited.resize(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-index
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    // Step 1: DFS on original graph to fill stack
    fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    // Step 2: DFS on transposed graph to find SCCs
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, component);
            sort(component.begin(), component.end());
            sccs.push_back(component);
        }
    }

    // Step 3: Sort SCCs based on smallest element in each
    sort(sccs.begin(), sccs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    cout << "Strongly Connected Components are:" << endl;
    for (auto& comp : sccs) {
        for (int node : comp)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
