//#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "temperatureADC.h"
#include "hardware/adc.h"

/********************
global variable section
*********************/
bool initReady = false;


/********************
Initializes the on-board temperature ADC 
*********************/
void init_temperatureADC(void){
    printf("Initiating the temperature ADC\n");
    adc_init(); 
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
}


/********************
Conversion of the raw data to digital data
*********************/
void temperatureConversion(void){
    if(!initReady){
        init_temperatureADC();
        initReady = true;
    }
    uint16_t raw = adc_read();
    const float conversion = 3.3f / (1<<12);
    float voltage = raw * conversion;
    float temperature = 27 - (voltage - 0.706) / 0.00172;
    printf("Temperature: %f C\n", temperature);
}