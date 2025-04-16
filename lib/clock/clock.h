#ifndef CLOCK_H
#define CLOCK_H

#pragma once

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_rcc_ex.h>
#include <stm32f4xx_hal_pwr.h>
#include <stm32f4xx_hal_flash.h>

void config_source_clock(uint32_t freq_in, uint8_t source_clock, uint8_t m, uint16_t n, uint8_t q, uint8_t p);

#endif