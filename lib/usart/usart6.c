#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"

#include "usart6.h"

/* Define baudrate usart6 */
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

/*
* USART6: 2 possible pairs TX/RX

*/

/* Error handler function */
static void Error_Handler(void) {

}

/* Init usart6 */
void init_usart6(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit) {

    USART_HandleTypeDef handle_usart6;

    memset(&handle_usart6, 0, sizeof(handle_usart6));

    /* Disable clock usart6 */
    __HAL_RCC_USART6_CLK_DISABLE();

    handle_usart6.Instance = USART2;

    /* De init usart6 */
    if(HAL_USART_DeInit(&handle_usart6) != HAL_OK) {
        Error_Handler();        
    }

    /* Set usart parameters */
    handle_usart6.Init.BaudRate = baudrate;
    handle_usart6.Init.WordLength = word_length;
    handle_usart6.Init.StopBits = stop_bit;
    handle_usart6.Init.Parity = parity_bit;
    
    /* Set usart mode */
    handle_usart6.Init.Mode = mode;
    
    /* Init usart and apply config */
    if (HAL_USART_Init(&handle_usart6) != HAL_OK) {
        Error_Handler();
    }

    /* Enable clock usart6 */
    __HAL_RCC_USART6_CLK_ENABLE();

    return;
}

/* Configure pin usart2 */
void configure_pin_usart6() {

    /* Configure PB6(Tx) and PB7(Rx) */
    GPIO_InitTypeDef GPIO_InitStruct;

    memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

    /* Configure PB6 as USART6_TX */
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

/* Send single char by usart6 */
HAL_StatusTypeDef send_char_usart6(USART_HandleTypeDef handle_usart6, uint8_t data) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart6, &data, sizeof(data), HAL_MAX_DELAY);

    return state;
}

/* Send string by usart6 */
HAL_StatusTypeDef send_string_usart6(USART_HandleTypeDef handle_usart6, uint8_t *data, uint8_t data_size) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart6, data, data_size, HAL_MAX_DELAY);

    return state;
}

/* Enable interrupt usart6 */
void enable_interrupt_usart6(uint32_t priority, uint32_t sub_priority) {

    HAL_NVIC_SetPriority(USART6_IRQn, priority, sub_priority);
    HAL_NVIC_EnableIRQ(USART6_IRQn);

    return;
}

/* Disable interrupt usart6 */
void disable_interrupt_usart6() {

    HAL_NVIC_DisableIRQ(USART6_IRQn);

    return;
}