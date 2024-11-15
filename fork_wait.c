//
// Created by olu on 10/6/24.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
    const int id = fork();
    if (id == -1) {
        perror("fork");
    }
    int counter;
    if (id == 0) {
       counter = 1;
        printf("child process id: %d\n", getpid());
    }else {
        counter = 5;
        printf("main process id: %d\n", getpid());
        wait(NULL); //wait for child process
    }

    for (int i = counter; i < counter+5; i++) {
        printf("%d\n", i);
        fflush(stdout);
    }
    return 0;
}
