#ifndef CLOCK_H
#define CLOCK_H

#pragma once

#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_rcc_ex.h"
#include "stm32f4xx_hal_pwr.h"
#include "stm32f4xx_hal_flash.h"

/*
    Main source clock

    HSE (High-Speed External): Oscillatore esterno ad alta velocità, collegato a un cristallo o risonatore 
                               ceramico con frequenze tipicamente tra 4 MHz e 16 MHz. Offre una maggiore 
                               precisione e stabilità rispetto agli oscillatori interni.

    HSI (High-Speed Internal): Oscillatore RC interno ad alta velocità a 16 MHz. Sebbene meno preciso dell'HSE, 
                               è utile in applicazioni dove la precisione non è critica.

    LSE (Low-Speed External): Oscillatore esterno a bassa velocità, generalmente un cristallo a 32.768 kHz,
                              utilizzato principalmente per il Real-Time Clock (RTC).

    LSI (Low-Speed Internal): Oscillatore RC interno a bassa velocità, con frequenza approssimativa di 40 kHz, 
                              utilizzato per funzioni come il watchdog indipendente e, in assenza di LSE, per l'RTC.
*/

void init_clock();

#endif