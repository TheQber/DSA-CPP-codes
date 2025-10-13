/*
 * Level Order Population and Inorder Traversal
 * 
 * This program builds a binary tree using level order (breadth-first) insertion and then
 * performs inorder traversal. It uses a custom queue implementation to manage node insertion
 * in level order fashion. The tree is populated by reading positive integers until a non-positive
 * value is encountered. After building the tree, it performs inorder traversal (left-root-right)
 * to display the tree contents in sorted order.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Queue {
    public:
    Node* arr[200];
    int front = -1;
    int tail = -1;
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return front == 199;
    }
    void push(Node* val) {
        if (isEmpty()) {
            front = tail = 0;
            arr[front] = val;
            return;
        }
        arr[++tail] = val;
        
        return;
    }
    void pop() {
        front++;
    }
    Node* top() {
        return arr[front];
    }
};
void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    int val;
    cin>>val;
    if (val<= 0) {
        return 0;
    }
    Queue q;
    Node* root = new Node(val);
    q.push(root);
    while (cin>>val && val>0) {
        Node* newNode = new Node(val);
        if (!(q.top()->left)) {
            q.top()->left = newNode;
            q.push(newNode);
        }
        else if (!(q.top()->right)) {
            q.top()->right = newNode;
            q.push(newNode);
            q.pop();
        }
        else {
            q.pop();
        }
    }
    inorder(root);
}