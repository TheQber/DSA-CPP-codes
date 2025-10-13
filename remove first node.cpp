/*
 * Remove First Node from Linked List
 * 
 * This program demonstrates basic linked list operations including insertion at the end
 * and deletion of the first node. It creates a singly linked list from input values and
 * then removes the head node. The implementation uses a simple LinkedList class with
 * pushVal, removeFirstNode, and printList methods. Input consists of array size followed
 * by the integer values to insert. Output displays the list after removing the first element.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedList {
    public:
    Node* head = nullptr;
    void pushVal(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void removeFirstNode() {
        Node* temp = head->next;
        delete head;
        head = temp;
        
       
    }
    void printList() {
        Node* temp = head;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main() {
    int size,val;
    cin>>size;
    LinkedList l;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        l.pushVal(val);
    }
    l.removeFirstNode();
    l.printList();
}
