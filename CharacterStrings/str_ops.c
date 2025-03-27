//
// Created by olu on 8/5/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define size  100
int* char_indexOf(const char *sa, const char *n){
    if(!sa|| strcmp(n,"") ==0)return NULL;

    static int r;
    const char  *found = strchr(sa, n[0]);

    if(found != NULL){
        r = found - sa;
        return &r;
    }

    return NULL;
}

//
// Timi is a bad boy
// good
// foolish
// hi

char* string_replace(char* source, size_t sourceSize, char* substring, char* with) {
    char* substring_source = strstr(source, substring);
    if (substring_source == NULL) {
        return NULL;
    }

    if (sourceSize < strlen(source) + (strlen(with) - strlen(substring)) + 1) {
        printf("Buffer size is too small\n");
        return NULL;
    }

    memmove(
        substring_source + strlen(with),
        substring_source + strlen(substring),
        strlen(substring_source) - strlen(substring) + 1
    );

    memcpy(substring_source, with, strlen(with));
    return substring_source + strlen(with);
}
void str_replace(const char * source, char * find, char * replace) {
    char *find_pos = strstr(source, find);
    if (find_pos == NULL) {
        return;
    }
    memmove(find_pos, find_pos+1, strlen(find_pos+1));



}
int main(void ){


    int a1[] = {1,2,3,4};
    int a2[] = {1,2,3,4};
    printf("%d\n",memcmp(a1,a2,sizeof (int )*4));

    char haystackp[] = "abcdef";
    char needle[] = "a";

    const int *r = char_indexOf(haystackp, needle);
    if (r == NULL){
        printf("char %c not found\n", needle[0]);

    } else{
        printf("char %c found at position %d\n", needle[0], *r);
    }


    char str[] = "this, is the string - I want to parse";
    for(const char *p = strtok(str, " "); p; p = strtok(NULL," ")){
        printf("next token %s\n", p);
    }

    char *strsample = "aa-2a155abc 123 r4t";
    printf("Integers are detected from index %ld\n",   strpbrk(strsample,"123456890") - strsample);


    const char* string = "abcde312$#@";
    const char* low_alpha = "qwertyuiopasdfghjklzxcvbnm";

    size_t spnsz = strspn(string, low_alpha);
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string + spnsz);


    const char dest[size]="";
    const char src[]="abcd";
    printf("%s\n", strncat(dest,src, size- strlen(src)-1));

    char t[] ="ttqa bb abcde";
    char c[]="bb";
    char d[]="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    // str_replace(t,c,d);

    string_replace(t,50,c,d);
    printf("%s\n", t);


}