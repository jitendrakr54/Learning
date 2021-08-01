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
    srand(time(NULL));
    int i;
    printf("Generated: ");
    for(int i=0; i<5; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    int fd = open("sum", O_WRONLY);
    if(fd == -1) {
        return 1;
    }

    // for(int i=0; i<5; i++ ) {
    //     if(write(fd, &arr[i], sizeof(int)) == -1) {
    //         return 2;
    //     }
    //     printf("Wrote %d\n", arr[i]);
    // }
    if(write(fd, arr, sizeof(int)*5) == -1) {
        return 2;
    }
    close(fd);
    return 0;
}