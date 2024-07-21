#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * === Float Decomposition ===
 *
 * Build a program that decomposes integer and fractional parts of a floating point number.
 *
 * Goals:
 *  - Write a function called decompose that receives a floating point number
 *    and returns an integer part (int) and fractional part (float).
 *  - Acquire a floating point from the keyboard.
 *  - Use the decompose function and print to screen integer and fractional part.
 *  - Reconstruct the original floating point number and print it.
 *
 * Tips:
 *  - You might need pointers ;)
 *  - Think carefully about the const keyword.
 */

void decompose(float f, int *a, float *b);

void swappiness(int *p1, int *p2);

int main()
{

    // int a = 1, b = 0;
    // printf("\t\t\tBoth %5u and %3u\n", a, b);

    // swappiness(&a, &b);
    // printf("\t\t\tBoth %5u and %3u\n", a, b);

    float f = 0.00;
    int a = 0;
    float b = 0.00;

    printf("Enter a float: ");
    scanf("%f", &f);

    decompose(f, &a, &b);

    printf("%5d\n\n", a);
    printf("%5.2f\n\n", b);
    printf("%5.2f\n\n", a + b);

    return EXIT_SUCCESS;
}

void swappiness(int *p1, int *p2)
{
    int temp = 0;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void decompose(float f, int *const a, float *const b)
{
    *b = (float)f - (int)f;
    *a = (int)f;
}
