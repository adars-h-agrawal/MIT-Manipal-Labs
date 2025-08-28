// lab5_3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Bubble Sort
void bubbleSort(char arr[], int n) {
    char temp;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

// Selection Sort
void selectionSort(char arr[], int n) {
    int min; char temp;
    for(int i=0;i<n-1;i++) {
        min=i;
        for(int j=i+1;j<n;j++) {
            if(strcmp(arr[j], arr[min]) < 0)
                min=j;
        }
        if(min!=i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[min]);
            strcpy(arr[min], temp);
        }
    }
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d",&n);

    char arr[n];
    for(int i=0;i<n;i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", arr[i]);
    }

    pid_t pid1 = fork();

    if (pid1 == 0) {
        bubbleSort(arr, n);
        printf("\nChild 1 (Bubble Sort Result): ");
        for(int i=0;i<n;i++) printf("%s ", arr[i]);
        printf("\n");
        exit(0);
    } 
    else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            selectionSort(arr, n);
            printf("\nChild 2 (Selection Sort Result): ");
            for(int i=0;i<n;i++) printf("%s ", arr[i]);
            printf("\n");
            exit(0);
        } 
        else {
            int status;
            wait(&status);
            printf("\nParent: One child finished, synchronization complete!\n");
        }
    }
    return 0;
}
