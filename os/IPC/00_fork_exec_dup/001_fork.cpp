#include <iostream>
#include <stdlib.h>
#include <unistd.h>

// int main() {
//     std::cout<<"Hello World!\n";
//     int id = fork();
//     std::cout<<"id: "<<id<<"\n"; //print 0 in child process and process id of child process in parent process
//     if(id == 0) {
//         std::cout<<"Hello from child process! "<<getpid()<<"\n"; // print child process id
//     } else {
//         std::cout<<"Hello from main Process! "<<getpid()<<"\n"; // print parent process id
//     }
//     return 0;
// }

// int main() {
//     fork();
//     fork(); // 2^n processes => if we call fork 4 times, no of processes will be 2^4 = 16 processes
//     std::cout<<"Hello World\n";
//     return 0;
// }

// To prevent the process being created multiple times
// Let's say if we want to create only 3 processes, follow below code

int main() {
    std::cout<<"Hi\n";
    pid_t id = fork();
    if(id) {
        fork();
    }
    std::cout<<"Hello\n";
    return 0;
}