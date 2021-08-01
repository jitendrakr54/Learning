// All the system resources are shared between threads while each process is different from other
// means each process has their own copy of resource
// eg: In below example, x is shared between threads while parent and chld process has their own copy
// of x, so x modified by child process doesn't affect parent's x.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// int main() {
//     int x = 2;
//     int pid = fork();
//     if(pid == -1) {
//         return 1;
//     }

//     if(pid == 0) {
//         x++;
//     }
//     sleep(2);
//     printf("Value of x: %d\n", x);
//     if(pid != 0) {
//         wait(NULL);
//     }
//     return 0;
// }



#include <pthread.h>

int x = 2;
void* routine1(void*){
    x++;
    sleep(2);
    printf("Value of x: %d\n", x);
    return 0;
}

void* routine2(void*){
    sleep(2);
    printf("Value of x: %d\n", x);
    return 0;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine1, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}