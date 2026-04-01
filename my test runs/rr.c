#include <stdio.h>
int main() {
    /*
        1. input n,tq, bt
        2. wt,rt,tat arrays
        3. rr while loop
        4. find tat, totals
        5. print
        6. averages

    */
    int n;
    printf("No of P: \n");
    scanf("%d", &n);

    int tq;
    printf("TQ: \n");
    scanf("%d", &tq);

    int burst_time[10];
    int rem_time[10];
    int wait_time[10];
    int turnaround_time[10];

    for (int i = 0; i < n; i++) {
        printf("Enter Burst time of P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        rem_time[i] = burst_time[i];
    }

    int allDone = 0;
    int current_time = 0;

    while (!allDone) {
        allDone = 1;
        for (int i = 0; i < n; i++) {
            if (rem_time[i] > 0) {
                allDone = 0;
                if (rem_time[i] > tq) {
                    current_time += tq;
                    rem_time[i] -= tq;
                } else {
                    current_time += rem_time[i];
                    rem_time[i] = 0;
                    wait_time[i] = current_time - burst_time[i];
                }
            }
        }
    }

    int totalWT = 0;
    int totalTAT = 0;
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
        totalWT += wait_time[i];
        totalTAT += turnaround_time[i];
    }

    printf("\n RR \n");
    printf("PID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, burst_time[i], wait_time[i],
               turnaround_time[i]);
    }

    printf("Average WT: %.2f \n ", (float)totalWT / n);
    printf("Average TAT: %.2f \n", (float)totalTAT / n);
}