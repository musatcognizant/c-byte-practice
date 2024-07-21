#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * === Sphere ===
 *
 * Calculate surface and volume of a sphere
 *
 * Goals:
 *  - prompt user to enter the radius
 *  - calculate the surface area
 *  - calculate the enclosed volume
 *  - print the radius and the results in decimal format (2 digit of precision)
 *  - print the radius and the results in scientific notation (3 digits of precision)
 *  - check the results
 */

int main()
{
    const double pi = 3.14159265359;
    double r;

    printf("\tEnter radius:");
    scanf("%lf", &r);

    double A = 4 * pi * r * r;
    double V = (4.00 / 3.00) * pi * r * r * r;

    printf("\t\t\t%0.2lf\n", A);
    printf("\t\t\t%0.2lf\n", V);

    return EXIT_SUCCESS;
}
