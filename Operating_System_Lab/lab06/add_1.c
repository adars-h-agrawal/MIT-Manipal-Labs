// fcfs.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, at, bt, ct, tat, wt;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    Process p[n];

    for(int i=0;i<n;i++) {
        p[i].pid=i+1;
        printf("Enter AT BT for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    // Sort by AT
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at > p[j+1].at) {
                Process t=p[j]; p[j]=p[j+1]; p[j+1]=t;
            }

    int t=0,totalWT=0,totalTAT=0;
    for(int i=0;i<n;i++) {
        if(t<p[i].at) t=p[i].at; // CPU idle
        t+=p[i].bt;
        p[i].ct=t;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        totalWT+=p[i].wt;
        totalTAT+=p[i].tat;
    }

    printf("\nFCFS Scheduling\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    printf("Avg TAT=%.2f, Avg WT=%.2f\n",(float)totalTAT/n,(float)totalWT/n);

    return 0;
}
