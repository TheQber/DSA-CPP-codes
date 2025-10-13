/*
 * Binary Tree Construction and Postorder Traversal
 * 
 * This program constructs a binary tree from preorder input and performs postorder traversal.
 * The tree is built recursively where -1 represents NULL nodes, allowing construction of
 * any binary tree structure. After building the tree, it performs postorder traversal
 * (left-right-root) and calculates the sum of all node values. Input consists of preorder
 * sequence with -1 for NULL nodes. Output shows postorder traversal and total sum of nodes.
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
void postorder(Node* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int val;
int sum;
Node* buildTree() {
    cin>>val;
    if (val == -1) {
        return nullptr;
    }
    Node* root = new Node(val);
    sum+=val;
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
int main() {
    int val;
    Node* root = buildTree();
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Sum of all nodes: "<<sum;
}