// Print fibonacii series using child process
#include <cstdlib>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    
    pid_t pid = fork();
    if(pid==0) {
        int n1 = 0;
        int n2 = 1;
        int n3;
        std::cout<<n1<<" "<<n2<<" ";
        for(int i=2; i<5; ++i) {
           n3 = n1+n2;
           std::cout<<n3<<" ";
           n1=n2;
           n2=n3;
        }
    } else if (pid>0) {
        wait(NULL);
        exit(0);
    }
}