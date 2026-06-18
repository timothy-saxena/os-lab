#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;

int buffer[3];
int in = 0, out = 0;

int wait(int s) { return --s; }
int signal(int s) { return ++s; }

void producer() {
    if (mutex == 1 && empty > 0) {
        mutex = wait(mutex);

        int item;
        printf("Enter item to produce: ");
        scanf("%d", &item);

        buffer[in] = item;
        in = (in + 1) % 3;

        full = signal(full);
        empty = wait(empty);

        printf("Produced item: %d\n", item);

        mutex = signal(mutex);
    } else {
        printf("Buffer Full!\n");
    }
}

void consumer() {
    if (mutex == 1 && full > 0) {
        mutex = wait(mutex);

        int item = buffer[out];
        out = (out + 1) % 3;

        full = wait(full);
        empty = signal(empty);

        printf("Consumed item: %d\n", item);

        mutex = signal(mutex);
    } else {
        printf("Buffer Empty!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}