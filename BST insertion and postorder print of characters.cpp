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
