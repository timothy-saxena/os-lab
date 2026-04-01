#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5

int buf[N], in = 0, out = 0;
sem_t m, f, e;

void *prod(void *p) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&e);
        sem_wait(&m);

        buf[in] = i;
        in = (in + 1) % N;

        sem_post(&m);
        sem_post(&f);
    }
}

void *cons(void *p) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&f);
        sem_wait(&m);

        int x = buf[out];
        out = (out + 1) % N;

        sem_post(&m);
        sem_post(&e);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&m, 0, 1);
    sem_init(&f, 0, 0);
    sem_init(&e, 0, N);

    pthread_create(&p, 0, prod, 0);
    pthread_create(&c, 0, cons, 0);

    pthread_join(p, 0);
    pthread_join(c, 0);
}