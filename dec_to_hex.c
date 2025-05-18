#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("===^^===\n");
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Enter a number: ");

    int the_number;
    scanf("%d", &the_number);

    printf("Decimal representation:%10d\n", the_number);
    printf("Converted to hexadecimal:%8X\n", the_number);
    printf("===^^===\n");
    
    return EXIT_SUCCESS;
}