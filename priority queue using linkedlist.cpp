/*
 * Priority Queue Implementation Using Linked List
 * 
 * This program implements a priority queue using a linked list where elements are
 * inserted in priority order (higher priority values are placed earlier in the list).
 * The implementation uses sorted insertion to maintain the priority ordering and
 * supports insertion with both data value and priority level. Input consists of
 * number of elements followed by value-priority pairs for each element.
 * Output displays all elements with their data and priority values in priority order.
 */

//You are using GCC
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    int priority;
    Node* next;
};
class LinkedList {
    public:
    Node* top = NULL;
    void push(int val, int p) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->priority = p;
        if (!top) {
            newNode->next = NULL;
            top = newNode;
            //printList();
            return;
        }
        Node* temp1 = top;
        Node* temp2 = temp1;
        if (temp1->priority>newNode->priority) {
            newNode->next = temp1;
            top = newNode;
            //printList();
            return;
        }
        while ((temp1->priority)<=(newNode->priority)) {
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
        Node* temp = top;
        while (temp) {
            cout<<"Data: "<<temp->data<<"\tPriority: "<<temp->priority<<endl;
            temp = temp->next;
        }
    }
};
int main() {
    int size;
    cin>>size;
    int val,prio;
    LinkedList l;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val>>prio;
        l.push(val,prio);
    }
    l.printList();
}