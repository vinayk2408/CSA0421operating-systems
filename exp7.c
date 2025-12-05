#include <stdio.h>

struct process {
    int pid, bt, at, wt, tat;
};

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i+1;
    }

    int completed = 0, current_time = 0;
    int is_completed[n];
    for(i=0;i<n;i++) is_completed[i] = 0;

    while(completed != n){
        int idx = -1;
        int min_bt = 10000;
        for(i=0;i<n;i++){
            if(p[i].at <= current_time && !is_completed[i] && p[i].bt < min_bt){
                min_bt = p[i].bt;
                idx = i;
            }
        }

        if(idx != -1){
            current_time += p[idx].bt;
            p[idx].tat = current_time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            is_completed[idx] = 1;
            completed++;
        } else {
            current_time++;
        }
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);

    return 0;
}
