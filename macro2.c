//
// Created by olu on 01/12/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MINSIZE(X, Y) (sizeof(X)<sizeof(Y) ? sizeof(X) :sizeof(Y))

#define BYTECOPY(T, S) memcpy(&(T), &(S), MINSIZE(T, S))

double min(double a, double b);

inline double min(double a, double b) {

    return a < b ? a : b;

}


inline

long double minl(long double a, long double b) {

    return a < b ? a : b;

}


inline

float minf(float a, float b) {

    return a < b ? a : b;

}



/**
 @brief Type-generic minimum for floating-point values

**/
#define TRACE_ON 1
#define min(A, B) \
_Generic((A)+(B), \
float: minf, \
long double: minl, \
default: min)((A), (B))

#define TRACE_PRINT2(F, X) \
do { if (TRACE_ON) fprintf(stderr, "" F "\n", X); } while (0)

#define TRACE_PTR1(HEAD, X) \
TRACE_PRINT2(HEAD  "%p", ((void*){ 0 } = (X)))

int main(void) {
    char s1[10] = "a,b,c";
    char s2[10];

    BYTECOPY(s2, s1);


    printf("%s", s2);
    printf("%g", min((double )1.0,(float )0.3)); //args get promoted to double

    TRACE_PTR1("Tracing print\t", s1);



    return EXIT_SUCCESS;
}
