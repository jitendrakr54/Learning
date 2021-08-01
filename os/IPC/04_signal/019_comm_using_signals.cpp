#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;

void handle_sigusr1(int sig) {
    if(x == 0) {
        printf("\n(HINT) Remember that multiplication is repitative addition!\n");
    }
}

int main() {
    int pid = fork();
    if(pid == -1) {
        return 1;
    } else if(pid == 0) {
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler= &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);
        
        printf("What is the result of 3 * 5?: ");
        scanf("%d", &x);
        if(x == 15) {
            printf("Right!\n");
        } else {
            printf("Wrong!\n");
        }
        wait(NULL);
    }
    return 0;
}