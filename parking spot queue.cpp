/*
 * Parking Lot Management System
 * 
 * This program simulates a parking lot management system using a queue data structure.
 * It manages parking spots (numbered 0-9) and assigns cars to the first available spot
 * when parking, and retrieves cars in FIFO order when leaving. The system tracks which
 * spots are free/occupied using a boolean array. Input consists of command numbers (1-3)
 * where 1 parks a car, 2 retrieves a car, and 3 exits. Output shows parking/retrieval
 * confirmations with spot numbers and handles full/empty lot scenarios.
 */

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    int spotNo;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    bool isFree[10];

    LinkedList() {
        head = nullptr;
        for (int i = 0; i < 10; i++) isFree[i] = true;
    }

    void push() {
        int val;
        cin >> val;

        // find first available spot
        int spot = -1;
        for (int i = 0; i < 10; i++) {
            if (isFree[i]) {
                spot = i;
                break;
            }
        }

        if (spot == -1) {
            cout << "Parking lot is full." << endl;
            return;
        }

        // create and insert new node
        Node* newNode = new Node();
        newNode->data = val;
        newNode->spotNo = spot;
        newNode->next = nullptr;
        isFree[spot] = false;

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }

        cout << "Car " << val << " parked in spot " << spot << "." << endl;
    }

    void pop() {
        if (!head) {
            cout << "Parking lot is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        cout << "Car " << temp->data << " retrieved from spot " << temp->spotNo << "." << endl;
        isFree[temp->spotNo] = true;

        delete temp;
    }
};

int main() {
    int command;
    LinkedList l;

    while (true) {
        if (!(cin >> command)) break;

        if (command == 1) {
            l.push();
        } else if (command == 2) {
            l.pop();
        } else if (command == 3) {
            return 0;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}
