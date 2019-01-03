#ifndef __SPI2_H__
#define __SPI2_H__

#include <stdint.h>

#ifndef WITH_NUCLEO
	#include "stm32f10x_gpio.h"
	#include "stm32f10x_rcc.h"
	#include "stm32f10x_spi.h"
#else
	#include "stm32f4xx_gpio.h"
	#include "stm32f4xx_rcc.h"
	#include "stm32f4xx_spi.h"
#endif

#ifdef SPEEDUP_STM_LIB
#ifndef WITH_NUCLEO
inline void SPI2_Select  (void) { GPIOA->BRR  = GPIO_Pin_12; }
inline void SPI2_Deselect(void) { GPIOA->BSRR = GPIO_Pin_12; }
#else
inline void SPI2_Select  (void) { GPIOA->BSRRH  = GPIO_Pin_12; }
inline void SPI2_Deselect(void) { GPIOA->BSRRL = GPIO_Pin_12; }
#endif //WITH_NUCLEO
#else
inline void SPI2_Select  (void) { GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET); }
inline void SPI2_Deselect(void) { GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET  ); }
#endif

void SPI2_Configuration(void);

uint8_t SPI2_TransferByte(uint8_t Byte);

void SPI2_Fast(void);
void SPI2_Slow(void);

#endif // __SPI2_H__
