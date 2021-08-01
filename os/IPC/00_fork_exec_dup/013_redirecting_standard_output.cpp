// Problem: Write output of ping to file instead of terminal
// Solution: Writing to terminal refers to STDOUT, 
// So if we could somehow swap STDOUT file discriptor(1) to opened file descriptor(4) then
// it is possible
// dup2() can help for this
// int dup2(int __fd, int __fd2)
// Duplicate FD to FD2, closing FD2 and making it open on the same file.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

int main() {
    int pid = fork();
    if(pid < 0) {
        return 1;
    } else if(pid == 0) {
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if(file == -1) {
            return 2;
        }
        printf("The fd to pingResults: %d\n", file);
        dup2(file, STDOUT_FILENO);
        close(file);

        int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
        // execlp("/bin/ls", "ls", NULL);
        printf("err: %d", err);
        if(err = -1) {
            printf("Could not find program to execute!\n");
            return 3;
        }
    } else {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode == 0) {
                printf("Success!\n");
            } else {
                printf("Failed with error code: %d\n", statusCode);
            }
        }
    }
    return 0;
}