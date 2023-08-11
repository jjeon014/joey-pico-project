#ifndef BUTTONDETECTION_H
#define BUTTONDETECTION_H

#include <stdio.h>
#include "hardware/gpio.h"


void init_Button(int ButtonInputNum);
bool detectButton(int ButtonInputNum);

#endif