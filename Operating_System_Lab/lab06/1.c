#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, at, bt, ct, tat, wt, pr, rt, completed;
} Process;

void sortByArrival(Process p[], int n) {
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (p[i].at > p[j].at) {
                Process temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

/* ---------- 1. Preemptive SJF (SRTF) ---------- */
void SRTF(Process p[], int n) {
    int completed=0, t=0, minIndex=-1;
    int totalWT=0, totalTAT=0;

    for(int i=0;i<n;i++) {
        p[i].rt=p[i].bt;
        p[i].completed=0;
    }

    while(completed<n) {
        minIndex=-1;
        int minRemaining=9999;

        for(int i=0;i<n;i++) {
            if(p[i].at<=t && !p[i].completed && p[i].rt<minRemaining) {
                minRemaining=p[i].rt;
                minIndex=i;
            }
        }

        if(minIndex==-1) { t++; continue; }

        p[minIndex].rt--;
        t++;

        if(p[minIndex].rt==0){
            p[minIndex].completed=1;
            p[minIndex].ct=t;
            p[minIndex].tat=p[minIndex].ct - p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat - p[minIndex].bt;
            totalWT+=p[minIndex].wt;
            totalTAT+=p[minIndex].tat;
            completed++;
        }
    }

    printf("\nSRTF Scheduling\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    printf("Avg TAT=%.2f, Avg WT=%.2f\n",(float)totalTAT/n,(float)totalWT/n);
}

/* ---------- 2. Round Robin ---------- */
void RoundRobin(Process p[], int n, int tq) {
    int t=0, completed=0;
    int totalWT=0,totalTAT=0;
    int done;

    for(int i=0;i<n;i++) {
        p[i].rt=p[i].bt;
        p[i].completed=0;
    }

    while(completed<n) {
        done=1;
        for(int i=0;i<n;i++) {
            if(p[i].at<=t && p[i].rt>0) {
                done=0;
                if(p[i].rt>tq) {
                    t+=tq;
                    p[i].rt-=tq;
                } else {
                    t+=p[i].rt;
                    p[i].ct=t;
                    p[i].tat=p[i].ct - p[i].at;
                    p[i].wt=p[i].tat - p[i].bt;
                    totalWT+=p[i].wt;
                    totalTAT+=p[i].tat;
                    p[i].rt=0;
                    completed++;
                }
            }
        }
        if(done) t++;
    }

    printf("\nRound Robin (TQ=%d)\nPID\tAT\tBT\tCT\tTAT\tWT\n",tq);
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    printf("Avg TAT=%.2f, Avg WT=%.2f\n",(float)totalTAT/n,(float)totalWT/n);
}

/* ---------- 3. Non-preemptive Priority ---------- */
void PriorityNP(Process p[], int n) {
    int completed=0, t=0, minIndex=-1, totalWT=0, totalTAT=0;

    for(int i=0;i<n;i++) p[i].completed=0;

    while(completed<n) {
        minIndex=-1;
        int best=9999;

        for(int i=0;i<n;i++) {
            if(p[i].at<=t && !p[i].completed && p[i].pr<best) {
                best=p[i].pr; minIndex=i;
            }
        }

        if(minIndex==-1) { t++; continue; }

        t+=p[minIndex].bt;
        p[minIndex].ct=t;
        p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
        p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
        totalWT+=p[minIndex].wt;
        totalTAT+=p[minIndex].tat;
        p[minIndex].completed=1;
        completed++;
    }

    printf("\nNon-preemptive Priority Scheduling\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);

    printf("Avg TAT=%.2f, Avg WT=%.2f\n",(float)totalTAT/n,(float)totalWT/n);
}

/* ------ Main Menu ------ */
int main() {
    int n, choice, tq;
    Process p[20];
    printf("Enter number of processes: "); scanf("%d",&n);

    for(int i=0;i<n;i++) {
        p[i].pid=i+1;
        printf("Enter AT & BT of P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        printf("Enter priority of P%d: ",i+1);
        scanf("%d",&p[i].pr);
    }

    sortByArrival(p,n);

    do {
        printf("\n--- CPU Scheduling ---\n1. SRTF\n2. Round Robin\n3. Priority (Non-preemptive)\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: SRTF(p,n); break;
            case 2: printf("Enter Time Quantum: "); scanf("%d",&tq); RoundRobin(p,n,tq); break;
            case 3: PriorityNP(p,n); break;
        }
    } while(choice!=4);

    return 0;
}
