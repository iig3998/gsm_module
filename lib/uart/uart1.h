#ifndef UART1_H
#define UART1_H

#include <stdint.h>

#define MAJOR_UART_VER 0
#define MINOR_UART_VER 1
#define PATCH_UART_VER 0

void init_uart1(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit);

#endif