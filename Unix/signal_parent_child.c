//
// Created by olu on 11/14/24.
// use child process to signal parent after timeout
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


static int input = 0;
void sig_child(int signo) {

    if (input == 0) {
        printf("\n\nHint: Enter an integer between 1 and 100\n");
    }

}
int main(void) {
    const pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {

        sleep(5);
        kill(getppid(), SIGUSR1 );
    }else {
        struct sigaction action;
        action.sa_handler = &sig_child;
        sigemptyset(&action.sa_mask);
        action.sa_flags = SA_RESTART;

        sigaction(SIGUSR1, &action, NULL);

        printf("Enter a number \n" );
        scanf("%d", &input);

        printf("You entered %d\n", input);
        wait(NULL);

    }

}
