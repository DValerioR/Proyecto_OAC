#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 1000 // Tamaño máximo de la cola

typedef struct {
    int data[MAX_QUEUE_SIZE]; // Arreglo fijo para almacenar los elementos
    int front;                // Índice del frente de la cola
    int back;                 // Índice del final de la cola
    int size;                 // Cantidad de elementos en la cola
} Queue;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->back = -1;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

bool isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

// Función para insertar un elemento en la cola
void enQueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Error: La cola está llena\n");
        return;
    }
    q->back = (q->back + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->data[q->back] = value;
    q->size++;
}

// Función para eliminar un elemento de la cola
int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: La cola está vacía\n");
        return -1; // Indica error
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->size--;
    return value;
}

// Función principal para probar la implementación
int main() {
    Queue queue;
    initializeQueue(&queue);

    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);

    printf("Dequeued: %d\n", deQueue(&queue));
    printf("Dequeued: %d\n", deQueue(&queue));
    printf("Dequeued: %d\n", deQueue(&queue));
    printf("Dequeued: %d\n", deQueue(&queue)); // Prueba con cola vacía

    return 0;
}
