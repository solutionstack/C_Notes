/*The idea here is to access the 2D indices with the help of a pointer variable.
 * This can be done in similarly to how the */
/*single dimension array is accessed with a pointer variable. ''To do so, we
 * need to assign the address of the individual */
/*row to the pointer variable.*/
#include <stdint.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int data[5][5];
  int i, j;
  int count = 0;
  int(*aptr)[5];
  int *dataptr;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      data[i][j] = count++;
    }
  }
  aptr = data;
  for (i = 0; i < 5; i++) {
    printf("Address of %d row = %p\n", i, (*aptr + i));
    dataptr = *aptr + i;

    for (j = 0; j < 5; j++) {
      printf("row:%d, col:%d ; column address: %p val = %d \n", i, j, dataptr,
             *dataptr);
      dataptr++;
    }
    printf("\n");
  }
  return 0;
}
