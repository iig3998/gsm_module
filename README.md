
# GSM Module

![GSM Module schema v1.0](img/gsm_module_schema_v1.0.png)

## Microcontroller
STM32f411CEU6

- Core: Arm® 32-bit Cortex®-M4 CPU with FPU, Adaptive real-time accelerator (ART Accelerator™) allowing 0-wait state execution from Flash memory, frequency up to 100 Hz
- Memories: Up to 512 Kbytes of Flash memory and 128 Kbytes of Static RAM

Peripherals used for the this project:
- UART1 (GSM module)
- UART2 (Modbus)
- I2C1 (AHT20)
- 3 relay outputs 220V

## Header 1 pins

| #  | Name | Function | Connected to  |
|----|------|----------|---------------|
| 1  | 5V   | -        | +5V rail      |
| 2  | G    | -        | Ground plane  |
| 3  | 3.3  | -        | +3.3V rail    |
| 4  | B10  | -        | PB10          |
| 5  | B2   | -        | PB2           |
| 6  | B1   | -        | PB1           |
| 7  | B0   | -        | PB0           |
| 8  | A7   | -        | PA7           |
| 9  | A6   | -        | PA6           |
| 10 | A5   | -        | PA5           |
| 11 | A4   | -        | PA4           |
| 12 | A3   | -        | PA3           |
| 13 | A2   | -        | PA2           |
| 14 | A1   | -        | PA1           |
| 15 | A0   | -        | PA0           |
| 16 | R    | -        | NRST          |
| 17 | C15  | -        | PC15          |
| 18 | C14  | -        | PC14          |
| 19 | C13  | -        | PC13          |
| 20 | VB   | -        | VBAT          |

## Header 2 pins

| #  | Name | Function | Connected to  |
|----|------|----------|---------------|
| 1  | B12  | -        | PB12          |
| 2  | B13  | -        | PB13          |
| 3  | B14  | -        | PB14          |
| 4  | B15  | -        | PB15          |
| 5  | A8   | -        | PA8           |
| 6  | A9   | -        | PA9           |
| 7  | A10  | -        | PA10          |
| 8  | A11  | -        | PA11          |
| 9  | A12  | -        | PA12          |
| 10 | A15  | -        | PA15          |
| 11 | B3   | -        | PB3           |
| 12 | B4   | -        | PB4           |
| 13 | B5   | -        | PB5           |
| 14 | B6   | -        | PB6           |
| 15 | B7   | -        | PB7           |
| 16 | B8   | -        | PB8           |
| 17 | B9   | -        | PB9           |
| 18 | 5V   | -        | +5V rail      |
| 19 | G    | -        | Ground plane  |
| 20 | 3.3  | -        | +3.3V rail    |


## How to build

`
pio run
`