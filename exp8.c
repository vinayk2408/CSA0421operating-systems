#include <stdio.h>

int main() {
    int n, i, time_quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], rt[n], wt[n], tat[n];
    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    int t = 0, done = 0;
    while(done < n){
        done = 0;
        for(i=0;i<n;i++){
            if(rt[i] > 0){
                if(rt[i] > time_quantum){
                    t += time_quantum;
                    rt[i] -= time_quantum;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i] - at[i];
                    rt[i] = 0;
                }
            }
            if(rt[i] == 0) done++;
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
