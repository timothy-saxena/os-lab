#include <stdio.h>
int main() {
    /*
    1. input pid,bt and at
    2. sort acc to at
    3. schedule it
    4. print table
    5. find averages
    */

    int n;
    printf("No of P: \n");
    scanf("%d", &n);

    int process_id[10];
    int arrival_time[10];
    int burst_time[10];
    int wait_time[10];
    int turnaround_time[10];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival time of P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst time of P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process_id[i] = i + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                int temp;
                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = process_id[j];
                process_id[j] = process_id[j + 1];
                process_id[j + 1] = temp;
            }
        }
    }
    int start_time = 0;
    int totalWT = 0;
    int totalTAT = 0;
    for (int i = 0; i < n; i++) {
        if (start_time < arrival_time[i]) {
            start_time = arrival_time[i];
        }
        wait_time[i] = start_time - arrival_time[i];
        turnaround_time[i] = wait_time[i] + burst_time[i];
        start_time += burst_time[i];
    }

    printf("\n FCFS AT \n");
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", process_id[i], arrival_time[i],
               burst_time[i], wait_time[i], turnaround_time[i]);
        totalWT += wait_time[i];
        totalTAT += turnaround_time[i];
    }

    printf("Average WT: %.2f \n ", (float)totalWT / n);
    printf("Average TAT: %.2f \n", (float)totalTAT / n);
}