#ifndef LED_H
#define LED_H

#include <stdint.h>

void led_init();

void led_set(uint32_t x, uint32_t y);

void led_clear(uint32_t x, uint32_t y);

void led_draw();

#endif // LED_H