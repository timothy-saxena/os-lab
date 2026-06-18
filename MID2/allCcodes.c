/* ##### PAGING */
#include <stdio.h>

int main() {
    int page[10];
    int n, ps, pno, off, frame;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page size: ");
    scanf("%d", &ps);

    printf("Enter frame number for each page:\n");

    for (int i = 0; i < n; i++) {
        printf("Page %d: ", i);
        scanf("%d", &page[i]);
    }

    printf("Enter page number and offset: ");
    scanf("%d%d", &pno, &off);

    frame = page[pno];

    if (frame == -1) {
        printf("Page Fault\n");
    } else {
        int physical_address;

        physical_address = frame * ps + off;

        printf("Frame Number = %d\n", frame);
        printf("Physical Address = %d\n", physical_address);
    }

    return 0;
}
/* ##### SEGMENTATION */
#include <stdio.h>

int main() {
    int numSeg;

    printf("Enter number of segments: ");
    scanf("%d", &numSeg);

    int segTable[10][2];  // [Limit][Base]

    printf("\nEnter Limit and Base Address for each segment:\n");

    for (int i = 0; i < numSeg; i++) {
        printf("Segment %d: ", i);
        scanf("%d %d", &segTable[i][0], &segTable[i][1]);
    }

    int segNo, offset;

    printf("\nEnter Segment Number and Offset: ");
    scanf("%d %d", &segNo, &offset);

    if (segNo < 0 || segNo >= numSeg) {
        printf("Invalid Segment Number\n");
    } else if (offset < 0 || offset >= segTable[segNo][0]) {
        printf("Invalid Offset (exceeds limit)\n");
    } else {
        int base = segTable[segNo][1];
        int physicalAddress = base + offset;

        printf("Base Address = %d\n", base);
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
}

/* ##### FIFO PR */
#include <stdio.h>
int main() {
    int nof, nor;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages in reference string: ");
    scanf("%d", &nor);

    int ref[50];
    printf("Enter reference string:\n");

    for (int i = 0; i < nor; i++) scanf("%d", &ref[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;
    int victim = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;
        // checking for page hit
        for (int j = 0; j < nof; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[victim] = ref[i];
            victim = (victim + 1) % nof;
            pageFaults++;
        }

        printf("%d\t", ref[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}

/* ##### LRU PR */
#include <stdio.h>

int main() {
    int nof, nor;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages: ");
    scanf("%d", &nor);

    int ref[50];

    printf("Enter reference string:\n");

    for (int i = 0; i < nor; i++) scanf("%d", &ref[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;
        // checking for page hit
        for (int j = 0; j < nof; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1;
            // checking for empty frame
            for (int j = 0; j < nof; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }
            // Need replacement
            if (pos == -1) {
                int lruIndex = i;
                pos = 0;

                for (int j = 0; j < nof; j++) {
                    int k;

                    for (k = i - 1; k >= 0; k--) {
                        if (frame[j] == ref[k]) break;
                    }

                    if (k < lruIndex) {
                        lruIndex = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = ref[i];
            pageFaults++;
        }

        printf("%d\t", ref[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}
/* ##### Optimal PR */
#include <stdio.h>

int main() {
    int nof, nor;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages: ");
    scanf("%d", &nor);

    int pages[50];

    printf("Enter reference string:\n");

    for (int i = 0; i < nor; i++) scanf("%d", &pages[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;

        // Check page hit
        for (int j = 0; j < nof; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1;

            // Find empty frame
            for (int j = 0; j < nof; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Need replacement
            if (pos == -1) {
                int farthest = -1;

                for (int j = 0; j < nof; j++) {
                    int k;

                    for (k = i + 1; k < nor; k++) {
                        if (frame[j] == pages[k]) break;
                    }

                    // Never used again
                    if (k == nor) {
                        pos = j;
                        break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}
/* ##### Unnamed Pipe */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd[2];
    char write_msg[100];
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    // Parent Process
    if (pid > 0) {
        close(fd[0]);  // Close read end
        printf("Enter message: ");
        scanf("%s", write_msg);
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }

    // Child Process
    else {
        close(fd[1]);  // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }
}
/* ##### Shared Memory */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid;
    shmid = shmget(2345, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    char *shared_memory;
    shared_memory = (char *)shmat(shmid, NULL, 0);
    printf("ID %d", shmid);
    printf("Attach loc: %p", shared_memory);

    char msg[100];
    printf("enter something: ");
    scanf("%s", msg);

    strcpy(shared_memory, msg);
    printf("value: %s", shared_memory);
}
/* ##### fifo pipe send */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char msg[100];

    mkfifo(FIFO_NAME, 0666);

    fd = open(FIFO_NAME, O_WRONLY);

    printf("Enter data: ");
    fgets(msg, sizeof(msg), stdin);

    write(fd, msg, strlen(msg) + 1);

    close(fd);
}
/* ##### fifo pipe recieve */
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char msg[100];

    fd = open(FIFO_NAME, O_RDONLY);

    read(fd, msg, sizeof(msg));

    printf("Received: %s", msg);

    close(fd);
}
/* ##### producer consumer pnc */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

int buffer[5];
sem_t m, f, e;
int front = 0, rear = 0;

void *producer(void *args) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&e);
        sem_wait(&m);

        rear = (rear + 1) % 5;
        buffer[rear] = i;
        printf("Produced %d\n", i);

        sleep(1);

        sem_post(&m);
        sem_post(&f);
    }
    return NULL;
}

void *consumer(void *args) {
    int item;

    for (int i = 0; i < 10; i++) {
        sem_wait(&f);
        sem_wait(&m);

        front = (front + 1) % 5;
        item = buffer[front];
        printf("Consumed %d\n", item);

        sleep(1);

        sem_post(&m);
        sem_post(&e);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&m, 0, 1);
    sem_init(&e, 0, 5);
    sem_init(&f, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
/* ##### msg send*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512

struct msg {
    long type;
    char text[MAX];
};

int main() {
    int msgid;
    msgid = msgget(12345, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msg m;

    while (1) {
        printf("Enter message: ");
        fgets(m.text, MAX, stdin);

        m.type = 1;

        msgsnd(msgid, &m, strlen(m.text) + 1, 0);

        if (strncmp(m.text, "end", 3) == 0) break;
    }
}
/* ##### msg rcv*/
include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512

    struct msg {
    long type;
    char text[MAX];
};

int main() {
    int msgid;
    msgid = msgget(12345, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    struct msg m;
    while (1) {
        msgrcv(msgid, &m, MAX, 0, 0);

        printf("Received: %s", m.text);

        if (strncmp(m.text, "end", 3) == 0) break;
    }

    msgctl(msgid, IPC_RMID, NULL);
}
/* ##### bank*/
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
void bankersAlgorithm() {
    int finished[MAX] = {0};
    int safeSequence[MAX];
    int count = 0;
    // run till we cross total processes
    while (count < numProcesses) {
        int found = 0;
        // run for every process
        for (int i = 0; i < numProcesses; i++) {
            if (finished[i] == 0) {
                int canExecute = 1;
                // do we have enough resources to exectue this process
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                // yes we can
                if (canExecute == 1) {
                    for (int j = 0; j < numResources; j++) {
                        available[j] += allocation[i][j];
                    }

                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        // not a single process can execute
        if (found == 0) {
            printf("\nSystem is NOT in a safe state (Deadlock possible)\n");
            return;
        }
    }
    // while loop ends
    printf("\nSystem is in SAFE state\n");
    printf("Safe sequence: ");

    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }
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
