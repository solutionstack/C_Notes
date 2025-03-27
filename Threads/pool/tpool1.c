#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Task {
  void (*taskFunc)(struct Task *task);
  int a, b, c;
} Task;

Task taskQueue[128];
int i, taskCount = 0;
pthread_mutex_t mutexOnQueue;
pthread_cond_t condOnQueue = PTHREAD_COND_INITIALIZER;

void executeTask(Task *task) {
  usleep(50000);
  int result = task->a + task->b;
  printf("The sum of %d and %d is %d\n", task->a, task->b, result);
}

void *starThread(void *atgs) {

  while (1) {
    Task *task = NULL;

    pthread_mutex_lock(&mutexOnQueue);
    while (taskCount == 0) {
      pthread_cond_wait(&condOnQueue, &mutexOnQueue);
    }

    task = &taskQueue[0];
    int i;
    for (i = 0; i < taskCount - 1; i++) {
      taskQueue[i] = taskQueue[i + 1];
    }
    taskCount--;

    pthread_mutex_unlock(&mutexOnQueue);

    task->taskFunc(task);
    usleep(100);
  }
}

void submitTask(Task task) {
  pthread_mutex_lock(&mutexOnQueue);
  taskQueue[taskCount] = task;
  taskCount++;

  pthread_mutex_unlock(&mutexOnQueue);

  pthread_cond_broadcast(&condOnQueue);
}
int main(int argc, char *argv[]) {
  srand(time(NULL));
  const int THREAD_NUM = 4;
  pthread_t th[THREAD_NUM];

  for (int i = 0; i < THREAD_NUM; i++) {
    if ((pthread_create(&th[i], NULL, &starThread, NULL) != 0)) {
      perror("phread_create");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = 0; i < 100; i++) {
    Task t = {.taskFunc = &executeTask, .a = rand() % 100, .b = rand() % 100};
    submitTask(t);
  }

  for (int i = 0; i < THREAD_NUM; i++) {
    if ((pthread_join(th[i], NULL) != 0)) {
      perror("phread_join");

      exit(EXIT_FAILURE);
    }
  }
  pthread_cond_destroy(&condOnQueue);
  pthread_mutex_destroy(&mutexOnQueue);

  return EXIT_SUCCESS;
}
