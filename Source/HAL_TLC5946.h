#ifndef __HAL_TLC5946_H
#define __HAL_TLC5946_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"

// Modes
#define Mode_GS 	0
#define Mode_DC		1

// Pin Control
#define pXLAT(state)		HAL_GPIO_WritePin(TLC_XLAT_GPIO_Port,  TLC_XLAT_Pin,  (GPIO_PinState)state)
#define pMODE(state)		HAL_GPIO_WritePin(TLC_MODE_GPIO_Port,  TLC_MODE_Pin,  (GPIO_PinState)state)
#define pBLANK(state)		HAL_GPIO_WritePin(TLC_BLANK_GPIO_Port, TLC_BLANK_Pin, (GPIO_PinState)state)
 
// Prototypes
void TLC5946_init (SPI_HandleTypeDef *config);
void TLC5946_SetOutput_GS(uint8_t IC, uint8_t LED_ID, uint16_t value);
void TLC5946_SetOutput_DC(uint8_t IC, uint8_t LED_ID, uint8_t value);
void TLC5946_Refresh_GS(void);
void TLC5946_Refresh_DC(void);
void TLC5946_TxINTCallback(void);

void TLC5946_setRGB(uint8_t LED_ID, uint16_t val_R, uint16_t val_G, uint16_t val_B);
void TLC5946_setRGB_DC(uint16_t val_R, uint16_t val_G, uint16_t val_B);
void TLC5946_setAll(uint16_t val_R, uint16_t val_G, uint16_t val_B);

#ifdef __cplusplus
}
#endif
#endif
