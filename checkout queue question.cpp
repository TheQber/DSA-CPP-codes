/*
 * Checkout Queue Implementation
 * 
 * This program simulates a checkout queue system using a circular queue implementation with array.
 * It manages customer IDs with operations: enqueue (add customer to queue), dequeue (process customer),
 * and display (show waiting customers). The queue has a maximum capacity of 5 customers.
 * Input consists of menu options (1-4) followed by customer IDs for enqueue operations.
 * The system prevents overflow and handles empty queue conditions gracefully.
 */

// You are using GCC
//header
#include <iostream>
#define MAX_SIZE 5
using namespace std;

int ticketIDs[MAX_SIZE];
int front = -1;
int rear = -1;

void initializeQueue() {
    front = -1;
    rear = -1;
}
//middle code
// You are using GCC
bool isEmpty() {
    //Type your code here
    return front == -1;
}
#include <bits/stdc++.h>
bool isFull() {
    //Type your code here
    return rear == MAX_SIZE-1;
}

bool enqueue(int ticketID) {
    //Type your code here
    if (isFull()) {
        cout<<"Checkout queue is full."<<endl;
        return false;
    }
    if (isEmpty()) {
        front++;
    }
    ticketIDs[++rear] = ticketID;
    cout<<"Customer ID "<<ticketID<<" joined the checkout queue."<<endl;
    return true;
}

bool dequeue(int &ticketID) {
    //Type your code here
    if (isEmpty()) {
        //cout<<"Queue is empty."<<endl;
        return false;
    }
    //cout<<"Dequeued Helpdesk Ticket ID: "<<ticketIDs[front]<<endl;
    ticketID = ticketIDs[front];
    ticketIDs[front] = NULL;
    for (int i = 0 ; i < rear ; i ++) {
        swap(ticketIDs[i],ticketIDs[i+1]);
    }
    rear--;
    if (rear == -1) {
        front = -1;
    }
    return true;
}

void display() {
    //Type your code here
    if (isEmpty()) {
        cout<<"Checkout queue is empty."<<endl;
        return;
    }
    cout<<"Customers waiting in the checkout queue: ";
    for (int i = 0 ; i <= rear ; i ++) {
        cout<<ticketIDs[i]<<" ";
    }
    cout<<endl;
}
//footer
int main() {
    int ticketID;
    int option;
    initializeQueue();
    while (true) {
        try {
            cin >> option;
        } catch (...) {
            break;
        }
        switch (option) {
            case 1:
                try {
                    cin >> ticketID;
                } catch (...) {
                    break;
                }
                if (enqueue(ticketID)) {
                    
                }
                break;
            case 2:
                if (dequeue(ticketID)) {
                    cout << "Processed Customer ID: " << ticketID << endl;
                } else {
                    cout << "Checkout queue is empty." << endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting Program" << endl;
                return 0;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
    return 0;
}
