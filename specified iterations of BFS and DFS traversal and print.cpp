/*
 * BFS and DFS Traversal with Specified Iterations
 * 
 * This program implements both BFS (Breadth-First Search) and DFS (Depth-First Search)
 * algorithms for graph traversal. It processes multiple graphs in iterations, where each
 * graph is represented as an adjacency list. The implementation includes custom Queue
 * class for BFS and recursive approach for DFS. Both algorithms start from the first
 * encountered node and traverse all connected components. Input consists of number of
 * iterations, followed by nodes, edges, and edge connections for each graph.
 * Output displays the traversal order for each graph using DFS algorithm.
 */

// You are using GCC
// You are using GCC
// You are using GCC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int top = -1;
    int bottom = -1;
    bool isEmpty() {
        return head == nullptr;
    }
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (!head) {
            head = tail = newNode;
            top = bottom = 0;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        bottom++;
    }
    void pop() {
        Node* temp = head;
        if (head->next) head = head->next;
        else {
            top = -1;
            head = nullptr;
        }
        delete temp;
        
    }
    int peek() {
        return head->data;
    }
};
class FindBFSPath {
    public:
    vector<vector<int>> arr;
    Queue BFSQueue;
    vector<bool> visited;
    Queue ResultQueue;
    int sizes;
    void initVector(int size) {
        sizes = size;
        arr.resize(size);
        visited.resize(size);
        fixBoolArray();
    }
    void fixBoolArray() {
        for (int i = 0 ; i < visited.size() ; i ++) {
            visited[i] = false;
        }
    }
    void sortArray() {
        for (int i = 0 ; i < arr.size() ; i ++) {
            sort(arr[i].begin(),arr[i].end());
        }
    }
    void addConnection(int from, int to) {
        arr[from].push_back(to);
    }
    void printVector() {
        for (int i = 0 ; i < sizes ; i ++) {
            for (int j = 0 ; j < arr[i].size() ; j ++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void startBFS(int val) {
        BFSQueue.push(val);
        visited[val] = true;
        while(!BFSQueue.isEmpty()) {
            int check = BFSQueue.peek();
            BFSQueue.pop();
            ResultQueue.push(check);
            for (int i = 0 ; i < arr[check].size() ; i ++) {
                if (!visited[arr[check][i]]) {
                    visited[arr[check][i]] = true;
                    BFSQueue.push(arr[check][i]);
                }
            }
        }
        return;
    }
    void printResult() {
        Node* temp = ResultQueue.head;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
class FindDFSPath {
    public:
    vector<vector<int>> arr;
    vector<bool> visited;
    vector<int> result;
    int sizes;
    void initVector(int size) {
        sizes = size;
        arr.resize(size);
        visited.resize(size);
        fixBoolArray();
    }
    void fixBoolArray() {
        for (int i = 0 ; i < visited.size() ; i ++) {
            visited[i] = false;
        }
    }
    void sortArray() {
        for (int i = 0 ; i < arr.size() ; i ++) {
            sort(arr[i].begin(),arr[i].end());
        }
    }
    void addConnection(int from, int to) {
        arr[from].push_back(to);
    }
    void printVector() {
        for (int i = 0 ; i < sizes ; i ++) {
            for (int j = 0 ; j < arr[i].size() ; j ++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void startDFS(int val) {
        visited[val] = true;
        result.push_back(val);
        for (int connection: arr[val]) {
            if (!visited[connection]) {
                startDFS(connection);
            }
        }
    }
    void printResult() {
        for (int i = 0 ; i < result.size() ; i ++) {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    int iterations;
    cin>>iterations;
    FindDFSPath f[iterations];
    for (int j = 0 ; j < iterations ; j ++) {
        int nodes;
        int edges;
        cin>>nodes>>edges;
        f[j].initVector(nodes);
        int from,to;
        int startingNode = 9999;
        for (int i = 0 ; i < edges ; i ++) {
            cin>>from>>to;
            if (startingNode == 9999) {
                startingNode = from;
            }
            f[j].addConnection(from,to);
        }
        //f.printVector();
        f[j].sortArray();
        f[j].startDFS(startingNode);
        f[j].printResult();
    }
}