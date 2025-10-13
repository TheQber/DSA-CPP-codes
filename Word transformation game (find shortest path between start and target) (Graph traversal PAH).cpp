/*
 * Shortest Path Finder Using BFS (Word Transformation Game)
 * 
 * This program finds the shortest path between two nodes in a directed graph using
 * BFS (Breadth-First Search) algorithm. It's designed for word transformation games
 * where each node represents a word and edges represent valid transformations.
 * The algorithm uses a queue to explore nodes level by level and returns the minimum
 * distance to the target. Input consists of number of nodes, edges, edge connections,
 * start node, and target node. Output displays the shortest path distance or -1 if
 * no path exists.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int nodes,edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes); 
    int u,v;// assuming nodes <= 1000
    for (int i = 0 ; i < edges ; i ++) {
        cin>>u>>v;
        adj[u].push_back(v); // directed edge
    }
    int start, target;
    cin>>start>>target;
    vector<bool> visited(nodes, false);
    queue<pair<int,int>> q; // pair<node, distance>
    q.push({start, 0});
    visited[start] = true;

    int answer = -1;

    while(!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == target) {
            answer = dist;
            break;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }

    cout << answer << endl;
    return 0;
}
