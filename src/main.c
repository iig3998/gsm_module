#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_cortex.h>

#include "FreeRTOS.h"
#include "task.h"

#include "clock.h"
#include "gpio.h"
#include "usart1.h"
int __io_putchar(int ch) {

    //HAL_UART_Transmit(&huart6, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    //return ch;
}


/* Main program */
int main() {

  GPIO_InitTypeDef GPIO_InitStruct_PC13;

  HAL_Init();

  HAL_NVIC_SystemReset();

  __HAL_RCC_GPIOC_CLK_ENABLE();

  memset(&GPIO_InitStruct_PC13, 0, sizeof(GPIO_InitStruct_PC13));

  /* COnfigure GPIO13 to drive LED on board */
  GPIO_InitStruct_PC13.Pin = GPIO_PIN_13;
  GPIO_InitStruct_PC13.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct_PC13.Pull = GPIO_NOPULL;
  GPIO_InitStruct_PC13.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct_PC13);

  while (1) {
    HAL_GPIO_TogglePin (GPIOC, GPIO_PIN_13);
    HAL_Delay (100);
  }
}
