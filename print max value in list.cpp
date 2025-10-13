/*
 * Find and Print Maximum Value in Linked List
 * 
 * This program finds the maximum value in a linked list during the insertion process.
 * It maintains a running maximum value that gets updated whenever a larger value is
 * inserted. The implementation tracks the maximum during insertion to avoid a separate
 * traversal. Input consists of list size followed by the integer values to insert.
 * Output displays the maximum value found in the linked list.
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
    int max = 0;
    void push(int val) {
        if (max<val) {
            max = val;
        }
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
    void returnMax() {
        cout<<max;
    }
};
int main() {
    int size;
    cin>>size;
    LinkedList l;
    int val;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        l.push(val);
    }
    l.returnMax();
}
