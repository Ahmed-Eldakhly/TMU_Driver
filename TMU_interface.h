/*
 * TMU_interface.h
 *
 *  Created on: Sep 7, 2019
 *      Author: hp
 */

#ifndef TMU_INTERFACE_H_
#define TMU_INTERFACE_H_


#include"TMU_cfg.h"
Status TMU_Init(void);
Status TMU_Start(uint8 ID,Task_Cfg* Task_Cfg_ptr);
Status TMU_Dispatch(void);


#endif /* TMU_INTERFACE_H_ */
