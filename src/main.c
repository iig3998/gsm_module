#include <stdio.h>
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"


int main(void) {

  HAL_Init();

  GPIO_InitTypeDef GPIO_InitStruct;

  #if 0
  GPIO_InitStruct.Pin = ;       // Specifies the GPIO pins to be configured.
  GPIO_InitStruct.Mode = ;      // This parameter can be a value of @ref GPIO_mode_define */
  GPIO_InitStruct.Pull = ;      // This parameter can be a value of @ref GPIO_pull_define */
  GPIO_InitStruct.Speed = ;     // This parameter can be a value of @ref GPIO_speed_define */
  GPIO_InitStruct.Alternate = ; //  Peripheral to be connected to the selected pins
  #endif
  while (1) {
    HAL_GPIO_TogglePin (GPIOB, GPIO_PIN_12);
    HAL_Delay (100);
  }
}
