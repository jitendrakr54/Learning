#include <stdio.h>
#include <signal.h>

void handle_sigtstp(int sig) {
    printf("Stop not allowed!\n");
}

void handle_sigcont(int sig) {
    printf("Input number: ");
    fflush(stdout);
}

int main() {
    // struct sigaction sa;
    // sa.sa_handler = &handle_sigstop;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGTSTP, &sa, NULL);

    // signal(SIGTSTP, &handle_sigtstp);

    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa, NULL);

    int n;
    printf("Input number: ");
    scanf("%d", &n);
    printf("Result of %d * 5 is: \n", n*5);
    return 0;
}