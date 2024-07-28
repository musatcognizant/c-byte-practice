#include <stdio.h>
#include "mod1.h"

void print_mod1()
{
    Led led = LED_ON;
    puts("MOD 1");

    print_led_status(led);
};
