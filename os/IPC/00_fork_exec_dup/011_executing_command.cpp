// exec() -> load a program into memory and then execute it
// In this code, program like "ping", "ls" is executed
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if(pid < 0) {
        return 1;
    } else if(pid == 0) {
        printf("Child pid: %d\n", getpid());
        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        // execlp("/bin/ls", "ls", NULL);
        printf("hello!");
        // exit(0);
    } else {
        int p = wait(NULL);
        printf("pid: %d\n", p);
        printf("Success!\n");
    }
    return 0;
}