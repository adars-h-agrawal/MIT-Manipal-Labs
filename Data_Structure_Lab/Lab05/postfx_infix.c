#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char str[]) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], str);
}

void pop(char str[]) {
    if (top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    strcpy(str, stack[top--]);
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void convert(char postfix[]) {
    int i;
    char op1[MAX], op2[MAX], result[MAX];

    for (i = 0; postfix[i] != '\0'; i++) {
        // If character=operand, push
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            push(operand);
        }
        // If character=operator, pop two elements, create an infix expression and push back
        else if (isOperator(postfix[i])) {
            char operator = postfix[i];

            // Pop two operands
            pop(op2);
            pop(op1);

            // Form the new string with parenthesis
            sprintf(result, "(%s%c%s)", op1, operator, op2);

            // Push the resulting expression back onto the stack
            push(result);
        }
    }

    // The final result is at the top of the stack
    pop(result);
    printf("Infix expression is : %s", result);
}

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    convert(postfix);
    return 0;
}
