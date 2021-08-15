#include <cstdio>
#include <cstdlib>
#include <pthread.h>

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void* sumArray(void* arg) {
    int index = *(int*)arg;
    int sum = 0;
    for(int i=0; i<5; i++) {
        sum += prime[index+i];
    }
    *(int*)arg = sum;
    return arg;
}

int main() {
    pthread_t t[2];
    for(int i=0; i<2; i++) {
        int *a = (int*)malloc(sizeof(int));
        *a = i*5;
        if(pthread_create(&t[i], NULL, &sumArray, a) != 0) {
            perror("Failed to create thread!\n");
        }
    }

    int globalSum = 0;
    for(int i=0; i<2; i++) {
        int *r;
        if(pthread_join(t[i], (void**)&r) != 0) {
            perror("Failed to join thread!\n");
        }
        globalSum += *r;
        free(r);
    }
    printf("Sum: %d\n", globalSum);
    return 0;
}