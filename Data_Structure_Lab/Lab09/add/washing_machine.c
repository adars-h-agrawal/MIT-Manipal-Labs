#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    char name[50];
    int time;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(char* name, int time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->time = time;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node** header, char* name, int time) {
    Node* newNode = createNode(name, time);
    if (*header == NULL) {
        *header = newNode;
    } else {
        Node* last = (*header)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *header;
        (*header)->prev = newNode;
    }
}

void displayQueue(Node* header) {
    Node* temp = header;
    if (temp == NULL) return;
    printf("Current Queue:\n");
    do {
        printf("%s booked for %d minutes\n", temp->name, temp->time);
        temp = temp->next;
    } while (temp != header);
}

void processQueue(Node** header) {
    Node* current = *header;
    if (current == NULL) return;

    do {
        printf("\nWashing Machine available for %s for %d minutes.\n", current->name, current->time);
        current = current->next;
    } while (current != *header);
}

int main() {
    Node *queue = NULL;
    int choice, time;
    char name[50];

    while (1) {
        printf("\n1. Book Washing Machine\n2. Display Queue\n3. Process Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter booking time (in minutes): ");
            scanf("%d", &time);
            insertEnd(&queue, name, time);
            break;
        case 2:
            displayQueue(queue);
            break;
        case 3:
            processQueue(&queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
