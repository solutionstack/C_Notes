//
// Created by olu on 10/6/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char **argv){
  const int id = fork();
  if (id == 0) { //fork returns zero for cheild processes
    printf("Forking again from a child\n");
    fork();
  }
  printf("Hello World:\n");
  return 0;
}

