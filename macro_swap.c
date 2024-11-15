//
// Created by Olubodun Agbalaya on 01/03/2021.
//
#include "stdio.h"

#define dprint(expr) printf(#expr " = %g\n", expr)
#define SWAP(a, b) \
    { \
        (a) ^= (b); \
        (b) ^= (a); \
        (a) ^= (b); \
    }

#define SWAP_TYPE(type, a, b) \
    { \
        type __swap_temp; \
        __swap_temp = b; \
        b = a; \
        a = __swap_temp; \
    }

int main() {
    int a = 6;
    int b = 123;
    double fa = 3.1415;
    double fb = 2.7182;

    SWAP(a, b);
    SWAP_TYPE(float, fa, fb);

    printf("b = %d\n", b);
    printf("b = %f\n", fb);
    dprint(9.0 / 3);


}
