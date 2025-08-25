#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i]; i++)
    {
        if (infix[i] == '(')
            stack[++top] = infix[i];
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; // Remove '(' from stack
        }
        else if (isalnum(infix[i]))
            postfix[k++] = infix[i];
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[k++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

void infixToPrefix(char *infix, char *prefix) {
    char reversedInfix[MAX];
    char postfix[MAX];

    strcpy(reversedInfix, infix);
    reverse(reversedInfix);

    for (int i = 0; reversedInfix[i]; i++) {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }

    infixToPostfix(reversedInfix, postfix);
    reverse(postfix);

    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
