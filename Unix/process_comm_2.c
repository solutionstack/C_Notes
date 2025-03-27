//
// Created by olu on 10/24/24.
// unix process communication with pipes
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/wait.h>
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

    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data_size = sizeof(data) / sizeof(data[0]);
    int startPos = 0;
    int endPos;

    if (cid == 0) {
        endPos = floor(data_size / 2);

        printf("child_end: %d\n", endPos);
    } else {
        startPos = floor(data_size / 2);
        endPos = data_size;
        printf("par_start: %d\n", startPos);
        printf("par_end: %d\n", endPos);
    }

    int sum = 0;
    for (int i = startPos; i < endPos; i++) {
        sum += data[i];
    }

    if (cid == 0) {
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    } else {
        wait(NULL);
        int temp;
        close(fd[1]);
        read(fd[0], &temp, sizeof(int));
        close(fd[0]);
        sum += temp;

        printf("%d\n", sum);
    }
}
