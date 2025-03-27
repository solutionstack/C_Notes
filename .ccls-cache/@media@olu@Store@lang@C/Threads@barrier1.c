#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <unistd.h>


pthread_barrier_t barr;


void* routine(void* arg){

    int id = *(int*)arg;

    printf("Thread with id [%d] waiting at barrier\n", id);

    sleep(2);


    pthread_barrier_wait(&barr);


    printf("Thread with id [%d] exited barrier\n", id);

    free(arg);

    pthread_exit(0);

}


int main(int argc, char *argv[]){

    pthread_barrier_init(&barr, NULL, 4); // Change to 4 to match the number of threads

    pthread_t th[4]; // Change to 4 to hold all threads


    for(int i = 0; i < 4; i++){

        int* _i = malloc(sizeof(int));

        if (_i == NULL) { // Check for malloc failure

            perror("malloc");

            exit(EXIT_FAILURE);

        }

        *_i = i;

        if(pthread_create(&th[i], NULL, routine, _i) != 0){ // Check against 0

            perror("thread_create");

            free(_i); // Free allocated memory on failure

            exit(EXIT_FAILURE);

        }

    }


    for(int i = 0; i < 4; i++){ // Join all threads

        if(pthread_join(th[i], NULL) != 0){ // Check against 0

            perror("thread join");

            exit(EXIT_FAILURE);

        }

    }


    pthread_barrier_destroy(&barr); // Clean up barrier

    return 0;

}
