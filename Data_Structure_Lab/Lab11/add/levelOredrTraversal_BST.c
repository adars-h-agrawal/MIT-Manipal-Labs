#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node* data;
    struct Queue* next;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue functions for level order traversal
Queue* createQueue(Node* root) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = root;
    queue->next = NULL;
    return queue;
}

void enqueue(Queue** head, Node* root) {
    Queue* newQueue = createQueue(root);
    Queue* temp = *head;
    if (*head == NULL) {
        *head = newQueue;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newQueue;
}

Node* dequeue(Queue** head) {
    if (*head == NULL) return NULL;
    Queue* temp = *head;
    *head = (*head)->next;
    Node* root = temp->data;
    free(temp);
    return root;
}

// Function for level order traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue* queue = createQueue(root);
    while (queue != NULL) {
        Node* current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL) enqueue(&queue, current->left);
        if (current->right != NULL) enqueue(&queue, current->right);
    }
}

// Function to insert elements in the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Level order traversal of the BST: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
