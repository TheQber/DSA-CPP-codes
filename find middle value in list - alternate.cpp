#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};
// You are using GCC
int length = 0;
Node* findMiddleElement(Node* head) {
   //Type your code here
   Node* temp = head;
   while (temp) {
       length++;
       temp = temp->next;
       if (temp->next == head) {
           length++;
           break;
       }
   }
 
   temp = head;
   for (int i = 1 ; i < (length/2)+1 ; i ++) {
       temp = temp->next;
   }
   return temp;
}

void displayCircularLinkedList(Node* head) {
   //Type your code here
}

int main() {
    int n, val;

    cin >> n;

    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> val;

        Node* newNode = new Node();
        newNode->data = val;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            current = head;
        } else {
            newNode->next = head;
            current->next = newNode;
            current = newNode;
        }
    }

    Node* middleElement = findMiddleElement(head);

    cout << middleElement->data;

    return 0;
}
