// C Program to find the size of the union
#include <stdio.h>

// declaring multiple unions
union test1 {
    int x;
    int y;
} Test1;

union test2 {
    int x;
    char y;
} Test2;
typedef enum e1 {
    A,
    B,
    C
} ENUM1;
typedef union test3 {
    int arr[10];
    char y;
} Test3;

// driver code
int main() {
    ENUM1 e = A;
    // finding size using sizeof() operator
    int size1 = sizeof(Test1);
    int size2 = sizeof(Test2);
    int size3 = sizeof(Test3);

    const Test3 t3 = {
        .arr = {1},
        .y =  '2'
    };

    printf("%d\n", t3.arr[0]);
    printf("%c\n", t3.y);

    printf("Sizeof test1: %d\n", size1);
    printf("Sizeof test2: %d\n", size2);
    printf("Sizeof test3: %d\n", size3);
    printf("Enum instance: %d", e);
    return 0;
}
