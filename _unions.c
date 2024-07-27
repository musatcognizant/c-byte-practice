#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

void print_bits(void *data, int size);

typedef struct
{
    uint8_t enable : 1;
    uint8_t ready : 1;
    uint8_t mode : 2;
    uint8_t other : 2;

} RegBits;

typedef union
{
    /* data */
    RegBits bits;
    uint8_t byte;
} HardReg;

typedef union
{
    char word[5];
    struct
    {
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
    } bytes;
} Word;

int main()
{
    HardReg reg_A = {.byte = 0b00001100};

    printf("\nregA: %d\n", reg_A.byte);

    print_bits(&reg_A, sizeof(reg_A));
    reg_A.bits.mode = 0;
    puts("\n\nMODIFIED");
    print_bits(&reg_A, sizeof(reg_A));

    Word reg_B = {.word = "ABCD\0"};

    printf("\n\n%s", reg_B.word);

    reg_B.bytes.byte2 = 'X';
    reg_B.bytes.byte3 = 'Y';
    reg_B.bytes.byte4 = 'Z';
    printf("\n\n%s \n\n", reg_B.word);

    return EXIT_SUCCESS;
};

void print_bits(void *data, int size)
{
    uint8_t *byte = data;

    // printf("%d", byte[4] & 255);

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            // printf("0x%08X | ", ((byte[i] << j) & 0x80) >> 7);
            printf("%d | ", ((byte[i] << j) & 0b10000000) >> 7);
        };

        puts("\nREVERESESE   ");
        for (int j = 0; j < 8; j++)
        {
            printf("%d | ", (byte[i] >> j) & 1);
        };
    };

    puts("");
};
