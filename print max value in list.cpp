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
    int max = 0;
    void push(int val) {
        if (max<val) {
            max = val;
        }
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
    void returnMax() {
        cout<<max;
    }
};
int main() {
    int size;
    cin>>size;
    LinkedList l;
    int val;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        l.push(val);
    }
    l.returnMax();
}
