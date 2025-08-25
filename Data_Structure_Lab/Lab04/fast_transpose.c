#include <stdio.h>
#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Element;

void fastTranspose(Element sparse[], Element transpose[], int numTerms, int numCols) {
    int rowTerms[MAX], startingPos[MAX];
    int i, j;

    // Initialize rowTerms array to zero
    for (i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }

    // Count the number of terms in each column of the original matrix
    for (i = 0; i < numTerms; i++) {
        rowTerms[sparse[i].col]++;
    }

    // Calculate starting positions for each row in the transposed matrix
    startingPos[0] = 0;
    for (i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    }

    // Fill the transposed matrix using starting positions
    for (i = 0; i < numTerms; i++) {
        j = startingPos[sparse[i].col]++;
        transpose[j].row = sparse[i].col;
        transpose[j].col = sparse[i].row;
        transpose[j].val = sparse[i].val;
    }
}

int main() {
    int rows, cols, numTerms, i;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numTerms);

    Element sparse[MAX], transpose[MAX];

    printf("Enter the sparse matrix elements (row, col, value):\n");
    for (i = 0; i < numTerms; i++) {
        scanf("%d%d%d", &sparse[i].row, &sparse[i].col, &sparse[i].val);
    }

    fastTranspose(sparse, transpose, numTerms, cols);

    printf("The transposed sparse matrix is:\n");
    printf("Row  Column  Value\n");
    for (i = 0; i < numTerms; i++) {
        printf("%d         %d       %d\n", transpose[i].row, transpose[i].col, transpose[i].val);
    }

    return 0;
}