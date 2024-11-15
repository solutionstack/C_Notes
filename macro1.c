//
// Created by olu on 25/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ABS_COMPARE(x,y) (abs(x) > abs(y) ? (x) : (y) )


#define swap(type__, a , b) \
({ \
    type__ temp; \
    temp = *b; \
    *b = *a; \
    *a = temp; \
})



 int main(void) {

   int a = 9, b = 10;

   swap(int, &a,&b);

   printf("%d\n", a);
   printf("%d\n", b);

   b =  ABS_COMPARE(10,-5) ;

   printf("%d",b);
   return 0;
}