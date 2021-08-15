// 1. The primary difference is that threads within the same process run in a shared memory space, 
//    while processes run in separate memory spaces.
// 2. Threads are not independent of one another like processes are, and as a result threads share
//    with other threads their code section, data section, and OS resources (like open files and signals).
//    But, like process, a thread has its own program counter (PC), register set, and stack space.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// int main() {
//     int pid = fork();
//     if(pid == -1) {
//         return 1;
//     }

//     printf("Process id: %d\n", getpid());
//     if(pid != 0) {
//         wait(NULL);
//     }
//     return 0;
// }



#include <pthread.h>

void* routine(void*){
    printf("Process id: %d\n", getpid());
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