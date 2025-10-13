/*
 * BST with Insert and Delete Nodes (Level-based Display)
 * 
 * This program implements a Binary Search Tree with insertion and deletion operations,
 * displaying the tree using a level-based matrix representation. It maintains level
 * information for each node and uses a matrix array to store nodes by their levels.
 * The tree is displayed level by level after each operation. Input consists of tree
 * size, elements to insert, and values for insertion and deletion operations.
 * Output shows the BST state after initial population, insertion, and deletion.
 */

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int level;
};

class matrixArray {
public:
    int arr[100][100] = {0};
    int maxLevel = 0;
    void push(int value, int level) {
        if (level > maxLevel)
            maxLevel = level;
        for (int i = 0; i < 100; i++) {
            if (arr[level][i] == 0) {
                arr[level][i] = value;
                return;
            }
        }
    }
    void print() {
        for (int i = 0; i < maxLevel + 1; i++) {
            for (int j = 0; j < 100; j++) {
                if (arr[i][j] == 0)
                    break;
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
};

class Tree {
public:
    Node* root = nullptr;
    matrixArray m;

    Node* populate(Node* root, int val, int level = 0) {
        if (!root) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->level = level;
            return newNode;
        }
        if (val < root->data)
            root->left = populate(root->left, val, level + 1);
        else if (val > root->data)
            root->right = populate(root->right, val, level + 1);
        return root;
    }

    void populate(int val) {
        root = populate(root, val, 0);
    }

    void callWhenDone() {
        m = matrixArray(); // reset the matrix before re-traversal
        sendToArray(root);
    }

    void sendToArray(Node* top) {
        if (!top)
            return;
        m.push(top->data, top->level);
        sendToArray(top->left);
        sendToArray(top->right);
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right)
                return nullptr;
            else if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void deleteKey(int val) {
        root = deleteNode(root, val);
    }
};

int main() {
    int size, val;
    cin >> size;
    Tree t;

    for (int i = 0; i < size; i++) {
        cin >> val;
        t.populate(val);
    }

    // Build and print initial BST
    t.callWhenDone();
    cout << "Initial BST: ";
    t.m.print();

    int insertVal, deleteVal;
    cin >> insertVal >> deleteVal;

    // Insert new node
    t.populate(insertVal);
    t.callWhenDone();
    cout << "BST after inserting a new node " << insertVal << ": ";
    t.m.print();

    // Delete node
    t.deleteKey(deleteVal);
    t.callWhenDone();
    cout << "BST after deleting node " << deleteVal << ": ";
    t.m.print();

    return 0;
}
