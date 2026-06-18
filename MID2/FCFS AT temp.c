/* FCFS AT
 */
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int pid[10], at[10], bt[10];
    int wt[10], tat[10];

    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;
        scanf("%d%d",&at[i],&bt[i]);
    }

    // Sort by arrival time
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(at[j]>at[j+1])
            {
                int temp;

                temp=at[j]; at[j]=at[j+1]; at[j+1]=temp;
                temp=bt[j]; bt[j]=bt[j+1]; bt[j+1]=temp;
                temp=pid[j]; pid[j]=pid[j+1]; pid[j+1]=temp;
            }
        }
    }

    int currentTime=0;

    for(int i=0;i<n;i++)
    {
        if(currentTime < at[i])
            currentTime = at[i];

        wt[i]=currentTime-at[i];

        tat[i]=wt[i]+bt[i];

        currentTime+=bt[i];
    }
}