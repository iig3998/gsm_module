#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_def.h"

#include "clock.h"

/* Main program */
int main(void) {

  HAL_Init();

  HAL_NVIC_SystemReset();

  GPIO_InitTypeDef GPIO_InitStruct;

  while (1) {
    HAL_GPIO_TogglePin (GPIOB, GPIO_PIN_12);
    HAL_Delay (100);
  }
}
