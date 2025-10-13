/*
 * Priority Queue with Priority and Deadline Scheduling
 * 
 * This program implements a task scheduling system using a priority queue that considers
 * both priority level and deadline. Tasks with higher priority are scheduled first, and
 * for tasks with equal priority, earlier deadlines take precedence. The implementation
 * uses a linked list with sorted insertion to maintain proper ordering. Input consists
 * of number of tasks followed by priority, deadline, and task name for each task.
 * Output displays executed tasks in the correct scheduling order.
 */

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int priority;
    int deadline;
    string name;
    Node* next;
};

class LinkedList {
public:
    Node* head = nullptr;

    void push(int prio, int dead, string name) {
        Node* newNode = new Node();
        newNode->priority = prio;
        newNode->deadline = dead;
        newNode->name = name;
        newNode->next = nullptr;

        // Case 1: empty list
        if (!head) {
            head = newNode;
            return;
        }

        // Case 2: insert at head (higher priority OR same priority & earlier deadline)
        if (prio > head->priority || 
            (prio == head->priority && dead < head->deadline)) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Case 3: find insertion point
        Node* curr = head;
        while (curr->next &&
               (curr->next->priority > prio ||
                (curr->next->priority == prio && curr->next->deadline <= dead))) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void printList() {
        cout << "Executed Tasks:" << endl;
        Node* temp = head;
        while (temp) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList q;
    for (int i = 0; i < n; i++) {
        int prio, dead;
        string name;
        cin >> prio >> dead >> name;
        q.push(prio, dead, name);
    }
    q.printList();
    return 0;
}
