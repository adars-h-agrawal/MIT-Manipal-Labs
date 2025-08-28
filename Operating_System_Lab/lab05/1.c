// lab5_1.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("\n--- Child Process ---\n");
        printf("Child PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Message: Hello from Child!\n");
    }
    else {
        // Parent process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID = %d, Parent’s Parent PID = %d\n", getpid(), getppid());
        printf("Message: Hello from Parent!\n");
    }

    return 0;
}