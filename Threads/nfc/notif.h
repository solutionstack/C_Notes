//
// Created by olu on 11/19/24.
//

#ifndef NOTIF_H
#define NOTIF_H

#define MAX_NOTIF_KEY_SIZE 128
#include <stddef.h>

typedef (*nfc_app_cb)(void *, size_t);
typedef struct notif_chain {
    char name[6];
    struct notif_chain *next;

} notif_chain;

typedef struct notif_chain_elem {
    char key[MAX_NOTIF_KEY_SIZE];
    size_t key_len;
    _Bool is_key_set;

} notif_chain_elem;

#endif //NOTIF_H

