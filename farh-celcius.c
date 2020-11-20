//
// Created by Olubodun Agbalaya on 15/11/2020.
//farh to celsius convert

#include <stdio.h>

int main() {

    float start = 0, step = 20, max = 300;
    int max_width = 8;

    printf("\t Farh to Celsius table \n");
    printf("\t %-4sFarh \t | \t %-4sCelsius \n", "","");
    for (; start < max;) {
        float celsius = (5.0f / 9.0f) * (start - 32.0f);

        printf("\t %*.2f \t | \t %*.2f \n", max_width, start, max_width, celsius);
        start += step;

    }

}