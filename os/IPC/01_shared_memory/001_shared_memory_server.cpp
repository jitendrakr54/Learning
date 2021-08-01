#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSIZE 27
int main() {
    char c;
    char *shm, *s;
    int shmid;
    // key_t key = 5678;
    key_t key = ftok("shmfile", 5678); // to generate unique key

    if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("error in creating shared memory");
        exit(1);
    }

    if((shm = (char*)shmat(shmid, NULL, 0)) == (char*) -1) {
        perror("error in attaching");
        exit(2);
    }

    s = shm;
    for(char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = 0;
    while(*shm != '*') {
        sleep(1);
    }

    //detach from shared memory 
    shmdt(shm);

    // destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}