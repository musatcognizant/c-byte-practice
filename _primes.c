#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define LOWER_LIMIT 3
#define UPPER_LIMIT 1000000
#define PRIME_FOUND_LEN 100000
#define PRINTABLE_LIMIT 50

/**
 * === Prime Numbers Further Improved ===
 *
 * Prime number: integer number greater than 1, only divisible by 1 and itself
 *
 * Goals:
 *  - Find all prime numbers below a given upper limit given by the user
 *  - Check that 2 < upper limit <= 1 million
 *  - Store prime numbers in an array of 100k integers
 *  - Optimize the program by using stored prime numbers
 *  - Compare the execution time of the simple version with the optimized one
 *  - Implement printing of primes found separately from the algorithm
 *  - Print up to 50 prime numbers found
 *
 * Simple version:
 *  - given an input number, n, check whether it is evenly divisible by ANY NUMBER
 *    between 2 and sqrt(n) (i.e. that the division leaves no remainder)
 *
 * Optimized version:
 *  - given an input number, n, check whether it is evenly divisible by ANY PRIME NUMBER
 *    between 2 and sqrt(n) (i.e. that the division leaves no remainder)
 *
 */

bool is_prime(int no, int primes[], int count, bool optimize);
bool is_prime_optimized(int no, int primes[], int count);
bool is_prime_unoptimized(int no);
int get_prime(int limit, int primes[], bool optimize);
void print_primes(int primes[], int limit, double time);
double elapsed_time_sec(clock_t start, clock_t end);

int main()
{
    int arr[PRIME_FOUND_LEN];
    int no = LOWER_LIMIT - 1;
    int count = 0;
    clock_t start = 0, end = 0;
    while (no < LOWER_LIMIT || no > UPPER_LIMIT)
    {
        printf("Enter\n\t");
        scanf("%d", &no);
    }

    start = clock();
    count = get_prime(no, arr, false);
    end = clock();
    print_primes(arr, count, elapsed_time_sec(start, end));

    start = clock();
    count = get_prime(no, arr, true);
    end = clock();
    print_primes(arr, count, elapsed_time_sec(start, end));
    return EXIT_SUCCESS;
}

int get_prime(int limit, int primes[], bool optimize)
{
    int count = 0;
    for (int i = 2; i < limit; i++)
    {
        if (is_prime(i, primes, count, optimize))
        {

            primes[count] = i;
            count++;
        }
    }

    return count;
};

bool is_prime(int no, int primes[], int count, bool optimize)
{
    return optimize ? is_prime_optimized(no, primes, count) : is_prime_unoptimized(no);
};

bool is_prime_optimized(int no, int primes[], int count)
{
    const int limit = sqrt(no);

    for (int i = 0; i < count && primes[i] <= limit; i++)
    {
        if (no % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
};

bool is_prime_unoptimized(int no)
{
    const int limit = sqrt(no);

    for (int i = 2; i <= limit; i++)
    {
        if ((no % i) == 0)
        {
            return false;
        }
    }

    return true;
};

void print_primes(int primes[], int limit, double time)
{
    printf("We found %5d prime numbers.\n", limit);
    for (int i = 0; i < limit && i < PRINTABLE_LIMIT; i++)
    {
        printf("%d, ", primes[i]);
    }
    printf("\n\tTime is \t %.1f\n\n\n", time);
}

double elapsed_time_sec(clock_t start, clock_t end)
{
    return ((end - start) / (double)CLOCKS_PER_SEC) * 1e3;
}
