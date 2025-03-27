//
// Created by olu on 12/5/24.
//

#ifndef DIN_PH_H
#define DIN_PH_H
#include <stdbool.h>
#include <pthread.h>


typedef struct phil {
    int id;
    pthread_t th;
    int eat_count;
} phil_t;

typedef struct spn {
    int spn_id;
    bool is_used;
    phil_t *phil;

    pthread_mutex_t mutex;
    pthread_cond_t cond;
}  spn_t;

#define NUM_PHILOSOPHER 5
extern phil_t* phil[NUM_PHILOSOPHER];
extern spn_t* spoon[NUM_PHILOSOPHER];



void * phil_thread_fn(void *);

spn_t *phil_get_right_spoon(const phil_t *phil);
spn_t *phil_get_left_spoon(const phil_t *phil);
void phil_eat(phil_t *phil);


bool phil_release_spn(phil_t *phil);
bool phil_acquire_spn(phil_t *phil);

phil_t* phil_init(int phil_id) ;
spn_t *spn_init(const int spn_id) ;

#endif //DIN_PH_H
