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
    void pushToEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        if (!head) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = tail = newNode;
            length++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
        length++;
    }
    void deleteAtPos(int num) {
        int pos = num;
        int count = 1;
        if (pos == 1) {
            Node*temp = head->next;
            temp->prev = nullptr;
            delete head;
            head = temp;
            length--;
            return;
        }
        if (pos == length) {
            Node* temp = tail->prev;
            delete tail;
            temp->next = nullptr;
            tail = temp;
            length--;
            return;
        }
        Node* temp = head;
        while (temp) {
            if (count == pos) {
                Node* temp2 = temp->prev;
                temp2->next = temp->next;
                Node* temp3 = temp->next;
                temp3->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
            count++;
        }
    }
    void printList() {
        Node* temp = head;
        int count = 1;
        while (temp->next) {
            cout<<" node "<<count<<" : "<<temp->data<<endl;
            temp = temp->next;
            count++;
        }
        cout<<" node "<<count<<" : "<<temp->data;
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
        d.pushToEnd(val);
    }
    int pos;
    cin>>pos;
    cout<<"Data entered in the list:"<<endl;
    d.printList();
    d.deleteAtPos(pos);
    if (pos>size) {
        cout<<"Invalid position. Try again.";
        return 0;
    }
    cout<<endl<<" After deletion the new list:"<<endl;
    d.printList();
}