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