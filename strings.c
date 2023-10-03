#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * sizeof
 * strlen
 * strcpy
 * strncpy
 * strcmp
 * strncmp
 * 
 */

int main()
{
    char my_string[] = "I love programming in C!";
    printf("%s\n", my_string);

    /* String Length */
    int i;
    for (i = 0; my_string[i] != '\0'; i++);
    printf("length: %d\n", i);
    printf("sizeof(my_string): %ld\n", sizeof(my_string));

    /* String Length: Built In Method */
    printf("strlen(my_string): %ld\n", strlen(my_string));

    /* String Copy: strcpy strncpy */
    char another_string[] = "Programming is fun";
    printf("Before copy: \"%s\"\n", my_string);
    printf("After copy: \"%s\"\n", strcpy(my_string, another_string));  // Do not use strcpy!

    char another_long_string[] = "This is a very very very long string...";
    printf("Before copy: \"%s\"\n", my_string);
    printf("After copy: \"%s\"\n", strncpy(my_string, "Hello", 3));     // The '\0' is missing! 
    printf("Before copy: \"%s\"\n", my_string);
    printf("After copy: \"%s\"\n", strncpy(my_string, "Hello", sizeof(my_string))); 
    printf("Before copy: \"%s\"\n", my_string);
    strncpy(my_string, another_long_string, sizeof(my_string));
    my_string[sizeof(my_string) - 1] = '\0';
    printf("After copy: \"%s\"\n", my_string);

    /* String Compare: strcmp, strncmp */
    char str_1[] = "abc";
    char str_2[] = "abcaaaa";
    printf("strcmp %s, %s, %d\n", str_1, str_2, strcmp(str_1, str_2));
    printf("strncmp %s, %s, %d\n", str_1, str_2, strncmp(str_1, str_2, 3));



    return EXIT_SUCCESS;
}