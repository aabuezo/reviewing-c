#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char *get_line_alloc(int *plen)
{
    if (!plen)
    {
        /* the user doesn't care about the string length */
        plen = malloc(sizeof(*plen));
        if (!plen)
        {
            /* cannot allocate memory... failure */
            return NULL;
        }
    }
    
    *plen = 0;

    char *line = NULL;
    int buffer_size = 0, input;
    const int alloc_block_size = 5;

    while (true)
    {
        input = getchar();

        if (buffer_size <= *plen)
        {
            /* resize the memory block! */
            buffer_size += alloc_block_size;
            char *realloc_line = realloc(line, buffer_size);

            if (!realloc_line)
            {
                /* cannot do reallocation... failure */
                free(line);
                return NULL;
            }
            
            /* reallocation done! */
            line = realloc_line;
        }
        

        if (input != '\n' && input != EOF)
        {
            line[(*plen)++] = (char)input;
        }
        else
        {
            break;
        }
        
    }
    
    line[*plen] = '\0';
    return line;
}


int main()
{
    char *line = NULL;
    int len = -1;

    do
    {
        printf("Enter a line (END to quit):\n");

        free(line);
        // line = get_line_alloc(&len);
        line = get_line_alloc(NULL);

        if (line)
        {
            printf("%s (len=%d)\n", line, len);
        }
        else
        {
            printf("Error allocating memory for line\n");
        }
        

    } while (line && strcmp(line, "END"));  // && short circuit
    

    return EXIT_SUCCESS;
}