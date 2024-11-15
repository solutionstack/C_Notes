//
// Created by olu on 8/11/24.
//
#include <stdio.h>
typedef struct Point{
    int x,y;
}Point;
int main(int argc, char * argv[]){
   Point p ={
       .x = 10,
       .y  =11
   };

   char buff[100];
    snprintf(buff, 100, "{%d, %d}\n", p.x, p.y);
    printf("%s\n", buff);
    return 0;
}