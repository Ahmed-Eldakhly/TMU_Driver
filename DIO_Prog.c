/*
 * DIO_Prog.c
 *
 *  Created on: Aug 1PIN7, 2PIN019
 *      Author: hp
 */

#include"DIO_MemoryMaping.h"
#include"DIO_interface.h"
#include"Macro.h"
#include "STDTYPES.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinValue==High)
	{
		if((PinNum>=PIN0)&&(PinNum<=PIN7))
		{
			Set_Bit(PORTA,PinNum);
		}
		else if((PinNum>=PIN8)&&(PinNum<=PIN15))
		{
			Set_Bit(PORTB,(PinNum-PIN8));
		}
		else if((PinNum>=PIN16)&&(PinNum<=PIN23))
		{
			Set_Bit(PORTC,(PinNum-PIN16));
		}
		else if((PinNum>=PIN24)&&(PinNum<=PIN31))
		{
			Set_Bit(PORTD,(PinNum-PIN24));
		}
	}
	else if(PinValue==PIN0)
	{

		if((PinNum>=PIN0)&&(PinNum<=PIN7))
		{
			Clear_Bit(PORTA,PinNum);
		}
		else if((PinNum>=PIN8)&&(PinNum<=PIN15))
		{
			Clear_Bit(PORTB,(PinNum-PIN8));
		}
		else if((PinNum>=PIN16)&&(PinNum<=PIN23))
		{
			Clear_Bit(PORTC,(PinNum-PIN16));
		}
		else if((PinNum>=PIN24)&&(PinNum<=PIN31))
		{
			Clear_Bit(PORTD,(PinNum-PIN24));

		}
	}

}
uint8 DIO_ReadPin(uint8 PinNum)
{
	if((PinNum>=PIN0)&&(PinNum<=PIN7))
	{
		return Get_Bit(PINA,PinNum);
	}
	else if((PinNum>=PIN8)&&(PinNum<=PIN15))
	{
		return Get_Bit(PINB,(PinNum-PIN8));
	}
	else if((PinNum>=PIN16)&&(PinNum<=PIN23))
	{
		return Get_Bit(PINC,(PinNum-PIN16));
	}
	else if((PinNum>=PIN24)&&(PinNum<=PIN31))
	{
		return Get_Bit(PIND,(PinNum-PIN24));
	}
	return PIN8;
}
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection==Input)
	{
		if((PinNum>=PIN0)&&(PinNum<=PIN7))
		{
			Clear_Bit(DDRA,PinNum);
		}
		else if((PinNum>=PIN8)&&(PinNum<=PIN15))
		{
			Clear_Bit(DDRB,(PinNum-PIN8));
		}
		else if((PinNum>=PIN16)&&(PinNum<=PIN23))
		{
			Clear_Bit(DDRC,(PinNum-PIN16));
		}
		else if((PinNum>=PIN24)&&(PinNum<=PIN31))
		{
			Clear_Bit(DDRD,(PinNum-PIN24));
		}
	}
	else if(PinDirection==Output)
	{
		if((PinNum>=PIN0)&&(PinNum<=PIN7))
		{
			Set_Bit(DDRA,PinNum);
		}
		else if((PinNum>=PIN8)&&(PinNum<=PIN15))
		{
			Set_Bit(DDRB,(PinNum-PIN8));
		}
		else if((PinNum>=PIN16)&&(PinNum<=PIN23))
		{
			Set_Bit(DDRC,(PinNum-PIN16));
		}
		else if((PinNum>=PIN24)&&(PinNum<=PIN31))
		{
			Set_Bit(DDRD,(PinNum-PIN24));
		}
	}


}
