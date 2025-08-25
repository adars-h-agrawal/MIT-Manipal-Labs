#include<stdio.h>
#define MAX 20

void push(int x, int *top, char stack[]){
    if(*top==(MAX-1))
        printf("Stack Overflow\n");
    else{
        *top+=1;
        stack[*top]=x;
    }
}

int pop(int *top, char stack[]){
    int x;
    if(*top==-1)
        printf("Stack Underflow\n");
    else{
        x=stack[*top];
        *top-=1;
    }
    return x;
}

void DecToBin(int num){
    char stack[MAX]; 
    int top=-1, rem;
    while(num!=0){
        rem=num%2;
        push(rem, &top, stack);
        num/=2;
    }
    while(top!=-1)
        printf("%d", pop(&top, stack));
    printf("\n");
}

void DecToOct(int num){
    char stack[MAX]; 
    int top=-1, rem;
    while(num!=0){
        rem=num%8;
        push(rem, &top, stack);
        num/=8;
    }
    while(top!=-1)
        printf("%d", pop(&top, stack));
    printf("\n");
}

void DecToHex(int num){
    char stack[MAX], ch; 
    int top=-1, rem;
    while(num!=0){
        rem=num%16;
        if(rem<10)
            push(rem, &top, stack);
        else{
            ch=rem+55;
            push(ch, &top, stack);
        }
        num/=16;
    }
    while(top!=-1){
        if(stack[top]<10)
            printf("%d", pop(&top, stack));
        else
            printf("%c", pop(&top, stack));
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