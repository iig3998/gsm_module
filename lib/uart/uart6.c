#include <stdint.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_usart.h"

#include "usart.h"

/* Define baudrate usart */
#define BAUDRATE_USART_1200    1200
#define BAUDRATE_USART_9600    9600
#define BAUDRATE_USART_19200   19200	
#define BAUDRATE_USART_38400   38400
#define BAUDRATE_USART_57600   57600	
#define BAUDRATE_USART_115200  115200
#define BAUDRATE_USART_230400  230400
#define BAUDRATE_USART_460800  460800	
#define BAUDRATE_USART_921600  921600	
#define BAUDRATE_USART_1000000 1000000
#define BAUDRATE_USART_2000000 2000000

/* USART6:
    TX: PC6
    RX: PC7
*/


/* Enable clock usart */
void enable_clock_usart() {


    return;
}

/* Configure pin usart */
void configure_pin_usart() {

    GPIO_InitTypeDef GPIO_InitStruct;

    memeset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

    GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;   // Alternate Function Push-Pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;  // AF7 per USART2
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    return;
}

/* Configure usart parameters */
void config_usart(uint32_t baudrate, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit) {

    USART_InitTypeDef usart;

    usart.BaudRate = baudrate;
    usart.WordLength = word_length;
    usart.StopBits = stop_bit;
    usart.Parity = parity_bit;

    usart.Mode;

    usart.CLKPolarity;
    usart.CLKPhase;
    usart.CLKLastBit;

    return;
}

void send_char_usart(char data) {


    return;
}

void send_string_usart(char data) {


    return;
}