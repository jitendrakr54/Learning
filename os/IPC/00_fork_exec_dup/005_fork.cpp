#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int value = 10;

int main() {
    pid_t pid;
    pid = fork();

    if(pid == 0) { 
        value += 5;
        printf("CHILD: value=%d\n", value);
    } else if(pid > 0) {
        // wait(NULL);
        value += 2;
        printf("PARENT: value=%d\n", value);
        exit(0);
    }
}