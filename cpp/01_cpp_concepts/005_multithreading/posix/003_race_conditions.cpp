#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

int mails= 0;

void* routine(void*) {
    for(int i=0; i<100000; i++) {
        mails++;
    }
    return 0;
}

int main() {
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    }
    std::cout<<mails<<"\n";
    return 0;
}