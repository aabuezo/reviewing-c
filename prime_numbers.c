#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define LEN 100000
#define MAX_LIMIT 1000000


bool is_prime(int num)
{
    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}


size_t find_primes(int *const sieve, int up_to)
{
    size_t idx = 0;
    for (size_t i = 2; i <= up_to; i++)
    {
        if (is_prime(i))
        {
            *(sieve + idx++) = i;
        }
    }
    return idx;
}


void print_primes(int *const sieve, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d\n", sieve[i]);
    }
    
}


int main() 
{
    int sieve[LEN] = {0};
    int user_input = 0;
    printf("Enter a number (2 < number < 1.000.000): ");
    scanf("%d", &user_input);

    if (user_input < 2 || user_input > MAX_LIMIT)
    {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    size_t len = find_primes(sieve, user_input);
    print_primes(sieve, len);
    
    return EXIT_SUCCESS;
}