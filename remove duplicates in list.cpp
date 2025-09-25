// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class LinkedList {
    public:
    Node* head = nullptr;
    int length = 0;
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!head) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
            length++;
            return;
        }
        
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = nullptr;
        head = newNode;
        length++;
    }
    void removeDuplicates() {
        Node* temp = head;
        int count = 1;
        if (!temp->next) {
            cout<<"List has only one element"<<endl;
            return;
        }
        Node* temp2;
        while (temp->next) {
            temp2 = temp->next;
            while (temp2) {
                if (temp2->data==temp->data) {
                    if (temp2->next) {
                        temp2->prev->next = temp2->next;
                        temp2->next->prev = temp2->prev;
                        length--;
                        //cout<<"Removed "<<temp2->data<<endl;
                    }
                    else {
                        temp2->prev->next = nullptr;
                        //cout<<"Removed "<<temp2->data<<endl;
                    }
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
            count++;
            if (count == length) {
                printList();
            }
            //cout<<"Going to next value"<<endl;
        }
        printList();
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
    int size,val;
    cin>>size;
    LinkedList l;
    for (int i =  0 ; i < size ; i ++) {
        cin>>val;
        l.push(val);
    }
    l.removeDuplicates();
    l.printList();
}

