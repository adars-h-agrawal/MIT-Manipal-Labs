#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} stack;

//funtion prototypes
void push(stack *s, char item);
char pop(stack *s);
int precedence(char operator);
int isOperator(char symbol);
void convert(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression : ");
    scanf("%s", infix);
    
    convert(infix, postfix);

    printf("Postfix Expression is : %s\n", postfix);
    return 0;
}

void push(stack *s, char item) {
    if (s->top == MAX -1) {
        printf("Stack Overflow!");
        exit(1);
    }
    else {
        s->items[++(s->top)] = item;
    }
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Satck Underflow!");
        exit(1);
    }
    else {
        return s->items[(s->top)--];
    }
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void convert(char infix[], char postfix[]) {
    stack s;
    s.top = -1;
    char symbol, temp;
    int i=0,j=0;

    while(infix[i]!='\0') {
        symbol = infix[i];

        //if symbol = operand...add it to postfix exp
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }

        //if symbol = '('...push it to stack
        else if (symbol == '(') {
            push(&s, symbol);
        }

        //if symbol = ')'...pop until '(' is found
        else if (symbol == ')') {
            while ((temp = pop(&s)) != '(') {
                postfix[j++] = temp;
            }
        }

        //if symbol = operator
        else if(isOperator(symbol)) {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
        i++;
    }

    // pop the remaining items 
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}