// A thread is a path of execution within a process. A process can contain multiple threads
// A thread is also known as lightweight process. The idea is to achieve parallelism by dividing a
//  process into multiple threads. For example, in a browser, multiple tabs can be different threads.
//  MS Word uses multiple threads: one thread to format the text, another thread to process inputs, etc.

#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

void* routine(void*) {
    printf("test from threads\n");
    sleep(3);
    printf("Ending threads\n");
    return nullptr;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}