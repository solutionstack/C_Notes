/*
* simplerecursive mutex demo, increment a number recursively from a thread
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static int counter = 0;
pthread_mutex_t lock;

void * incrementer(){

    if (counter == 100){
        pthread_exit(  (void  *)&counter);
    }
    pthread_mutex_lock( &lock); //mutex gets locked for as many times a s the funtion recurses
    ++counter;
    printf("current counter value %d\n", counter);
    pthread_mutex_unlock(  &lock);
    return incrementer();
}

int main(){
    pthread_t th;
    pthread_mutexattr_t recurseAttrib;

    pthread_mutexattr_init(&recurseAttrib);
    pthread_mutexattr_settype(&recurseAttrib, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock, &recurseAttrib);

    if(pthread_create(&th, NULL, incrementer, NULL) != 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);     
    }
    
    int *result;
    if (pthread_join(th, (void**) &result) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_destroy(&lock);

    printf("final computed data: %d\n", *result);
 


}
