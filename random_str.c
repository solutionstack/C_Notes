//
// Created by olu on 8/2/24.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

const char *random_str(int length) {
    char *value = malloc(length);
    if (!value)return NULL;

    int ascii_start = 65, ascii_end = 122;

    for (int i = 0; i < length; i++) {
        value[i] = rand() % (ascii_end - ascii_start) + ascii_start;
        //value[i] = rand()%('z'-'a')+'a';
    }
    return value;
}

int main(void) {
    srand(time(NULL));
    for (int i = 5; i < 10; i++) {
        const char *str = random_str(i);
        printf("Random str of length %d: %s\n", i, str);
        free((void *) str);
    }

}
