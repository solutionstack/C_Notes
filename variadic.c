//
// Created by olu on 8/2/24.
//

#include <stdarg.h>
#include <stdio.h>

int sum(int input, ...) {
    va_list args;
    va_start(args, input);

    int result=0;
    while ((input--)) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}

int main(void) {
    printf("Sum is %d", sum(3, 11, 12,10));
    return 0;
}