//
// Created by olu on 9/1/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *p = "111.11, -2.22, 0xFF";
    char *pP  = p;
    char *end;
    for (double f = strtod(p, &end); p != end; f = strtod(p, &end)) {
        if (*end == ',') end++;

        printf("%e\n", f);
        p = end;

        // do whatever with f
    }
    //or

   p = pP;
    while (p != p + strlen(p)) {
        const double f = strtod(p, &end);
        printf("%e\n", f);

        if (*end ==',') end++;
        p=end;
    }
}
