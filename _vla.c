#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MIN_ROWS 2
#define MIN_COLS 2
#define MAX_COLS 10
#define MAX_ROWS 10
#define UPPER_LIMIT 1000
#define LOWER_LIMIT 10

/**
 * === Random Matrix ===
 *
 * Generate a random matrix and display it in direct and transposed form
 *
 * Goals:
 *  - Generate random matrix with number of rows and columns given by the user
 *  - Check that 1 < rows <= 10, the same for the columns
 *  - Generate random matrix with 0 <= numbers < upper limit given by the user
 *  - Check that 1 < upper limit <= 1000
 *  - Display the matrix in direct and transposed form
 *
 * Tips:
 *  - To generate random numbers below an upper bound you may find the modulo operator useful...
 */

void genMat(const int rows, const int cols, const int limit, int matrix[rows][cols]);
void printMat(const int rows, const int cols, int matrix[rows][cols], bool trans);

int main()
{
    int rows = 0, cols = 0, limit = 0;

    while (rows < MIN_ROWS || rows > MAX_ROWS)
    {
        printf("\tENTER rows between %d and %d\n\t", MIN_ROWS, MAX_ROWS);
        scanf("\t%d", &rows);
    }

    while (cols < MIN_COLS || cols > MAX_COLS)
    {
        printf("\tENTER cols between %d and %d\n\t", MIN_COLS, MAX_COLS);
        scanf("%d", &cols);
    }

    while (limit < LOWER_LIMIT || limit > UPPER_LIMIT)
    {
        printf("\tENTER cols between %d and %d\n\t", LOWER_LIMIT, UPPER_LIMIT);
        scanf("%d", &limit);
    }

    int mat[rows][cols];
    srand(time(NULL));
    genMat(rows, cols, limit, mat);
    printMat(rows, cols, mat, false);

    return EXIT_SUCCESS;
}

void genMat(const int rows, const int cols, const int limit, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % limit;
        }
    }
};

void printMat(const int rows, const int cols, int matrix[rows][cols], bool trans)
{
    if (!trans)
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%4d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                printf("%4d ", matrix[j][i]);
            }
            printf("\n");
        }
    }
}
