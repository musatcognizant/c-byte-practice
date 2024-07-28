#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

int find_all_chars(char str[], char c, int index[]);
void print_locations(char str[], int found, int indexes[]);
int find_substr(char str[], char sub[]);
void print_sample(char str[], char sub[], int index);
/**
 * @param {char*} str
 * @param {char*const} deli
 * @param {int} max_len
 * @param {char**} tokens
 * @returns number of tokens found in a string
 */
int tokenize_string(char str[], const char deli[], int max_len, char tokens[][max_len]);
void print_tokens(int no_tokens, int max_len, char tokens[][max_len], char str[], const char deli[]);

int main()
{
    char str[] = "ABCA, lalalal. kas-dna-sl";
    int indexes[sizeof(str)];

    int found = 0;
    found = find_all_chars(str, 'l', indexes);

    print_locations(str, found, indexes);

    int index = -1;
    index = find_substr(str, "lalalal");
    print_sample(str, "lalalal", index);

    const char deli[] = " ,.-";
    int max_len = sizeof(str);
    char tokens[max_len][max_len];
    char str_copy[max_len];
    strncpy(str_copy, str, max_len);
    int no_tokens = tokenize_string(str, deli, max_len, tokens);

    print_tokens(no_tokens, max_len, tokens, str_copy, deli);

    return EXIT_SUCCESS;
}

int find_all_chars(char str[], char c, int index[])
{

    int found = 0;
    char *ptr = str;

    do
    {
        ptr = strchr(ptr, (int)c);

        if (ptr)
        {
            index[found] = ptr - str;
            found++;
            ptr++;
        }
    } while (ptr);

    return found;
};

void print_locations(char str[], int found, int indexes[])
{
    char pattern[strlen(str)];
    memset(pattern, '.', sizeof(pattern));

    for (int i = 0; i < found; i++)
    {
        pattern[indexes[i]] = '^';
    }
    printf("\n\t\t%s \t\t\t\n", str);
    printf("\n\t\t%s \t\t\t\n", pattern);
}

int find_substr(char str[], char sub[])
{
    char *ptr = strstr(str, sub);

    return ptr ? ptr - str : -1;
}

void print_sample(char str[], char sub[], int index)
{
    printf("\n\t\t%s\n", str);

    if (index >= 0)
    {
        printf("\t\t");
        for (int i = 0; i < index + strlen(sub); i++)
        {
            if (i < index)
            {
                printf("%c", '.');
            }
            else
            {
                printf("%c", '^');
            }
        }
        printf("\n\t\t\t");
    }
}

int tokenize_string(char str[], const char deli[], int max_len, char tokens[][max_len])
{
    int i = 0;
    char *temp = str;

    for (; temp; i++)
    {
        if (i == 0)
        {
            temp = strtok(temp, deli);
        }
        else
        {
            temp = strtok(NULL, deli);
        }

        if (temp)
        {
            strncpy(tokens[i], temp, max_len);
        }
    }

    return i - 1;
};

void print_tokens(int no_tokens, int max_len, char tokens[][max_len], char str[], const char deli[])
{
    printf("\n\n delimiters:\t\"%s\"\n", deli);
    printf("%s\n", str);

    for (int i = 0; i < no_tokens; i++)
    {
        printf("[%d] %s\n", i, tokens[i]);
    }
}
