/*
 * Priority Queue Implementation with Heap-based Operations
 * 
 * This program implements a priority queue using a max-heap data structure where elements
 * with higher priority values are dequeued first. It provides enqueue and dequeue operations
 * with heapify up and heapify down functions to maintain heap properties. The implementation
 * uses an array-based heap with Element structures containing data and priority fields.
 * Input consists of data-priority pairs followed by 'y'/'Y' to continue or any other character to stop.
 * Output displays dequeued elements in priority order (highest first).
 */

//header
#include <iostream>

struct Element {
    int data;
    int priority;
};
//middle code
struct PriorityQueue {
    Element arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

    void swap(Element &a, Element &b) {
        Element temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index].priority > arr[parent].priority) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left].priority > arr[largest].priority)
            largest = left;
        if (right < size && arr[right].priority > arr[largest].priority)
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

    void enqueue(int data, int priority) {
        if (size >= 100) return; // max size reached
        arr[size].data = data;
        arr[size].priority = priority;
        heapifyUp(size);
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int topData = arr[0].data;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return topData;
    }

    bool isEmpty() {
        return size == 0;
    }
};
//footer
int main() {
    PriorityQueue queue;
    int data, priority;
    char choice;
    
    do {
        std::cin >> data >> priority;
        queue.enqueue(data, priority);
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    while (!queue.isEmpty()) {
        std::cout << "Dequeued element with data: " << queue.dequeue() << '\n';
    }
    
    return 0;
}