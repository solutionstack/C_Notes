//
// Created by olu on 12/8/24.
//
#include <stdio.h>
int main() {
    int iArray[32];
    int i;
    for(i = 0; i<32; i++)
    {
        iArray[i] = i;
    }
    for(i = 0; i<32; i++)
    {
        printf("a[%d] %p %d ",i,  (void*)&iArray[i], iArray[i]);
        if((i%4 == 0) && (i != 0))
            printf("\n");
    }
}