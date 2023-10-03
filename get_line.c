#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

void clear_stdin()
{
    int c = ' ';
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int get_line(char buffer[], int size)
{
    char c;
    int i = 0;
    do
    {
        c = getchar();
        if(c != '\n')
        {
            buffer[i++] = (char)c;
        }
    } while (c != '\n' && i < size - 1 && c != EOF);
    
    if (i == size - 1)
    {
        clear_stdin();
    }
    
    buffer[i] = '\0';
    return i;
}

int main()
{
    char buf[BUF_SIZE];
    do
    {
        printf("Enter a line:\n");
        int n = get_line(buf, sizeof(buf));
        printf("[%d] %s\n", n, buf);
    } while(strcmp(buf, "END"));
    return EXIT_SUCCESS;
}