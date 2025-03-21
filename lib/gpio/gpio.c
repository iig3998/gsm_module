#include "gpio.h"

/* */
void enable_clock_port_a() {

    __HAL_RCC_GPIOA_CLK_ENABLE();

    return;
}

/* */
void enable_clock_port_b() {

    __HAL_RCC_GPIOB_CLK_ENABLE();

    return;
}

/* */
void enable_clock_port_c() {

    __HAL_RCC_GPIOC_CLK_ENABLE();

    return;
}

int init_configure_pin_port_a(uint16_t gpio) {

    GPIO_InitTypeDef gpio_struct;

    memset(&gpio_struct, 0, sizeof(gpio_struct));

    gpio_struct.Pin = gpio;
    gpio_struct.Mode = mode;
    gpio_struct.Pull = pull;
    gpio_struct.Speed = speed;

    HAL_GPIO_Init(GPIOA, &gpio_struct);

    return 0;
}

int init_configure_pin_port_b(uint16_t gpio, uint32_t mode, uint32_t pull, uint32_t speed) {

    GPIO_InitTypeDef gpio_struct;

    memset(&gpio_struct, 0, sizeof(gpio_struct));

    gpio_struct.Pin = gpio;
    gpio_struct.Mode = mode;
    gpio_struct.Pull = pull;
    gpio_struct.Speed = speed;

    HAL_GPIO_Init(GPIOB, &gpio_struct);

    return 0;
}

int init_configure_pin_port_c(uint16_t gpio) {


    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = gpio;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Output Push-Pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    return 0;
}


HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_SET);   // Imposta il pin a livello alto
HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_RESET); // Imposta il pin a livello basso


GPIO_PinState state = HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_x);

HAL_GPIO_TogglePin(GPIOx, GPIO_PIN_x);