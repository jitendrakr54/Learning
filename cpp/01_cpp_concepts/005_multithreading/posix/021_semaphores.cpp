// sem_wait() : it checks the semaphore's value
//              if s == 0, then thread will wait on that semaphore
//              if s > 0, then it's gonna decrement it and starts executing, not gonna wait
// sem_post() : it increments semaphore's value
// Semphore : It's sort of mutex with counter on it
// It locks multiple times but between multiple threads
// you could only lock a mutex in one single thread you could lock it twice in the same thread
// but you cannot lock it twice on different threads
// Semaphores are used for limiting access to a resource
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void* args) {
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread: %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
    return 0;
}

int main() {
    pthread_t t[THREAD_NUM];
    sem_init(&semaphore, 0, 2);
    for(int i=0; i<THREAD_NUM; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i], NULL, &routine, a) != 0) {
            printf("Failed to create thread!");
            return 1;
        }
    }

    for(int i=0; i<THREAD_NUM; i++) {
        if(pthread_join(t[i], NULL) != 0) {
            printf("Failed to join thread!");
            return 1;
        }
    }
    sem_destroy(&semaphore);
    return 0;
}