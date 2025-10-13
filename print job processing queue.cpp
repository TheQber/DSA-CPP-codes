/*
 * Print Job Processing Queue
 * 
 * This program simulates a print job processing system using a queue data structure.
 * It manages print jobs with different page counts and processes them in FIFO order.
 * The system supports enqueuing print jobs, dequeuing for processing, and displaying
 * the current queue status. Input consists of menu options (1-3) followed by page counts
 * for enqueue operations. Output shows job processing status and queue contents.
 */

// You are using GCC
//header
#include <iostream>
using namespace std;

struct Node {
    int pages;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void initializeQueue() {
    front = rear = NULL;
}

//middle code
bool isEmpty() {
    return front == NULL;
}

bool enqueue(int pages) {
    Node* newNode = new Node();
    newNode->pages = pages;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Print job with " << pages << " pages is enqueued." << endl;
    return true;
}

bool dequeue(int &pages) {
    if (isEmpty()) {
        return false;
    }
    Node* temp = front;
    pages = front->pages;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
    return true;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Print jobs in the queue: ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->pages << " pages ";
        temp = temp->next;
    }
    cout << endl;
}

//footer
int main() {
    int option, pages;
    initializeQueue();

    while (cin >> option) {
        switch (option) {
            case 1:
                cin >> pages;
                enqueue(pages);
                break;
            case 2:
                if (dequeue(pages))
                    cout << "Processing print job: " << pages << " pages" << endl;
                else
                    cout << "Queue is empty." << endl;
                break;
            case 3:
                display();
                break;
            default:
                cout << "Invalid option." << endl;
                return 0;
        }
    }
    return 0;
}
