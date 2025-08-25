#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    int x;
    printf("Enter the element to be searched : ");
    scanf("%d", &x);
    int low=0; int high=n-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(a[mid]==x){
            printf("The element is found at index position : %d", mid);
            break;
        }
        else{
            if(a[mid]>x)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    return 0;
}
