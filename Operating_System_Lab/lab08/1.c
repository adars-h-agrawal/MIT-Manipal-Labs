#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int n, m;
int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX], avail[MAX];
bool finish[MAX];

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available vector:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Calculate need
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool safetyCheck() {
    int work[MAX], safeSeq[MAX];
    for (int i = 0; i < m; i++) work[i] = avail[i];
    for (int i = 0; i < n; i++) finish[i] = false;
    int cnt = 0;

    while (cnt < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[cnt++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }
    if (cnt == n) {
        printf("System is in SAFE state.\nSafe Sequence: ");
        for(int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
        return true;
    } else {
        printf("System is in UNSAFE state.\n");
        return false;
    }
}

void resourceRequest() {
    int req[MAX], p;
    printf("Enter the process number making request (0-indexed): ");
    scanf("%d", &p);
    printf("Enter the request vector:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &req[i]);
    for (int i = 0; i < m; i++) {
        if (req[i] > need[p][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return;
        }
        if (req[i] > avail[i]) {
            printf("Process must wait: resources not available.\n");
            return;
        }
    }
    // Pretend to allocate
    for (int i = 0; i < m; i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }
    if (safetyCheck()) {
        printf("Request can be granted.\n");
    } else {
        // Revert
        for (int i = 0; i < m; i++) {
            avail[i] += req[i];
            alloc[p][i] -= req[i];
            need[p][i] += req[i];
        }
        printf("Request cannot be granted as state is not safe.\n");
    }
}

int main() {
    input();
    safetyCheck();
    char ch;
    do {
        printf("\nDo you want to make a resource request? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
            resourceRequest();
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
