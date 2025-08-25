#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    int key;
    for(int i=1;i<n;i++){
        key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}
