#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_DIMENSION 3

typedef struct Dude
{
    char *name;
    bool active;
    int dim;
    int pos[MAX_DIMENSION];
    struct Dude *friend;
} Dude;

typedef struct LedStatus
{
    uint8_t led1;
    uint8_t led2;
    uint8_t led3;
} LedStatus;

typedef struct StatusBitFields
{
    uint8_t led1 : 1;
    uint8_t led2 : 3;
    uint8_t led3 : 4;
} StatusBitFields;

typedef struct BLEHeader
{
    uint16_t pdu : 4;
    uint16_t rfu1 : 2;
    uint16_t t_add : 1;
    uint16_t r_add : 1;
    uint16_t length : 6;
    uint16_t rfu2 : 2;

} BLEHeader;

void print_bits(uint8_t *data, int size);
void print_bits_16(uint16_t *data, int size);

int main()
{
    Dude dude = {
        .active = true,
        .name = "Dude",
        .dim = 3,
        .pos = {100, 200, 300},
    };

    StatusBitFields status = {
        .led1 = 0,
        .led2 = 1,
        .led3 = 15,
    };

    print_bits((uint8_t *)&status, sizeof(status));

    BLEHeader header = {
        .pdu = 3,
        .t_add = 1,
        .length = 63,
    };

    // 0011001000100000
    // 1100001000010000
    print_bits_16((uint16_t *)&header, sizeof(status));

    Dude *ptrDudu = &dude;

    ptrDudu->friend = malloc(sizeof(Dude));

    Dude *friend = ptrDudu->friend;
    friend->name = "Elon";
    friend->active = true;
    friend->pos[0] = 122;
    friend->pos[1] = 155;
    friend->pos[2] = 177;
    friend->friend = &dude;

    int num = 10;
    Dude *arrOfDudes = malloc(num * sizeof(Dude));

    arrOfDudes[0].name = "Bill";
    arrOfDudes[0].friend = friend;

    *(arrOfDudes + 1) = dude;
    (arrOfDudes + 1)->friend = arrOfDudes[0].friend;
    printf("%s is friends width %s\n", arrOfDudes[1].name, arrOfDudes[1].friend->name);

    return EXIT_SUCCESS;
}

void print_bits(uint8_t *data, int size)
{
    printf("8: ");
    for (int i = 0; i < size; i++)
    {
        uint8_t byte = data[i];

        for (int j = 0; j < 8; j++)
        {
            printf("%d", (byte >> j) & 1);
        };
    };

    puts("");
};
void print_bits_16(uint16_t *data, int size)
{
    printf("16: ");
    for (int i = 0; i < size; i++)
    {
        uint16_t byte = data[i];

        for (int j = 0; j < 16; j++)
        {
            printf("%d", (byte >> j) & 1);
        };
    };

    puts("");
};
