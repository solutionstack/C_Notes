//
// Created by olu on 10/09/23.
//
//simple grep
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int main(void) {
    const size_t N = SIZE;
    char str[N];
    const char *example = "Hello Worldsssssss";

    snprintf(str, sizeof(str), "%s", example);

    printf("String = %s, Length = %zu\n", str, strlen(str));

   /* unsigned val = 0xAABBCCDD;
    unsigned char * valp = (unsigned char* )&val;
    for (size_t i = 0; i < sizeof val; ++i)
        printf("byte[%zu]: 0x%.02hhX\n", i, valp[i]);*/

    return 0;
}

