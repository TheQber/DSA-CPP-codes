/*
 * Shelf Management Using Stack Operations
 * 
 * This program implements a shelf management system using stack operations where items
 * are pushed onto the top of the shelf and popped from the top (LIFO principle).
 * It provides push, pop, and display operations for managing items on the shelf.
 * The implementation uses an array-based stack with global variables. Input consists
 * of menu choices and item values for push operations. Output shows item placement
 * and removal confirmations along with current shelf contents.
 */

// You are using GCC
#include <bits/stdc++.h>
int shelf[100];
void push(int value) {
    //Type your code here
    if (top == -1) {
        shelf[0] = value;
        cout<<"Item "<<value<<" is pushed onto the shelf"<<endl;
        top++;
        return;
    }
    shelf[top+1] = 0;
    for (int i = top+1 ; i > 0 ; i --) {
        swap(shelf[i],shelf[i-1]);
    }shelf[0] = value;
    cout<<"Item "<<value<<" is pushed onto the shelf"<<endl;
    top++;
}

void pop() {
    //Type your code here
    if (top == -1) {
        cout<<"No items in the shelf"<<endl;
        return;
    }
    cout<<"Item "<<shelf[0]<<" is popped from the shelf"<<endl;
    shelf[0] = 0;
    for (int i = 0 ; i < top ; i ++) {
        swap(shelf[i],shelf[i+1]);
    }
    top--;
    return;
}

void displayStack() {
    //Type your code here
    if (top == -1) {
        cout<<"Shelf is empty"<<endl;
        return;
    }
    cout<<"Items in the shelf: ";
    for (int i = 0 ; i < top+1 ; i ++) {
        cout<<shelf[i]<<" ";
    }
    cout<<endl;
}