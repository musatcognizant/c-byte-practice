#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main()
{
    uint8_t a = 12;
    u_int8_t b = 1U;

    u_int8_t c = a & (1 << 5);

    printf("\t\t %9d \n\n\n", (u_int8_t)~b);
    printf("\t\t %9d \n\n\n", ~(-2));
    printf("\t\t %9d \n\n\n", (u_int8_t) ~(0b11111110));

    return EXIT_SUCCESS;
}
