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