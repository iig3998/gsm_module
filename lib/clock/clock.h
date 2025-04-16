#ifndef CLOCK_H
#define CLOCK_H

#pragma once

/**/
void config_source_clock(uint32_t freq_in, uint8_t source_clock, uint8_t m, uint16_t n, uint8_t q, uint8_t p);

/**/
uint32_t get_sys_clock_freq();

/* Get the HCLK frequency */
uint32_t get_hclk_freq();

/* Get the PCLK1 frequency */
uint32_t get_pclk_freq();

/* Deinit clock */
void deinit_clock();

#endif