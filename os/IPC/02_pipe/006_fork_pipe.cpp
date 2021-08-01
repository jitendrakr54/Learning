//  Practical use case for fork and pipe
// Add half of the nos by child process, write it to fd
// Add another half of the nos by parent process
// Read sum from child process by parent and calulate total summ

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    int arr[] = {1, 2, 3, 4, 9, 8, 7, 6};
    int arrSize = sizeof(arr)/sizeof(int);
    int start, end, sum=0;
    int fd[2];
    if(pipe(fd) == -1) {
        printf("An error occured with opening the pipe!\n");
        return 1;
    }
    int id = fork();
    if(id == -1) {
        printf("An error occured with fork!\n");
        return 2;
    } else if(id == 0) {
        start = 0;
        end = arrSize/2;
    } else {
        start = arrSize/2;
        end = arrSize;
    }

    for(int i = start; i<end; ++i) {
        sum += arr[i];
    }
    printf("Calculate partial Sum: %d\n", sum);

    if(id == 0) {
        close(fd[0]);
        if(write(fd[1], &sum, sizeof(int)) == -1) {
            printf("An error occured with write!\n");
            return 3;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int sumFromChild;
        if(read(fd[0], &sumFromChild, sizeof(int)) == -1) {
            printf("An error occured with read!\n");
            return 4;
        }
        int totalSum = sum + sumFromChild;
        printf("Total sum is: %d\n", totalSum);
        wait(NULL);
    }
    
    return 0;
}

// HW : Instead of having 1 child process try to have 2 child proesses, sum parts of array, and 
//  finally some them all in parent process