#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("No of P: \n");
    scanf("%d", &n);

    int arrival_time[10];
    int pri[10];
    int rem_time[10];
    int burst_time[10];
    int wait_time[10];
    int turnaround_time[10];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival time of P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst time of P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter Priority of P%d: ", i + 1);
        scanf("%d", &pri[i]);
        rem_time[i] = burst_time[i];
    }

    int completed = 0;
    int currentTime = 0;

    while (completed < n) {
        int high_job_id = -1;
        int highestPriority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (rem_time[i] > 0 && arrival_time[i] <= currentTime &&
                pri[i] < highestPriority) {
                highestPriority = pri[i];
                high_job_id = i;
            }
        }
        if (high_job_id == -1) {
            currentTime++;
            continue;
        }
        rem_time[high_job_id]--;
        currentTime++;

        if (rem_time[high_job_id] == 0) {
            completed++;
            turnaround_time[high_job_id] =
                currentTime - arrival_time[high_job_id];
            wait_time[high_job_id] =
                turnaround_time[high_job_id] - burst_time[high_job_id];
        }
    }

    int totalWT = 0;
    int totalTAT = 0;
    printf("\n PRI AT \n");
    printf("PID\tAT\tBT\tPRI\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i],
               burst_time[i], pri[i], wait_time[i], turnaround_time[i]);

        totalWT += wait_time[i];
        totalTAT += turnaround_time[i];
    }
    printf("Average WT: %.2f \n ", (float)totalWT / n);
    printf("Average TAT: %.2f \n", (float)totalTAT / n);
}