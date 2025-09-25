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
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!head) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = tail = newNode;
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
    cout<<"List in original order:"<<endl;
    d.printFromBeg();
    cout<<"List in reverse order:"<<endl;
    d.printFromEnd();
}