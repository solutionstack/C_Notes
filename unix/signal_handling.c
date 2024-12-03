//
// Created by olu on 11/8/24.
// simple intercept UNIX signal
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>


void signal_handling(int signum) {
    printf("Caught SIGINT : %d\n", signum);
    psignal(signum, NULL);

    // fflush(stdout);
    kill(getpid(), SIGKILL);
}

int main() {
    struct sigaction action;

    action.sa_handler = &signal_handling;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);


    while (1) {
    }
}
