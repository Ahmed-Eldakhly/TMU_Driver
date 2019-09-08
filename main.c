/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: hp
 */
#include"STDTYPES.h"
#include"TMU_cfg.h"
#include"TMU_interface.h"
#include"DIO_interface.h"
#include"Macro.h"
#include"avr/interrupt.h"
/*#include"TIMER0_MemoryMaping.h"*/
void led_on(void){
	 /* GO LED*/
	DIO_WritePin(PIN12,1u);
}
void led_off(void){
	 /* OFF LED*/
	DIO_WritePin(PIN12,0u);
}
int main(void)
{

	DIO_SetPinDirection(PIN12,1u);

	/* Replace with your application code */
	TMU_Init();
	Task_Cfg x={30,Repeated,led_on,0};
	Task_Cfg y={35,Repeated,led_off,0};
	TMU_Start(5,&x);
	TMU_Start(11,&y);
	/*TMU_Stop(11);
	TMU_Stop(5);*/
	Set_Bit(SREG,7);
/*if((Get_Bit(TIMSK,OCIE))==0)
	DIO_WritePin(PIN12,0u);
TMU_DeInit();
if(((Get_Bit(TCCR0,CS00))&(Get_Bit(TCCR0,CS01))&(Get_Bit(TCCR0,CS02)))==0)
	DIO_WritePin(PIN12,1u);*/
	while (1)
	{

	}
}


