#include <stdio.h>
#include <stdlib.h>

// Define the structure for a sparse matrix node
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create and represent a sparse matrix
Node* createSparseMatrix(int matrix[][5], int rows, int cols) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                Node* newNode = createNode(i, j, matrix[i][j]);

                if (head == NULL) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
    return head;
}

// Function to display the sparse matrix in linked list form
void displaySparseMatrix(Node* head) {
    if (!head) {
        printf("Sparse matrix is empty.\n");
        return;
    }

    printf("Row\tCol\tValue\n");
    while (head) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

// Function to add a value to the sparse matrix
void addElement(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    newNode->next = *head;
    *head = newNode;
}

// Function to search for an element in the sparse matrix
int searchElement(Node* head, int row, int col) {
    while (head) {
        if (head->row == row && head->col == col) {
            return head->value;
        }
        head = head->next;
    }
    return 0; // Return 0 if the element is not found
}

// Function to delete an element from the sparse matrix
void deleteElement(Node** head, int row, int col) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp && (temp->row != row || temp->col != col)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Element at (%d, %d) deleted.\n", row, col);
}

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    Node* sparseMatrix = createSparseMatrix(matrix, 4, 5);

    printf("Initial Sparse Matrix:\n");
    displaySparseMatrix(sparseMatrix);

    printf("\nAdding an element (1, 1, 8):\n");
    addElement(&sparseMatrix, 1, 1, 8);
    displaySparseMatrix(sparseMatrix);

    printf("\nSearching for element at (1, 1): %d\n", searchElement(sparseMatrix, 1, 1));

    printf("\nDeleting element at (0, 2):\n");
    deleteElement(&sparseMatrix, 0, 2);
    displaySparseMatrix(sparseMatrix);

    return 0;
}
