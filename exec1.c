//
// Created by olu on 11/3/24.
// run ext program in child process and log output in custom file
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "../../../../../usr/lib/gcc/x86_64-linux-gnu/11/include/stdbool.h"

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();

    int logFd = open("./exec_log", O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (logFd < 0 ) {
        perror("open");
        exit(1);
    }
    dup2(logFd, STDOUT_FILENO);

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        int ret = execlp("bash", "bash", "-c","ping -c4 1.1.1.1", NULL);
        // int ret = execlp("ping", "ping", "-c4", "8.8.8.8", NULL);
        if (ret == -1) {
            perror("execlp: ping");
            return EXIT_FAILURE;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (false == WIFEXITED(status)) {
            perror("ping failed: ");
            return 1;
        }

        if (WEXITSTATUS(status) == 0) {
            printf("ping succeeded with exit status %d\n", WEXITSTATUS(status));
        }
    }
}
