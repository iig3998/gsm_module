
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "clock.h"

/* Configure source clock */
void config_source_clock(uint32_t freq_in, uint8_t source_clock, uint8_t m, uint16_t n, uint8_t q, uint8_t p) {

    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Clean oscillator struct */
    memset(&RCC_OscInitStruct, 0, sizeof(RCC_OscInitStruct));

    switch(source_clock) {
        case RCC_OSCILLATORTYPE_NONE:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
        break;

        /* HSE (High-Speed External spurce clock) 4 to 48 MHz */
        case RCC_OSCILLATORTYPE_HSE:

            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
            RCC_OscInitStruct.HSEState = RCC_HSE_ON;

            __HAL_RCC_PLL_DISABLE();                             /* Disable PLL */

            assert_param(IS_RCC_PLLM_VALUE(m));
            assert_param(IS_RCC_PLLN_VALUE(n));
            assert_param(IS_RCC_PLLP_VALUE(p));
            assert_param(IS_RCC_PLLQ_VALUE(q));

            /* PLLCLK = (HSE / PLL_M) × PLL_N / PLL_P */
            RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;         /* Enable or disable PLL */
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; /* Set source clock main PLL */
            RCC_OscInitStruct.PLL.PLLM = m;
            RCC_OscInitStruct.PLL.PLLN = n;
            RCC_OscInitStruct.PLL.PLLP = p;
            RCC_OscInitStruct.PLL.PLLQ = q;

            __HAL_RCC_PLL_ENABLE();                              /* Enable PLL */
        break;

        /* Enable HSI (High-Speed Internal source clock) 16 MHz */
        case RCC_OSCILLATORTYPE_HSI:
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
            RCC_OscInitStruct.HSEState = RCC_HSI_ON;

            assert_param(IS_RCC_CALIBRATION_VALUE(RCC_HSICALIBRATION_DEFAULT));
            RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;

            __HAL_RCC_PLL_DISABLE();                             /* Disable PLL */

            assert_param(IS_RCC_PLLM_VALUE(m));
            assert_param(IS_RCC_PLLN_VALUE(n));
            assert_param(IS_RCC_PLLP_VALUE(p));
            assert_param(IS_RCC_PLLQ_VALUE(q));                       

            RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;         /* Enable or disable PLL */
            RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI; /* Set source clock main PLL */
            RCC_OscInitStruct.PLL.PLLM = m;
            RCC_OscInitStruct.PLL.PLLN = n;
            RCC_OscInitStruct.PLL.PLLP = p;
            RCC_OscInitStruct.PLL.PLLQ = q;                      
            __HAL_RCC_PLL_ENABLE();                              /* Enable PLL */

        case RCC_OSCILLATORTYPE_LSE:
            /* LSE (Low-Speed External) 32 kHz */
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE;
            RCC_OscInitStruct.LSEState = RCC_LSE_ON;
        break;

        case RCC_OSCILLATORTYPE_LSI:
            /* LSI (Low-Speed Internal) ~ 32 kHz */
            RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
            RCC_OscInitStruct.LSIState = RCC_LSI_ON;
        break;
    }
    
    /* Set configuration */
    if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    return;
}



/* Configure system clock */
void config_system_clock(uint8_t sys_clock_source, uint32_t ahb_prescaler, uint32_t apb1_prescaler, uint32_t apb2_prescaler) {

    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /* List clock to configure */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; /* SYS clock source*/

    /* Set prescaler for each clock */
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        /* AHB prescaler */
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         /* APB1 prescaler */
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         /* APB2 prescaler */

    if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        Error_Handler();
    }

    return;
}

/* Get sysclock frequency */
uint32_t get_sys_clock_freq() {

    return HAL_RCC_GetSysClockFreq();

}

/* Deinit clock */
void deinit_clock() {

    HAL_RCC_DeInit();

    return;
}