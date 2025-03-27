//
// Created by olu on 12/5/24.
//

#include <assert.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#include "din_ph.h"

spn_t *spn_init(const int spn_id) {
    spn_t *spn = malloc(sizeof(spn_t));
    if (spn == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    spn->spn_id = spn_id;
    spn->is_used = false;
    spn->phil = NULL;
    pthread_mutex_init(&spn->mutex, NULL);
    pthread_cond_init(&spn->cond, NULL);

    return spn;
}

//  spn_t *phil_get_right_spoon
// get the spoon to the right of the philosopher i.e -1
spn_t *phil_get_right_spoon(const phil_t *phil) {
    assert(phil != NULL);

    if (phil->id == 0) {
        return spoon[NUM_PHILOSOPHER - 1];
    }
    return spoon[phil->id - 1];
}

//  spn_t *phil_left_right_spoon
// get the spoon to the left of the philosopher i.e -1
spn_t *phil_get_left_spoon(const phil_t *phil) {
    assert(phil != NULL);
    return spoon[phil->id];
}
