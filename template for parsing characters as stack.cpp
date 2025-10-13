/*
 * Character Stack Template for Section Management
 * 
 * This program implements a character-based stack for managing sections (likely course sections)
 * with push, pop, and view operations. It uses an array-based stack implementation with
 * custom messages for adding/removing sections. The stack follows LIFO principle where
 * characters represent section identifiers. Input consists of menu choices (1-4) followed
 * by character values for push operations. Output shows section management operations
 * with descriptive messages.
 */

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
char items[MAX_TEXT_LENGTH];
string AddingCharacter = "Adding Section: ";
string RemovingCharacter = "Removing Section: ";
string EmptyListWhilePop = "Stack is empty. Cannot pop.";
string DisplayCharacter = "Enrolled Sections: ";
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
void pushCharacter(char value) {
    //Type your code here
    if (top == -1) {
        items[0] = value;
        cout<<AddingCharacter<<value<<endl;
        top++;
        return;
    }
    items[top+1] = '0';
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
    items[0] = '0';
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
    char input;
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