#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if(pid == -1) {
        return 1;
    } else if(pid == 0) {
        while(true) {
            printf("Some text goes here!\n");
            usleep(50000);
            // sleep(2);
        }
    } else {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return 0;
}