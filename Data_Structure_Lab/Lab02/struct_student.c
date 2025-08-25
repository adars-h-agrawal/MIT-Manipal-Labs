#include<stdio.h>

struct student{
    char name[30];
    int roll;
    char grade[3];
};

int main(){
    struct student s[20], temp;
    int i,j,n;

    printf("Enter number of students: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
            printf("Enter name, roll and grade of student:\n");
            scanf("%s%d%s",&s[i].name, &s[i].roll, &s[i].grade);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(s[i].roll>s[j].roll){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("Sorted records are:\n");
    for(i=0;i<n;i++){
        printf("Name: %s\t", s[i].name);
        printf("Roll: %d\t", s[i].roll);
        printf("Grade: %s\n", s[i].grade);
    }
    return 0;
}
