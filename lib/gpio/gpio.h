#ifndef GPIO_H
#define GPIO_H

#pragma once

#include <stdint.h>
#include <string.h>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>

typedef GPIO_TypeDef* port;

void enable_clock_port_a();

void enable_clock_port_b();

void enable_clock_port_c();

void init_configure_gpio_port(port p, uint16_t gpio_num, uint8_t mode, uint8_t pull_mode, uint8_t speed_mode);

void set_high_gpio_level(port p, uint16_t gpio_num);

void set_low_gpio_level(port p, uint16_t gpio_num);

uint8_t get_gpio_level(port p, uint16_t gpio_num);

void toggle_gpio_level(port p, uint16_t gpio_num);

#endif