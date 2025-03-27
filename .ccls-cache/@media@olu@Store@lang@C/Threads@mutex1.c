//
// Created by olu on 11/29/24.
//
// do not memcpy a DS having a mutex member

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t mutex;

static void *thread_function(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);//or pthread_mutex_trylock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2;
    pthread_mutex_init(&mutex,NULL);
    if (pthread_create(&t1,NULL, thread_function,NULL) !=0){
        perror("pthread_create");
        exit(1);
    };
    if (pthread_create(&t2,NULL, thread_function,NULL) !=0){
        perror("pthread_create");
        exit(1);
    };
    pthread_create(&t2,NULL, thread_function,NULL);
    if (pthread_join(t1, NULL) !=0) {
        perror("pthread_join");
        exit(1);
    };
    if (pthread_join(t2, NULL) !=0) {
        perror("pthread_join");
        exit(1);
    };

    printf("Main thread joined\n");

    printf("Incremented value\n %d", counter);
    pthread_mutex_destroy(&mutex);
}
