#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);  // Exit the program if stack underflow occurs
    }
    return s->items[(s->top)--];
}

// Queue structure using two stacks
typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value) {
    push(&q->stack1, value);
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            int temp = pop(&q->stack1);
            push(&q->stack2, temp);
        }
    }

    // If stack2 is still empty, then the queue is empty
    if (isEmpty(&q->stack2)) {
        printf("Queue Underflow\n");
        exit(1);  // Exit the program if queue underflow occurs
    }

    // Pop the element from stack2 (which is the front of the queue)
    int dequeued = pop(&q->stack2);
    printf("Dequeued: %d\n", dequeued);
    return dequeued;
}

// Function to display the queue elements
void displayQueue(Queue *q) {
    if (isEmpty(&q->stack1) && isEmpty(&q->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    // Display elements in stack2
    printf("Queue: ");
    for (int i = q->stack2.top; i >= 0; i--) {
        printf("%d ", q->stack2.items[i]);
    }

    // Display elements in stack1 in reverse order
    for (int i = 0; i <= q->stack1.top; i++) {
        printf("%d ", q->stack1.items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    do {
        printf("\nQueue Operations:\n");
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

