//
//= Created by Olubodun Agbalaya on 21/11/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

int main() {
    const int max = 500;

    char *longest = malloc(max );
    char *current = malloc(max);
    *current = 0; //sets the first index to NULL so length is 0, or we can memset the whole array to \0
    *longest = 0;

    while ((current = get_next_line())) {//check for null is inferred
        if (strlen(current) > strlen(longest)) {
            *longest =  *current;
        }
    }
    printf("\nLongest line entered is : %s\n", longest);
    free(longest);
    free(current);
}

