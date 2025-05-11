
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*const long MALLOC_FILL_BYTE =*/
/*0xbebebebebebebebe; // libasan stuff, so we can't just check against NULL*/
/*int current_index;*/
void backtrack(char **input, int current_index, int len) {

  if (current_index == 1) {

    for (int i = 0; i < len; i++)
      printf("%s ", input[i]);
    printf("\nfinished perm \n");
  } else {

    for (int i = 0; i < current_index; i++) {

      backtrack(input, current_index - 1, len);
      if (current_index % 2) {

        char *temp = *(input + i);
        *(input + i) = *(input + (current_index - 1));
        *(input + (current_index - 1)) = temp;

      } else {
        char *temp = *(input + 0);

        *(input + 0) = *(input + (current_index - 1));
        *(input + (current_index - 1)) = temp;
      }
    }
  }
}

void permute(char **input, int len) { backtrack(input, len, len); }
int main(int argc, char *argv[]) {
  char *source[] = {"a", "b", "c"};

  permute(source, 3);
  return EXIT_SUCCESS;
}
