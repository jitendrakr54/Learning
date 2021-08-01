#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int main() {
    int arr[5];
    int fd = open("sum", O_RDONLY);
    if(fd == -1) {
        return 1;
    }

    // for(int i = 0; i<5; i++) {
    //     if(read(fd, &arr[i], sizeof(int)) == -1) {
    //         return 2;
    //     }
    //     printf("Received %d\n", arr[i]);
    // }

    if(read(fd, arr, sizeof(int) * 5) == -1) {
        return 2;
    }
    close(fd);
    
    int sum = 0;
    for(int i=0; i<5; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
    close(fd);
}