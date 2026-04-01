#include <stdio.h>
int main() {
    printf("Enter number of processes: ");
    int n;
    scanf("%d", &n);
    int burstTime[10];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time of process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    int waitingTime[10];
    int turnaroundTime[10];
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    // FCFS calculation !!!!!!!!!!
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            waitingTime[i] = 0;
        } else {
            waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        }
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    printf("\nFCFS Scheduling\n");
    printf("---------------------------------\n");
    printf("PID\tBT\tWT\tTAT\n");
    printf("---------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, burstTime[i], waitingTime[i],
               turnaroundTime[i]);
    }
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("---------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time = %.2f\n", avgTurnaroundTime);
    return 0;
}