#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>

int main() {
    int fd[2];
    if(pipe(fd) == -1) {
        return 1;
    }

    int id = fork();
    if(id == -1) {
        return 2;
    } else if(id == 0) {
        close(fd[0]);
        char str[200] = "hello";
        // char str[200];
        // printf("Input String: ");
        // fgets(str, 200, stdin);
        // str[strlen(str) -1] = '\0';

        int n = strlen(str);
        if (write(fd[1], &n, sizeof(int)) == -1) {
            return 2;
        }

        if (write(fd[1], str, n) == -1) {
            return 3;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        // char str[200];
        int n;
        if (read(fd[0], &n, sizeof(int)) == -1) {
            return 4;
        }
        char str[n];
        if (read(fd[0], str, n) == -1) {
            return 5;
        }

        printf("received: %s\n", str);
        wait(NULL);
    }

    return 0;
}

// int main() {
//     int fd[2];
//     if(pipe(fd) == -1) {
//         return 1;
//     }

//     int id = fork();
//     if(id == -1) {
//         return 2;
//     } else if(id == 0) {
//         close(fd[0]);
//         std::string str;
//         std::cout<<"Input String: ";
//         std::cin>>str;

//         int n = str.length();
//         if (write(fd[1], &n, sizeof(int)) == -1) {
//             return 2;
//         }

//         if (write(fd[1], &str, n) == -1) {
//             return 3;
//         }
//         close(fd[1]);
//     } else {
//         close(fd[1]);
//         std::string str;
//         int n;
//         if (read(fd[0], &n, sizeof(int)) == -1) {
//             return 4;
//         }

//         if (read(fd[0], &str, n) == -1) {
//             return 5;
//         }

//         // printf("received: %s\n", str.c_str());
//         std::cout<<"Received: "<<str<<"\n";
//         wait(NULL);
//     }

//     return 0;
// }