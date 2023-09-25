#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"

#include <bme280_spi.h>


int32_t humidity, pressure, temperature;
//CGI Handler which is run when a request for /room.cgi is detected
const char * cgi_room_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    printf("Triggered cgi_room_handler\n");
    if(strcmp(pcParam[0], "room") == 0)
    {
        //check parameter value
        if(strcmp(pcValue[0], "0") == 0)
        {//get room hum, pres, temperature
            configureModes(0x1, 0b00100101); //forced mode, with oversampling x1 mode   
        }
    }
    return "/index.shtml";
}


static const tCGI cgi_handlers[] = {
    {
        //HTML request for "/room.cgi" triggers cgi_handler
        "/room.cgi", cgi_room_handler
    },
};

void cgi_init(void){
    //handler and the number of handlers
    http_set_cgi_handlers(cgi_handlers, 1);
}