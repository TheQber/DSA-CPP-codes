// You are using GCC
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(int v, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[v] = true;
    for (int u : adj[v])
        if (!visited[u])
            dfs1(u, adj, visited, st);
    st.push(v);
}

void dfs2(int v, vector<int> rev[], vector<bool>& visited) {
    visited[v] = true;
    for (int u : rev[v])
        if (!visited[u])
            dfs2(u, rev, visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], rev[n+1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vector<bool> visited(n+1, false);
    stack<int> st;

    // Step 1: Topo sort order
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i, adj, visited, st);

    // Step 2: Find SCCs using reversed graph
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;
    vector<int> sccId(n+1, 0);

    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!visited[v]) {
            sccCount++;
            stack<int> temp;
            temp.push(v);
            visited[v] = true;
            sccId[v] = sccCount;
            while (!temp.empty()) {
                int node = temp.top(); temp.pop();
                for (int u : rev[node]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        sccId[u] = sccCount;
                        temp.push(u);
                    }
                }
            }
        }
    }

    if (sccCount == 1) {
        cout << 0;
        return 0;
    }

    vector<int> in(sccCount+1, 0), out(sccCount+1, 0);

    // Step 3: Build condensed graph and count in/out degree
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (sccId[u] != sccId[v]) {
                out[sccId[u]]++;
                in[sccId[v]]++;
            }
        }
    }

    int sources = 0, sinks = 0;
    for (int i = 1; i <= sccCount; i++) {
        if (in[i] == 0) sources++;
        if (out[i] == 0) sinks++;
    }

    cout << max(sources, sinks);
    return 0;
}
