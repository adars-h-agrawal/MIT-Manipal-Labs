#include <stdio.h>
#include <stdlib.h>

void fifoPageReplacement(int pages[], int n, int frames) {
    int *frameArr = (int*)malloc(frames * sizeof(int));
    int i, j, k, flag, pageFaults = 0, front = 0;

    for (i = 0; i < frames; i++)
        frameArr[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < frames; j++) {
            if (frameArr[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frameArr[front] = pages[i];
            front = (front + 1) % frames;
            pageFaults++;
        }
        printf("Step %d: ", i + 1);
        for (k = 0; k < frames; k++)
            printf("%d ", frameArr[k]);
        printf("\n");
    }
    printf("FIFO Page Faults: %d\n", pageFaults);
    free(frameArr);
}

int getOptimalIndex(int pages[], int frameArr[], int n, int frames, int index) {
    int i, j, maxIndex = -1, maxDistance = -1, flag;
    for (i = 0; i < frames; i++) {
        flag = 0;
        for (j = index + 1; j < n; j++) {
            if (frameArr[i] == pages[j]) {
                if (j > maxDistance) {
                    maxDistance = j;
                    maxIndex = i;
                }
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    if (maxIndex == -1)
        return 0;
    else
        return maxIndex;
}

void optimalPageReplacement(int pages[], int n, int frames) {
    int *frameArr = (int*)malloc(frames * sizeof(int));
    int i, j, k, flag, pageFaults = 0;

    for (i = 0; i < frames; i++)
        frameArr[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < frames; j++) {
            if (frameArr[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            int replaceIndex = -1;
            for (j = 0; j < frames; j++) {
                if (frameArr[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }
            if (replaceIndex == -1)
                replaceIndex = getOptimalIndex(pages, frameArr, n, frames, i);
            frameArr[replaceIndex] = pages[i];
            pageFaults++;
        }
        printf("Step %d: ", i + 1);
        for (k = 0; k < frames; k++)
            printf("%d ", frameArr[k]);
        printf("\n");
    }
    printf("Optimal Page Faults: %d\n", pageFaults);
    free(frameArr);
}

int main() {
    int n, frames, i;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int *pages = (int*)malloc(n * sizeof(int));
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("\nFIFO Page Replacement:\n");
    fifoPageReplacement(pages, n, frames);

    printf("\nOptimal Page Replacement:\n");
    optimalPageReplacement(pages, n, frames);

    free(pages);
    return 0;
}
