/*
 * TMU_cfg.c
 *
 *  Created on: Sep 7, 2019
 *      Author: hp
 */

#include"TMU_cfg.h"
TMU_cfg TMU_Config = {TIMER0, NUM_1};
void TIMER_Base(Delay TIMER_Delay, uint8* FlagNum)
{
	TIMER_FLAG Timer_Flag;
	switch(TIMER_Delay)
	{
	case NUM_1:
		Timer_Flag=NUM_4;
		break;
	case NUM_2:
		Timer_Flag=NUM_8;
		break;
	case NUM_5:
		Timer_Flag=NUM_20;
		break;
	default:
		break;
	}
	*FlagNum = Timer_Flag;
}
