#include<stdio.h>
#include<string.h>
int main(){

    printf("1) length of the string\n2) string concatenation\n3) string comparison\n4) to insert a sub string\n5) to delete a substring\n");
    int ch;
    printf("Enter your choice : ");
    scanf("%d", &ch);

    if(ch==1){
        char x[100];
        printf("Enter a string : ");
        fflush(stdin);
        gets(x);
        int c=0;
        for(int i=0;x[i]!='\0';i++)
            c++;
        printf("The length of the string is : %d\n", c);
        return 0;
    }

    char a[100]; char b[100];
    printf("Enter first string : ");
    fflush(stdin);
    gets(a);
    printf("Enter second string : ");
    fflush(stdin);
    gets(b);

    if(ch==2){
        int i=0; int j=0;
        while(a[i]!='\0')
            i++;
        while(b[j]!='\0'){
            a[i]=b[j];
            i++; j++;
        }
        a[i]='\0';
        printf("%s", a);
    }

    else if(ch==3){
        int i=0;
        while(a[i]==b[i] && a[i]!='\0')
            i++;
        if(a[i]>b[i]  && a[i]-b[i]!=32 && b[i]-a[i]!=32)
            printf("First string is bigger than second\n");
        else if(b[i]>a[i] && a[i]-b[i]!=32 && b[i]-a[i]!=32)
            printf("Second string is bigger than first\n");
        else
            printf("Both strings are same\n");
    }

    else if(ch==4){
        int pos;
        printf("Enter index to insert string : ");
        scanf("%d", &pos);
        int c=strlen(b);
        for(int i=70;i>=pos;i--){
            a[i+c]=a[i];
        }
        int j=0;
        for(int i=pos;i<pos+c;i++){
            a[i]=b[j];
            j++;
        }
        printf("New string is : %s\n", a);
    }

    else if(ch==5){
        int c=strlen(b);
        int pos;
        int j=0;
        for(int i=0;i<100;i++)
            if(a[i]==b[j])
                pos=i;
        for(int j=0;j<c;j++){
                for(int i=pos;i<100;i++)
                a[i]=a[i+1];
        }
        printf("%s", a);
    }

    else
        printf("Wrong Choice!");
    return 0;
}
