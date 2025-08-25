#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *expr) {
    if (top < MAX - 1) {
        strcpy(stack[++top], expr);
    }
}

char* pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return NULL;
}

void prefixToInfix(char *prefix, char *infix) {
    int len = strlen(prefix);
    char op1[MAX], op2[MAX];

    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(operand);
        }
        else {
            char *op1 = pop();
            char *op2 = pop();
            char result[MAX];
            sprintf(result, "(%s%c%s)", op1, prefix[i], op2);
            push(result);
        }
    }
    strcpy(infix, pop());
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter prefix expression: ");
    gets(prefix);

    prefixToInfix(prefix, infix);

    printf("Fully parenthesized infix expression: %s\n", infix);

    return 0;
}

