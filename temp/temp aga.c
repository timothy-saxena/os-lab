#include <stdio.h>

int max[10][10], alloc[10][10], need[10][10];
int avail[10], finish[10];
int n, r;

int main() {
    int i, j, k, count = 0, safe[10];

    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &r);

    printf("Enter Max matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d", &max[i][j]);

    printf("Enter Allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Available resources:\n");
    for(j=0;j<r;j++)
        scanf("%d", &avail[j]);

    // Need = Max - Allocation
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i=0;i<n;i++) finish[i] = 0;

    while(count < n) {
        int found = 0;

        for(i=0;i<n;i++) {
            if(!finish[i]) {
                for(j=0;j<r;j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == r) { // can execute
                    for(k=0;k<r;k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found) {
            printf("System is NOT safe\n");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ", safe[i]);

    return 0;
}