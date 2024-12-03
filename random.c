//
// Created by olu on 8/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_d(){
    //rand returns from 0 to RAND_MAX
    //so
   return (double)rand() / (double )RAND_MAX;//== 0.0 to 1.0

}
int main(void ){
    srand(time(NULL));

    printf("rand: %d\n", rand());
    printf("rand()%%100: %d\n", rand()%100);

    //to get from a range say 50-150
    printf("rand()%%100 +50 %d\n", rand()%100 +50);

    //or min=50, max is 160, interval size 160-50 = 110
    printf("%d\n",(rand()%(160-50)) +50);

    //rand double
    printf("%.2lf\n", rand_d());

    //to get up to a maximum say [0.0,5.0] multiply the result by 5
    printf("%.2lf\n", rand_d()*5);

    //to change the minimum value say [2.0,5.0] making our interval 3 (i.e 2 to 5)
    //so multiply by the interval and add the start number to set the minimum
    printf("%.2lf\n", rand_d()*(5-2) +2 );
    return 0;


}