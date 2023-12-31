#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>


int main()
{
    char str[] = "99 0XFF";
    char *pend, *pstart = str;

    while(true)
    {
        long num = strtol(pstart, &pend, 0);

        printf("\nConverting: %s\n", pstart);
        printf("errno: %d %s\n", errno, errno == ERANGE ? "(ERANGE)" : "");
        printf("%s\n", pend == pstart ? "pend == pstart (ERR)" : "pend != pstart (OK)");
        if (errno || pend == str)
        {
            printf("Conversion error!\n");
        }
        else
        {
            printf("Conversion: %ld\n", num);
        }

        if (pend == pstart)
        {
            break;
        }
        

        pstart = pend;
    }

    return EXIT_SUCCESS;
}