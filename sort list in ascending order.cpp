/*
 * Sort Linked List in Ascending Order Using Insertion Sort
 * 
 * This program sorts a linked list in ascending order using an insertion sort approach.
 * It maintains the list in sorted order during insertion by finding the correct position
 * for each new element. The algorithm compares each new element with existing elements
 * and inserts it in the appropriate position to maintain ascending order. Input consists
 * of list size followed by the integer values to insert. Output displays the sorted list.
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
    Node* head = NULL;
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!head) {
            newNode->next = NULL;
            head = newNode;
            //printList();
            return;
        }
        Node* temp1 = head;
        Node* temp2 = temp1;
        if (temp1->data>newNode->data) {
            newNode->next = temp1;
            head = newNode;
            //printList();
            return;
        }
        while ((temp1->data)<(newNode->data)) {
            if (temp1->next) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            else {
                newNode->next = NULL;
                temp1->next = newNode;
                //printList();    
                return;
            }
        }
        newNode->next = temp2->next;
        temp2->next = newNode;
        //printList();    
        return;
    }
    void printList() {
        Node* temp = head;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main() {
    int size;
    cin>>size;
    int val;
    LinkedList l;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        l.push(val);
    }
    l.printList();
}