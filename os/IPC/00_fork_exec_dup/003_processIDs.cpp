#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int main() {
    int id = fork();
    // std::cout<<"Current ID: ", getpid(),
    //             "Parent ID: ", getppid(), "\n";
    if(id==0) {
        sleep(1);
    }
    printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());

    // int res;
    // if(id) {
        int res = wait(NULL);
    // }
    if(res == -1) {
        printf("No Children to wait for\n");
    } else {
        printf("%d finished execution\n", res);
    }
    return 0;
}