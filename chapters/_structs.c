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

#define MAX_DIMENSIONS 3

double calc_dist(int dim, double a[dim], double b[dim]);

struct GUY
{
    char *name;
    bool active;
    int dim;
    // double pos[]; // flexible array member / incomplete array
    double pos[MAX_DIMENSIONS];
};

/* Aliasing with typedef  */
typedef struct Dude
{
    char *name;
    bool active;
    int dim;
    // double pos[]; // flexible array member / incomplete array
    double pos[MAX_DIMENSIONS];
    struct Dude *dude;
} Dude;

typedef struct Veh
{
    char *model;
    int speed;
    Dude owner;
} Veh;

int main()
{
    // implicit declaration
    Dude elon = {
        "Elon MUsk",
        true,
        3,
        {1, 2, 3},
    };

    // Explicit initialization
    Dude bill = {
        .name = "Billutz",
        .active = true,
        .dim = '3',
        .pos = {3, 1, 2},
    };

    Veh moto = {
        .model = "HOnda",
        .speed = 200,
        .owner = {
            .name = "Andrea",
            .active = true,
            .dim = 3,
            .pos = {100, 2, 300},
        },
    };

    // initilize struct with values from another struct
    Dude jeff = elon;
    jeff.name = "Jeff";

    printf("\n\tThe dist between %s  and %s is : %.1f\n", jeff.name, moto.owner.name, calc_dist(MAX_DIMENSIONS, elon.pos, moto.owner.pos));

    return EXIT_SUCCESS;
}

double calc_dist(int dim, double a[dim], double b[dim])
{
    double sum = 0;

    for (int i = 0; i < dim; i++)
    {
        sum += pow(a[i] - b[i], 2);
    }

    return sqrt(sum);
}
