#include <stdio.h>
#include <stdlib.h>

// Structure for a process
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int deadline;
    int period;
    int remaining_time;
    int completed;
} Process;

// Comparator for sorting by period (Rate Monotonic)
int comparePeriod(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->period - p2->period;
}

// Comparator for sorting by earliest deadline (EDF)
int compareDeadline(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->deadline - p2->deadline;
}

// Rate Monotonic Scheduling simulation
void rateMonotonic(Process processes[], int n, int hyperperiod) {
    printf("Rate Monotonic Scheduling order of execution (pid:time):\n");
    
    qsort(processes, n, sizeof(Process), comparePeriod);
    
    int time;
    for(time = 0; time < hyperperiod; time++) {
        int i, selected = -1;
        for(i = 0; i < n; i++) {
            if(processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                selected = i;
                break;  // Highest priority found (shortest period)
            }
        }
        if(selected != -1) {
            printf("%d:%d ", processes[selected].pid, time);
            processes[selected].remaining_time--;

            // If process completed its burst time, it is ready for next period
            if(processes[selected].remaining_time == 0) {
                processes[selected].arrival_time += processes[selected].period;
                processes[selected].remaining_time = processes[selected].burst_time;
            }
        } else {
            printf("Idle:%d ", time);
        }
    }
    printf("\n");
}

// Earliest Deadline First scheduling simulation
void earliestDeadlineFirst(Process processes[], int n, int hyperperiod) {
    printf("Earliest Deadline First Scheduling order of execution (pid:time):\n");
    
    int time;
    for(time = 0; time < hyperperiod; time++) {
        int i, selected = -1;
        int min_deadline = 100000;
        for(i = 0; i < n; i++) {
            if(processes[i].arrival_time <= time && processes[i].remaining_time > 0 && processes[i].deadline < min_deadline) {
                min_deadline = processes[i].deadline;
                selected = i;
            }
        }
        if(selected != -1) {
            printf("%d:%d ", processes[selected].pid, time);
            processes[selected].remaining_time--;

            if(processes[selected].remaining_time == 0) {
                processes[selected].arrival_time += processes[selected].period;
                processes[selected].deadline += processes[selected].period;
                processes[selected].remaining_time = processes[selected].burst_time;
            }
        } else {
            printf("Idle:%d ", time);
        }
    }
    printf("\n");
}

// Utility function to compute the least common multiple (LCM)
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Calculate hyperperiod i.e., LCM of periods
int calculateHyperperiod(Process processes[], int n) {
    int result = processes[0].period;
    for(int i = 1; i < n; i++)
        result = lcm(result, processes[i].period);
    return result;
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process processes[n];

    printf("Enter PID, Burst Time, Period (also same as deadline for RMS and initial deadline for EDF) for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].burst_time, &processes[i].period);
        // initializing arrival_time and deadline for first period
        processes[i].arrival_time = 0;
        processes[i].deadline = processes[i].period;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }

    int hyperperiod = calculateHyperperiod(processes, n);

    Process rms_processes[n];
    Process edf_processes[n];

    // Copy original data
    for(int i=0; i<n; i++){
        rms_processes[i] = processes[i];
        edf_processes[i] = processes[i];
    }

    rateMonotonic(rms_processes, n, hyperperiod);
    earliestDeadlineFirst(edf_processes, n, hyperperiod);

    return 0;
}
