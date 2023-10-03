#include <stdio.h>
#include <stdlib.h>


int main() 
{
    int some_data = 255;

    int *const my_const_ptr = &some_data;   // const pointer

    const int *my_ptr_to_const = &some_data;    // pointer to const

    const int *const my_const_ptr_to_const = &some_data;    // everything constant

    return EXIT_SUCCESS;
}