//header
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
//middle code
// You are using GCC

struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;
    struct Node* temp = queue->front;
    int val = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return val;
}

void rev(struct Queue* queue) {
    if (queue->front == NULL)
        return;
    int data = dequeue(queue);
    rev(queue);
    enqueue(queue, data);
}

void printQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//footer
int main() {
    int N;
    scanf("%d", &N);
    struct Queue* q = createQueue();
    for (int i = 0; i < N; i++) {
        int element;
        scanf("%d", &element);
        enqueue(q, element);
    }
    rev(q);
    printQueue(q);

    return 0;
}
