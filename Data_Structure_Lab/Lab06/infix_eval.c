#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

int evaluatePrefix(char *prefix) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i]))
            push(prefix[i] - '0'); // Convert char to int
        else {
            int op1 = pop();
            int op2 = pop();
            int result;
            switch (prefix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < op2; j++)
                        result *= op1;
                    push(result);
                    break;
                default:
                    printf("Invalid operator!");
            }
        }
    }
    return pop();
}

int main() {
    char prefix[MAX];

    printf("Enter prefix expression: ");
    gets(prefix);

    printf("Result: %d\n", evaluatePrefix(prefix));

    return 0;
}

