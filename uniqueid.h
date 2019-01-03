#ifndef __UNIQUEID_H__
#define __UNIQUEID_H__

#ifndef WITH_NUCLEO
	#define UniqueID ((uint32_t*)(0x1FFFF7E8))
#else //STM32F4
	#define UniqueID ((uint32_t*)(0x1FFF7A10))
#endif

uint32_t inline getUniqueID(uint8_t Idx) { return UniqueID[Idx]; }

#endif // __UNIQUEID_H__

