//
// Created by olu on 11/7/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        while (1) { //continue until stopped by external process
            printf("I am the child process\n");
            sleep(1);
        }
    }else {
        int t;
        if ( kill(pid, SIGSTOP) == -1) { perror("kill"); exit(1); }
        do {

            printf("Time in sec for execution: \n"); //the child would resume exec. for number of seconds we specify
            scanf("%d", &t);


            if (t >0) {
                kill(pid, SIGCONT);
                sleep(t);
            }

            if ( kill(pid, SIGSTOP) == -1) { perror("kill"); exit(1); }

        }while (t >0);
    }
    kill(pid, SIGKILL);
    wait(NULL);
}
