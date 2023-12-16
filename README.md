# Basic STM32 LIN Communication API with Checksum Calculation

STM32 LIN Communication API for basic usage like unleasing the closed features of a car, reverse engineering etc. 
Do not forget to configure UART as LIN in CubeIDE

## Features

- **Send LIN Frames:** Transmit LIN frames over the UART interface with calculated checksum, just pass data and uart channel
- **Process Received LIN Frames:** Extract and process data from received LIN frames.

Note: More features will be added

## Usage

To use the library change the "stm32f4xx_hal.h" according to your MCU
```c
#ifndef INC_STM32_SENDLINFRAME_H_
#define INC_STM32_SENDLINFRAME_H_

#include "stm32f4xx_hal.h" //change this 
#include <stdint.h>
```

Initialize the LIN frame structure in main.c:
```c
#include "stm32_lin_frame.h"
LIN_Frame_t BLDC_BLOWER_02_Set_Frame = {
    .Sync = 0x55,
    .Identifier = 0x6A,
    .Data = {0x00, 0x00, 0x50, 0x00, 0x81, 0x11, 0xC5, 0x00}
};
```
