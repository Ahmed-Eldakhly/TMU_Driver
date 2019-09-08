/*
 * TMU_cfg.h
 *
 *  Created on: Sep 7, 2019
 *      Author: hp
 */

#ifndef TMU_CFG_H_
#define TMU_CFG_H_

#include"STDTYPES.h"
#define ID_MAX 100
#define NULL ((void*)0x00)

typedef enum
{
NUM_1,
NUM_2,
NUM_5
}Delay;

typedef enum
{
NUM_4,
NUM_8,
NUM_20
}TIMER_FLAG;

typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2

}TIMER_Select;

#define MAX_ID 50

typedef struct
{
	TIMER_Select TIMER;
	Delay BaseTime;
}TMU_cfg;

extern TMU_cfg TMU_Config;

typedef enum
{
	EnmTMUError_t,
	OK
}Status;

typedef enum
{
	OneTime,
	Repeated
}Fun_Repeat;
typedef struct
{
	uint8 TimeTask;
	Fun_Repeat fun_rep;
	void (*ptr)(void);
	uint32 StartFlag;

}Task_Cfg;

Task_Cfg arr[ID_MAX];

void TIMER_Base(Delay TIMER_Delay, uint8* FlagNum);



#endif /* TMU_CFG_H_ */
