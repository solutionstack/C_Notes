//
// Created by Olubodun Agbalaya on 20/12/2020.
//Set bits in an integer from position p (from least significant bit) and by count n..
// leave other bits unchanged
//

#include <stdint.h>
#include "print_bits.h"

uint64_t set_bits(uint64_t, int, int);

int main() {
    //e.g
    set_bits(1, 7, 4);
}


uint64_t set_bits(uint64_t v, int p, const int n) {
    uint64_t mask = 0x1ull << (uint64_t) (p - 1); //set bit of starting point (p) in mask..
    printBitsLilEndian(mask);

    //we minus 1 above as the starting value 0x1 has 1 as its LSB, so only p-1 shifts is needed to get to
    // the starting pos.


    //alternate for loop solution
    // uint64_t result = 0;
    // for (int i = 0; i < n; i++) {
    //     result |= mask | v;
    //     mask >>= 1;
    // }
    const int mask_stop = p - n;
    while (p-- > mask_stop) {//reduce p till we have looped n places
        mask |= 0x1ull << (uint64_t) p; //set the other needed bits to form the full mask
    }
    //
    v |= mask; //set the needed bits on - in the value v
    printBitsLilEndian(mask);
    printBitsLilEndian(v);
    return v;
}
