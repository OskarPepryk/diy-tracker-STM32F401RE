#ifndef __UART_H__
#define __UART_H__

#ifndef WITH_NUCLEO
	#include "stm32f10x.h"
	#include "stm32f10x_usart.h"
	#include "stm32f10x_gpio.h"
#else
	#include "stm32f4xx.h"
	#include "stm32f4xx_usart.h"
	#include "stm32f4xx_gpio.h"
#endif
#include "misc.h"

void UART_ConfigNVIC(uint8_t IRQ, uint8_t Priority, uint8_t SubPriority);
void UART_ConfigGPIO(GPIO_TypeDef* GPIO, uint16_t InpPin, uint16_t OutPin);
void UART_ConfigUSART(USART_TypeDef* USART, int BaudRate);
void UART_ConfigAF(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSourceRx, uint16_t GPIO_PinSourceTx, uint8_t GPIO_AF);


#endif // __UART_H__
