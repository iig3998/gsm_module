#include "gpio.h"

/*
    * List GPIO available *

    GPIO_PIN_0
    GPIO_PIN_1
    GPIO_PIN_2
    GPIO_PIN_3
    GPIO_PIN_4
    GPIO_PIN_5
    GPIO_PIN_6
    GPIO_PIN_7
    GPIO_PIN_8
    GPIO_PIN_9
    GPIO_PIN_10
    GPIO_PIN_11
    GPIO_PIN_12
    GPIO_PIN_13
    GPIO_PIN_14
    GPIO_PIN_15

    * List PORT available *

    - GPIOA with 16 pins
    - GPIOB with 16 pins
    - GPIOC with 16 pins
    - GPIOD with 16 pins
    - GPIOE with 16 pins
    - GPIOH with 1 pin
*/

/* Enable clock for PORTA */
void enable_clock_port_a() {

    __HAL_RCC_GPIOA_CLK_ENABLE();

    return;
}

/* Enable clock for PORTB */
void enable_clock_port_b() {

    __HAL_RCC_GPIOB_CLK_ENABLE();

    return;
}

/* Enable clock for PORTC */
void enable_clock_port_c() {

    __HAL_RCC_GPIOC_CLK_ENABLE();

    return;
}

/* Configure GPIOx */
void init_configure_gpio_port(port p, uint16_t gpio_num, uint8_t mode, uint8_t pull_mode, uint8_t speed_mode) {

    GPIO_InitTypeDef gpio;

    memset(&gpio, 0, sizeof(gpio));
    gpio.Pin = gpio_num;
    gpio.Mode = mode;
    gpio.Pull = pull_mode;
    gpio.Speed = speed_mode;

    HAL_GPIO_Init(p, &gpio);

    return;
}

/* Set high gpio */
void set_high_gpio_level(port p, uint16_t gpio_num) {

    HAL_GPIO_WritePin(p, gpio_num, GPIO_PIN_SET);

    return;
}

/* Set low gpio */
void set_low_gpio_level(port p, uint16_t gpio_num) {

    HAL_GPIO_WritePin(p, gpio_num, GPIO_PIN_RESET);

    return;
}

/* Get gpio value */
uint8_t get_gpio_level(port p, uint16_t gpio_num) {

    return HAL_GPIO_ReadPin(p, gpio_num);
}

/* Toggle gpio */
void toggle_gpio_level(port p, uint16_t gpio_num) {

    HAL_GPIO_TogglePin(p, gpio_num);

    return;
}





