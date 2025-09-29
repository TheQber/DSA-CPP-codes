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