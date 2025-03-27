#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void __str_copy(const char * src, char* dest){

    while((*dest++ = *src++));

}
int main(){
    
    char * src = "test_string";
    char * dest = malloc(strlen(src)+1);

    __str_copy(src,  dest);

    printf("copied data %s\n", dest);



}
