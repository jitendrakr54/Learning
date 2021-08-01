// Stopping and continuing the execution of a process

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// int main() {
//     int pid = fork();
//     if(pid == -1) {
//         return 1;
//     } else if(pid == 0) {
//         while(true) {
//             printf("Some text goes here!\n");
//             usleep(50000);
//         }
//     } else {
//         kill(pid, SIGSTOP);
//         sleep(1);
//         kill(pid, SIGCONT);
//         sleep(1);
//         kill(pid, SIGKILL);
//         wait(NULL);
//     }
//     return 0;
// }

int main() {
    int pid = fork();
    if(pid == -1) {
        return 1;
    } else if(pid == 0) {
        while(true) {
            printf("Some text goes here!\n");
            usleep(50000);
        }
    } else {
        kill(pid, SIGSTOP);
        int t;
        do {
            printf("Time in seconds for execution: ");
            scanf("%d", &t);
            kill(pid, SIGCONT);
            sleep(t);
            kill(pid, SIGSTOP);
        } while (t>0);
        
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return 0;
}