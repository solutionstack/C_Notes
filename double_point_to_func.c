//
// Created by olu on 9/19/24.
//
#include <stdio.h>

void printArr(const int (*arrArg)[5]) {
    printf(" arg[0][2] : %d",*arrArg[1]+1);
}

int main(void) {
    int arr[][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},


    };
    printArr(arr);
}
