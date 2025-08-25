#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the matrices : ");
    scanf("%d", &n);
    int a[n][n], b[n][n], c[n][n];
    printf("Enter the elements of A :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    printf("Enter the elements of B :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &b[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>b[i][j])
                c[i][j]=a[i][j];
            else
                c[i][j]=b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d  ", c[i][j]);
        printf("\n");
    }
    return 0;
}