#ifndef BLINKEXTERNALLED_H
#define BLINKEXTERNALLED_H

#include <stdio.h>
#include "hardware/gpio.h"

void init_ExternalLed(int inputPortNum);
void turnOnExternalLED(int inputPortNum);
void turnOffExternalLED(int inputPortNum);

#endif