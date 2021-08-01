#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int pid = fork();
    if(pid < 0) {
        return 1;
    } else if(pid == 0) {
        // int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        int err = execlp("ping", "ping", "-c", "3", "google.com", "|",
                    "grep", "\"rtt\"", NULL);
    } else {
        wait(NULL);
        printf("Success!\n");
    }
    return 0;
}

// >ping -c 1 google.comm | grep "rtt"
// means need only rtt output

// Dfference between executing program and executing scripts is:
// C program directly executes executable file such as ping, ls but
// scripts has interpreter so before executing executable file it BASH interprets and then pass
// it to executable file 