#include <stdint.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_uart.h"

#include "uart.h"

/* Define baudrate uart */
#define BAUDRATE_UART_1200    1200
#define BAUDRATE_UART_9600    9600
#define BAUDRATE_UART_19200   19200	
#define BAUDRATE_UART_38400   38400
#define BAUDRATE_UART_57600   57600	
#define BAUDRATE_UART_115200  115200
#define BAUDRATE_UART_230400  230400
#define BAUDRATE_UART_460800  460800	
#define BAUDRATE_UART_921600  921600	
#define BAUDRATE_UART_1000000 1000000
#define BAUDRATE_UART_2000000 2000000

/* Init uart1 */
void init_uart1(uint32_t baudrate, uint8_t mode, uint8_t word_length, uint8_t parity_bit, uint8_t stop_bit) {

    UART_HandleTypeDef handle_uart1;

    memset(&handle_uart1, 0, sizeof(handle_uart1));

    __HAL_RCC_UART1_CLK_DISABLE();

    handle_uart1.Instance = UART1;

    handle_uart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;

    /* De init uart */
    if(HAL_UART_DeInit(&handle_uart1) != HAL_OK) {
        Error_Handler();        
    }

    /* Set uart parameters */
    handle_uart1.Init.BaudRate = baudrate;
    handle_uart1.Init.WordLength = word_length;
    handle_uart1.Init.StopBits = stop_bit;
    handle_uart1.Init.Parity = parity_bit;
    handle_uart1.Init.OverSampling = UART_OVERSAMPLING_16; // Oversampling 8 or 16
    
    /* Set uart mode */
    handle_uart1.Mode = mode;
    
    /* Init uart and apply config */
    if (HAL_UART_Init(&handle_uart1) != HAL_OK) {
        Error_Handler();
    }

    __HAL_RCC_UART1_CLK_ENABLE();

    return;
}

/* Configure pin uart */
void configure_pin_uart1() {

    GPIO_InitTypeDef GPIO_InitStruct;

    memeset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

   
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    return;
}

/* Send single char by uart1 */
HAL_StatusTypeDef send_char_uart1(UART_HandleTypeDef handle_uart1, char data) {

    HAL_StatusTypeDef ret;

    ret = HAL_UART_Transmit(&handle_uart1, &data, 1, HAL_MAX_DELAY);

    return ret;
}

/* Send string by uart1 */
HAL_StatusTypeDef send_string_uart1(UART_HandleTypeDef handle_uart1, char *data, uint8_t data_size) {

    HAL_StatusTypeDef ret;

    ret = HAL_UART_Transmit(&handle_uart1, &data, data_size, HAL_MAX_DELAY);

    return ret;
}

/* Enable interrupt uart1 */
void enable_interrupt_uart1(uint32_t priority, uint32_t sub_priority) {

    HAL_NVIC_SetPriority(USART1_IRQn, priority, sub_priority);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

    return;
}

/* Disable interrupt uart1 */
void disable_interrupt_uart1() {

    HAL_NVIC_DisableIRQ(USART1_IRQn);

    return;
}