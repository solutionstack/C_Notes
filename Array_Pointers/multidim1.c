#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[5][5];

  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 5; i++) {
      arr[j][i] = i;
    }
  }

  int column_idx = 0;
  int row = 0;

  for (int i = 0; i < 25; i++) {
    printf("row: %d; column: %d; val: %d\n", row, column_idx,
           *(arr[row] + column_idx)); // arr[row][column_idx]

    if (column_idx++ == 4) {
      ++row;
      column_idx = 0;
    }
  }

  return EXIT_SUCCESS;
}
