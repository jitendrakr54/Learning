// Difference between Binary Semaphores and Mutexes
// Mutexes have concept of ownership, so whenever a thread is locking a mutex
// then mutex expect unlock by the the same thread, if it isn't then undefined behavior
// But with semaphore, this is not the case, sem_wait() can be done by one thread and sem_post() by
// another thread
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

int fuel = 50;
pthread_mutex_t fuelMutex;
sem_t semFuel;

void* routine(void*) {
    // pthread_mutex_lock(&fuelMutex);
    sem_wait(&semFuel);
    fuel += 50;
    printf("Current value is %d\n", fuel);
    // pthread_mutex_unlock(&fuelMutex);
    sem_post(&semFuel);
    return 0;
}

int main() {
    pthread_t t[THREAD_NUM];
    // pthread_mutex_init(&fuelMutex, NULL);
    sem_init(&semFuel, 0, 1);
    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_create(&t[i], NULL, &routine, NULL)) {
            return 1;
        }
    }
    
    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(t[i], NULL)) {
            return 2;
        }
    }
    // pthread_mutex_destroy(&fuelMutex);
    sem_destroy(&semFuel);
    return 0;
}