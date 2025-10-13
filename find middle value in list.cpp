/*
 * Find Middle Value in Doubly Linked List
 * 
 * This program finds the middle element(s) in a doubly linked list. For even-length lists,
 * it displays both middle elements, and for odd-length lists, it displays the single middle
 * element. The implementation uses a doubly linked list with both head and tail pointers
 * for efficient traversal. Input consists of array size followed by integer values.
 * Output displays the list and then the middle value(s) based on the list length.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoubleList {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    void push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            length++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }
    void printList() {
        Node* temp = head;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void findMiddleValue() {
        int count = 1;
        Node* temp = head;
        while (temp) {
            if (count == length/2) {
                if (length%2 == 0) {
                    cout<<temp->data<<" "<<temp->next->data;
                }
                else {
                    cout<<temp->next->data;
                }
            }
            temp = temp->next;
            count++;
        }
    }
};
int main() {
    int size,val;
    cin>>size;
    DoubleList d;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        d.push(val);
    }
    d.printList();
    d.findMiddleValue();
}