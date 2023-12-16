/*
 * stm32_lin_frame.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Muhammet Koçak
 */

#include "stm32_lin_frame.h"

uint8_t LIN_Calculate_Checksum(uint8_t identifier, uint8_t *pData) {
    // Calculate LIN checksum
    uint16_t sum = identifier;

    for (uint8_t i = 0; i < 8; i++) {
        sum += pData[i];
    }
    while (sum > 0xFF) {
        sum -= 0xFF;
    }
    sum = 0xFF - sum;
    return (uint8_t) sum;
}

void LIN_Send_Frame(UART_HandleTypeDef *uart_channel, LIN_Frame_t *LIN_Frame) {
    // Prepare and transmit LIN frame
    uint8_t lin_frame[11];
    lin_frame[0] = LIN_Frame->Sync;
    lin_frame[1] = LIN_Frame->Identifier;

    // Copy data bytes
    for (uint8_t i = 0; i < 8; i++) {
        lin_frame[i + 2] = LIN_Frame->Data[i];
    }

    // Calculate and set checksum
    lin_frame[10] = LIN_Calculate_Checksum(LIN_Frame->Identifier, LIN_Frame->Data);

    // Transmit LIN frame
    HAL_LIN_SendBreak(uart_channel);
    HAL_UART_Transmit(uart_channel, lin_frame, 11, 10);
}


void LIN_Process_Frame(LIN_Frame_t *LIN_Frame, uint8_t *rxData) {
    // Extract components from received LIN frame
    LIN_Frame->Sync = rxData[0];
    LIN_Frame->Identifier = rxData[1];

    // Copy data bytes
    for (uint8_t i = 0; i < 8; i++) {
        LIN_Frame->Data[i] = rxData[i + 2];
    }

    // Extract checksum
    LIN_Frame->Checksum = rxData[10];
}
