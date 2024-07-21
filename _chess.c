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

void get_allowed_moves1(char cur[], char buffer[]);
void get_allowed_moves2(char cur[], char buffer[]);
void get_allowed_moves3(char cur[], char buffer[]);

int main()
{

    char *cur = "D5";

    char buffer[100] = "";

    get_allowed_moves3(cur, buffer);

    printf("CUR : %s\n", cur);
    printf("ALLOWED : %s\n\n", buffer);

    return EXIT_SUCCESS;
}

void get_allowed_moves1(char cur[], char buffer[])
{
    const char cols[] = "ABCDEFGH";
    const char rows[] = "12345678";

    char cur_col = cur[0];
    char cur_row = cur[1];
    char *out = buffer;

    for (const char *p = cols; *p; p++)
    {
        if (*p != cur_col)
        {
            *out = *p;
            out++;
            *out = cur_row;
            out++;
            *out = ' ';
            out++;
        }
    }

    for (const char *p = rows; *p; p++)
    {
        if (*p != cur_row)
        {
            *out = cur_col;
            out++;
            *out = *p;
            out++;
            *out = ' ';
            out++;
        }
    }

    *out = '\0';
}

void get_allowed_moves2(char cur[], char buffer[])
{
    const char cols[] = "ABCDEFGH";
    const char rows[] = "12345678";

    char cur_col = cur[0];
    char cur_row = cur[1];
    char *out = buffer;

    for (const char *c = cols, *r = rows; *c || *r; *c != '\0' ? c++ : r++)
    {
        if (*c != cur_col && *r != cur_row)
        {

            *out = *c ? *c : cur_col;
            out++;

            *out = *c ? cur_row : *r;
            out++;

            *out = ' ';
            out++;
        }
    }

    *out = '\0';
}

void get_allowed_moves3(char cur[], char buffer[])
{
    const char cols_rows[] = "ABCDEFGH12345678";

    char cur_col = cur[0];
    char cur_row = cur[1];
    char *out = buffer;

    for (const char *c = cols_rows; *c; c++)
    {
        if (*c != cur_col && *c != cur_row)
        {

            *out = isdigit(*c) ? cur_col : *c;
            out++;

            *out = isdigit(*c) ? *c : cur_row;
            out++;

            *out = ' ';
            out++;
        }
    }

    *out = '\0';
}
