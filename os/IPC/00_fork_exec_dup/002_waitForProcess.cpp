// Print number from 1 to 10 such that Child process should print from 1 to 5 whereas
// parent process should print 6 to 10

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

int main() {
    int id = fork();
    int start;
    if(id==0) {
        start=1;
    } else if(id>0) {
        start=6;
    }
    if(id!=0) {
        wait(NULL);
    }
    for(int i=start; i<start+5; ++i) {
        std::cout<<i<<" ";
    }
    if(id!=0) {
        std::cout<<"\n";
    }
    return 0;
}