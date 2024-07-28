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
 * === Get The Line Dynamically ===
 *
 *  Implement a function that acquires a line from the console and has this prototype:
 *
 *    char *get_line_alloc(int *plen)
 *
 * Goals:
 *  - don't use scanf!
 *  - acquire a string up to the newline character
 *  - always put a null characher at the end of the buffer
 *  - return a newly allocated buffer containig the entire input string
 *  - if given, store the length of the input string in plen
 *  - plen may be NULL
 *  - return NULL if an error occurs
 *  - implement a main loop that asks the user to insert a line, acquire it and print it
 *  - terminate the main loop when the user enters "END"
 *  - in the main loop manage the allocated buffer
 *
 * Tips:
 *  - something might be useful to dynamically allocate memory...
 *
 */

#define ALLOC_BLOCK_SIZE 5
#define EXIT_COND "quit"

char *get_line_alloc(int *plen);

int main()
{
    char *line = NULL;
    int len = 0;

    do
    {
        printf("Please enter a line: \n");
        /* code */
        free(line);
        line = get_line_alloc(NULL);

        if (line)
        {
            printf("%s (len=%d)\n", line, len);
        }
        else
        {
            printf("Could not allocate memory\n");
        }
    } while (line && strcmp(line, EXIT_COND));

    return EXIT_SUCCESS;
}

char *get_line_alloc(int *plen)
{
    if (!plen)
    {
        plen = malloc(sizeof(*plen));

        if (!plen)
        {
            return NULL;
        }
    }

    *plen = 0;

    char *line = NULL;
    int buffur_size = 0, input = 0;

    while (true)
    {
        input = getchar();

        if (buffur_size <= *plen)
        {
            buffur_size += ALLOC_BLOCK_SIZE;

            char *r_line = realloc(line, buffur_size);

            if (!r_line)
            {
                free(line);
                return NULL;
            }

            line = r_line;
        }

        if (input != '\n' && input != EOF)
        {
            line[*plen] = (char)input;
            (*plen)++;
        }
        else
        {
            break;
        }
    }

    line[*plen] = '\0';

    return line;
}
