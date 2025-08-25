#include<stdio.h>
#define MAX 50

struct Element{
    int row;
    int col;
    int val;
};

void Transpose(struct Element sparse[], struct Element transpose[], int totalelements){
    for(int i=0;i<totalelements;i++){
        transpose[i].row = sparse[i].col;
        transpose[i].col = sparse[i].row;
        transpose[i].val = sparse[i].val;     
    }
}

int main(){
    int n, m, totalelements;
    printf("Enter the number of rows and columns : ");
    scanf("%d%d", &n, &m);
    printf("Enter the number of non-zero elements : ");
    scanf("%d", &totalelements);
    
    struct Element sparse[MAX], transpose[MAX];
    printf("Enter row, column and value of each non-zero element:\n");
    for(int i=0;i<totalelements;i++)
        scanf("%d%d%d", &sparse[i].row, &sparse[i].col, &sparse[i].val);

    Transpose(sparse, transpose, totalelements);

    printf("Transpose of the sparse matrix is :\n");
    printf("Row  Column  Value\n");
    for(int i=0;i<totalelements;i++)
        printf("%d       %d      %d\n", transpose[i].row, transpose[i].col, transpose[i].val);
    return 0;
}