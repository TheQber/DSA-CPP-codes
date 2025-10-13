/*
 * Print Adjacency Matrix as List of Connections (Header, Middle Code, Footer)
 * 
 * This program converts an adjacency matrix to an adjacency list representation for
 * an undirected graph. It reads edges and builds an adjacency matrix, then displays
 * each vertex with its connected neighbors in list format. The implementation uses
 * a 2D array for the adjacency matrix and shows connections with arrow notation.
 * Input consists of number of vertices, number of edges, and edge connections.
 * Output displays each vertex with its adjacency list showing connected nodes.
 */

//header
#include <iostream>

using namespace std;

#define MAX_V 100 

//middle code
// You are using GCC
void addEdge(int adj[MAX_V][MAX_V], int s, int d) {
    //Type your code here
    adj[s][d] = 1;
    adj[d][s] = 1;
}

void printGraph(int adj[MAX_V][MAX_V], int V) {
   //Type your code here
   for (int i = 0 ; i < V ; i ++) {
       cout<<"Vertex "<<i<<":";
       for (int j = 0 ; j < V ; j ++) {
           if (adj[i][j] == 1) {
               cout<<" "<<j<<" ->";
           }
       }
       cout<<endl;
   }
}



//footer
int main() {
    int V, edge, x, y;
    cin >> V;
    cin >> edge;

    int adj[MAX_V][MAX_V] = {0};  

    for (int i = 0; i < edge; i++) {
        cin >> x >> y;
        addEdge(adj, x, y);
    }

    printGraph(adj, V);

    return 0;
}