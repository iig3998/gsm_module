#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"

#include "usart2.h"

/* Define baudrate usart2 */
#define BAUDRATE_usart_1200    1200
#define BAUDRATE_usart_9600    9600
#define BAUDRATE_usart_19200   19200
#define BAUDRATE_usart_38400   38400
#define BAUDRATE_usart_57600   57600
#define BAUDRATE_usart_115200  115200
#define BAUDRATE_usart_230400  230400
#define BAUDRATE_usart_460800  460800
#define BAUDRATE_usart_921600  921600
#define BAUDRATE_usart_1000000 1000000
#define BAUDRATE_usart_2000000 2000000

/*
* USART2: 2 possible pairs TX/RX

*/

static void Error_Handler(void) {

}

/* Init usart2 */
void init_usart2(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit) {

    USART_HandleTypeDef handle_usart2;

    memset(&handle_usart2, 0, sizeof(handle_usart2));

    /* Disable clock usart2 */
    __HAL_RCC_USART2_CLK_DISABLE();

    handle_usart2.Instance = USART2;

    /* De init usart2 */
    if(HAL_USART_DeInit(&handle_usart2) != HAL_OK) {
        Error_Handler();        
    }

    /* Set usart parameters */
    handle_usart2.Init.BaudRate = baudrate;
    handle_usart2.Init.WordLength = word_length;
    handle_usart2.Init.StopBits = stop_bit;
    handle_usart2.Init.Parity = parity_bit;
    
    /* Set usart mode */
    handle_usart2.Init.Mode = mode;
    
    /* Init usart and apply config */
    if (HAL_USART_Init(&handle_usart2) != HAL_OK) {
        Error_Handler();
    }

    /* Enable clock usart2 */
    __HAL_RCC_USART2_CLK_ENABLE();

    return;
}

/* Configure pin usart2 */
void configure_pin_usart2() {

    /* Configure PB6(Tx) and PB7(Rx) */
    GPIO_InitTypeDef GPIO_InitStruct;

    memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

    /* Configure PB6 as USART2_TX */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Configure PB7 as USART2_RX */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    return;
}

/* Send single char by usart2 */
HAL_StatusTypeDef send_char_usart2(USART_HandleTypeDef handle_usart2, uint8_t data) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart2, &data, sizeof(data), HAL_MAX_DELAY);

    return state;
}

/* Send string by usart2 */
HAL_StatusTypeDef send_string_usart2(USART_HandleTypeDef handle_usart2, uint8_t *data, uint8_t data_size) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart2, data, data_size, HAL_MAX_DELAY);

    return state;
}

/* Enable interrupt usart2 */
void enable_interrupt_usart2(uint32_t priority, uint32_t sub_priority) {

    HAL_NVIC_SetPriority(USART2_IRQn, priority, sub_priority);
    HAL_NVIC_EnableIRQ(USART2_IRQn);

    return;
}

/* Disable interrupt usart2 */
void disable_interrupt_usart2() {

    HAL_NVIC_DisableIRQ(USART2_IRQn);

    return;
}