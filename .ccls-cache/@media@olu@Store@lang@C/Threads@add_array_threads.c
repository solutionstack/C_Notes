//
// Created by olu on 11/29/24.
// Create threads to return successive elements  from num_arr
//


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
static int num_arr[] = {11, 22, 3, 4, 43, 444, 56, 66, 777, 5, 34, 2, 3, 31, 6, 8, 3, 43, 5, 0, 5656};


static void *add_array_threads(void *start_index) {
    int *arr_value = malloc(sizeof(int));
    *arr_value = num_arr[*(int *) start_index];

    return arr_value;
}

int main(int argc, char *argv[]) {
    int arr_size = sizeof(num_arr) / sizeof(num_arr[0]);
    pthread_t threads_arr[arr_size];

    for (int i = 0; i < arr_size; i++) {
        pthread_t tid;
        int *find_index = malloc(sizeof(int));
        *find_index = i;

        // pthread_attr_t attr;
        // pthread_attr_init(&attr);
        // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        if (pthread_create(&tid, NULL, &add_array_threads, find_index) != 0) {
            perror("pthread_create");
            exit(1);
        }
        threads_arr[i] = tid;
    }

    for (int i = 0; i < arr_size; i++) {
        int *result;
        if (pthread_join(threads_arr[i], (void **) &result) != 0) {
            perror("pthread_join");
            exit(1);
        }

        printf("Got value %d from thread no #%d\n", *result, i);
        free(result);
    }
}
