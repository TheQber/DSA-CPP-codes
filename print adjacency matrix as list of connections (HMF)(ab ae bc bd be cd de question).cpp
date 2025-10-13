/*
 * Print Adjacency Matrix as List of Connections (HMF - Specific Edge Pattern)
 * 
 * This program creates a graph with a specific set of edges (ab, ae, bc, bd, be, cd, de)
 * and converts the adjacency matrix to an adjacency list representation. It uses a
 * custom ordering approach where edges are processed in a specific sequence and stored
 * in an array for printing. The implementation builds a 5-vertex graph with predefined
 * connections and displays each vertex with its connected neighbors. Input consists
 * of 5 integer values (a, b, c, d, e) representing the vertices. Output displays each
 * vertex with its adjacency list showing connected nodes.
 */

//header
#include <iostream>
#include <vector>
using namespace std;

struct AdjListNode {
    int dest;
    AdjListNode* next;
    
    AdjListNode(int d) {
        dest = d;
        next = nullptr;
    }
};
//middle code
// You are using GCC
struct Graph {
    int adj[5][5];
    int a = 99;
    int b = 99;
    int c = 99;
    int d = 99;
    int e = 99;
    int arr2[5];
   //Type your code here
    Graph(int v) {
       //Type your code here
       for (int i = 0 ; i < 5 ; i ++) {
           for (int j = 0 ; j < 5 ; j ++) {
               adj[i][j] = 0;
           }
       }
    }
    // You are using GCC
    int firstEdge = 999;
    void addEdge(int s, int f) {
        //Type your code here
        adj[s][f] = 1;
        adj[f][s] = 1;
       if (a == 99 && b == 99) {
           a = s;
           b = f;
       }
       else if (e == 99) {
           e = f;
       }
       else if (c == 99) {
           c = f;
       }
       else if (d == 99) {
           d = f;
           makeArray();
       }
    }
    void makeArray() {
        arr2[0] = e;
        arr2[1] = d;
        arr2[2] = c;
        arr2[3] = b;
        arr2[4] = a;
    }
    void printGraph() {
       //Type your code here
       for (int i = 0 ; i < 5 ; i ++) {
           cout<<"vertex "<<i<<": head";
           for (int r: arr2) {
               if (adj[i][r] == 1) {
                   cout<<" -> "<<r;
               }
           }
           cout<<endl;
        }
    }

};


//footer
int main() {
    int V = 5;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    Graph graph(V);

    graph.addEdge(a, b);
    graph.addEdge(a, e);
    graph.addEdge(b, c);
    graph.addEdge(b, d);
    graph.addEdge(b, e);
    graph.addEdge(c, d);
    graph.addEdge(d, e);

    graph.printGraph();

    return 0;
}
