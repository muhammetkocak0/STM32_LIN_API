/*
 * stm32_lin_frame.h
 *
 *  Created on: Dec 16, 2023
 *      Author: Muhammet Koçak
 */

#ifndef INC_STM32_SENDLINFRAME_H_
#define INC_STM32_SENDLINFRAME_H_

#include "stm32f4xx_hal.h" //change this 
#include <stdint.h>

// LIN frame structure definition
typedef struct {
    uint8_t Sync;               // Sync byte of the LIN frame
    uint8_t Identifier;         // Identifier byte of the LIN frame
    uint8_t Data[8];            // Data bytes of the LIN frame
    uint8_t Checksum;           // Checksum byte of the LIN frame
} LIN_Frame_t;

// Function to send a LIN frame
void LIN_Send_Frame(UART_HandleTypeDef *uart_channel, LIN_Frame_t *LIN_Frame);

// Function to process a received LIN frame
void LIN_Process_Frame(LIN_Frame_t *LIN_Frame, uint8_t *rxData);

#endif /* INC_STM32_SENDLINFRAME_H_ */
