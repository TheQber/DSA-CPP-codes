/*
 * BST with Multiple Traversal Methods
 * 
 * This program provides a complete Binary Search Tree implementation with menu-driven operations.
 * It supports BST creation, and three types of tree traversals: inorder (left-root-right),
 * preorder (root-left-right), and postorder (left-right-root). The program uses a menu system
 * where users can create a BST with specified number of nodes, and then perform any of the
 * three traversals. Input consists of menu choices and integer values for BST construction.
 * Each traversal displays the tree elements in the respective order.
 */

//header
#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct tnode
{
    int data;
    tnode *right;
    tnode *left;
};

tnode *CreateBST(tnode *, int);
void Inorder(tnode *);
void Preorder(tnode *);
// void Postorder(tnode *);
//middle codee
// You are using GCC
tnode *CreateBST(tnode *root, int item)
{
    // write your code here
    tnode* newNode = new tnode();
    newNode->data = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr)
        return newNode;

    if (item < root->data)
        root->left = CreateBST(root->left, item);
    else
        root->right = CreateBST(root->right, item);

    return root;
}

void Inorder(tnode *root)
{
    // write your code here
    if (root == nullptr)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(tnode *root)
{
   // write your code here
    if (root == nullptr)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(tnode *root)
{
    // write your code here
    if (root == nullptr)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//footer
int main()
{
    tnode *root = nullptr;
    int choice, item, n, i;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = nullptr;
            cin >> n;
            for (i = 1; i <= n; i++)
            {
                cin >> item;
                root = CreateBST(root, item);
            }
            cout << "BST with " << n << " nodes is ready to use" << endl;
            break;
        case 2:
            cout << "BST Traversal in INORDER" << endl;
            Inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "BST Traversal in PREORDER" << endl;
            Preorder(root);
            cout << endl;
            break;
        case 4:
            cout << "BST Traversal in POSTORDER" << endl;
            Postorder(root);
            cout << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    } while (1);
    return 0;
}