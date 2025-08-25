#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to append a node to the end of a list
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to print a doubly linked list
void printList(Node* node) {
    Node* last;
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

// Function to concatenate two doubly linked lists
void concatenate(Node** list1_ref, Node** list2_ref) {
    Node* list1 = *list1_ref;
    Node* list2 = *list2_ref;

    if (list1 == NULL) {
        *list1_ref = list2;
        return;
    }

    Node* last = list1;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = list2;
    if (list2 != NULL) {
        list2->prev = last;
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Create first list: 1->2->3
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    // Create second list: 4->5->6
    append(&list2, 4);
    append(&list2, 5);
    append(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    concatenate(&list1, &list2);

    printf("Concatenated List: ");
    printList(list1);

    return 0;
}
