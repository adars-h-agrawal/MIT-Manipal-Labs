#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Function prototypes
Node* createList(int n);
void displayList(Node *head);
Node* insertEnd(Node *head, int data);
Node* unionLists(Node *list1, Node *list2);
Node* intersectionLists(Node *list1, Node *list2);
void freeList(Node *head);

// Main function
int main() {
    int n, data;
    Node *list1 = NULL, *list2 = NULL, *result = NULL;

    printf("Create first doubly linked list:\n");
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    list1 = createList(n);

    printf("Create second doubly linked list:\n");
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    list2 = createList(n);

    // Display lists
    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Union
    result = unionLists(list1, list2);
    printf("Union: ");
    displayList(result);
    freeList(result);

    // Intersection
    result = intersectionLists(list1, list2);
    printf("Intersection: ");
    displayList(result);
    freeList(result);

    // Free memory
    freeList(list1);
    freeList(list2);

    return 0;
}

// Create a doubly linked list
Node* createList(int n) {
    Node *head = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertEnd(head, data);
    }
    return head;
}

// Insert node at the end of the list
Node* insertEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display the doubly linked list
void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Union of two doubly linked lists
Node* unionLists(Node *list1, Node *list2) {
    Node *result = NULL;
    Node *temp;

    // Add elements from list1
    temp = list1;
    while (temp != NULL) {
        result = insertEnd(result, temp->data);
        temp = temp->next;
    }

    // Add elements from list2 if not present in result
    temp = list2;
    while (temp != NULL) {
        Node *check = result;
        int found = 0;
        while (check != NULL) {
            if (check->data == temp->data) {
                found = 1;
                break;
            }
            check = check->next;
        }
        if (!found) {
            result = insertEnd(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Intersection of two doubly linked lists
Node* intersectionLists(Node *list1, Node *list2) {
    Node *result = NULL;
    Node *temp1 = list1;
    Node *temp2;

    while (temp1 != NULL) {
        temp2 = list2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                Node *check = result;
                int found = 0;
                while (check != NULL) {
                    if (check->data == temp1->data) {
                        found = 1;
                        break;
                    }
                    check = check->next;
                }
                if (!found) {
                    result = insertEnd(result, temp1->data);
                }
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

// Free the memory of the doubly linked list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
