#include <stdio.h>
#define MAX 10

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int remBlock[m];

    for (int i = 0; i < m; i++) remBlock[i] = blockSize[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (remBlock[j] >= processSize[i]) {
                allocation[i] = j;
                remBlock[j] -= processSize[i];
                break;
            }
        }
    }

    printf("First Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int remBlock[m];

    for (int i = 0; i < m; i++) remBlock[i] = blockSize[i];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (remBlock[j] >= processSize[i]) {
                if (bestIdx == -1 || remBlock[j] < remBlock[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            remBlock[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[MAX], processSize[MAX], m, n;

    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter block sizes:\n");
    for (int i = 0; i < m; i++) scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++) scanf("%d", &processSize[i]);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);

    return 0;
}
