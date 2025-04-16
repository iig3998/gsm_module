#ifndef CLOCK_H
#define CLOCK_H

#pragma once

/*
| Source clock |       Freq     |
|--------------|----------------|
|      HSI	   |     16MHz      |
|      LSI	   |     32kHz      |
|      HSE	   |     25MHz      |
|      LSE	   |     32.768kHz  |
|--------------|----------------|
*/

/* Confire source clock */
void config_source_clock(uint32_t freq_in, uint8_t source_clock, uint8_t m, uint16_t n, uint8_t q, uint8_t p);

/* Get sys cclock frequency */
uint32_t get_sys_clock_freq();

/* Get the HCLK frequency */
uint32_t get_hclk_freq();

/* Get the PCLK1 frequency */
uint32_t get_pclk_freq();

/* Deinit clock */
void deinit_clock();

#endif