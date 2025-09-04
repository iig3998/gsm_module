#include "gpio.h"

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





