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
