#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_DIM 3

typedef struct Dude
{
    char *name;
    bool active;
    int dim;
    double pos[MAX_DIM];
} Dude;

typedef struct FlexiDude
{
    char *name;
    bool active;
    int dim;
    double pos[]; // flexible array member
} FlexiDude;

typedef struct BLEHeader
{
    uint8_t pdu : 4;
    uint8_t rfu1 : 2;
    uint8_t t_add : 1;
    uint8_t r_add : 1;
    uint8_t length : 6;
    uint8_t rfu2 : 2;

} BLEHeader;

typedef struct BLEPacket
{
    BLEHeader header;
    uint8_t payload[];
} BLEPacket;

FlexiDude *alloc_dude_flexi(int dim);
void read_ble_packet(BLEPacket *pkt);

int main()
{
    printf("Size of dude is:\t%10lu\n", sizeof(Dude));
    printf("Size of flexi dude is:\t%10lu\n", sizeof(FlexiDude));

    const uint8_t buff[] = {255, 6, 3, 4, 5, 6, 77, 18, 10, 28, 75};

    read_ble_packet((BLEPacket *)buff);

    return EXIT_SUCCESS;
}

FlexiDude *alloc_dude_flexi(int dim)
{
    size_t size = sizeof(((FlexiDude *)0)->pos[0]);
    FlexiDude *dude = malloc(sizeof(FlexiDude) + (dim * size));

    if (!dude)
    {
        return NULL;
    }

    dude->dim = dim;

    return dude;
};

void read_ble_packet(BLEPacket *pkt)
{
    const uint8_t size = pkt->header.length;

    printf("%d\n", pkt->header.rfu1);
    for (uint8_t i = 0; i < size; i++)
    {

        printf("0x%x\n", pkt->payload[i]);
    }
    puts("");
};
