#include <stdio.h>
#include <string.h>
#define MAX 20
 
int stack[MAX];
int top=-1, front=0;
void push(char a){
    top++;
    stack[top]=a;
}
void pop(){
    top--;
}

int main(){
    char s[MAX], b;
	printf("Enter the String : ");
	scanf("%s", s);
	for(int i=0;s[i]!='\0';i++){
		b=s[i];
		push(b);
	}
	for(int i=0;i<(strlen(s)/2);i++){
		if(stack[top]==stack[front]){
			pop();
			front++;
		}
		else{
			printf("%s is not a palindrome\n", s);
			break; 
		}
	}
	if((strlen(s)/2)==front)
		printf("%s is palindrome\n", s);
	return 0;
}
