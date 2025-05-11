
#include <stdio.h>

void swap(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void permute(char **array, int current_index, int length) {
  if (current_index == length) {
    // Base case: print the current permutation
    for (int i = 0; i < length; i++) {
      printf("%s ", array[i]);
    }
    printf("\n");
  } else {
    for (int i = current_index; i < length; i++) {
      swap(&array[current_index], &array[i]);    // Swap current index with i
      permute(array, current_index + 1, length); // Recur for the next index
      swap(&array[current_index], &array[i]);    // Backtrack: swap back
    }
  }
}

int main() {
  char *source[] = {"a", "b", "c"};
  int length =
      sizeof(source) / sizeof(source[0]); // Get the length of the array
  permute(source, 0, length);             // Call the permute function
  return 0;
}
