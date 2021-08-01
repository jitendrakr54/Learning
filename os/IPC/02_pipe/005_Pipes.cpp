// Communication between processes using pipes
// Always between parent and child
// Always unidirectional

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    int fd[2];
    // fd[0] - read
    // fd[1] - write
    if(pipe(fd) == -1) {
        printf("An error occured with opening the pipe!\n");
        return 1;
    }
    int id = fork();
    if(id == -1) {
        printf("An error occured with fork!\n");
        return 2;
    } else if(id == 0) {
        close(fd[0]); // Close read file descriptor
        int x;
        printf("Enter a number: ");
        scanf("%d", &x);
        if(write(fd[1], &x, sizeof(int)) == -1) {
            printf("An error occured with write!\n");
            return 2;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1) {
            printf("An error occured with read!\n");
            return 3;
        }
        printf("Hello\n");
        printf("Got from child process: %d\n", y);
        close(fd[0]);
    }
    return 0;
} 