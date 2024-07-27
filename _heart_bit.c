#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

/**
 * === Workouts Heart Rate Monitor ===
 *
 * Build a heart rate monitor for your workouts!
 *
 * Maximum heart rate (Tanaka formula):
 *    hr_max = 208 - 0.7 * AGE
 *
 * Zones:
 * 1 | below 50% | rest
 * 2 |  50%-60%  | very light, active recovery
 * 3 |  60%-70%  | light, cardio training, improves your general endurance
 * 4 |  70%-80%  | moderate, aerobic fitness, improve your efficiency
 * 5 |  80%-90%  | hard, raise the anaerobic threshold, improve your speed endurance
 * 6 | above 90% | peak performance, improve your power, only for pros!
 *
 * Goals:
 *  - Ask for the user's age
 *  - Print the hr max
 *  - Print each training zone in the format 'id, hr min, hr max, description'
 *  - In loop ask for the current BPM
 *  - Print the current zone in the format 'id, description'
 *
 */

typedef struct Zone
{
    uint8_t id;
    float low;
    char *description;
} Zone;

typedef struct User
{
    int age;
    int bpm;
    int max_hr;
    int min_hr;
    Zone *zone;
} User;

float calc_max_hr(int age);
void print_zones();
Zone get_zone(int percent);
void print_zone_table(const Zone zones[], float max_hr, uint8_t zones_len);
void print_table_row(uint8_t id, float lower, float upper, char desc[]);

const Zone zones[] = {
    {
        .description = "rest",
        .low = 0,
        .id = 1,
    },
    {
        .description = "very light, active recovery",
        .id = 2,
        .low = 0.5,
    },
    {
        .description = "light, cardio training, improves your general endurance",
        .id = 3,
        .low = 0.6,
    },
    {
        .description = "moderate, aerobic fitness, improve your efficiency",
        .id = 4,
        .low = 0.7,
    },
    {
        .description = "hard, raise the anaerobic threshold, improve your speed endurance",
        .id = 5,
        .low = 0.8,
    },
    {
        .description = "peak performance, improve your power, only for pros!",
        .id = 6,
        .low = 0.9,
    },
};

int main()
{

    uint8_t zones_len = sizeof(zones) / sizeof(zones[0]);
    int age = 0;

    printf("Enter your age: ");
    scanf("%d", &age);

    float max_hr = calc_max_hr(age);
    printf("Your max hr is: %.0f.\nPlease reference the zone below:\n", max_hr);

    print_zone_table(zones, max_hr, zones_len);

    int bpm = 0;

    while (true)
    {
        /* code */
        printf("Please enter your current BPM\n");
        scanf("%d", &bpm);

        if (bpm <= 0)
        {
            break;
        }

        float coef = bpm / max_hr;
        Zone current_zone = {0, 0, 0};

        for (uint8_t i = 0; i < zones_len; i++)
        {
            if (coef >= 1)
            {
                current_zone = zones[zones_len - 1];
                break;
            }

            if (zones[i].low >= coef)
            {
                current_zone = zones[i - 1];
                break;
            }
        }

        printf("\n\n\nYou are in zone: %d.\nThis zone is for %s\n\n", current_zone.id, current_zone.description);

        sleep(3);
    };

    return EXIT_SUCCESS;
}

float calc_max_hr(int age)
{
    float max_hr = 208 - 0.7 * age;
    printf("Max hr is: %.3f\n", max_hr);

    return max_hr;
};

Zone get_zone(int percent)
{
    if (percent <= 50)
    {
        return (Zone){
            .id = 1,
            .description = "rest",
            .low = percent,
        };
    };

    if (percent > 50 && percent <= 60)
    {
        return (Zone){
            .id = 2,
            .description = "very light, active recovery",
            .low = percent,
        };
    };
    return (Zone){
        .id = 6,
        .description = "peak performance, improve your power, only for pros!",
        .low = percent,
    };
};

void print_table_row(uint8_t id, float lower, float upper, char desc[])
{
    printf("%d | %3.0f - %3.0f | %s\n", id, lower, upper, desc);
};

void print_zone_table(const Zone zones[], float max_hr, uint8_t zones_len)
{
    for (uint8_t i = 0; i < zones_len; i++)
    {
        /* code */
        float upper = i < zones_len - 1 ? zones[i + 1].low * max_hr : max_hr;
        print_table_row(zones[i].id, zones[i].low * max_hr, upper, zones[i].description);
    }
}
