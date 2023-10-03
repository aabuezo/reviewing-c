#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LEN 5

int main()
{
    /* Array initialization from brace-enclosed lists */
    int x[] = {1, 2, 3, 4, 5};  // x has type int[5] and holds 1, 2, 3, 4, 5
    // int y[LEN] = {1, 2, 3};     // y has type int[5] and holds 1, 2, 3, 0, 0
    // int z[LEN] = {0};           // z has type int[5] and holds 0, 0, 0, 0, 0

    /* Array initialization with designators (sparse arrays) */
    // int w[LEN] = {[1] = 1, [3] = 1};        // w has type int[5] and holds 0, 1, 0, 1, 0
    // int q[LEN] = {[1] = 3, [LEN - 1] = 5};  // q has type int[5] and holds 0, 3, 0, 0, 5
    int t[10]  = {[0] = 5, 4, [LEN - 1] = 3, 2, 1}; // t has type int[10] and holds 5, 4, 0, 0..., 3, 2, 1

    /* size of an array */
    printf("sizeof(t): %lu\n", sizeof(t)); // size in bytes
    printf("sizeof(t) / sizeof(t[0]): %lu\n", sizeof(t) / sizeof(t[0])); // size in elements

    /* accesing arrays with pointers */
    int *p_int = x;      // same as: int *pint = &x[0]
    printf("x[2]: %d\n", x[2]);
    printf("p_int[2]: %d\n", p_int[2]);

    printf("*(x + 2): %d\n", *(x + 2));
    printf("*(p_int + 2): %d\n", *(p_int + 2));

    printf("&x[0]: 0x%lX\n", (uint64_t) &x[0]);
    printf("x: 0x%lX\n", (uint64_t) x);
    printf("p_int: 0x%lX\n", (uint64_t) p_int);
    printf("sizeof(p_int): %ld\n", sizeof(p_int));


    return EXIT_SUCCESS;
}