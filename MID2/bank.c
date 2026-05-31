#include <stdbool.h>
#include <stdio.h>

#define MAX 100

int max[MAX][MAX];
int allocation[MAX][MAX];
int need[MAX][MAX];
int available[MAX];

int numProcesses, numResources;

void input();
void calculateNeed();
void display();
void bankersAlgorithm();

int main() {
    printf("********** Banker's Algorithm **********\n");

    input();
    calculateNeed();
    display();
    bankersAlgorithm();

    return 0;
}

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter number of resources: ");
    scanf("%d", &numResources);

    printf("Enter Max matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Available resources:\n");
    for (int j = 0; j < numResources; j++) {
        scanf("%d", &available[j]);
    }
}

void calculateNeed() {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void display() {
    printf("\nProcess\tAllocation\tMax\tNeed\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("P%d\t", i);

        for (int j = 0; j < numResources; j++) printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (int j = 0; j < numResources; j++) printf("%d ", max[i][j]);

        printf("\t");

        for (int j = 0; j < numResources; j++) printf("%d ", need[i][j]);

        printf("\n");
    }

    printf("Available: ");
    for (int j = 0; j < numResources; j++) printf("%d ", available[j]);

    printf("\n");
}
void bankersAlgorithm() {
    bool finished[MAX] = {false};
    int safeSequence[MAX];
    int count = 0;

    while (count < numProcesses) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canExecute = true;

                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    for (int j = 0; j < numResources; j++) {
                        available[j] += allocation[i][j];
                    }

                    safeSequence[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in a safe state (Deadlock possible)\n");
            return;
        }
    }
    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}
/* #include <stdbool.h>
#include <stdio.h>

#define MAX 100

int max[MAX][MAX];
int allocation[MAX][MAX];
int need[MAX][MAX];
int available[MAX];

int numProcesses, numResources;

void input();
void calculateNeed();
void display();
void bankersAlgorithm();

int main() {
    printf("********** Banker's Algorithm **********\n");

    input();
    calculateNeed();
    display();
    bankersAlgorithm();

    return 0;
}

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter number of resources: ");
    scanf("%d", &numResources);

    printf("Enter Max matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Available resources:\n");
    for (int j = 0; j < numResources; j++) {
        scanf("%d", &available[j]);
    }
}

void calculateNeed() {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void display() {
    printf("\nProcess\tAllocation\tMax\tNeed\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("P%d\t", i);

        for (int j = 0; j < numResources; j++) printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (int j = 0; j < numResources; j++) printf("%d ", max[i][j]);

        printf("\t");

        for (int j = 0; j < numResources; j++) printf("%d ", need[i][j]);

        printf("\n");
    }

    printf("Available: ");
    for (int j = 0; j < numResources; j++) printf("%d ", available[j]);

    printf("\n");
}

void bankersAlgorithm() {
    bool finished[MAX] = {false};
    int safeSequence[MAX];
    int count = 0;

    while (count < numProcesses) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (finished[i]) continue;

            int j;

            for (j = 0; j < numResources; j++) {
                if (need[i][j] > available[j]) break;
            }

            if (j == numResources) {
                for (j = 0; j < numResources; j++) {
                    available[j] += allocation[i][j];
                }

                safeSequence[count++] = i;
                finished[i] = true;
                found = true;
            }
        }

        if (!found) {
            printf("\nSystem is NOT in a safe state (Deadlock possible)\n");
            return;
        }
    }

    printf("\nSystem is in SAFE state\n");
    printf("Safe sequence: ");

    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }

    printf("\n");
} */