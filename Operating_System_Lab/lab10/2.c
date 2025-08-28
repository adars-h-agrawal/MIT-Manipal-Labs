#include <stdio.h>
#include <stdlib.h>

void lruPageReplacement(int pages[], int n, int frames) {
    int *frameArr = (int*)malloc(frames * sizeof(int));
    int *counter = (int*)malloc(frames * sizeof(int));
    int i, j, k, pos, least, pageFaults = 0;
    for (i = 0; i < frames; i++)
        frameArr[i] = -1;

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (j = 0; j < frames; j++) {
            if (frameArr[j] == page) {
                found = 1;
                counter[j] = i;
                break;
            }
        }
        if (!found) {
            least = counter[0];
            pos = 0;
            for (j = 1; j < frames; j++) {
                if (counter[j] < least) {
                    least = counter[j];
                    pos = j;
                }
            }
            frameArr[pos] = page;
            counter[pos] = i;
            pageFaults++;
        }
        printf("Step %d: ", i + 1);
        for (k = 0; k < frames; k++)
            printf("%d ", frameArr[k]);
        printf("\n");
    }
    printf("LRU Page Faults: %d\n", pageFaults);
    free(frameArr);
    free(counter);
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

    printf("\nLRU Page Replacement:\n");
    lruPageReplacement(pages, n, frames);

    free(pages);
    return 0;
}
