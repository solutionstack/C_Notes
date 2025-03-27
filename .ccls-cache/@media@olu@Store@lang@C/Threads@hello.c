//
// Created by olu on 11/15/24.
// Hello threads
//

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *hello_thread_fn(void *arg) {

    char *data = arg;
    printf("thread received:"" %s\n", data);

    sleep(1);
    printf("thread exiting\n");
    return NULL;
}

void hello_thread_create() {
    pthread_t thread;
    static char *buffer = "hello world data for thread";

    const int c =pthread_create(&thread, NULL, &hello_thread_fn, buffer);
    if (c != 0) {
        perror("pthread_create");
        exit(1);
    }

}
int main() {
    hello_thread_create();
    pause();
    return 0;
}
