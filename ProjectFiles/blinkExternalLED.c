#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/********************
global variable section
*********************/
bool ledON = false;     //Initially the LED is off

/********************
Initializes the GPIOs associated with the button
*********************/
void init_ExternalLed(int inputPortNum){
    gpio_init(inputPortNum);
    gpio_set_dir(inputPortNum, GPIO_OUT);
}

/********************
Turns on the LED
*********************/
void turnOnExternalLED(int inputPortNum){
    gpio_put(inputPortNum, 1);
}

/********************
Turns off the LED
*********************/
void turnOffExternalLED(int inputPortNum){
    gpio_put(inputPortNum, 0);
}