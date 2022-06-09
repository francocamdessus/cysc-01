/**
 * main.c generico para nuevo proyecto.
 *
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {

    stdio_init_all();
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    const float factor = 3.3f / (1<<12);
    while (true) {
        
        uint16_t resultado = adc_read();
        float voltaje = resultado * factor;
        float T = 27 - (voltaje-0.706)/0.001721;
        printf ("Raw value: 0x%03x, voltage: %.2f V, Temperatura= %.2f C°\n", resultado, resultado * factor, T);
        sleep_ms(500);
    
    }
    return 0;
}