//
// Created by olu on 05/09/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate_memory(char ** ptr) {
    // Allocate space for a string of 9 characters
    *ptr =  malloc(17 * sizeof(char)); //strlen +1
}

int main() {
    char *word;
    char b[50] ="aaaaaaaaaa World";
    allocate_memory( &word);

    strcpy(word, b);
    printf("%s\n", word);
    printf("%c\n", word[1]);
    printf("%zu\n", strlen(word));
//    free(word);
    printf("%s\n", word);

    return 0;
}