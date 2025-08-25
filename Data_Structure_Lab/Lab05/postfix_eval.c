#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} stack;

// Function prototypes
void push(stack *s, int item);
int pop(stack *s);
int evaluate(char postfix[]);

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate(postfix);
    printf("The evaluated expression is: %d\n", result);
    return 0;
}

void push(stack *s, int item) {
    if (s->top == (MAX - 1)) 
        printf("Stack overflow\n");
    else
        s->items[++(s->top)] = item;
}

int pop(stack *s){
    if (s->top == -1)
        printf("Stack underflow\n");
    else
        return s->items[(s->top)--];
}

int evaluate(char postfix[]) {
    stack s;
    s.top = -1;

    int i = 0, op1, op2, result;
    char symbol;

    while (postfix[i] != '\0') {
        symbol = postfix[i];

        // If the symbol = operand, push to stack
        if (isdigit(symbol))
            push(&s, symbol - '0'); // Convert character to integer and push

        // If the symbol = operator, pop two operands, perform the operation, and push the result back
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (symbol) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < op2; j++) {
                        result *= op1;
                    }
                    break;
                default:
                    printf("Invalid operator!");
            }
            push(&s, result);
        }
        i++;
    }

    // The final result is the only element remaining in the stack
    return pop(&s);
}
