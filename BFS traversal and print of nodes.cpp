/*
 * BFS Traversal and Print of Nodes
 * 
 * This program performs BFS (Breadth-First Search) traversal on a directed graph
 * starting from a specified node. It uses a custom Queue implementation with linked
 * list nodes and an adjacency list representation for the graph. The algorithm
 * explores all reachable nodes level by level and stores the traversal order.
 * Input consists of number of nodes, number of edges, edge connections, and starting node.
 * Output displays the BFS traversal order of all reachable nodes.
 */

// You are using GCC
#include <iostream>
#include <vector>
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
class FindPath {
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
    }
};
int main() {
    int nodes;
    int edges;
    cin>>nodes>>edges;
    FindPath f;
    f.initVector(nodes);
    int from,to;
    for (int i = 0 ; i < edges ; i ++) {
        cin>>from>>to;
        f.addConnection(from,to);
    }
    //f.printVector();
    int startingNode;
    cin>>startingNode;
    f.startBFS(startingNode);
    f.printResult();
}