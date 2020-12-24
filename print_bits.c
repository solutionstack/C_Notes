//
// Created by Olubodun Agbalaya on 19/12/2020.
//

#include <stdio.h>
#include <stdint.h>
void printBitsBigEndian(uint64_t);

void printBitsLilEndian(uint64_t);

int main() {
    printf("Print in Big endian...\n");
    for (int i = 0; i <= 20; i++) {
        printBitsBigEndian(i);
    }

    printf("\n\nPrint in Lil endian...\n");
    for (int i = 0; i <= 20; i++) {
        printBitsLilEndian(i);
    }
}

void printBitsBigEndian(uint64_t num) {//MSB last
    printf("Bits in %d = ", (int) num);
    for (int bits = 0; bits < (sizeof(uint64_t) * 8); bits++) {

        printf("%llu", 0x01ull & num);
        num >>= 1;
    }
    printf("\n");
}

void printBitsLilEndian(uint64_t num) {//MSB first
    printf("Bits in %d = ", (int) num);
    size_t bit_size = sizeof(num) * 8;

    //shift set bit of 1 to MSB of bit_size, then & with num till we get to LSB
    int shift_size= 1;
    for (size_t i = 1ull << (bit_size - shift_size);;) {

        printf("%d", i & num ? 1:0);
        if (i == 1) break; //we have shifted to 0x1
        i = 1ull  << (bit_size - (++shift_size));
    }
    printf("\n");
}

