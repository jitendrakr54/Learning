// Get return value from thread
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void* roll_dice(void*) {
    int value = (rand() % 6) +1;
    int *result = (int*)malloc(sizeof(int));
    *result = value;
    // printf("%d\n", value);
    printf("Thread result: %p\n", result);
    return (void*)result;
}

int main() {
    srand(time(NULL));
    pthread_t t;
    if(pthread_create(&t, NULL, &roll_dice, NULL) != 0) {
        perror("falied to craete thread!");
        return 1;
    }
    int *res;
    if(pthread_join(t, (void**) &res) != 0) {
        return 2;
    }
    printf("Main res: %p\n", res);
    printf("%d\n", *res);
    return 0;
}