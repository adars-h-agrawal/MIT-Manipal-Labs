#include <stdio.h>
#include <stdlib.h>

// Define a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create an initial list
void createInitialList() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));

    node1->data = 10;
    node1->prev = NULL;
    node1->next = node2;

    node2->data = 20;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 30;
    node3->prev = node2;
    node3->next = NULL;

    head = node1;
}

// Function to insert an element at the rear end of the list
void insertAtRear(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete an element from the rear end of the list
void deleteFromRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

// Function to insert an element at a given position of the list
void insertAtPosition(int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete an element from a given position of the list
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    if (position == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to insert an element after another element
void insertAfter(int newValue, int existingValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != existingValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", existingValue);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newValue;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to insert an element before another element
void insertBefore(int newValue, int existingValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != existingValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", existingValue);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newValue;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
}

// Function to traverse the list
void traverse() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverse() {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

int main() {
    int choice, value, position, existingValue;

    createInitialList();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at the rear end of the list\n");
        printf("2. Delete an element from the rear end of the list\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element from a given position\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                insertAtRear(value);
                break;

            case 2:
                deleteFromRear();
                printf("Deleted element from rear end.\n");
                break;

            case 3:
                printf("Enter the element to insert and the position: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;

            case 4:
                printf("Enter the position of the element to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;

            case 5:
                printf("Enter the new element and the existing element: ");
                scanf("%d %d", &value, &existingValue);
                insertAfter(value, existingValue);
                break;

            case 6:
                printf("Enter the new element and the existing element: ");
                scanf("%d %d", &value, &existingValue);
                insertBefore(value, existingValue);
                break;

            case 7:
                printf("Current list: ");
                traverse();
                break;

            case 8:
                reverse();
                printf("List reversed.\n");
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
