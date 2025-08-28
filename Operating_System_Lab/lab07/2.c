// readers_writers.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readcount = 0;

void *reader(void *param) {
    int id = *((int *)param);
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("Reader %d is reading\n", id);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);

    pthread_exit(0);
}

void *writer(void *param) {
    int id = *((int *)param);
    sem_wait(&wrt);
    printf("Writer %d is writing\n", id);
    sleep(2);
    sem_post(&wrt);

    pthread_exit(0);
}

int main() {
    int nr = 3, nw = 2;
    pthread_t r[3], w[2];
    int i, rid[3], wid[2];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader and writer threads
    for (i=0;i<nr;i++) {
        rid[i]=i+1;
        pthread_create(&r[i], NULL, reader, &rid[i]);
    }
    for (i=0;i<nw;i++) {
        wid[i]=i+1;
        pthread_create(&w[i], NULL, writer, &wid[i]);
    }
    // Wait for all
    for (i=0;i<nr;i++) pthread_join(r[i],NULL);
    for (i=0;i<nw;i++) pthread_join(w[i],NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
