/* FCFS
CODE 1 : FCFS WITHOUT ARRIVAL TIME
 */
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int bt[10], wt[10], tat[10];

    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    wt[0]=0;

    for(int i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(int i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];

    printf("PID\tBT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",
               i+1,bt[i],wt[i],tat[i]);
}