#include <pthread.h>
#include <iostream>

int main() {
    const pthread_t id = pthread_self();
    pthread_setname_np(id, "Main thread");

    char str[100];
    int buffLen = 100;
    pthread_getname_np(id, str, buffLen);
    std::cout<<id<<" "<<str<<"\n";
    return 0;
}