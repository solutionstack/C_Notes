
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

char *  get_next_line(void) {
    int c;
    const int max = 500;
    char *s = malloc(max * sizeof(char));
    while ((c = getchar()) != EOF && c != '\n') {//is not EOF and c is not a new line
        s[strlen(s)] = (char) c;
    }
    if (c == EOF) return NULL;
    s[strlen(s)] = '\0';//null terminate
    return s;
}