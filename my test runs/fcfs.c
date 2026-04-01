#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes. \n");
    scanf("%d", &n);

    int burstTime[10];
    for (int i = 0; i < n; i++) {
        printf("Enter BT of P%d: \n", i + 1);
        scanf("%d", &burstTime[i]);
    }

    int wt[10];
    int turnAroundtime[10];

    int totalWT = 0;
    int totalTAT = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            wt[i] = 0;
        } else {
            wt[i] = wt[i - 1] + burstTime[i - 1];
        }
        turnAroundtime[i] = wt[i] + burstTime[i];

        totalTAT += turnAroundtime[i];
        totalWT += wt[i];
    }

    printf("\n FCFS \n");
    printf("P\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, burstTime[i], wt[i],
               turnAroundtime[i]);
    }

    printf("\n Average WT: %.2f", (float)totalWT / n);
    printf("\n Average TAT: %.2f", (float)totalTAT / n);
}