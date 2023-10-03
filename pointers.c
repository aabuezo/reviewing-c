#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() 
{
    char a = 'A';
    char *ptr = &a;
    printf(" 1 | %c, %c, %lu\n", a, *ptr, (uint64_t) ptr);

    char b = 'B';
    ptr = &b;
    printf(" 2 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr);

    *ptr = 'C';
    printf(" 3 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr);

    (*ptr)++;
    printf(" 4 | %c, %c, %lu\n", b, *ptr, (uint64_t) ptr);

    unsigned x = 'A';
    ptr = (char *)&x;
    printf(" 5 | %u, %c, %lu\n", x, *ptr, (uint64_t) &x);

    unsigned y = 'B';
    ptr = (char *)&y;
    printf(" 6 | %u, %c, %lu\n", y, *ptr, (uint64_t) &y);

    x = 0xABCD1240;
    ptr = (char *) &x;
    printf(" 7 | %X, %X, %c\n", x, *ptr, *ptr);

    *ptr = 'A';
    printf(" 8 | %u, %X, %X, %c\n", x, x, *ptr, *ptr);

    unsigned *uint_ptr = (unsigned *)ptr;
    *uint_ptr = 'C';
    printf(" 9 | %u, %X, %X, %c\n", x, x, *ptr, *ptr);

    ptr = NULL;
    // if(ptr != NULL)
    if (ptr)
    {
        printf("10 | Pointed value: %d\n", *ptr);
    }

    return EXIT_SUCCESS;
}