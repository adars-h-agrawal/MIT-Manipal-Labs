// dining_philosophers.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];

void *philosopher(void *num) {
    int id = *((int *)num);

    printf("Philosopher %d is thinking\n", id);
    sleep(rand() % 3);

    sem_wait(&forks[id]);
    sem_wait(&forks[(id+1)%N]); // pick both forks

    printf("Philosopher %d is eating\n", id);
    sleep(1);

    sem_post(&forks[id]);
    sem_post(&forks[(id+1)%N]); // put down forks

    printf("Philosopher %d finished eating\n", id);

    pthread_exit(0);
}

int main() {
    pthread_t philo[N];
    int i, id[N];

    for(i=0;i<N;i++) sem_init(&forks[i],0,1);

    for(i=0;i<N;i++) {
        id[i]=i;
        pthread_create(&philo[i],NULL,philosopher,&id[i]);
    }
    for(i=0;i<N;i++)
        pthread_join(philo[i],NULL);

    for(i=0;i<N;i++) sem_destroy(&forks[i]);
    return 0;
}
