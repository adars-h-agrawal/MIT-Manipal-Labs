#include <stdio.h>
#define MAX 10

int alloc[MAX][MAX], req[MAX][MAX], avail[MAX], finish[MAX];
int n, m;

void deadlock_detection() {
    int work[MAX], deadlocked[MAX], count = 0;

    for(int i = 0; i < m; i++) work[i] = avail[i];
    for(int i = 0; i < n; i++) {
        finish[i] = 0;
        int zero = 1;
        for(int j = 0; j < m; j++)
            if(alloc[i][j] != 0) zero = 0;
        if(zero) finish[i] = 1;
    }
    int made_prog;
    do {
        made_prog = 0;
        for (int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int can_run = 1;
                for(int j = 0; j < m; j++)
                    if(req[i][j] > work[j]) can_run = 0;
                if(can_run) {
                    for(int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    made_prog = 1;
                }
            }
        }
    } while (made_prog);

    for(int i = 0; i < n; i++)
        if(finish[i] == 0)
            deadlocked[count++] = i;

    if(count == 0) printf("No deadlock detected in the system.\n");
    else {
        printf("Deadlock detected. The following processes are deadlocked:\n");
        for(int i = 0; i < count; i++) printf("P%d ", deadlocked[i]);
        printf("\n");
    }
}

int main() {
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    printf("Enter number of Resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for(int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    deadlock_detection();
    return 0;
}
