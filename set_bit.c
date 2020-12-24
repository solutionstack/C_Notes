//
// Created by Olubodun Agbalaya on 20/12/2020.
//Set bits in an integer from position p (from least significant bit) and by count n..
// leave other bits unchanged
//

#include <stdio.h>
#include <stdint.h>

uint64_t set_bits(uint64_t, int, int);

int main() {
    //e.g
    set_bits(531ull, 7, 4);

}


uint64_t set_bits(uint64_t v, int p, int n) {

    uint64_t mask = 1ull << (p - 1); //set bit of starting point (p) in mask..
    //we minus 1 above as the starting value 0x1 has 1 as its LSB, so only p-1 shifts is needed to get to
    // the starting pos.
    int j = p - n;
    while (p-- > j) {//reduce p till we have looped n places
        mask |= 1ull << p; //set the other needed bits to form the full mask
    }

    v |= mask; //set the needed bit range on in the value
    return v;
}

