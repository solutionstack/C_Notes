//
// Created by olu on 16/10/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "fcntl.h"
void filecopy(FILE *, FILE *);

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[]) {
    FILE *fp;
    char *prog = argv[0]; /* program name for errors */
    if (argc == 1) /* no args; copy standard input */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n",
                        prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {

        perror(" perror:");

        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);

}

void filecopy(FILE *ifp, FILE *ofp) {
    char *c = (char *) malloc(500);
    while ((f(c, 500, ifp)) != NULL) //or getc putc
        fputs(c, ofp);

    FILE *sp = popen("/usr/bin/date", "r");
    if (sp == NULL) {
        fprintf(stderr, "unable to open process");
        exit(1);

    }
    fgets(c, 50, sp);
    fputs(c, ofp);
    fclose(sp);

}
