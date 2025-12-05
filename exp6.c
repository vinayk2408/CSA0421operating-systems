#include <stdio.h>

struct process {
    int pid;
    int bt; // burst time
    int pri; // priority (lower value means higher priority)
    int at; // arrival time
    int wt; // waiting time
    int tat; // turnaround time
};

int main() {
    int n, i, j, total=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    
    for(i=0;i<n;i++){
        printf("Enter arrival time, burst time and priority for process %d: ", i+1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pri);
        p[i].pid = i+1;
    }

    int remaining_bt[n];
    for(i=0;i<n;i++) remaining_bt[i] = p[i].bt;
    
    int completed = 0, current_time = 0;
    while(completed < n){
        int idx = -1;
        int highest_priority = 10000; // large number
        
        for(i=0;i<n;i++){
            if(p[i].at <= current_time && remaining_bt[i] > 0 && p[i].pri < highest_priority){
                highest_priority = p[i].pri;
                idx = i;
            }
        }

        if(idx != -1){
            remaining_bt[idx]--;
            current_time++;

            if(remaining_bt[idx] == 0){
                completed++;
                p[idx].tat = current_time - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        } else {
            current_time++;
        }
    }

    printf("\nPID\tAT\tBT\tPriority\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pri, p[i].wt, p[i].tat);

    return 0;
}
