#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue structure
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX-1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert %d\n", value);
    } 
    else {
        q->items[++(q->rear)] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to dequeue an element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
    } 
    else {
        printf("Dequeued: %d\n", q->items[(q->front)++]);
        if (q->front > q->rear) {
            q->rear = -1;
            q->front = 0;  // Reset queue if it becomes empty
        }
    }
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } 
    else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
