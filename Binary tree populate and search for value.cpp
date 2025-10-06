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