#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a linked list from user input
void create_list(struct node **head) {
    int data;
    struct node *new_node, *last = NULL;

    printf("Enter values to add to the list (enter -1 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        new_node = create_node(data);
        if (*head == NULL) {
            *head = new_node;
        } else {
            last->next = new_node;
        }
        last = new_node;
    }
}

// Function to insert a node after a specific element
void insertafter(struct node *head) {
    int data, element;
    struct node *temp = head, *newnode;

    printf("Enter the data to insert: ");
    scanf("%d", &data);
    printf("Enter the element to insert after: ");
    scanf("%d", &element);

    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", element);
        return;
    }

    newnode = create_node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to insert a node before a specific element
void insertbefore(struct node **head) {
    int data, element;
    struct node *temp = *head, *prev = NULL, *newnode;

    printf("Enter the data to insert: ");
    scanf("%d", &data);
    printf("Enter the element to insert before: ");
    scanf("%d", &element);

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", element);
        return;
    }

    newnode = create_node(data);
    if (prev == NULL) {
        newnode->next = *head;
        *head = newnode;
    } else {
        newnode->next = prev->next;
        prev->next = newnode;
    }
}

// Function to delete a node
void delete(struct node **head) {
    int element;
    struct node *temp = *head, *prev = NULL;

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the element to delete: ");
    scanf("%d", &element);

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", element);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to reverse the linked list
void reverse(struct node **head) {
    struct node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to traverse the list
void traverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list
void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
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
void deletealternate(struct node *head) {
    struct node *temp = head;

    while (temp != NULL && temp->next != NULL) {
        struct node *nextNode = temp->next->next;
        free(temp->next);
        temp->next = nextNode;
        temp = nextNode;
    }
}

// Function to insert a node in sorted order
void insertinsorted(struct node **head) {
    struct node *newnode, *i;
    int data;

    printf("Enter the data to insert: ");
    scanf("%d", &data);
    newnode = create_node(data);

    if (*head == NULL || data <= (*head)->data) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    i = *head;
    while (i->next != NULL && i->next->data < data) {
        i = i->next;
    }
    newnode->next = i->next;
    i->next = newnode;
}

// Function to free the linked list
void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    int choice;

    create_list(&head);

    while (1) {
        printf("\n1. Insert after\n2. Insert before\n3. Delete\n4. Reverse\n5. Traverse\n6. Sort\n7. Delete alternate\n8. Insert in sorted order\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertafter(head);
                break;
            case 2:
                insertbefore(&head);
                break;
            case 3:
                delete(&head);
                break;
            case 4:
                reverse(&head);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                deletealternate(head);
                break;
            case 8:
                insertinsorted(&head);
                break;
            case 9:
                printf("Exiting...\n");
                free_list(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
