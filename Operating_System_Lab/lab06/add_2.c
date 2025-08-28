// sjf_np.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, at, bt, ct, tat, wt, completed;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process p[n];

    for(int i=0;i<n;i++) {
        p[i].pid=i+1;
        printf("Enter AT & BT for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].completed=0;
    }

    int completed=0, t=0, totalTAT=0,totalWT=0;
    while(completed<n) {
        int minIndex=-1;
        int minBT=9999;

        for(int i=0;i<n;i++) {
            if(p[i].at<=t && !p[i].completed && p[i].bt<minBT) {
                minBT=p[i].bt;
                minIndex=i;
            }
        }

        if(minIndex==-1) { t++; continue; }

        p[minIndex].ct=t+p[minIndex].bt;
        p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
        p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
        t=p[minIndex].ct;
        p[minIndex].completed=1;
        totalTAT+=p[minIndex].tat;
        totalWT+=p[minIndex].wt;
        completed++;
    }

    printf("\nNon-preemptive SJF Scheduling\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    printf("Avg TAT=%.2f, Avg WT=%.2f\n",(float)totalTAT/n,(float)totalWT/n);

    return 0;
}
