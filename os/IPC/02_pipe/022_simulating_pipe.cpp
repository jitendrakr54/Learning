#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if(pipe(fd) == -1) {
        return 1;
    }

    int pid1 = fork();
    if(pid1 == -1) {
        return 2;
    } else if(pid1 == 0) {
        //child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO); // creates duplicate of fd[1] and pointed to STDOUT_FILENO
        close(fd[0]);   // close read end
        close(fd[1]);   // closed original write end because it's duplicated with STDOUT_FILENO
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
    }

    int pid2 = fork();
    if(pid2 == -1) {
        return 3;
    } else if(pid2 == 0) { // read end is duplicated here because grep reads from pipe(|)
        //child process 2 (grep)
        dup2(fd[0], STDIN_FILENO); // creates duplicate of fd[0] and pointed to STDIN_FILENO
        close(fd[1]);              // close write end
        close(fd[0]);              // close original read end because it's duplicated with STDIN_FILENO    
        execlp("grep", "grep", "rtt", NULL);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}