#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSION 3

typedef struct Dude
{
    char *name;
    bool active;
    int dim;
    int pos[MAX_DIMENSION];
    struct Dude *friend;
} Dude;

Dude create_bill();
Dude create_elon();
Dude *alloc_elon();
void deactivate_dude(Dude *dude);

int main()
{
    Dude bill = create_bill();
    // Dude elon = create_elon();

    bill.friend = alloc_elon();

    return EXIT_SUCCESS;
}

Dude create_bill()
{
    return (Dude){
        .name = "Dude",
        .active = true,
        .dim = 3,
        .friend = NULL,
        .pos = {1, 2, 3},
    };
};

Dude create_elon()
{
    return (Dude){
        .name = "Elon",
        .active = true,
        .dim = 3,
        .friend = NULL,
        .pos = {1, 2, 3},
    };
};

Dude *alloc_elon()
{
    Dude *elon = malloc(sizeof(Dude));

    if (!elon)
    {
        return NULL;
    };

    elon->name = "Elon";
    elon->dim = 3;
    elon->active = true;
    int pos[] = {1, 2, 3};
    memcpy(elon->pos, pos, MAX_DIMENSION);

    return elon;
};

void deactivate_dude(Dude *dude)
{
    dude->active = false;
};
