#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <iostream>


int main() {
    int id1 = fork();
    int id2 = fork();

    if (id1 == 0) {
        if(id2 == 0) {
            printf("We are process y\n");
        } else {
            printf("We are process x\n");
        }
    } else {
        if(id2 == 0) {
            printf("We are process z\n");
        } else {
            printf("We are the parent process!\n");
        }
    }
    // loop because one wait() will wait for any one child to finish execution
    while(wait(NULL) != -1 || errno != ECHILD) {
        printf("Waited for a child to finish\n");
    }
    return 0;
}