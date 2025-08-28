// lab5_2.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void sortStrings(int n, char *arr[]) {
    char temp[100];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ...\n", argv);
        exit(0);
    }

    pid_t pid = fork();

    if (pid == 0) {
        printf("\nChild Process – Sorted Strings:\n");
        sortStrings(argc, argv);
        for (int i = 1; i < argc; i++) printf("%s ", argv[i]);
        printf("\n");
        exit(0);
    } else {
        wait(NULL);
        printf("\nParent Process – Original Strings:\n");
        for (int i = 1; i < argc; i++) printf("%s ", argv[i]);
        printf("\n");
    }

    return 0;
}