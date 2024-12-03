//
// Created by olu on 03/09/23.
//  returns 1 if the string t occurs at the
//end of the string s, and zero otherwise.
//

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
int strend(char *, char *);
extern int errno;
char *month_name(int n);

 int main(){

     month_name(2);
char *s = "ssssssssjh";
char *t = "h";
int v;
    if(( (v = strend(s,t))) && v != -1) {
        printf("\n*s == *t");
        return 0;
    }
     printf("\n*s != *t");
     return EXIT_FAILURE ;
}

int strend(char *s, char *t){
    size_t nlen = strlen(t);
    if(!nlen || !strlen(s)){
        perror("\ninvalid argument");
        return -1;
    }
    char *p =  s + (strlen(s) - nlen); //go back on s by the length of the t

    while(*p++ == *t++ ) { //loop to length of both strings and
        if (!*p) {
            return 1;
        }
    }
    return 0;

}

char *month_name(int n)
{
    static char* name[] = {
            "Illegal month",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
    };

    printf("%s", *(name+1));
//    return (n < 1 || n > 12) ? name[0] : name[n];
}