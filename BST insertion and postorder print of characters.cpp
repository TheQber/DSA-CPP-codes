/*
 * BST Insertion and Postorder Traversal for Characters
 * 
 * This program creates a Binary Search Tree from character input and performs postorder traversal.
 * Characters are inserted into the BST maintaining the BST property (left < root < right).
 * Postorder traversal visits left subtree, right subtree, then root. Input consists of number
 * of characters followed by the character values. Output displays the postorder traversal result
 * with characters separated by spaces.
 */

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into BST
Node* insert(Node* root, char val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Postorder traversal
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        root = insert(root, ch);
    }
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}
