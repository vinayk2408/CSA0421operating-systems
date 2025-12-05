#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float avg_wt=0, avg_tat=0;

    for(i=0;i<n;i++){
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Process\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("Average WT=%.2f\nAverage TAT=%.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}
