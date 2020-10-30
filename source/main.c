#include "uart.h"
//#include "accelerometer.h"
#include "print.h"
#include <stdint.h>
#include "led.h"

int main(){
    uart_init();
    led_init();
    //accelerometer_init();

    //int16_t x, y, z;

    led_set(0,0);
    //led_draw();
    //led_draw();
    led_set(0,3);

    while(1){
        led_draw();
    }

    return 0;
}
