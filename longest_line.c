//
// Created by Olubodun Agbalaya on 21/11/2020.
//
//Print longest line from multiline input

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_next_line();

int main() {
    const int max = 500;

    char *longest = malloc(max * sizeof(char));
    char *current = malloc(max * sizeof(char));
    *current = '\0'; //sets the first index to NULL so length is 0, or we can memset the whole array to \0
    *longest = '\0';

    while ((current = get_next_line()) != NULL) {
        if (strlen(current) > strlen(longest)) {
            strcpy(longest, current);
        }
    }
    printf("\nLongest line entered is : %s\n", longest);

    free(longest);
    free(current);
}

char *get_next_line() {
    int c;
    const int max = 500;
    char *s = malloc(max * sizeof(char));
    *s = '\0';
    while ((c = getchar()) != EOF && c != '\n') {
        s[strlen(s)] = (char) c;
    }
    if (c == EOF) return NULL;
    return s;
}