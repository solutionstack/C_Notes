//
// Created by olu on 12/3/24.
//pthread cond variable
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int fuel = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_fuel = PTHREAD_COND_INITIALIZER;

void * fuel_filling(void * arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);

        fuel += 10;
        printf("Filled Fuel %d\n", fuel);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond_fuel);
        sleep(1);

    }
}
void *car(void * arg) {
    for (int i = 0; i < 2; i++) {
        pthread_mutex_lock(&mutex);
        while (fuel <= 19) {
            usleep(1000);
            printf("No fuel waiting %d\n", fuel);

            pthread_cond_wait(&cond_fuel, &mutex);
        }
        fuel -= 20;
        printf("Got fuel. Now left %d\n", fuel);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
int main() {
    pthread_t th[2];
    for (int i = 0; i < 2; i++) {
        if(i ==1) {
            if (pthread_create(&th[i], NULL, fuel_filling, NULL) !=0) {
                perror("pthread_create");
                exit(1);
            }
        } else {
            if (pthread_create(&th[i], NULL, car, NULL) != 0) {
                perror("pthread_join");
                exit(1);
            }
        }
    }

        for( int i=0; i < 2; i++) {
            if (pthread_join(th[i], NULL) != 0) {
                perror("pthread_join");
                exit(1);
            }

    }

    pthread_cond_destroy(&cond_fuel);
    pthread_mutex_destroy(&mutex);
    return 0;
}
