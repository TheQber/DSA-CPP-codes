/*
 * Find Minimum Value in Stack
 * 
 * This program implements a stack with functionality to find the minimum element
 * at any given time. It uses an array-based stack implementation with push, pop,
 * and findMinimum operations. The findMinimum function searches through all elements
 * in the stack to determine the smallest value. Input consists of number of elements
 * followed by the values to push onto the stack. Output shows the minimum element
 * before and after popping an element.
 */

//header
#include <iostream>
#include <climits>
using namespace std;

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}
//middle code
#include <bits/stdc++.h>
int items[20];
void push(int value) {
    //Type your code here
    if (top == -1) {
        items[0] = value;
        //cout<<"Pushed: "<<value<<endl;
        top++;
        return;
    }
    items[top+1] = 0;
    for (int i = top+1 ; i > 0 ; i --) {
        swap(items[i],items[i-1]);
    }
    items[0] = value;
    //cout<<"Pushed: "<<value<<endl;
    top++;
}

int pop() {
    //Type your code here
    if (top == -1) {
        cout<<"Stack is empty. Nothing to pop."<<endl;
        return -1;
    }
    //cout<<"Popped element: "<<items[0]<<endl;
    int g = items[0];
    items[0] = 0;
    for (int i = 0 ; i < top ; i ++) {
        swap(items[i],items[i+1]);
    }
    top--;
    return g;
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
int findMinimum() {
    int min = items[0];
    for (int i = 0 ; i < top ; i ++) {
        if (items[i]<min) {
            min = items[i];
        }
    }
    return min;
}
//footer
int main() {
    int n, value;
    cin >> n;
  
    for (int i = 0; i < n; i++) {
        cin >> value;
        push(value);
    }

    cout << "Minimum element in the stack: " << findMinimum() << endl;

    int popped = pop();
    if (popped != INT_MIN) {
        cout << "Popped element: " << popped << endl;
    }

    cout << "Minimum element in the stack after popping: " << findMinimum() << endl;

    return 0;
}