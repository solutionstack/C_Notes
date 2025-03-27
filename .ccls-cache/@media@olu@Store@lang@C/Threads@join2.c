//
// Created by olu on 11/29/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

static void* roll_dice(void * arg) {
  int random = rand() % 10 + 1;
   int* dice =  malloc(sizeof(int));
  if (dice == NULL) {
    perror("malloc");
    pthread_exit(NULL);
  }
   *dice = random;
   return dice;
}

int main(int argc, char *argv[]){
  srand(time(NULL));

  pthread_t tid;

  if(pthread_create(&tid, NULL, &roll_dice, NULL) !=0){
    perror("pthread_create");
    exit(1);
  }

  int *result = 0;
  if(pthread_join(tid, (void**)&result ) != 0){
    perror("pthread_join");
    exit(1);
  }

  printf("Recieved data from thread: %d\n", *result);
  free(result);
  return 0;
  }
