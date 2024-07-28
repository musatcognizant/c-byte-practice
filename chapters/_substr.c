#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main()
{
    char str[] = "DADADADADDADADADADADD";

    int i = 0;
    for (; str[i] != '\0'; i++)
        ;
    printf("Size id : %d\n", i);
    printf("Size id : %lu\n", strlen(str));

    char str1[] = "gugugugugu";
    printf("Before copy: \"%s\"\n", str);
    strncpy(str, str1, sizeof(str1));
    printf("After copy: \"%s\"\n", str);

    return EXIT_SUCCESS;
}
