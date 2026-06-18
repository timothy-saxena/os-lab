#include <stdio.h>

int main() {
    /*
        1. INPUT SO MUCH STUFF
    */

    int n;
    printf("Number of processes: ");
    scanf("%d", &n);

    int pid[10];
    int at[10];
    int bt[10];
    int wt[10];
    int tat[10];

    for (int i = 0; i < n; i++) {
        printf("enter arrival and burst times");
        scanf("%d %d", &at[i], &bt[i]);
        pid[i] = i + 1;
    }
    /*
    sort acc to AT
     */
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (at[j] > at[j + 1]) {
                int temp;
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    int currTime = 0;
    for (int i = 0; i < n; i++) {
        if (currTime < at[i]) {
            currTime = at[i];
        }
        wt[i] = currTime - at[i];
        tat[i] = wt[i] + bt[i];
        currTime += bt[i];
    }

    int twt = 0;
    int ttat = 0;
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

        twt += wt[i];
        ttat += tat[i];
    }
    printf("\n");
    printf("avg wt %.2f", (float)twt / n);
    printf("avg ttat %.2f", (float)ttat / n);
}