#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    int x; int c=0;
    printf("Enter the element to be searched : ");
    scanf("%d", &x);
    for(int i=0;i<n;i++){
        if(a[i]==x){
             printf("Element found at index position : %d\n", i);
             c=1;
        }
    }
    if(c==0)
        printf("Element not found!\n");
    return 0;
}
