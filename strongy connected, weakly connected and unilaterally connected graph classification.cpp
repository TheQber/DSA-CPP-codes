/*
 * Graph Connectivity Classification (Strongly, Weakly, Unilaterally Connected)
 * 
 * This program classifies directed graphs into different connectivity categories using
 * Floyd-Warshall algorithm and DFS. It determines if a graph is strongly connected
 * (path exists between all pairs), unilaterally connected (path exists between all
 * pairs in at least one direction), or weakly connected (connected when ignoring
 * edge directions). Input consists of graph size followed by adjacency matrix.
 * Output displays the connectivity classification of the graph.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    vector<vector<int>> reach(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            reach[i][j] = graph[i][j];
        }

    // Floyd-Warshall to compute reachability
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = 1;

    // Check strongly connected
    bool strongly = true;
    for (int i = 0; i < N && strongly; i++)
        for (int j = 0; j < N; j++)
            if (!reach[i][j]) {
                strongly = false;
                break;
            }

    if (strongly) {
        cout << "Strongly Connected";
        return 0;
    }

    // Check unilaterally connected
    bool unilateral = true;
    for (int i = 0; i < N && unilateral; i++)
        for (int j = 0; j < N; j++)
            if (i != j && !reach[i][j] && !reach[j][i]) {
                unilateral = false;
                break;
            }

    if (unilateral) {
        cout << "Unilaterally Connected";
        return 0;
    }

    // Check weakly connected
    vector<vector<int>> undirected(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (graph[i][j] || graph[j][i])
                undirected[i][j] = undirected[j][i] = 1;

    vector<int> visited(N, 0);
    vector<int> stack;
    stack.push_back(0);
    visited[0] = 1;
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        for (int v = 0; v < N; v++)
            if (undirected[u][v] && !visited[v]) {
                visited[v] = 1;
                stack.push_back(v);
            }
    }

    bool weakly = true;
    for (int i = 0; i < N; i++)
        if (!visited[i]) weakly = false;

    if (weakly)
        cout << "Weakly Connected";
    else
        cout << "Disconnected"; // just in case
}
