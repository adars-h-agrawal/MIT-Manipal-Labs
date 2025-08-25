#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create an initial list
void createInitialList() {
    Node* temp;

    // Creating initial list: 25 -> 20 -> 15 -> 10 -> 5
    head = (Node*)malloc(sizeof(Node));
    head->data = 25;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 15;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 10;
    head->next->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;
}

// Function to insert a node before a given node
void insertBefore(int newValue, int existingValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newValue;

    if (head == NULL) {
        printf("List is empty.\n");
        free(newNode);
        return;
    }

    if (head->data == existingValue) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != existingValue) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found.\n", existingValue);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(int newValue, int existingValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newValue;

    Node* temp = head;
    while (temp != NULL && temp->data != existingValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", existingValue);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a given node
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found.\n", value);
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
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
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Function to sort the list
void sort() {
    if (head == NULL || head->next == NULL) return;

    Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to delete every alternate node
void deleteEveryAlternateNode() {
    if (head == NULL) return;

    Node* temp = head;
    Node* nextNode;

    while (temp != NULL && temp->next != NULL) {
        nextNode = temp->next;
        temp->next = nextNode->next;
        free(nextNode);
        temp = temp->next;
    }
}

// Function to insert a node in a sorted list
void insertInSorted(int newValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newValue;

    if (head == NULL || head->data >= newValue) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < newValue) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    int choice, value, existingValue;

    createInitialList();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a given element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new element and the existing element: ");
                scanf("%d %d", &value, &existingValue);
                insertBefore(value, existingValue);
                break;

            case 2:
                printf("Enter the new element and the existing element: ");
                scanf("%d %d", &value, &existingValue);
                insertAfter(value, existingValue);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                printf("Current list: ");
                traverse();
                break;

            case 5:
                reverse();
                printf("List reversed.\n");
                break;

            case 6:
                sort();
                printf("List sorted.\n");
                break;

            case 7:
                deleteEveryAlternateNode();
                printf("Deleted every alternate node.\n");
                break;

            case 8:
                printf("Enter the new element to insert: ");
                scanf("%d", &value);
                insertInSorted(value);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}