// How to send an array through a pipe
// 2 process
// 1. Child process should generate random numbers and send them to parent
// 2. Parent is going to sum all the numbers and print the result


#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main() {
    int fd[2];
    if(pipe(fd) == -1) {
        return 1;
    }
    int id = fork();
    if(id == -1) {
        return 2;
    } else if(id == 0) {
        close(fd[0]);
        srand(time(NULL));
        int n = rand() % 10 +1;
        printf("Generated: ");
        int arr[n];
        for(int i =0; i<n; i++) {
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
        }
        printf("\n");
        write(fd[1], &n, sizeof(int));
        printf("Sent n = %d\n", n);
        write(fd[1], arr, sizeof(int)*n);
        printf("Sent Array\n");
        close(fd[1]);
    } else {
        close(fd[1]);
        int n;
        read(fd[0], &n, sizeof(int));
        printf("Received n = %d\n", n);
        int arr[n];
        read(fd[0], arr, sizeof(int)*n);
        printf("Received array!\n");
        close(fd[1]);
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        printf("Total sum: %d\n", sum);
        wait(NULL);
    }
}