//
// Created by olu on 10/09/23.
//
//simple grep
#define P99_NEW(T, ...) T ## _init(malloc(sizeof(T)), __VA_ARGS__)
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <getopt.h>
int main(int argc, char *argv[]) {
     int ch;
    char *argvalue;
    argvalue = malloc( sizeof (char) *110);
    int option_index = 0;
    static int verbose_flag;


    static struct option long_options[] ={
            {
                "verbose", no_argument, &verbose_flag,1}
            };


    while ((ch = getopt_long(argc, argv,"xf:n",long_options, &option_index )) != -1) {

            switch (ch) {

                case 0:
                    if (long_options[option_index].flag !=0){
                        printf("long option is %s\n", long_options[option_index].name);
                    }
                    break;
                case 'x':
                    printf("arg -x\n");
                    break;
                case 'n':
                    printf("arg -n\n");
                    break;
                case 'f':
                    printf("arg -f\n");
//                    strcpy(argvalue  ,optarg);
                    printf("value for -f: %s\n", optarg);
                    break;
                case '?':
                    printf("find: illegal option %c\n", optopt);
                default:
                    break;
            }
        }
   // printf("optind %d\n",optind);
//    printf("%s\n",argv[optind]);
//    /printf("%s\n",argv[++optind]);

    }

