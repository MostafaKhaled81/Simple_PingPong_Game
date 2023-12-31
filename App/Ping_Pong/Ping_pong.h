/*
 * Ping_pong.h
 *
 * Created: 8/30/2023 1:59:27 AM
 *  Author: mk591
 */ 


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PING_PONG_H_
#define PING_PONG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"
#include "Button.h"
#include "Buzzer.h"

#define F_CPU 16000000U
#include <util/delay.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void PingPong_Init(void);
void PingPong_Start(void);
 
#endif /* PING_PONG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/