#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSIZE 27

int main() {
    char *shm, *s;
    int shmId;
    // key_t key = 5678;
    key_t key = ftok("shmfile", 5678); // to generate unique key
    if((shmId = shmget(key, SHMSIZE, 0666)) < 0) {
        perror("error in creating shared memory");
        exit(1);
    }

    if((shm = (char*)shmat(shmId, NULL, 0)) == (char*) -1) {
        perror("error in attaching");
        exit(2);
    }

    for(s=shm; *s!=0; s++) {
        putchar(*s);
    }

    *shm = '*';
    printf("\n");
    //detach from shared memory 
    shmdt(shm);
    return 0;
}