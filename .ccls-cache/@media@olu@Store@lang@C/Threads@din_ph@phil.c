//
// Created by olu on 12/5/24.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "din_ph.h"
#include <threads.h>

void *phil_thread_fn(void *arg) {
    phil_t *phil = arg;
    while (1) {
        if (phil_acquire_spn(phil)) {
            //acquire both left and right spoons
            phil_eat(phil); //eat
            phil_release_spn(phil); //release spoons
            sleep(1); //wait 1 sec before attempting to re-acquire
        }
        usleep(500000); //unable to acquire  bothleft and right spoons, wait a bit
    }
}

phil_t *phil_init(int phil_id) {
    phil_t *phil = malloc(sizeof(phil_t));
    if (phil == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    phil->id = phil_id;
    phil->eat_count = 0;
    return phil;
}
bool phil_release_spn(phil_t *phil) {
    spn_t *lft_spn = phil_get_left_spoon(phil);
    spn_t *rgt_spn = phil_get_right_spoon(phil);

    pthread_mutex_lock(&lft_spn->mutex);
    pthread_mutex_lock(&rgt_spn->mutex);

    assert(lft_spn->phil == phil);
    assert(rgt_spn->phil == phil);

    printf("phil %d, releasing spoons left:%d and right:%d\n", phil->id, lft_spn->spn_id, rgt_spn->spn_id);

    lft_spn->phil = NULL;
    lft_spn->is_used = false;

    pthread_cond_signal(&lft_spn->cond);
    pthread_mutex_unlock(&lft_spn->mutex);

    rgt_spn->phil = NULL;
    rgt_spn->is_used = false;
    pthread_cond_signal(&rgt_spn->cond);
    pthread_mutex_unlock(&rgt_spn->mutex);


    return true;
}
void phil_eat(phil_t *phil) {
    const spn_t *lft_spn = phil_get_left_spoon(phil);
    const spn_t *rgt_spn = phil_get_right_spoon(phil);

    assert(lft_spn->phil == phil);
    assert(rgt_spn->phil == phil);
    assert(rgt_spn->is_used == true);
    assert(rgt_spn->is_used == true);
    phil->eat_count++;

    printf("phil_eat: phil_id: %d; eat count:%d\n", phil->id, phil->eat_count);

    sleep(1);
}



bool phil_acquire_spn(phil_t *phil) {
    spn_t *lft_spn = phil_get_left_spoon(phil);
    spn_t *rgt_spn = phil_get_right_spoon(phil);

    pthread_mutex_lock(&lft_spn->mutex);
    while (lft_spn->is_used && lft_spn->phil != phil) {
        printf("phil %d, blocked on left spoon acquisition\n", phil->id);
        pthread_cond_wait(&lft_spn->cond, &lft_spn->mutex);
    }
    lft_spn->phil = phil;
    lft_spn->is_used = true;
    pthread_mutex_unlock(&lft_spn->mutex);


    pthread_mutex_lock(&rgt_spn->mutex);


    if(rgt_spn->is_used == false) {
        rgt_spn->phil = phil;
        rgt_spn->is_used = true;
        pthread_mutex_unlock(&rgt_spn->mutex);

    }else if(rgt_spn->phil != phil) {
        //if we acquire the left spoon, but we're unable to acquire the right
        pthread_mutex_lock(&lft_spn->mutex);
        lft_spn->phil = NULL;
        lft_spn->is_used = false;

        pthread_mutex_unlock(&rgt_spn->mutex);
        pthread_mutex_unlock(&lft_spn->mutex);
        printf("phil %d, blocked on right spoon acquisition, releasing all spoon resource\n", phil->id);
        return false;

    }

    printf("phil %d, acquired spoons left:%d and right:%d\n", phil->id, lft_spn->spn_id, rgt_spn->spn_id);

    return true;
}
