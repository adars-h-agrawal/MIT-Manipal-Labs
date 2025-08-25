#include<stdio.h>

int multiply(int a, int b){
    if(b==0)
        return 0;
    if(b>0)
        return a+multiply(a, b-1);
    if(b<0)
        return -multiply(a, -b);
}

int main(){
    int a,b;
    printf("Enter A :");
    scanf("%d", &a);
    printf("Enter B :");
    scanf("%d", &b);
    printf("%d * %d = %d\n", a,b,multiply(a,b));
    return 0;
}