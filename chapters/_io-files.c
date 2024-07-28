#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define SAMPLES_LEN 100
#define DOWN_SAMPLE_K 10

void program_failure(char text[]);

int main(void)
{
    double samples[SAMPLES_LEN];

    for (uint8_t i = 0; i < SAMPLES_LEN; i++)
    {
        samples[i] = (i + 1) / 10.0;
        printf("%.1lf, ", samples[i]);
    }

    puts("END");

    FILE *fp = fopen("samples.bin", "wb");

    if (!fp)
    {
        program_failure("Could not open file!");
    }

    uint8_t count = fwrite(samples, sizeof(samples[0]), SAMPLES_LEN, fp);

    if (count != SAMPLES_LEN)
    {
        program_failure("Could not write to file!");
    }
    fclose(fp);

    double samples_down[SAMPLES_LEN / DOWN_SAMPLE_K];
    fp = fopen("samples.bin", "rb");

    puts("");

    for (uint8_t i = 0; i < SAMPLES_LEN / DOWN_SAMPLE_K; i++)
    {
        int offset = sizeof(samples_down[0]) * (DOWN_SAMPLE_K - 1);
        if (fseek(fp, offset, SEEK_CUR) != 0)
        {
            program_failure("Failed to set head!");
        };

        uint8_t count = fread(&samples_down[i], sizeof(samples_down[0]), 1, fp);

        if (count != 1)
        {
            if (feof(fp))
            {
                program_failure("Early end of file!");
            }
            else
            {
                program_failure("Some went wrong!");
            }
        }

        printf("Downsized sample is: %1.3lf\n", samples_down[i]);
    }

    return EXIT_SUCCESS;
}

void program_failure(char text[])
{
    perror(text);
    exit(EXIT_FAILURE);
}
