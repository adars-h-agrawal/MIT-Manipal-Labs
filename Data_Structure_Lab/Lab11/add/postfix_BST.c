#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definition of the tree node
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Stack node definition
typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

// Function to create a new tree node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a tree node onto the stack
void push(StackNode** top, Node* treeNode) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a tree node from the stack
Node* pop(StackNode** top) {
    if (*top == NULL) return NULL;
    StackNode* temp = *top;
    *top = (*top)->next;
    Node* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate the postfix expression tree
int evaluate(Node* root) {
    if (root == NULL) return 0;

    // If it's a leaf node (operand), return its value
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    // Evaluate left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Apply the operator at the current node
    if (root->data == '+') return leftEval + rightEval;
    if (root->data == '-') return leftEval - rightEval;
    if (root->data == '*') return leftEval * rightEval;
    if (root->data == '/') return leftEval / rightEval;

    return 0;
}

// Function to create an expression tree from a postfix expression
Node* constructTree(char postfix[]) {
    StackNode* stack = NULL;
    Node* t, *t1, *t2;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // If operand, push to stack
        if (!isOperator(postfix[i])) {
            t = createNode(postfix[i]);
            push(&stack, t);
        }
        // If operator, pop two nodes, create tree and push it back
        else {
            t = createNode(postfix[i]);
            t1 = pop(&stack);
            t2 = pop(&stack);

            t->right = t1;
            t->left = t2;

            push(&stack, t);
        }
    }

    // The remaining node is the root of the expression tree
    t = pop(&stack);
    return t;
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    Node* root = constructTree(postfix);
    printf("The result of the postfix expression is: %d\n", evaluate(root));

    return 0;
}
