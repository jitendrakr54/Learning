
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    // 5 => 5*4 => 20
    int fd1[2]; // C => P
    int fd2[2]; // P => C
    if(pipe(fd1) == -1) { return 1; }
    if(pipe(fd2) == -1) { return 1; }

    int pid = fork();
    if(pid < 0) {
        return 2;
    } else if(pid == 0) {
        close(fd1[0]);
        close(fd2[1]);
        int x;
        if(read(fd2[0], &x, sizeof(x)) == -1) {return 3;}
        printf("Child received %d\n", x);
        x *= 4;
        if(write(fd1[1], &x, sizeof(x)) == -1) {return 4;}
        printf("Child Wrote %d\n", x);
        close(fd1[1]);
        close(fd2[0]);
    } else {
        close(fd1[1]);
        close(fd2[0]);
        srand(time(NULL));
        int y = rand() % 10;
        write(fd2[1], &y, sizeof(y));
        printf("Parent Wrote: %d\n", y);
        read(fd1[0], &y, sizeof(y));
        printf("Parent Result is: %d\n", y);
        close(fd1[0]);
        close(fd2[1]);
        wait(NULL);
    }
    // close(fd1[0]);
    // close(fd1[1]);
    return 0;
}