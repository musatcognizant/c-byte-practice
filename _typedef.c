#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    A,
    B,
    C = 100,
    D
} Menu;

int main()
{
    Menu a = A;
    Menu b = D;

    printf("MENU a: %c\n", a);
    printf("MENU b: %d\n", b);

    return EXIT_SUCCESS;
}
