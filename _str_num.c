#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main()
{
    // unsigned int s = 25U;
    // unsigned long long int wc = 7000000000ULL;
    // double d = 1.234567890;
    // double wp = 7.801E9;
    // double plank = 6.626E-34;

    // printf("%12u | Students\n", s);
    // printf("%12llu | Wc      \n", wc);
    // printf("%12.3f | d      \n", d);
    // printf("%12.1e | WP      \n\n", wp);
    // printf("%12.1E | plank      \n\n", plank);
    // printf("%12.3E | plank      \n\n", plank);

    char c = 'A';

    printf("Char :\t%5c\n", c);

    c++;
    printf("Char :\t%5c\n", c);

    printf("Enter a char: ");
    c = getchar();
    printf("Char :\t%5c\n", c);

    return EXIT_SUCCESS;
}
