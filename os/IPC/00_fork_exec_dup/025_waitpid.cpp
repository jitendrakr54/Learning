// waitpid() waits for a specific child process to finish its execution instead wait for any
// child process to finish its execution
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1 = fork();
    if(pid1 <0) {
        return 1;
    }
    if(pid1 == 0) {
        sleep(4);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    }

    int pid2 = fork();
    if(pid2 < 0) {
        return 1;
    }
    if(pid2 == 0) {
        sleep(1);
        printf("Finished execution (%d)\n", getpid());
        return 0;
    }

    // int pid1_res = wait(NULL);
    // printf("1 Waited for %d\n", pid1_res);
    // int pid2_res = wait(NULL);
    // printf("2 Waited for %d\n", pid2_res);

    // int pid1_res = waitpid(pid1, NULL, 0);
    // printf("1 Waited for %d\n", pid1_res);
    // int pid2_res = waitpid(pid2, NULL, 0);
    // printf("2 Waited for %d\n", pid2_res);

    int pid1_res = waitpid(pid1, NULL, WNOHANG);
    printf("1 Waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, WNOHANG);
    printf("2 Waited for %d\n", pid2_res);
    return 0;
}