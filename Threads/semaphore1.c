#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define THREADS_NUM 4

sem_t semaph;

void *routine(void *arg) {
  sem_wait(&semaph);
  printf("Hello from thread %d\n", *(int *)arg);
  sleep(1);

  free(arg);
  sem_post(&semaph);
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  pthread_t th[THREADS_NUM];

  sem_init(&semaph, 0, 2);

  for (int i = 0; i < THREADS_NUM; i++) {

    int *arg = malloc(sizeof(int));
    *arg = i;
    if (pthread_create(&th[i], NULL, routine, arg) != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = 0; i < THREADS_NUM; i++) {

    if (pthread_join(th[i], NULL) != 0) {
      perror("pthread_join");
      exit(EXIT_FAILURE);
    }
  }
  sem_destroy(&semaph);

  return EXIT_SUCCESS;
}
