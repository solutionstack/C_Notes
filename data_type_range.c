//
// Created by Olubodun Agbalaya on 25/11/2020.
//


/**
 * Calculate the rage of data types by modulo arithmetic
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <limits.h>

void printUnsignedRange(size_t);

void printSignedRange(size_t);

int main() {


    printf("\nPrinting range of unsigned char\n");
    printUnsignedRange(sizeof(unsigned char) * 8); //* by eight so we get the number of bits
    printf("Printing range of signed char\n");
    printSignedRange(sizeof(char) * 8);
`

    printf("\nPrinting range of unsigned int\n");
    printUnsignedRange(sizeof(unsigned int) * 8);
    printf("Printing range of signed int\n");
    printSignedRange(sizeof(int) * 8);

    printf("\nPrinting range of unsigned long\n");
    printUnsignedRange(sizeof(unsigned long) * 8);
    printf("Printing range of signed long \n");
    printSignedRange(sizeof(long) * 8);

    printf("\nPrinting range of unsigned long long\n");
    printUnsignedRange(sizeof(unsigned long long) * 8);
    printf("Printing range of signed long long \n");
    printSignedRange(sizeof(long long) * 8);
    printf("Pchar :: %c \n", 260);



    return EXIT_SUCCESS;
}


void printSignedRange(size_t no_of_bits) {

    printf("Min value: %lld\n", (long long) (-1 * (pow(2, no_of_bits - 1))));
    printf("Max value: %lld\n", (long long) (pow(2, no_of_bits - 1))-1 );
}

void printUnsignedRange(size_t no_of_bits) {
    printf("Range: %d to: %llu\n", 0, (unsigned long long) (pow(2, no_of_bits ))-1);

}