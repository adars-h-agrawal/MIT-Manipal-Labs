#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Function to create a stack
void createStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(Stack* stack, char item) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to check if the given expression has matching parentheses
bool areParenthesesBalanced(char* expr) {
    Stack stack;
    createStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            // Push the opening parenthesis onto the stack
            push(&stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            // If stack is empty and we encounter a closing parenthesis, return false
            if (isEmpty(&stack)) {
                return false;
            }
            // Pop the top element from the stack and check if it matches the closing parenthesis
            char top = pop(&stack);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack is not empty after processing the entire expression, return false
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
