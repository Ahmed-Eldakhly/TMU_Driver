/*
 * Timer0_interface.h
 *
 *  Created on: Aug 18, 2019
 *      Author: hp
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
#include"TIMER0_MemoryMaping.h"
#include"TIMER0_Config.h"
#ifndef F_CPU
#define F_CPU 8000000UL //8MHz Clock frequency
#endif

void TIMER_init(void);
void TIMER_Deinit(void);

/*void Timer_delayWithButton_ms(uint32 u32DelayNumber,uint8 StopButton);*/

#endif /* TIMER0_INTERFACE_H_ */
