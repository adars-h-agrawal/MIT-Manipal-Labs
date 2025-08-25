#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    int pos;
    for(int i=0;i<n-1;i++){
      pos=i;
      for(int j=i+1;j<n;j++){
         if(a[pos]>a[j])
            pos=j;
      }
      if(pos!=i){
         int temp=a[i];
         a[i]=a[pos];
         a[pos]=temp;
      }
   }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
