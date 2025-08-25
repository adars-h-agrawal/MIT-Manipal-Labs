#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 5    // Maximum number of stacks
#define MAX_SIZE 100     // Maximum size of each stack

// Structure to hold multiple stacks
typedef struct {
    int stackArray[MAX_STACKS][MAX_SIZE];
    int top[MAX_STACKS];
} MultiStack;

// Function to initialize the stacks
void initStacks(MultiStack* ms) {
    for (int i = 0; i < MAX_STACKS; i++) {
        ms->top[i] = -1; // Initialize tops to -1 (indicating empty stacks)
    }
}

// Function to check if a stack is full
int isFull(MultiStack* ms, int stackIndex) {
    return ms->top[stackIndex] == MAX_SIZE - 1;
}

// Function to check if a stack is empty
int isEmpty(MultiStack* ms, int stackIndex) {
    return ms->top[stackIndex] == -1;
}

// Function to push an element onto a stack
void push(MultiStack* ms, int stackIndex, int value) {
    if (isFull(ms, stackIndex)) {
        printf("Stack %d is full. Cannot push %d.\n", stackIndex, value);
    } else {
        ms->stackArray[stackIndex][++(ms->top[stackIndex])] = value;
        printf("Pushed %d onto stack %d.\n", value, stackIndex);
    }
}

// Function to pop an element from a stack
int pop(MultiStack* ms, int stackIndex) {
    if (isEmpty(ms, stackIndex)) {
        printf("Stack %d is empty. Cannot pop.\n", stackIndex);
        return -1; // Indicating an error
    } else {
        return ms->stackArray[stackIndex][(ms->top[stackIndex]--)]; // Return the popped value
    }
}

// Function to display the contents of a stack
void displayStack(MultiStack* ms, int stackIndex) {
    if (isEmpty(ms, stackIndex)) {
        printf("Stack %d is empty.\n", stackIndex);
    } else {
        printf("Stack %d contents: ", stackIndex);
        for (int i = 0; i <= ms->top[stackIndex]; i++) {
            printf("%d ", ms->stackArray[stackIndex][i]);
        }
        printf("\n");
    }
}

int main() {
    MultiStack ms;
    initStacks(&ms);
    int choice, stackIndex, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack index (0 to %d): ", MAX_STACKS - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= MAX_STACKS) {
                    printf("Invalid stack index.\n");
                    break;
                }
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&ms, stackIndex, value);
                break;
            case 2:
                printf("Enter stack index (0 to %d): ", MAX_STACKS - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= MAX_STACKS) {
                    printf("Invalid stack index.\n");
                    break;
                }
                value = pop(&ms, stackIndex);
                if (value != -1) {
                    printf("Popped %d from stack %d.\n", value, stackIndex);
                }
                break;
            case 3:
                printf("Enter stack index (0 to %d): ", MAX_STACKS - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= MAX_STACKS) {
                    printf("Invalid stack index.\n");
                    break;
                }
                displayStack(&ms, stackIndex);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
