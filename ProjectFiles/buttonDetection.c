#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


/********************
global variable section
*********************/


/********************
Initializes the GPIOs associated with the button
*********************/
void init_Button(int inputPortNum){
    gpio_init(inputPortNum);
    gpio_set_dir(inputPortNum, GPIO_IN);
    gpio_pull_up(inputPortNum);
}


/********************
Checks whether the button has been pressed

Returns true if button pressed otherwise false
*********************/
bool detectButton(int inputPortNum){

    if(!gpio_get(inputPortNum)){ //if button pressed
        return true;        
    }
    else{
        return false;
    }
}