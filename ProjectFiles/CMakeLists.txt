add_executable(main
        main.c
        blinkExternalLED.c
        buttonDetection.c
        temperatureADC.c
)

target_link_libraries(main 
    pico_cyw43_arch_lwip_threadsafe_background 
    pico_stdlib 
    hardware_gpio
    hardware_adc
    hardware_spi
    freertos
)

target_include_directories(main 
    PRIVATE
        include include
)

pico_add_extra_outputs(main)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)