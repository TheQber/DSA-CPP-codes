/*
 * Binary Search Tree Population and Search
 * 
 * This program implements a Binary Search Tree (BST) with insertion and search functionality.
 * It creates a BST by inserting integer values and maintains the BST property where left child
 * is smaller and right child is larger than the parent. The search function traverses the tree
 * to find a target value and reports whether it exists in the tree. Input consists of array size,
 * followed by values to insert, and finally the target value to search. Output indicates whether
 * the target value is found or not found in the BST.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class Tree {
    public:
    Node* root = nullptr;
    void populate(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!root) {
            newNode->left = nullptr;
            newNode->right = nullptr;
            root = newNode;
            return;
        }
        Node* temp = root;
        bool PosNotFound = true;
        while (PosNotFound) {
            if (temp->data<newNode->data) {
                if (temp->right) {
                    temp = temp->right;
                }
                else {
                    temp->right = newNode;
                    PosNotFound = false;
                }
            }
            else if (temp->data>newNode->data) {
                if (temp->left) {
                    temp = temp->left;
                }
                else {
                    temp->left = newNode;
                    PosNotFound = false;
                }
            }
        }
    }
    void search(int val) {
        Node* temp = root;
        bool PosNotFound = true;
        while (PosNotFound) {
            if (temp->data<val) {
                if (temp->right) {
                    temp = temp->right;
                }
                else {
                    cout<<"Value "<<val<<" is not found in the tree.";
                    return;
                }
            }
            else if (temp->data>val) {
                if (temp->left) {
                    temp = temp->left;
                }
                else {
                    cout<<"Value "<<val<<" is not found in the tree.";
                    return;
                }
            }
            else if (temp->data == val) {
                cout<<"Value "<<val<<" is found in the tree.";
                return;
            }
        }
    }
};
int main() {
    int size,val;
    cin>>size;
    Tree t;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        t.populate(val);
    }
    int target;
    cin>>target;
    t.search(target);
}