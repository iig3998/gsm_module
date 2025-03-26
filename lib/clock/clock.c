#include "clock.h"

void init_clock(uint8_t source_clock) {

    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Clean oscillator struct */
    memset(&RCC_OscInitStruct, 0, sizeof(RCC_OscInitStruct));
    switch(source_clock) {
        case RCC_OSCILLATORTYPE_NONE:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
        break;

        case RCC_OSCILLATORTYPE_HSE:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
            RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        break;

        case RCC_OSCILLATORTYPE_HSI:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
            RCC_OscInitStruct.HSEState = RCC_HSI_ON;

        case RCC_OSCILLATORTYPE_LSE:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE;
            RCC_OscInitStruct.HSEState = RCC_LSE_ON;
        break;

        case RCC_OSCILLATORTYPE_LSI:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
            RCC_OscInitStruct.HSEState = RCC_LSI_ON;
        break;

    }
    
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 7;

    /* Set configuration */
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    return;
}