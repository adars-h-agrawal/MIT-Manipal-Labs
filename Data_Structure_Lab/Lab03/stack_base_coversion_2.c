#include<stdio.h>
#define MAX 20

int stack[MAX], rem;
int top=-1, front=0;

void push(int x){
    top++;
    stack[top]=x;
}

int pop(){
    int x;
    x=stack[top];
    top--;
    return x;
}

void DecToBin(int num){ 
    while(num!=0){
        rem=num%2;
        push(rem);
        num/=2;
    }
    while(top!=-1)
        printf("%d", pop());
    printf("\n");
}

void DecToOct(int num){
    while(num!=0){
        rem=num%8;
        push(rem);
        num/=8;
    }
    while(top!=-1)
        printf("%d", pop());
    printf("\n");
}

void DecToHex(int num){
    char c; 
    while(num!=0){
        rem=num%16;
        if(rem<10)
            push(rem);
        else{
            c=rem+55;
            push(c);
        }
        num/=16;
    }
    while(top!=-1){
        if(stack[top]<10)
            printf("%d", pop());
        else
            printf("%c", pop());
    }
    printf("\n");
}

int main(){
    int num, ch;
    printf("Enter an integer : ");
    scanf("%d", &num);
    printf("1. Binary\n2. Octal\n3. Hexadecimal\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    if(ch==1){
        printf("Binary Equivalent is : ");
        DecToBin(num);
    }
    else if(ch==2){
        printf("Octal Equivalent is : ");
        DecToOct(num);
    }
    else if(ch==3){
        printf("Hexadecimal Equivalent is : ");
        DecToHex(num);
    }
    else
        printf("Wrong Choice!");
    return 0;
}