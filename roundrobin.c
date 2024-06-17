#include <stdio.h>
#include <stdbool.h>

void main() {
    int i, n, time = 0, remain, flag = 0, quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    int wt[10], tat[10]; // Arrays to store waiting time and turnaround time for each process
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // Copy burst time to remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= quantum;
            time += quantum;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            wt[i] = time - at[i] - bt[i];
            tat[i] = time - at[i];
            printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, tat[i], wt[i]);
            wait_time += wt[i];
            turnaround_time += tat[i];
            flag = 0;
        }

        if (i == n - 1)
            i = 0; 
        else if (at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %f\n", (float) wait_time / n);
    printf("Average Turnaround Time = %f\n", (float) turnaround_time / n);

    // Printing the final table of WT and TAT for each process
    printf("\nFinal Table:\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
}
 