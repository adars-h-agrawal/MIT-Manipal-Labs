#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return (root != NULL);
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int n, data, key;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Value %d found in the tree.\n", key);
    else
        printf("Value %d not found in the tree.\n", key);

    return 0;
}
