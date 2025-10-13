/*
 * BST Populate and Inorder Print with Delete Values (Header, Middle Code, Footer)
 * 
 * This program implements a complete Binary Search Tree (BST) with insertion, deletion,
 * and inorder traversal operations. It uses a structured approach with header, middle code,
 * and footer sections. The deletion algorithm handles three cases: leaf nodes, nodes with
 * one child, and nodes with two children. Input consists of array size, array elements
 * to insert, and a value to delete. Output displays the BST before and after deletion
 * using inorder traversal.
 */

//header
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};

//middle code
// You are using GCC
void inorder(Node* root)
{
   // write your code here
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* getMinimumKey(Node* curr)
{
   // write your code here
    while (curr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

Node* insert(Node* root, int key)
{
    // write your code here
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
 
void searchKey(Node* &curr, int key, Node* &parent)
{
    // write your code here
    while (curr != nullptr && curr->data != key)
    {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void deleteNode(Node*& root, int key)
{
    // write your code here
    Node* parent = nullptr;
    Node* curr = root;
    searchKey(curr, key, parent);

    // key not found
    if (curr == nullptr)
        return;

    // Case 1: node has no children
    if (curr->left == nullptr && curr->right == nullptr)
    {
        if (curr != root)
        {
            if (parent->left == curr) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else
            root = nullptr;
        delete curr;
    }

    // Case 2: node has two children
    else if (curr->left && curr->right)
    {
        Node* successor = getMinimumKey(curr->right);
        int val = successor->data;
        deleteNode(root, successor->data);
        curr->data = val;
    }

    // Case 3: node has one child
    else
    {
        Node* child = (curr->left) ? curr->left : curr->right;

        if (curr != root)
        {
            if (curr == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
        delete curr;
    }
}
//footer
int main()
{
    int size;
    cin>>size;
    int keys[size];
    
    for(int i=0;i<size;i++)
    {
        cin>>keys[i];
    }
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
    cout << "Before deletion: ";

    inorder(root);
    int delkey;
    cin>>delkey;
    deleteNode(root, delkey);
    cout<<"\nAfter deletion: ";

    inorder(root);
 
    return 0;
}