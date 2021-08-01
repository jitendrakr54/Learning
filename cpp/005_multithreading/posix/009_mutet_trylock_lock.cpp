// pthread_mutex_lock -> process waits for lock if it doesn't get
// pthread_mutex_trylock -> process doesn't wait for lock if it doesn't get

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;

void* routine(void*) {
    if(pthread_mutex_trylock(&mutex) == 0) {
        printf("Got lock!\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Didn't get lock!\n");
    }
    return 0;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t th[4];
    for(int i = 0; i<4; i++) {
        if(pthread_create(&th[i], NULL, &routine, NULL) == -1){
            printf("Error in creating thread!\n");
        }
    }

    for(int i = 0; i<4; i++) {
        if(pthread_join(th[i], NULL) == -1){
            printf("Error in creating thread!\n");
        }
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}