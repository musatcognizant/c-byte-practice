#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/**
 * === Get The Line ===
 *
 *  Implement a function that acquires a line from the console and has this prototype:
 *
 *    int get_line(char dst[], int size)
 *
 * Goals:
 *  - don't use scanf!
 *  - acquire a string up to the newline character
 *  - always put a null characher at the end of the buffer
 *  - truncate the acquisition to leave space at the end of the buffer for the null character
 *  - return the number of characters acquired, excluding the null character
 *  - implement a main loop that asks the user to insert a line, acquire it and print it
 *  - terminate the main loop when the user enters "END"
 *
 */

#define SIZE 5
#define EXIT_COND "quit"

int get_line(char str[], int size);
void clear_stdin();

int main()
{
    char str[SIZE];

    while (true)
    {
        printf("Please enter a line: \n");
        int n = get_line(str, SIZE);

        if (strcmp(str, EXIT_COND))
        {
            printf("[%d] %s \n Type %s to exit program \n", n, str, EXIT_COND);
        }
        else
        {
            break;
        }
    }

    return EXIT_SUCCESS;
}

void clear_stdin()
{
    int c = ' ';

    while (c != '\n' && c != EOF)
    {
        // consume stdin
        c = getchar();
        printf("\n C is %c\n", c);
    }
};

int get_line(char str[], int size)
{
    int counter = 0;
    for (; counter < size - 1; counter++)
    {
        // gets char from stdin
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            break;
        }
        else
        {
            str[counter] = (char)c;
        }
    }
    if (counter == size - 1)
    {
        clear_stdin();
    }

    str[counter] = '\0';
    return counter;
}
