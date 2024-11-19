#include <stdlib.h>
#include <stdio.h>

typedef struct NodeStruct {
    int data;
    struct NodeStruct *next;
} Node;

typedef struct StructQueue {
    Node *front;
    Node *back;
    int size;
} *Queue;

Queue createQueue() {
    Queue newQueue = malloc(sizeof(struct StructQueue));
    if (newQueue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newQueue->front = NULL;
    newQueue->back = NULL;
    newQueue->size = 0;
    return newQueue;
}

void enQueue(Queue q, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->size != 0) {
        q->back->next = newNode;
    } else {
        q->front = newNode;
    }
    q->back = newNode;
    q->size++;
}

int deQueue(Queue q) {
    if (q->size == 0) {
        fprintf(stderr, "Queue is empty\n");
        return -1; // Indicate error
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->size == 0) {
        q->back = NULL; // Reset back if queue is empty
    }
    return data;
}

int main() {
    Queue queue = createQueue();

    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);

    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue)); // Test empty queue

    free(queue); // Free the queue structure
    return 0;
}
