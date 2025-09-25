//You are using GCC
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
    int length = 0;
    void pushToBeg(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = head;
            head = tail = newNode;
            cout<<"Node with data "<<val<<" inserted."<<endl;
            length++;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout<<"Node with data "<<val<<" inserted."<<endl;
        length++;
    }
    void printList() {
        Node* temp = new Node(9999);
        temp->next = head;
        do {
            temp = temp->next;
            cout<<temp->data<<" ";
        } while (temp!=tail);
        cout<<endl;
    }
    void deleteFirstNode() {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"Node at the beginning deleted."<<endl;
        length--;
    }
    void deleteLastNode() {
        Node* temp = head;
        while (temp->next!=tail) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        delete temp2;
        temp->next = head;
        tail = temp;
        cout<<"Node at the end deleted."<<endl;
        length--;
    }
    void deleteNode(int val) {
        Node* temp = head;
        do {
            if (val == tail->data) {
                deleteLastNode();
                return;
            }
            if (val == head->data) {
                deleteFirstNode();
                return;
            }
            if (val == temp->next->data) {
                Node* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                cout<<"Node with data "<<val<<" deleted."<<endl;
                length--;
                return;
            }
            temp = temp->next;
        } while (temp!=tail);
        cout<<"Node with data "<<val<<" not found."<<endl;
    }
    void searchNode(int val) {
        int count = 1;
        Node* temp = head;
        do {
            if (temp->data == val) {
                cout<<"Node with data "<<val<<" found at position "<<count<<"."<<endl;
                return;
            }
            temp = temp->next;
            count++;
        }while (temp!=tail);
        if (val == tail->data) {
            cout<<"Node with data "<<val<<" found at position "<<length<<"."<<endl;
            return;
        }
        cout<<"Node with data "<<val<<" not found."<<endl;
    }
};
int main() {
    int command, val;
    CircularList l;
    while (true) {
        cin>>command;
        if (command == 1) {
            cin>>val;
            l.pushToBeg(val);
        }
        else if (command == 2) {
            l.deleteFirstNode();
        }
        else if (command == 3) {
            l.deleteLastNode();
        }
        else if (command == 4) {
            cin>>val;
            l.deleteNode(val);
        }
        else if (command == 5) {
            cin>>val;
            l.searchNode(val);
        }
        else if (command == 6) {
            l.printList();
        }
        else if (command == 7) {
            break;
        }
        else {
            cout<<"Invalid choice. Please try again.";
        }
    }
}