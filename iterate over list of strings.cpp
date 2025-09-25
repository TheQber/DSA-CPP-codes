// You are using GCC
#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* next;
};
class LinkedList {
    public:
    Node* head = nullptr;
    int length = 0;
    void pushVal(string val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
            length++;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }
    void printList() {
        if (length == 0) {
            cout<<"No applications to iterate.";
            return;
        }
        Node* temp = head;
        cout<<"Running Applications:"<<endl;
        while (temp) {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};
int main() {
    string val;
    LinkedList l;
    while (true) {
        getline(cin,val);
        if (val == "exit") {
            break;
        }
        l.pushVal(val);
    }
    cout<<"Circular Linked List - Running Applications"<<endl<<endl;
    l.printList();
    cout<<endl;
}