/**
 *  Store consecutive chas using pointers to pointers
 */
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char **p2p;

  for (int i = 0; i < 6; i++) {

    if (i == 0) {
      p2p = (char **)malloc(sizeof(char *));
      if (p2p == NULL) {
        perror("malloc:");
        return EXIT_FAILURE;
      }

    } else {

      char **temp = (char **)realloc(
          p2p, sizeof(char *) * (i + 1)); // sizeof no of i char pointers

      if (p2p == NULL) {
        perror("malloc:");

        for (int i = 0; i < 6; i++)
          free(p2p[i]);

        free(p2p);
        return EXIT_FAILURE;
      }
      p2p = temp;
    }

    p2p[i] = (char *)malloc(2); // we're storing strings of size  plus nul1
    if (p2p[i] == NULL) {
      perror("malloc:");
      return EXIT_FAILURE;
    }

    sprintf(p2p[i], "%s", (char[2]){'A' + i, 0});
  }

  for (int i = 0; i < 6; i++) {
    printf("-%s\n", p2p[i]);
  }

  for (int i = 0; i < 6; i++) {
    free(p2p[i]);
  }
  free(p2p);

  return EXIT_SUCCESS;
}
