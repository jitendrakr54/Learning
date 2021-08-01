// How to pass arguments to thread in c
// Create 10 threads, each taking a unique prime from the primes array and print it on the screen'

#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
    // sleep(1);
    int index = *(int*)arg;
    printf("%d ", primes[index]);
    free(arg);
    return 0;
}

int main() {
    pthread_t t[10];
    int i;
    for(i=0; i<10; i++) {
        int* a = (int*)malloc(sizeof(int));
        *a = i;
        if(pthread_create(&t[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }
    
    for(i=0; i<10; i++) {
        if(pthread_join(t[i], NULL) != 0) {
            perror("Failed to create thread");
        }
    }
    
    return 0;
}