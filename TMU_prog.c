/*
 * TMU_prog.c

 *
 *  Created on: Sep 7, 2019
 *      Author: hp
 */
#include "TMU_interface.h"
#include"Timer0_interface.h"
#include"Macro.h"
#include"avr/interrupt.h"
#include"DIO_interface.h"
uint8 TMU_flag;
uint32 g_Flag;
uint8 g_count=0;
Status TMU_Init(void)
{

	if(TMU_Config.TIMER==TIMER0)
	{

		TIMER_init();
		TIMER_Base(TMU_Config.BaseTime,&TMU_flag);
		return OK;
	}
	else
	{
		return EnmTMUError_t;
	}

}

Status TMU_Start(uint8 ID,Task_Cfg* Task_Cfg_ptr)
{

	if((Get_Bit(TIMSK,OCIE))==0)
	{
		Set_Bit(TIMSK,OCIE);

	}
	else
	{
		/*DO No thing*/
	}
	if(ID<ID_MAX)
	{
		arr[ID].TimeTask=Task_Cfg_ptr->TimeTask;
		arr[ID].fun_rep=Task_Cfg_ptr->fun_rep;
		arr[ID].ptr=Task_Cfg_ptr->ptr;
		arr[ID].StartFlag=g_Flag;
		return OK;
	}
	else
	{
		return EnmTMUError_t;
	}
}

Status TMU_Stop(uint8 ID)
{
	if(arr[ID].ptr!=NULL)
	{
		/*uint8 Interrupt_check;*/
		arr[ID].TimeTask=0;
		arr[ID].fun_rep=0;
		arr[ID].ptr=NULL;
		for(uint8 count=0;count<ID_MAX;count++)
		{
			if(arr[count].ptr!=NULL)
			{
				return OK;
			}
		}
		Clear_Bit(TIMSK,OCIE);
		return OK;
	}
	else

	{
		return EnmTMUError_t;
	}
}

Status TMU_Dispatch(void)
{
	for(uint8 count=0;count<ID_MAX;count++)
	{

		if(((g_Flag-arr[count].StartFlag)%arr[count].TimeTask)==0)
		{
			if(arr[count].fun_rep==OneTime)
			{
				arr[count].ptr();
				TMU_Stop(count);
			}
			else
			{
				arr[count].ptr();
			}
		}
		else
		{
			/*Do No Thing*/
		}

	}
	return OK;
}

Status TMU_DeInit(void)
{
if((Get_Bit(TIMSK,OCIE))==0)
{
	TIMER_Deinit();
	return OK;
}
else
{
	return EnmTMUError_t;
}
}

ISR(TIMER0_COMP_vect)
{

	g_count++;
	if(g_count==TMU_flag)
	{
		g_count=0;
		g_Flag++;
		TMU_Dispatch();
	}
}

