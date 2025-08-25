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

int areEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->data == root2->data) && areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node *root1 = NULL, *root2 = NULL;
    int n, data;

    printf("Enter number of nodes for first tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root1 = insert(root1, data);
    }

    printf("Enter number of nodes for second tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root2 = insert(root2, data);
    }

    printf("First Tree (inorder): ");
    inorder(root1);
    printf("\nSecond Tree (inorder): ");
    inorder(root2);
    
    if (areEqual(root1, root2)) 
        printf("\nThe two trees are equal.\n");
    else 
        printf("\nThe two trees are not equal.\n");

    return 0;
}
