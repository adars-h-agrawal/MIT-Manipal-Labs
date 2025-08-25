#include <stdio.h>
#include <stdlib.h>

// Creating a Linked List
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n) {
    if (n <= 0) return NULL;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter data for node %d: ", n);
    scanf("%d", &newNode->data);
    newNode->next = createList(n - 1);

    return newNode;
}

// Traversing a Linked List
void traverseList(Node *head) {
    if (head == NULL) return;

    printf("%d ", head->data);
    traverseList(head->next);
}

// Merging Two Sorted Linked Lists
Node* mergeLists(Node *X, Node *Y) {
    if (X == NULL) return Y;
    if (Y == NULL) return X;

    Node *result = NULL;

    if (X->data <= Y->data) {
        result = X;
        result->next = mergeLists(X->next, Y);
    } else {
        result = Y;
        result->next = mergeLists(X, Y->next);
    }

    return result;
}

// Merging Two Lists Alternately
Node* mergeAlternately(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *result = list1;
    Node *temp1, *temp2;

    while (list1 != NULL && list2 != NULL) {
        temp1 = list1->next;
        temp2 = list2->next;

        list1->next = list2;
        list2->next = temp1;

        list1 = temp1;
        list2 = temp2;
    }

    if (list2 != NULL) {
        // Append the remaining elements of list2
        if (list1 != NULL) {
            list1->next = list2;
        } else {
            result = list2;
        }
    }

    return result;
}

// Stack Implementation
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

StackNode* push(StackNode *top, int data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

StackNode* pop(StackNode *top, int *data) {
    if (top == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    StackNode *temp = top;
    *data = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Queue Implementation
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

QueueNode* enqueue(QueueNode *rear, QueueNode **front, int data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
    } else {
        rear->next = newNode;
    }

    return newNode;
}

QueueNode* dequeue(QueueNode **front, int *data) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return NULL;
    }
    QueueNode *temp = *front;
    *data = temp->data;
    *front = (*front)->next;
    free(temp);
    return *front;
}

// Main Program
int main() {
    int choice, n, data;
    Node *head = NULL, *mergedList = NULL;
    StackNode *stackTop = NULL;
    QueueNode *queueFront = NULL, *queueRear = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Create and Traverse Linked List\n");
        printf("2. Merge Two Sorted Linked Lists\n");
        printf("3. Merge Two Lists Alternately\n");
        printf("4. Stack Operations\n");
        printf("5. Queue Operations\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createList(n);
                printf("Linked List: ");
                traverseList(head);
                printf("\n");
                break;

            case 2:
                // Create two sorted lists and merge them
                printf("Create first sorted list:\n");
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                Node *X = createList(n);

                printf("Create second sorted list:\n");
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                Node *Y = createList(n);

                mergedList = mergeLists(X, Y);
                printf("Merged List: ");
                traverseList(mergedList);
                printf("\n");
                break;

            case 3:
                // Create two lists and merge alternately
                printf("Create first list:\n");
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                Node *list1 = createList(n);

                printf("Create second list:\n");
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                Node *list2 = createList(n);

                mergedList = mergeAlternately(list1, list2);
                printf("Merged Alternately List: ");
                traverseList(mergedList);
                printf("\n");
                break;

            case 4:
                // Stack operations
                do {
                    printf("\nStack Operations:\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to push: ");
                            scanf("%d", &data);
                            stackTop = push(stackTop, data);
                            break;

                        case 2:
                            stackTop = pop(stackTop, &data);
                            if (stackTop != NULL) {
                                printf("Popped data: %d\n", data);
                            }
                            break;
                    }
                } while (choice != 3);
                break;

            case 5:
                // Queue operations
                do {
                    printf("\nQueue Operations:\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter data to enqueue: ");
                            scanf("%d", &data);
                            queueRear = enqueue(queueRear, &queueFront, data);
                            break;

                        case 2:
                            queueFront = dequeue(&queueFront, &data);
                            if (queueFront != NULL) {
                                printf("Dequeued data: %d\n", data);
                            }
                            break;
                    }
                } while (choice != 3);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

