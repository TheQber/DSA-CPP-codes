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
