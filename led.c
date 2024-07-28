#include <stdio.h>

#include "led.h"

void print_led_status(Led led)
{
    printf("The led is %s\n", led == LED_ON ? "ON" : "OFF");
};
