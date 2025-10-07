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