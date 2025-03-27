// https://www.hackerrank.com/challenges/sorting-array-of-strings0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char *a, const char *b) {
  if (a == NULL && b == NULL)
    return 0; // Both are NULL

  if (a == NULL)
    return 1;

  if (b == NULL)
    return -1;

  // Handle empty strings
  if (*a == '\0' && *b == '\0')
    return 0;

  if (*a == '\0')
    return 1;

  if (*b == '\0')
    return -1;

  while (*a != '\0' && *b != '\0') {

    if (*b < *a) {

      return -1; // a is less than b

    } else if (*b > *a) {

      return 1; // a is greater than b
    }
    a++;

    b++;
  }

  // If we reach here, one of the strings is a prefix of the other

  return (*b == '\0' && *a != '\0') ? -1 : (*b != '\0' && *a == '\0') ? 1 : 0;
}

int lexicographic_sort_reverse(const char *a, const char *b) {

  int r = lexicographic_sort(a, b);
  return r == -1 ? 1 : r == 1 ? -1 : 0;
}
int count_distinct_characters(const char *str) {

  int char_count[256] = {0}; // Assuming ASCII characters

  int distinct_count = 0;

  while (*str) {

    if (char_count[(unsigned char)*str] == 0) {

      distinct_count++;
    }

    char_count[(unsigned char)*str]++;

    str++;
  }

  return distinct_count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
  if (a == NULL && b == NULL)
    return 0; // Both are NULL

  if (a == NULL)
    return 1;

  if (b == NULL)
    return -1;

  // Handle empty strings

  if (*a == '\0' && *b == '\0')
    return 0;

  if (*a == '\0')
    return 1;

  if (*b == '\0')
    return -1;

  int distinct_a = count_distinct_characters(a);

  int distinct_b = count_distinct_characters(b);

  // Sort in ascending order of distinct character counts

  return distinct_b - distinct_a == 0
             ? lexicographic_sort(a, b)
             : distinct_b -
                   distinct_a; // Returns negative if a < b, positive if a > b
}

int sort_by_length(const char *a, const char *b) {
  // Store original pointers
  const char *orig_a = a;
  const char *orig_b = b;

  int len_a = 0;
  int len_b = 0;
  for (; *a != 0; len_a++, *a++)
    ;
  for (; *b != 0; len_b++, *b++)
    ;

  if (len_a == len_b)
    return lexicographic_sort(orig_a, orig_b);

  return len_b - len_a;
}

void string_sort(char **arr, const int len,
                 int (*cmp_func)(const char *a, const char *b)) {

  for (int i = 0; i < len; i++) {

    int min_index = i; // Start with the current index as the minimum

    for (int j = i + 1; j < len; j++) {

      if (cmp_func(*(arr + min_index), *(arr + j)) <= -1) {
        min_index = j; // Update min_index if a smaller element is found
      }
    }

    // Swap the found minimum element with the first element

    if (min_index != i) {

      char *temp = *(arr + i);

      *(arr + i) = *(arr + min_index);

      *(arr + min_index) = temp;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  char **arr;
  arr = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_length);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");
}
