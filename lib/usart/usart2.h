#ifndef USART2_H
#define USART2_H

#include <stdint.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_usart.h"

#define MAJOR_USART2_VER 0
#define MINOR_USART2_VER 1
#define PATCH_USART2_VER 0

void init_usart2(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit);

void configure_pin_usart2();

HAL_StatusTypeDef send_char_usart2(USART_HandleTypeDef handle_usart2, uint8_t data);

HAL_StatusTypeDef send_string_usart2(USART_HandleTypeDef handle_usart2, uint8_t *data, uint8_t data_size);

void enable_interrupt_usart2(uint32_t priority, uint32_t sub_priority);

void disable_interrupt_usart2();

#endif