/*
 * TImer0_Prog.c
 *
 *  Created on: Aug 18, 2019
 *      Author: hp
 */
#include"Timer0_interface.h"
#include"TIMER0_MemoryMaping.h"
#include"Macro.h"
#include"DIO_MemoryMaping.h"
#include"DIO_interface.h"
#include "STDTYPES.h"



void TIMER_init(void)
{

		TCCR0&=(~((1<<WGM00)|(1<<WGM01)));
		TCCR0|=(1<<WGM01);
		OCR0=250;
		TCCR0&=(~((1<<CS00)|(1<<CS01)|(1<<CS02)));
		TCCR0|=(1<<CS01);
}
void TIMER_Deinit(void)
{
	TCCR0&=(~((1<<CS00)|(1<<CS01)|(1<<CS02)));
	OCR0=0;
}


