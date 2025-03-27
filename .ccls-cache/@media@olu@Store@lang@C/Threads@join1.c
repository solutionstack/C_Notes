//
// Created by olu on 11/19/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t th1;
pthread_t th2;

static void *pthread_fn_cb(void *arg) {
    const int p =* (int*)arg;
    free(arg);

    printf("Thread #%d is doing work\n", p);
    sleep(rand() % 10);
    printf("Thread #%d is exiting\n", p);

    return NULL;
}

void thread_create(pthread_t *th_handle, const int th_id) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int *th_id_p = malloc(sizeof(int));
    if (th_id_p == NULL) {
        perror("malloc");
        pthread_exit(0);
    }
    *th_id_p = th_id;

    if(pthread_create(th_handle, &attr, &pthread_fn_cb, th_id_p) != 0){

        printf("Thread #%d failed to create thread\n", *th_id_p);
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    thread_create(&th1, 1);
    thread_create(&th2, 2);

    printf("Blocking main till all threads join\n");
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("Main thread joined\n");
    return 0;
}
