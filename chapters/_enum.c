#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

enum MENU
{
    A,
    B,
    C = 100,
    D
};

int main()
{
    enum MENU a = A;
    enum MENU b = D;

    printf("MENU a: %c\n", a);
    printf("MENU b: %d\n", b);

    return EXIT_SUCCESS;
}
