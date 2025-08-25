#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;       // Value of the element
    int priority;   // Priority of the element
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element into the priority queue
void enqueue(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);

    // Special case: Insert at the head if it has higher priority
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the correct position for insertion
    Node* temp = *head;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to remove the element with the highest priority
void dequeue(Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued element: %d with priority: %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the priority queue
void display(Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Priority Queue:\n");
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    Node* pq = NULL; // Initialize an empty priority queue

    enqueue(&pq, 10, 2); // Insert element 10 with priority 2
    enqueue(&pq, 20, 1); // Insert element 20 with priority 1
    enqueue(&pq, 30, 3); // Insert element 30 with priority 3

    printf("After enqueue operations:\n");
    display(pq);

    dequeue(&pq); // Remove the element with the highest priority
    printf("\nAfter dequeue operation:\n");
    display(pq);

    return 0;
}
