#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"

#include <bme280_spi.h>


int32_t humidity, pressure, temperature;
struct compensated_values * ptrToStruct;

const char * ssi_tags[] = {"hum", "pres", "temp"};

u16_t ssi_handler(int iIndex, char *pcInsert, int iInsertLen)
{
    printf("Inside ssi_handler\n");
    size_t data_buffer;
    ptrToStruct = compensate_measurements_address(&humidity, &pressure, &temperature);

    switch(iIndex)
    {
        case(0): //hum
        {
            const float hum = (*ptrToStruct).humidity;
            data_buffer = snprintf(pcInsert, iInsertLen, "%f", hum);
        }
        break;

        case(1): //pressure
        {
            const int pres = (*(ptrToStruct+1)).pressure;
            data_buffer = snprintf(pcInsert, iInsertLen, "%d", pres);
        }
        break;

        case(2): //temperature
        {
            const float temp = (*(ptrToStruct+2)).temeprature;
            data_buffer = snprintf(pcInsert, iInsertLen, "%f", temp);
        }
        break;

        default:
            data_buffer = 0;
            break;
    }

    return (u16_t) data_buffer;
}


void ssi_init()
{
    http_set_ssi_handler(ssi_handler, ssi_tags, LWIP_ARRAYSIZE(ssi_tags));
}
