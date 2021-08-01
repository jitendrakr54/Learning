// Create multiple thread using for loop
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

int mails= 0;
pthread_mutex_t mutex;
void* routine(void*) {
    for(int i=0; i<10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}

// int main() {
//     pthread_t t[4];
//     pthread_mutex_init(&mutex, NULL);

//     for(int i=0; i<4; i++) {
//         if(pthread_create(t+i, NULL, &routine, NULL) != 0) {
//             perror("falied to craete thread!");
//             return 1;
//         }
//         printf("Thread %d has strted\n", i);
//         if (pthread_join(t[i], NULL) != 0) {
//             return 5;
//         }
//         printf("Thread %d has finished execution\n", i);
//     }
//     std::cout<<mails<<"\n";
//     pthread_mutex_destroy(&mutex);
//     return 0;
// }

// Above approach of waiting for thread is wrong
// Because thread is created and we are just waiting for that thread to finish 
// which result into sequential exacution

int main() {
    pthread_t t[4];
    pthread_mutex_init(&mutex, NULL);

    for(int i=0; i<4; i++) {
        if(pthread_create(t+i, NULL, &routine, NULL) != 0) {
            perror("falied to craete thread!");
            return 1;
        }
        printf("Thread %d has strted\n", i);
    }

    for(int i=0; i<4; i++) {
        if (pthread_join(t[i], NULL) != 0) {
            return 2;
        }
        printf("Thread %d has finished execution\n", i);
    }
    std::cout<<mails<<"\n";
    pthread_mutex_destroy(&mutex);
    return 0;
}