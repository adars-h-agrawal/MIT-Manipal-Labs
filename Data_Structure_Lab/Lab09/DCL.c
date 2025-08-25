#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    struct Node* toDelete = NULL;

    do {
        if (temp->data == data) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != *head);

    if (toDelete) {
        if (toDelete->next == toDelete) {
            *head = NULL;
        } else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            if (*head == toDelete) {
                *head = toDelete->next;
            }
        }
        free(toDelete);
    }
}

void display(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert Element\n2. Delete Element\n3. Display List\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                display(head);
                break;
        }
    } while (choice != 4);
   
    return 0;
}
