//
// Created by olu on 10/24/24.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024


int main(int argc, char *argv[]) {
    int fd[2];


    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid_t cid = fork();

    if (cid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cid == 0) {
        close(fd[0]);
        const int x = 9;
        if (write(fd[1], &x, sizeof(int) == -1)) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);
        printf("Read shared process file in parent %d\n", (int) y);
    }
}
