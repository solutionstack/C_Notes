#include <stdio.h>
#include <stdlib.h>

struct num {
  int data;
};

void updateNum(struct num **n) {
  *n = (struct num *)malloc(sizeof(struct num));
  (*n)->data = 10;
}
int main(int argc, char *argv[]) {
  struct num *num = NULL;

  updateNum(&num);

  printf("%d\n", num->data);

  return EXIT_SUCCESS;
}
