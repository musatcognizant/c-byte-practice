#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * === Spaceship Thrust ===
 *
 * We are working on the man-machine interface of a revolutionary spaceship.
 * Define enumeration constants for different predefined thrust levels, these
 * levels will be used to communicate with the engine controller.
 *
 * The thrust levels are:
 *  - none:     0
 *  - low:      5
 *  - medium:   9
 *  - high:     12
 *  - maximum:  20
 *
 * Then launch the rocket!
 * We now want to log the thrust level in some critical points:
 *  - set thrust to none ---> log ready to go level
 *  - set thrust to maximum ---> log take off level
 *  - set thrust to medium ---> log entry into the ionosphere
 *  - set thrust to low ---> log traveling to deep space
 *
 */

typedef enum
{
    NONE = 0,
    LOW = 5,
    MEDIUM = 9,
    HIGH = 12,
    MAX = 20,
} Thrust;

int main()
{
    Thrust t;

    t = NONE;
    printf("\tThrust is: %3d\n", t);
    t = MAX;
    printf("\tThrust is: %3d\n", t);
    t = MEDIUM;
    printf("\tThrust is: %3d\n", t);
    t = LOW;
    printf("\tThrust is: %3d\n", t);

    return EXIT_SUCCESS;
}
