/*
 * Find Postorder Predecessor in Binary Tree
 * 
 * This program finds the postorder predecessor of a given node in a binary tree.
 * It constructs a binary tree from preorder input (with -1 for NULL nodes) and
 * maintains parent pointers to track node relationships. The algorithm searches
 * for the target node and determines its postorder predecessor based on tree structure.
 * Input consists of preorder traversal with -1 for NULL nodes, followed by the target value.
 * Output displays the postorder predecessor or indicates if the node is not found.
 */

// You are using GCC
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};
int val;
Node* previouss = nullptr;
Node* buildTree() {
    cin>>val;
    if (val == -1) {
        return nullptr;
    }
    Node* root = new Node(val);
    root->parent = previouss;
    previouss = root;
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
Node* previous = nullptr;
bool found = false;
void findPredec(Node* root, int val2) {
    if (!root || found) {
        return;
    }
    if (root->data == val2) {
        if (previous == nullptr) {
            cout<<"Postorder predecessor of "<<val2<<" is NULL"<<endl;
            
            found = true;
            return;
        }
        cout<<"Postorder predecessor of "<<val2<<" is "<<root->parent->data<<endl;
        found = true;
        return;
    }
    previous = root;
    findPredec(root->left, val2);
    findPredec(root->right, val2);
}
int main() {
    int val2;
    Node* root = buildTree();
    cin>>val2;
    findPredec(root, val2);
    if (!found) {
        cout<<"Node with the given key not found in the tree."<<endl;
    }    
    //cout<<"Postorder predecessor of  nodes: "<<sum;
}