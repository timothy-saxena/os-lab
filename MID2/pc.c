/* #include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

int buffer[5];
int front = 0, rear = 0;

sem_t mutex, full, empty;

void *producer(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        rear = (rear + 1) % 5;
        buffer[rear] = i;

        printf("Produced: %d\n", i);

        sleep(1);

        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;

    for (int i = 0; i < 10; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        front = (front + 1) % 5;
        item = buffer[front];

        printf("Consumed: %d\n", item);

        sleep(1);

        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
} */
