/*
 * TIMER0_MemoryMaping.h
 *
 *  Created on: Aug 18, 2019
 *      Author: hp
 */

#ifndef TIMER0_MEMORYMAPING_H_
#define TIMER0_MEMORYMAPING_H_

#include "STDTYPES.h"


//pre_scaler
#define Timer0_OFF 0
#define Timer0_Prescaler_1 1
#define Timer0_Prescaler_8 8
#define Timer0_Prescaler_64 64
#define Timer0_Prescaler_256 256
#define Timer0_Prescaler_1024 1024

//Timer_Mode
#define Timer0_NormalMode 0
#define Timer0_PWM_PhaseCorrectMode 1
#define Timer0_CTCMode 2
#define Timer0_FastPWMMode 3

//OCR0 Pin Actions at compare match
//Normal&CTC mode
#define OCR_Disconnect 0
#define OCR_Toggel 1
#define OCR_Clear 2
#define OCR_Set 3

//Fast PWM
#define OCR_Disconnect 0
#define OCR_ClearUpcounting_SetDowncounting 4
#define OCR_SetUpcounting_ClearDowncounting 6

//Fast Compare Match
#define OCR_Disconnect 0
#define OCR_ClearCompare_SetOverflow 7
#define OCR_SetCompare_ClearOverflow 9


#define TCCR0 (*(volatile uint8*)0x53)
#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0


#define TCNT0 (*(volatile uint8*)0x52)

#define OCR0 (*(volatile uint8*)0x5C)

#define TIMSK (*(volatile uint8*)0x59)
#define OCIE 1
#define TOIE 0

#define TIFR (*(volatile uint8*)0x58)
#define OCF0 1
#define TOV0 0

#endif /* TIMER0_MEMORYMAPING_H_ */
