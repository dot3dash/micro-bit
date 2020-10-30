#include "led.h"
#include "gpio.h"


const uint32_t led_hw[3][9] = 
                    { {0, 2, 4, 19, 18, 17, 16, 15, 11},
                    {14, 10, 12, 1, 3, 23, 21, 26, 26}, 
                    {22, 24, 20, 5, 6, 7, 8, 9, 13} };

static const uint32_t led_hw_cols = 9;
static uint32_t led_hw_current_row = 0;

static uint32_t matrix[26];

void led_init(){
    /* Setup GPIO */
    for(uint32_t i = 4; i < 16; i++){
        GPIO->DIRSET = (1 << i);
        GPIO->PIN_CNF[i] = 0x01;
        GPIO->OUTCLR = (1 << i);
    }
   
    for(uint32_t i = 0; i <= 26; i++){
        matrix[i] = 0;
    }
}

void led_set(uint32_t x, uint32_t y){
    matrix[x + (y*5)] = 1;
}

void led_clear(uint32_t x, uint32_t y){
    matrix[x + (y*5)] = 0;
}

void led_draw(){

    /* turning off columns [4, 12] */
    for(uint32_t i = 4; i < 4 + led_hw_cols; i++){
        GPIO->OUTSET = (1 << i);
    }
    GPIO->OUTCLR = (1 << (led_hw_current_row + 13));

    led_hw_current_row++;
    led_hw_current_row %= 3;

    GPIO->OUTSET = (1 << (led_hw_current_row + 13));

    /* turning columns on */
    for(uint32_t i = 4; i < 4 + led_hw_cols; i++){
        if(matrix[led_hw[led_hw_current_row][i - 4]]){
            GPIO->OUTCLR = (1 << i);
            /*
            int loop = 0;
            while (loop < 10000){
                loop++;
            }
            */
        }
    }
}