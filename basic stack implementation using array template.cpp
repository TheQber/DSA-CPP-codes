#include <iostream>
using namespace std;

#define MAX_SIZE 100

char items[MAX_SIZE];
int top = -1;

void initialize() {
    top = -1;
}
bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}
// You are using GCC
#include <bits/stdc++.h>
void push(char value) {
    //Type your code here
    if (top == -1) {
        items[0] = value;
        cout<<"Pushed: "<<value<<endl;
        top++;
        return;
    }
    items[top+1] = '0';
    for (int i = top+1 ; i > 0 ; i --) {
        swap(items[i],items[i-1]);
    }
    items[0] = value;
    cout<<"Pushed: "<<value<<endl;
    top++;
}

char pop() {
    //Type your code here
    if (top == -1) {
        cout<<"Stack is empty. Nothing to pop."<<endl;
        return 'a';
    }
    cout<<"Popped: "<<items[0]<<endl;
    items[0] = '0';
    for (int i = 0 ; i < top ; i ++) {
        swap(items[i],items[i+1]);
    }
    top--;
    return 'a';
}

void display() {
    //Type your code here
    if (top == -1) {
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<"Stack elements: ";
    for (int i = 0 ; i < top+1 ; i ++) {
        cout<<items[i]<<" ";
    }
    cout<<endl;
}
int main() {
    initialize();

    int choice;
    char value;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}