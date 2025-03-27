#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int main(int argc, char *argv[]) {

  int (*pointer_to_generic)(int, int);
  int (*pointer_to_arr_of_generic[3])(int, int) = {add, sub};

  pointer_to_generic = mul;
  printf("%d\n", (*pointer_to_generic)(9, 9));
  printf("%d\n", pointer_to_arr_of_generic[0](2, 4));

  return EXIT_SUCCESS;
}
