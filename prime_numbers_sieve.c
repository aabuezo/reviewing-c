#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#define LEN 1000000
#define MAX_LIMIT 10000000


bool is_prime(int *const sieve, int num, int limit)
{
    int sqrt_num = sqrt(num);
    for(int i = 0; i < limit && sieve[i] <= sqrt_num; i++)
    {
        if (num % sieve[i] == 0)
        {
            return false;
        }
    }
    return true;
}


int get_prime_numbers(int *const sieve, int num)
{
    int idx = 0;
    for (int i = 2; i <= num; i++)
    {
        if (is_prime(sieve, i, idx))
        {
            sieve[idx++] = i;
        }
    }
    return idx;
}


void print_primes(int *const sieve, int num)
{
    for (int i = 0; i < num && i < 50; i++)
    {       
        printf("%d ", sieve[i]);
    }
    printf("\n");
}


double elapsed_time_seconds(clock_t start, clock_t end)
{
    return (end - start) / (double)CLOCKS_PER_SEC;
}


int main() 
{
    int sieve[LEN] = {};
    int user_input = 0;
    int found;

    printf("Enter a number (2 < number < %d): ", MAX_LIMIT);
    scanf("%d", &user_input);

    if (user_input < 2 || user_input > MAX_LIMIT)
    {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    printf("Finding prime numbers with sieve:\n");
    clock_t start_2 = clock();
    found = get_prime_numbers(sieve, user_input);
    clock_t end_2 = clock();
    printf("%d prime numbers found.\n", found);
    printf("Took %.1f [ms]\n", elapsed_time_seconds(start_2, end_2) * 1e3);
    print_primes(sieve, 250);

    return EXIT_SUCCESS;
}