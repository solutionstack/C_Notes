
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREADS_NUM 32
sem_t semaph;

void * routine (void *arg){

    printf("Thread [%d]: waiting in login queue \n", *(int*)arg);
    sem_wait(&semaph);

    printf("Thread [%d]: loggen in \n", *(int*)arg);

    sleep(rand()% 5+1);

    printf("Thread [%d]: loggen out \n", *(int*)arg);

    sem_post(&semaph);
    free(arg);
    pthread_exit(0);
}


int main(int argc, char *argv[])
{

    pthread_t th[THREADS_NUM];

    sem_init(&semaph, 0, 4);

    for(int i=0; i < THREADS_NUM; i++){

        int *arg = malloc(sizeof(int));
        *arg = i;
        if (pthread_create(&th[i], NULL, routine, arg) !=0){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }

    }


    for(int i=0; i < THREADS_NUM; i++){

        if (pthread_join(th[i],NULL) !=0){
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }

    }
    sem_destroy(&semaph);

    return EXIT_SUCCESS;
}
