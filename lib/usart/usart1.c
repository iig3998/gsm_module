#include <stdint.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"

#include "usart1.h"

/* Define baudrate usart1 */
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
* USART1: 2 possible pairs TX/RX
*    PA9  = TX1      PA10 = RX1
*    PB6  = TX1_ALT  PB7  = RX1_ALT
*/

static void Error_Handler(void) {

}

/* Init usart1 */
void init_usart1(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit) {

    USART_HandleTypeDef handle_usart1;

    memset(&handle_usart1, 0, sizeof(handle_usart1));

    /* Disable clock usart1 */
    __HAL_RCC_USART1_CLK_DISABLE();

    handle_usart1.Instance = USART1;

    /* De init usart */
    if(HAL_USART_DeInit(&handle_usart1) != HAL_OK) {
        Error_Handler();        
    }

    /* Set usart parameters */
    handle_usart1.Init.BaudRate = baudrate;
    handle_usart1.Init.WordLength = word_length;
    handle_usart1.Init.StopBits = stop_bit;
    handle_usart1.Init.Parity = parity_bit;

    /* Set usart mode */
    handle_usart1.Init.Mode = mode;
    
    /* Init usart and apply config */
    if (HAL_USART_Init(&handle_usart1) != HAL_OK) {
        Error_Handler();
    }

    /* Enable clock usart1 */
    __HAL_RCC_USART1_CLK_ENABLE();

    return;
}

/* Configure pin usart */
void configure_pin_usart1() {

    /* Configure PB6(Tx) and PB7(Rx) */
    GPIO_InitTypeDef GPIO_InitStruct;

    memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

    /* Configure PB6 as USART1_TX */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Configure PB7 as USART1_RX */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    return;
}

/* Send single char by usart1 */
HAL_StatusTypeDef send_char_usart1(USART_HandleTypeDef handle_usart1, uint8_t data) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart1, &data, sizeof(data), HAL_MAX_DELAY);

    return state;
}

/* Send string by usart1 */
HAL_StatusTypeDef send_string_usart1(USART_HandleTypeDef handle_usart1, uint8_t *data, uint8_t data_size) {

    HAL_StatusTypeDef state;

    state = HAL_USART_Transmit(&handle_usart1, data, data_size, HAL_MAX_DELAY);

    return state;
}

/* Enable interrupt usart1 */
void enable_interrupt_usart1(uint32_t priority, uint32_t sub_priority) {

    HAL_NVIC_SetPriority(USART1_IRQn, priority, sub_priority);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

    return;
}

/* Disable interrupt usart1 */
void disable_interrupt_usart1() {

    HAL_NVIC_DisableIRQ(USART1_IRQn);

    return;
}