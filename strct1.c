//
// Created by olu on 02/10/23.
//
#include  <ctype.h>
#include  <stdio.h>
struct point{
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};
int main(void ){
    static const struct rect a = (struct rect){ 0 };
    printf("%u", a);
}
