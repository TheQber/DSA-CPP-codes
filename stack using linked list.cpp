//header
#include <iostream>
using namespace std;

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;
//middle code
// You are using GCC
void push(char value) {
    //Type your code here
    Node* newNode = new Node();
    newNode->data = value;
    cout<<"Pushed element: ";
    if (!top) {
        newNode->next = nullptr;
        top = newNode;
        cout<<top->data<<endl;
        return;
    }
    newNode->next = top;
    top = newNode;
    cout<<top->data<<endl;
}

void pop() {
    //Type your code here
    if (!top) {
        cout<<"Stack is empty. Cannot pop."<<endl;
        return;
    }
    cout<<"Popped element: ";
    Node* temp = top;
    top = top->next;
    cout<<temp->data<<endl;
    delete temp;
    
}

void displayStack() {
    //Type your code here
    if (!top) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node* temp = top;
    cout<<"Stack elements (top to bottom): ";
    while (temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//footer
int main() {
    char choice;
    char value;
    while (true) {
        try {
            cin >> choice;
            if (choice == '1') {
                cin >> value;
                push(value);
            } else if (choice == '2') {
                pop();
            } else if (choice == '3') {
                displayStack();
            } else if (choice == '4') {
                cout << "Exiting program" << endl;
                break;
            } else {
                cout << "Invalid choice" << endl;
            }
        } catch (...) {
            cout << "Invalid input. Please enter a character choice." << endl;
        }
    }
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}