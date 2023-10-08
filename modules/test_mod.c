#include <stdio.h>
#include <stdlib.h>
#include "mod_1.h"
#include "mod_2.h"

int main()
{
    Led led = LED_ON;
    if (led)
    {
        printf("The Led is %d\n", led);
    }
    
    return EXIT_SUCCESS;
}