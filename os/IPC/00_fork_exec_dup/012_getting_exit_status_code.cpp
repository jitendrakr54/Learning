// In this program we launched ping process, But how do we know that it's actually suceeded or got some error?
// There are two types of error here - one if the actual ping program dows not exist or not found
// Two - if he actual ping is found and executed but gives out an error.
// First - is simple, using return of execlp(), if process(ping) not found it returns -1
// Second - What if address(google.con) is not right, that answer lies in wait()
// Parameter of the wait() tells status about child process.
// To know exact status we need to make use of two macros - WIFEXITED, WEXITSTATUS
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
        int err = execlp("ping", "ping", "-c", "3", "google.con", NULL);
        // execlp("/bin/ls", "ls", NULL);
        if(err = -1) {
            printf("Could not find program to execute!\n");
            return 3;
        }
    } else {
        int wstatus;
        wait(&wstatus);
        printf("Return status: %d\n", wstatus);
        if(WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode == 0) {
                printf("Success!\n");
            } else {
                printf("Failed with error code: %d\n", statusCode);
            }
        }
        printf("Success!\n");
    }
    return 0;
}