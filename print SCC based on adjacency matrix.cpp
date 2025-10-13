/*
 * Print Strongly Connected Components Based on Adjacency Matrix
 * 
 * This program finds and prints all strongly connected components (SCCs) in a directed
 * graph using Kosaraju's algorithm. It reads edge pairs to build both the original
 * graph and its transpose, then performs two DFS passes to identify SCCs. The algorithm
 * uses a stack to store finishing times and processes vertices in reverse order during
 * the second DFS. Input consists of number of edges followed by edge pairs (u, v).
 * Output displays each SCC as a line of vertices belonging to that component.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define MAX 100

vector<int> adj[MAX];
vector<int> rev[MAX];
bool visited[MAX];
stack<int> st;

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v])
        if (!visited[u])
            dfs1(u);
    st.push(v);
}

void dfs2(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : rev[v])
        if (!visited[u])
            dfs2(u);
}

int main() {
    int n;
    cin >> n;

    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    // ✅ vertices are numbered from 0 to n-1
    int V = n;  

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    memset(visited, false, sizeof(visited));

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            dfs2(v);
            cout << endl;
        }
    }

    return 0;
}
