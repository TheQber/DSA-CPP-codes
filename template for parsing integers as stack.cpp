// You are using GCC
// You are using GCC
#include <iostream>
using namespace std;

#define MAX_TEXT_LENGTH 100

char textStack[MAX_TEXT_LENGTH];
int stackTop = -1;

void initialize() {
    stackTop = -1;
}
// You are using GCC
int top = stackTop;
int items[MAX_TEXT_LENGTH];
string AddingCharacter = "Pushed element: ";
string RemovingCharacter = "Popped element: ";
string EmptyListWhilePop = "Stack is empty. Cannot pop.";
string DisplayCharacter = "Stack elements (top to bottom): ";
string EmptyListWhileDisplay = "Stack is empty";
bool isFull() {
    //Type your code here
    if (top == MAX_TEXT_LENGTH - 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    //Type your code here
    if (top == -1) {
        return true;
    }
    return false;
}

#include <bits/stdc++.h>
void pushCharacter(int value) {
    //Type your code here
    if (top == -1) {
        items[0] = value;
        cout<<AddingCharacter<<value<<endl;
        top++;
        return;
    }
    items[top+1] = 0;
    for (int i = top+1 ; i > 0 ; i --) {
        swap(items[i],items[i-1]);
    }
    items[0] = value;
    cout<<AddingCharacter<<value<<endl;
    top++;
}

void popCharacter() {
    //Type your code here
    if (top == -1) {
        cout<<EmptyListWhilePop<<endl;
        return;
    }
    cout<<RemovingCharacter<<items[0]<<endl;
    items[0] = 0;
    for (int i = 0 ; i < top ; i ++) {
        swap(items[i],items[i+1]);
    }
    top--;
    return;
}

void view() {
    //Type your code here
    if (top == -1) {
        cout<<EmptyListWhileDisplay<<endl;
        return;
    }
    cout<<DisplayCharacter;
    for (int i = 0 ; i < top+1 ; i ++) {
        cout<<items[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int choice;
    int input;
    initialize();
    while (true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                pushCharacter(input);
                break;
            case 2:
                popCharacter();
                break;
            case 3:
                view();
                break;
            case 4:
            cout<<"Exiting program";
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}