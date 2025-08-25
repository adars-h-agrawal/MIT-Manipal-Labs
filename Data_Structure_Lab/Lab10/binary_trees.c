#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert values into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal (iterative)
void inorderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Post-order traversal (iterative)
void postorderTraversal(struct Node* root) {
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    struct Node* curr = root;

    if (curr == NULL) return;

    stack1[++top1] = curr;
    while (top1 != -1) {
        curr = stack1[top1--];
        stack2[++top2] = curr;
        if (curr->left) stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Pre-order traversal (iterative)
void preorderTraversal(struct Node* root) {
    if (!root) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);
        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}

// Function to find the parent of a given element
void printParent(struct Node* root, int value) {
    if (root == NULL) return;

    if ((root->left && root->left->data == value) || (root->right && root->right->data == value)) {
        printf("Parent of %d is %d\n", value, root->data);
    } else {
        printParent(root->left, value);
        printParent(root->right, value);
    }
}

// Function to calculate the depth of the tree
int treeDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to print ancestors of a given element
int printAncestors(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;

    if (printAncestors(root->left, value) || printAncestors(root->right, value)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;
   
    /*// Initialize the binary tree with existing values
    int initialValues[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(initialValues) / sizeof(initialValues[0]); i++) {
        root = insert(root, initialValues[i]);
    }
    */

    // Allow user input for additional values
    int value;
    do {
        printf("Enter a value to insert into the tree (-1 to stop): ");
        scanf("%d", &value);
        if (value != -1) {
            root = insert(root, value);
        }
    } while (value != -1);

    // Display tree traversals
    printf("\nIn-order Traversal: ");
    inorderTraversal(root);
    printf("\nPost-order Traversal: ");
    postorderTraversal(root);
    printf("\nPre-order Traversal: ");
    preorderTraversal(root);

    // Find parent
    int valueToFindParent;
    printf("\nEnter the value to find its parent: ");
    scanf("%d", &valueToFindParent);
    printParent(root, valueToFindParent);

    // Print depth
    printf("Depth of the tree: %d\n", treeDepth(root));

    // Print ancestors
    int valueToFindAncestors;
    printf("Enter the value to print its ancestors: ");
    scanf("%d", &valueToFindAncestors);
    printf("Ancestors of %d: ", valueToFindAncestors);
    printAncestors(root, valueToFindAncestors);
    printf("\n");

    // Count leaf nodes
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
