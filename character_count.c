//
// Created by Olubodun Agbalaya on 15/11/2020.
//count various character classes and map frequency of characters

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct charFrequency {
    int count[256];
} cf;

bool seenChar(const int [], int);

void insertNewCharCount(struct charFrequency *, int);

void incrementCharCount(struct charFrequency *, int);

char *getSpecialChar(int);

int main(void) {

    size_t arr_len;
    int c, nc = 0,
            ns = 0,
            nl = 0,
            nt = 0,
            nw = 0;
    bool IN_WORD = false;

    //simulate EOF with Ctrl+D or Control+D (Mac)
    for (; c = getchar(), c != EOF;) {
        ++nc;

        if (c == '\n') ++nl;
        if (c == 32) { //ascii space
            IN_WORD = false;
            ++ns;
        }
        if (c == 9) ++nt; //ascii tab


        if (c != ' ' && !IN_WORD) {
            IN_WORD = true;
            ++nw;
        }

        //if we have seen the char before, increment its count
        if (seenChar(cf.count, c)) {
            incrementCharCount(&cf, c);
        } else {
            insertNewCharCount(&cf, c);
        }
    }

    printf("Total chars:%20d\n", nc);
    printf("Total tabs:%21d\n", nt);
    printf("Total spaces:%19d\n", ns);
    printf("Total new-lines:%16d\n", nl);
    printf("Total words:%20d\n", nw);

    printf("\n\nCharacter frequency:\n");
    printf("ASCII DEC\t\t%-9s\t\tCOUNT \n\n","CHAR");


    char *spc;
    arr_len = sizeof(cf.count) / sizeof(int );
    for (size_t i = 0; i < arr_len; i++) {

        if (!cf.count[i]) continue; //no count registered for this ascii index

        if ((spc = getSpecialChar(i))) {
            printf("%-10zu\t\t%-10s\t\t%d \n", i, spc, cf.count[i]);
            continue;
        }

        printf("%-10zu\t\t%-10c\t\t%d \n", i, (char) i, cf.count[i]);
    }
    return EXIT_SUCCESS;
}

/**
 * Return a textual representation for the control character
 * @param c
 * @return char*
 */
char *getSpecialChar(int c) {
    int specialCharsACII[] = {9, 32, 10};
    char *specialCharsText[10] = {"TAB", "SPACE", "NEWLINE"};

    for (int i = 0; i < 3; i++) {
        if (specialCharsACII[i] == c)
            return specialCharsText[i];
    }
    return NULL;
}

/**
 * Does the ascii index already exist in the array
 * @param asciiArr
 * @param c
 * @param len
 * @return bool
 */
bool seenChar(const int asciiArr[], int c) {
    return asciiArr[c] > 0;
}

/**
 * Increment the count of the ascii index in the array
 * @param _cf
 * @param c
 */
void incrementCharCount(struct charFrequency *_cf, int c) {
    ++(*_cf).count[c];
}

/**
 * Init a new ascii index in the array, and set count to 1
 * @param _cf
 * @param c
 */
void insertNewCharCount(struct charFrequency *_cf, int c) {
    //we use the ascii value of the char to store its index
    (*_cf).count[c] = 1;
}

