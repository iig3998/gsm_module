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
#include "usart2.h"
#include "usart6.h"

int __io_putchar(int ch) {

    //HAL_UART_Transmit(&huart6, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    //return ch;
}

/* Reads mterics from aht20 */
void read_metrics_aht20() {

  #define ADDRESS_AHT20             0x38
  #define INIT_AHT20                0xBE
  #define STATUS_WORD_AHT20         0x71
  #define TRIGGER_MEASUREMENT_AHT20 0xAC
  #define SOFT_RESET_AHT20          0xBA

  I2C_HandleTypeDef hi2c1;
  uint8_t cmd = 0x00;
  uint8_t status = 0x00;
  uint8_t data[7];

  /* Wait 40ms after power-on */
  HAL_Delay(42);

  /* Soft reset */
  cmd = SOFT_RESET_AHT20;
  HAL_I2C_Master_Transmit(&hi2c1, ADDRESS_AHT20 << 1, &cmd, 1, HAL_MAX_DELAY);
  HAL_I2C_Master_Receive(&hi2c1, ADDRESS_AHT20 << 1, &status, 1, HAL_MAX_DELAY);

  if (status & 0x08) {
    uint8_t init_cmd[3] = {0xBE, 0x08, 0x00};
    HAL_I2C_Master_Transmit(&hi2c1, ADDRESS_AHT20 << 1, init_cmd, 3, HAL_MAX_DELAY);
    HAL_Delay(10);
  }

  /* Waits 20ms after reset */
  HAL_Delay(20);

  while(1) {

    uint8_t measure_cmd[3] = {TRIGGER_MEASUREMENT_AHT20, 0x33, 0x00};
    HAL_I2C_Master_Transmit(&hi2c1, ADDRESS_AHT20 << 1, measure_cmd, 3, HAL_MAX_DELAY);
    HAL_Delay(80);

    HAL_I2C_Master_Receive(&hi2c1, ADDRESS_AHT20 << 1, data, 7, HAL_MAX_DELAY);
    if(!(data[0] & 0x80)) {
      /* Data is ready */
      uint32_t raw_humidity = ((uint32_t)data[1] << 12) | ((uint32_t)data[2] << 4) | (data[3] >> 4);
      uint32_t raw_temperature = (((uint32_t)data[3] & 0x0F) << 16) | ((uint32_t)data[4] << 8) | data[5];

      float humidity = (raw_humidity * 100.0f) / 1048576.0f;
      float temperature = ((raw_temperature * 200.0f) / 1048576.0f) - 50.0f;
    } else {
      HAL_Delay(10);
    }

    /* Every 1 minutes read temperature and humidity value */
    HAL_Delay(60000);
  }

  return;
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
