#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    if(mkfifo("myfifo1", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Error in creating fifo file\n");
        }
    }
    printf("Opening...\n");
    int fd = open("myfifo1", O_WRONLY);
    printf("Opened!\n");
    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1) {
        return 2;
    }
    printf("Written\n");
    close(fd);
    printf("Closed\n");
    return 0;
}