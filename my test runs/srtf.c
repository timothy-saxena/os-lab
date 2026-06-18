#include <stdio.h>
int main() {
    /*
    1. input n,at,bt
    2. pid,bt,wt,tat,rt arrays
    3. rt[i] = bt[i]
    4. while(completed < n)
    5. find tat & totals
    6. print and averages
     */
    int n;
    printf("No of P: \n");
    scanf("%d", &n);

    int arrival_time[10];
    int rem_time[10];
    int burst_time[10];
    int wait_time[10];
    int turnaround_time[10];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival time of P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst time of P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        rem_time[i] = burst_time[i];
    }
    int completed = 0;
    int currentTime = 0;
    while (completed < n) {
        int minTime = 999;
        int shortest_job_id = -1;
        for (int i = 0; i < n; i++) {
            if (rem_time[i] > 0 && arrival_time[i] <= currentTime &&
                rem_time[i] < minTime) {
                minTime = rem_time[i];
                shortest_job_id = i;
            }
        }
        if (shortest_job_id == -1) {
            currentTime++;
            continue;
        }
        rem_time[shortest_job_id]--;
        currentTime++;

        if (rem_time[shortest_job_id] == 0) {
            completed++;
            turnaround_time[shortest_job_id] =
                currentTime - arrival_time[shortest_job_id];
            wait_time[shortest_job_id] =
                turnaround_time[shortest_job_id] - burst_time[shortest_job_id];
        }
    }

    int totalWT = 0;
    int totalTAT = 0;
    printf("\n SRTF \n");
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i],
               wait_time[i], turnaround_time[i]);

        totalWT += wait_time[i];
        totalTAT += turnaround_time[i];
    }
    printf("Average WT: %.2f \n ", (float)totalWT / n);
    printf("Average TAT: %.2f \n", (float)totalTAT / n);
}

/*
SRTF schedule the processes each unit time
*/

/*
int completed = 0;
int currentTime = 0;
while(completed < n){
    int SJ_id = -1;
    int SJ_rem_tim = 999;

    // find the SJ
    for(int i = 0; i < n; i++){
        // process should have arrived
        // process must not be completed
        // process RT must be less that minRT
        if(arrivalTime[i] <= currentTime && remainingTime[i]>0 &&
remainingTime[i] < SJ_rem_tim){ SJ_id = i; SJ_rem_tim = remainingTime[i];
        }
    }

    // incase there is no SJ
    if(SJ_id == -1){
        currentTime++;
        continue;
    }

    // exe this Sj for 1 unit time
    remainingTime[SJ_id]--;
    currentTime++;

    // check if SJ_id is completed
    if(remainingTime[SJ_id] == 0){
        completed++;
        turnaround_time[SJ_id] = currentTime - arrivalTime[SJ_id];
        wait_time[SJ_id] = turnaround_time[SJ_id]- burstTime[SJ_id];
    }
}
*/