#include <stdio.h>
#include <stdlib.h>

// Typedef for Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Circular connection
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to delete a node from the circular linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;

    // If head is the node to be deleted
    if (temp->data == key) {
        // Find the last node to maintain the circular nature
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
        } else {
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        return;
    }

    prev = *head;
    temp = (*head)->next;

    // Search for the node to be deleted
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If node with key found
    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
}

// Main function
int main() {
    Node* head = NULL;  // Single pointer for the head node
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
