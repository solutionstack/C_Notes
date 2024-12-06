//
// Created by olu on 12/5/24.
// dinning philosopher
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "din_ph.h"


spn_t *spoon[NUM_PHILOSOPHER] = {0};
phil_t *phil[NUM_PHILOSOPHER] = {0};

int main() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for (int i = 0; i < NUM_PHILOSOPHER; i++) {
        spoon[i] = spn_init(i);
    }

    for (int i = 0; i < NUM_PHILOSOPHER; i++) {
        phil[i] = phil_init(i);

        pthread_create(&phil[i]->th, &attr, phil_thread_fn, phil[i]);
    }

    pthread_exit(NULL);
}
