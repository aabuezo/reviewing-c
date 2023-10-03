#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#define MAX_LIMIT 1000000


bool is_prime(bool *const sieve, int num)
{
    int limit = sqrt(num);
    for(int i = 2; i <= limit; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}


void get_prime_numbers(bool *const sieve, int num)
{
    for (int i = 2; i <= num; i++)
    {
        if (is_prime(sieve, i))
        {
            sieve[i] = true;
        }
    }
}


void print_primes(bool *const sieve, int num)
{
    for (int i = 0; i < num && i < 50; i++)
    {
        if (sieve[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}


double elapsed_time_seconds(clock_t start, clock_t end)
{
    return (end - start) / (double)CLOCKS_PER_SEC;
}


int main() 
{
    bool sieve[MAX_LIMIT] = {};
    int user_input = 0;

    printf("Enter a number (2 < number < %d): ", MAX_LIMIT);
    scanf("%d", &user_input);

    if (user_input < 2 || user_input > MAX_LIMIT)
    {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    printf("Finding prime numbers with sieve:\n");
    clock_t start_2 = clock();
    get_prime_numbers(sieve, user_input);
    clock_t end_2 = clock();
    printf("Took %.1f [ms]\n", elapsed_time_seconds(start_2, end_2) * 1e3);
    print_primes(sieve, 50);

    return EXIT_SUCCESS;
}