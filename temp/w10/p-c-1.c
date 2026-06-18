#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, full, empty;

void *produce(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&empty);   // wait for empty slot
        sem_wait(&mutex);   // enter critical section

        buffer[in] = i;
        printf("Produced: %d at index %d\n", i, in);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&full);    // increase filled slots

        sleep(1);
    }
    return NULL;
}

void *consume(void *arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);    // wait for filled slot
        sem_wait(&mutex);   // enter critical section

        int item = buffer[out];
        printf("Consumed: %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&empty);   // increase empty slots

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    pthread_create(&producer_thread, NULL, produce, NULL);
    pthread_create(&consumer_thread, NULL, consume, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}