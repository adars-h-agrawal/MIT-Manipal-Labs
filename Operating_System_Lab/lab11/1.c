#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int absVal(int x) { return x < 0 ? -x : x; }

// SSTF Algorithm
void SSTF(int requests[], int n, int head) {
    int completed = 0, seek_count = 0, curr = head;
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    printf("\nSSTF order: %d ", curr);

    while (completed != n) {
        int min_dist = 100000, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && absVal(requests[i] - curr) < min_dist) {
                min_dist = absVal(requests[i] - curr);
                idx = i;
            }
        }
        visited[idx] = true;
        seek_count += min_dist;
        curr = requests[idx];
        printf("%d ", curr);
        completed++;
    }
    printf("\nTotal seek operations: %d\n", seek_count);
}

// SCAN Algorithm
void SCAN(int requests[], int n, int head, int disk_size, int direction) {
    int seek_count = 0, curr = head;
    int left[n], right[n], l=0, r=0;

    // Add end points
    if (direction == 0) right[r++] = disk_size - 1;
    else left[l++] = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head) left[l++] = requests[i];
        else right[r++] = requests[i];
    }

    // Sort left and right arrays
    for(int i=0; i<l-1; i++)
    for(int j=i+1; j<l; j++)
        if(left[i] > left[j])
            {int temp=left[i]; left[i]=left[j]; left[j]=temp;}
    for(int i=0; i<r-1; i++)
    for(int j=i+1; j<r; j++)
        if(right[i] > right[j])
            {int temp=right[i]; right[i]=right[j]; right[j]=temp;}

    printf("\nSCAN order: %d ", curr);
    if (direction == 0) { // Move right first
        for(int i=0; i<r; i++) {
            seek_count += absVal(curr - right[i]);
            curr = right[i];
            printf("%d ", curr);
        }
        for(int i=l-1; i>=0; i--) {
            seek_count += absVal(curr - left[i]);
            curr = left[i];
            printf("%d ", curr);
        }
    } else { // Move left first
        for(int i=l-1; i>=0; i--) {
            seek_count += absVal(curr - left[i]);
            curr = left[i];
            printf("%d ", curr);
        }
        for(int i=0; i<r; i++) {
            seek_count += absVal(curr - right[i]);
            curr = right[i];
            printf("%d ", curr);
        }
    }
    printf("\nTotal seek operations: %d\n", seek_count);
}

// Helper to find the next index for SCAN schemes
int indexOfMinimalDistance(int requests[], int n, int curr, bool done[]) {
    int min_dist = 100000, idx = -1;
    for (int i = 0; i < n; i++) {
        if (!done[i]) {
            int dist = absVal(requests[i] - curr);
            if (dist < min_dist) {
                min_dist = dist;
                idx = i;
            }
        }
    }
    return idx;
}

// C-SCAN Algorithm
void CSCAN(int requests[], int n, int head, int disk_size) {
    bool done[n];
    for (int i=0;i<n;i++) done[i]=false;
    int total_seek=0, curr=head;

    printf("\nC-SCAN order: %d ", curr);
    while (true) {
        int idx = -1;
        int min_above = disk_size + 1;
        // Seek min request greater than current head
        for (int i=0;i<n;i++) {
            if (!done[i] && requests[i] >= curr && requests[i] < min_above) {
                min_above = requests[i];
                idx = i;
            }
        }
        if (idx == -1) {
            // Jump to smallest request
            int min_req= disk_size+1, min_idx = -1;
            for (int i=0;i<n;i++) {
                if (!done[i] && requests[i] < min_req) {
                    min_req = requests[i];
                    min_idx = i;
                }
            }
            if (min_idx == -1) break;
            total_seek += absVal(curr - (disk_size-1)); // to end
            total_seek += (min_req);                   // to start
            curr = min_req;
            printf("%d ", curr);
            done[min_idx]=true;
        } else {
            total_seek += absVal(curr - requests[idx]);
            curr = requests[idx];
            printf("%d ", curr);
            done[idx] = true;
        }
    }
    printf("\nTotal seek operations: %d\n", total_seek);
}

// C-LOOK Algorithm
void CLOOK(int requests[], int n, int head) {
    bool done[n];
    for (int i=0; i<n; i++) done[i] = false;
    int total_seek = 0, curr = head;

    printf("\nC-LOOK order: %d ", curr);
    while (true) {
        int idx = -1;
        int min_above = 100000;
        for (int i=0; i<n; i++) {
            if (!done[i] && requests[i] >= curr && requests[i] < min_above) {
                min_above = requests[i]; idx = i;
            }
        }
        if (idx == -1) {
            int min_req = 100000, min_idx = -1;
            for (int i=0; i<n; i++) {
                if (!done[i] && requests[i] < min_req) {
                    min_req = requests[i];
                    min_idx = i;
                }
            }
            if (min_idx == -1) break;
            total_seek += absVal(curr - min_req);
            curr = min_req;
            printf("%d ", curr);
            done[min_idx] = true;
        } else {
            total_seek += absVal(curr - requests[idx]);
            curr = requests[idx];
            printf("%d ", curr);
            done[idx] = true;
        }
    }
    printf("\nTotal seek operations: %d\n", total_seek);
}

int main() {
    int n, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter requests:\n");
    for(int i=0; i<n; i++) scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size (max track number): ");
    scanf("%d", &disk_size);

    SSTF(requests, n, head);
    SCAN(requests, n, head, disk_size, 0);  // 0 for right direction
    CSCAN(requests, n, head, disk_size);
    CLOOK(requests, n, head);

    return 0;
}
