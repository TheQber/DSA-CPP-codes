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
