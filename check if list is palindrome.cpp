/*
 * Check if Doubly Linked List is Palindrome
 * 
 * This program checks whether a doubly linked list forms a palindrome by comparing
 * elements from both ends moving towards the center. It uses the bidirectional nature
 * of doubly linked lists to traverse from head and tail simultaneously. The algorithm
 * compares corresponding elements and determines if the list reads the same forwards
 * and backwards. Input consists of list size followed by integer values.
 * Output displays the list in both directions and indicates whether it's a palindrome.
 */

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoubleList {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!head) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = tail = newNode;
            length++;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = nullptr;
        temp->next = newNode;
        tail = newNode;
        length++;
    }
    void printFromBeg() {
        Node* temp = head;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void printFromEnd() {
        Node* temp = tail;
        while (temp) {
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    void checkIfPalindrome() {
        int checkLength = length/2;
        Node* temp1 = head;
        Node* temp2 = tail;
        for (int i = 0 ; i < checkLength ; i ++) {
            if (temp1->data != temp2->data) {
                cout<<"The doubly linked list is not a palindrome";
                return;
            }
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        cout<<"The doubly linked list is a palindrome";
    }
};
int main() {
    int size;
    cin>>size;
    DoubleList d;
    int val;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        d.push(val);
    }
    d.printFromBeg();
    d.printFromEnd();
    d.checkIfPalindrome();
}
