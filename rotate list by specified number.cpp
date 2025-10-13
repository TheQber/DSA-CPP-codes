/*
 * Rotate Circular Linked List by Specified Number
 * 
 * This program rotates a circular linked list by a specified number of positions.
 * It creates a circular linked list from input values and then rotates it by moving
 * the head pointer to a new position based on the rotation count. The rotation is
 * calculated as (size - rotation_value) to achieve the desired effect. Input consists
 * of list size, followed by list elements, and finally the number of rotations.
 * Output displays the rotated circular list.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class CircularList {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    void push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    void printList() {
        Node* temp = head;
        while (temp->next != head) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
    }
    void letsRunItBack(int size,int val) {
        int rotations = size-val;
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (count == rotations) {
                head = temp;
                return;
            }
            temp = temp->next;
            count++;
        }
    }
};
int main() {
    int size,val;
    cin>>size;
    CircularList c;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        c.push(val);
    }
    int rotations;
    cin>>rotations;
    c.letsRunItBack(size,rotations);
    c.printList();
}
