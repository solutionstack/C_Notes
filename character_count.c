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

bool seenChar(const int *, int, size_t);

void insertNewCharCount(struct charFrequency *, int);

void incrementCharCount(struct charFrequency *, int);

char *getSpecialChar(int);

int main() {
    //zero the global array, as we can't depend on C's default values
    memset(cf.count, 0, sizeof cf.count);

    size_t arr_len;
    int c, nc = 0,
            ns = 0,
            nl = 0,
            nt = 0,
            nw = 0;
    bool IN_WORD = false,
            OUT_WORD = false;

    //simulate EOF with Ctrl+D or Control+D (Mac)
    for (; c = getchar(), c != EOF;) {
        ++nc;

        if (c == '\n') ++nl;
        if (c == 32) { //ascii space
            OUT_WORD = true;
            IN_WORD = false;
            ++ns;
        }
        if (c == 9) ++nt; //ascii tab


        if (c != ' ' && !IN_WORD) {
            IN_WORD = true;
            OUT_WORD = false;
            ++nw;
        }

        arr_len = sizeof(cf.count) / sizeof(cf.count[0]);

        //if we have seen the char before, increment its count
        if (seenChar(cf.count, c, arr_len)) {
            incrementCharCount(&cf, c);
        } else {
            insertNewCharCount(&cf, c);
        }
    }
    printf("\n last %c\n", c);

    printf("Total chars:\t %d\n", nc);
    printf("Total tabs:\t %d\n", nt);
    printf("Total spaces:\t %d\n", ns);
    printf("Total new-lines:\t %d\n", nl);
    printf("Total words:\t %d\n", nw);

    printf("\n\nCharacter frequency:\n");
    printf("ASCII\t|\tCHAR\t|\tCOUNT \n");


    char *spc;
    for (int i = 0; i < arr_len; i++) {

        if (!cf.count[i]) continue; //no count registered for this ascii index

        spc = getSpecialChar(i);
        if (strcmp(spc, "") != 0) {//strcmp so we don't compare pointers i.e char *
            printf("%d\t|\t%s\t|\t%d \n", i, spc, cf.count[i]);
            continue;
        }

        printf("%d\t|\t%c\t|\t%d \n", i, (char) i, cf.count[i]);


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
    char *specialCharsText[10] = {"TAB", "TEXT", "NEWLINE"};
    char *ret = "";

    for (int i = 0; i < 3; i++) {
        if (specialCharsACII[i] == c)
            ret = specialCharsText[i];
    }
    return ret;
}

/**
 * Does the ascii index already exist in the array
 * @param asciiArr
 * @param c
 * @param len
 * @return bool
 */
bool seenChar(const int *asciiArr, int c, size_t len) {
    unsigned int i = 0;
    for (;; i++) {
        if (i == c && asciiArr[i] > 0) return true;
        if (i == len) break;
    }

    return false;
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

