#include<stdio.h>

int main(){
    int i,j,r1,c1,r2,c2;
    printf("\nMatrix A\nEnter rows : ");
    scanf("%d", &r1);
    printf("Enter coloumns : ");
    scanf("%d", &c1);
    printf("\nMatrix B\nEnter rows : ");
    scanf("%d", &r2);
    printf("Enter coloumns : ");
    scanf("%d", &c2);

    if(c1!=r2){
        printf("No opetaion possible!");
        return 0;
    }

    int a[r1][c1], b[r2][c2];
    printf("\nEnter A's elements : \n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d", &a[i][j]);
    printf("\nEnter B's elements : \n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d", &b[i][j]);

    printf("\nMultiplication Matrix : \n");
    int c[r1][c2], k;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            c[i][j]=0;
            for(k=0;k<c1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    if(r1==r2 && c1==c2){
        int d[r1][c1];
        printf("\nAddition Matrix : \n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                d[i][j]=a[i][j]+b[i][j];
                printf("%d\t", d[i][j]);
            }
            printf("\n");
        }
    }

    int n;
    printf("\nEnter size of square matrix : ");
    scanf("%d", &n);
    int e[n][n], s1,s2,ds1=0,ds2=0, flag=1;
    printf("Enter elements : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d", &e[i][j]);
        ds1+=e[i][i];
        ds2+=e[i][n-i-1];
    }
    if(ds1!=ds2)
        flag=0;
    
    for(i=0;i<n;i++){
        s1=0;s2=0;
        for(j=0;j<n;j++){
            s1+=e[i][j];
            s2+=e[j][i];
        }
        if(s1!=s2 || s1!=ds1)
            flag=0;
    }
    if(flag==1)
        printf("Magic Sqaure");
    else
        printf("Not a Magic Sqaure");

    return 0;
}