#include <stdio.h>
#include "mod2.h"

void print_mod_2()
{
    Led led = LED_OFF;
    puts("MOD 2");

    print_led_status(led);
};
