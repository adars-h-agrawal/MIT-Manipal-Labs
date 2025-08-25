#include<stdio.h>
#include<string.h>
int main(){
    char a[100]; char b[100];
    int x; int y;
    printf("Enter main string :");
    gets(a);
    printf("Enter string to be deleted :");
    gets(b);
    x=strlen(a); y=strlen(b);
    for(int i=0;i<x;i++){
        int flag=1,j=0;
        if(a[i]==b[j]){
            for(j=1;j<y;j++)
                if(a[i+j]==b[j])
                    flag++;

            if(flag==y){
                for(int z=0;z<y;z++){
                    for(int k=i;k<=x;k++)
                        a[k]=a[k+1];
                }
                x-=y;
            }
        }
    }
    printf("%s", a);
    return 0;
}