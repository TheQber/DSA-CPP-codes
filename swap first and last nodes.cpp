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
    void SwapNodes() {
        Node* temp2 = head;
        while (temp2->next->next) {
            temp2 = temp2->next;
        }
        Node* temp3 = temp2->next;
        temp3->next = head->next;
        head->next = nullptr;
        temp2->next = head;
        head = temp3;
        
       
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
    cout<<"Before Swap: ";
    l.printList();
    cout<<endl;
    cout<<"After Swap: ";
    l.SwapNodes();
    l.printList();
    cout<<endl;
}
