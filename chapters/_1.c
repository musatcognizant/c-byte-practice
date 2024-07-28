#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * === Bunch Of Constants ===
 *
 * Define the following numeric constants:
 *  - moonLanding: 1969
 *  - speedOfLight: 299792458
 *  - pi: 3.142
 *  - hexaDead: 0xDEAD
 *  - hexaSecret: 51966
 *
 * Print with following formats:
 *  - moonLanding:
 *      - integer, 10 characters width, padded with spaces
 *      - integer, 10 characters width, padded with zeroes
 *  - speedOfLight:
 *      - floating point without digits after decimal point
 *      - scientific notation with 3 digit of precision
 *  - pi:
 *      - floating point with 2 digits of precision
 *      - scientific notation with 1 digit of precision, sign forced
 *  - hexaDead:
 *      - unsigned hexadecimal integer, uppercase, leading 0x
 *      - unsigned integer, 6 characters width
 *  - hexaSecret:
 *      - unsigned hexadecimal integer, lowercase, no leading 0x
 *
 */

int main()
{
    const unsigned int mL = 1969U;
    const double sL = 299792458;
    const double pi = 3.142;
    const unsigned int dead = 0xDEADU;
    const unsigned int secret = 51966U;

    printf("\t%10d | Moon landing\n", mL);
    printf("\t%010d | Moon landing\n", mL);
    printf("\t%10.0f | Light Speed\n", sL);
    printf("\t%10.3E | Light Speed\n", sL);
    printf("\t%10.2f | Light Speed\n", pi);
    printf("\t%+10.1e | Light Speed\n", pi);
    printf("\t0x%10X | Light Speed\n", dead);
    printf("\t%6u | Light Speed\n", dead);
    printf("\t%x| Light Speed\n", secret);
    printf("\t%10.1X | Light Speed\n", secret);

    return EXIT_SUCCESS;
}
