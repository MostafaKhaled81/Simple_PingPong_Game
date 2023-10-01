/*
 * LCD_Core.c
 *
 * Created: 8/23/2023 9:30:49 PM
 *  Author: mk591
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LCD_Init(void)
{
	#if (LCD_MODE==LCD_4BIT_MODE)
	lCD_WriteCommand(0X33);
	lCD_WriteCommand(0X32);
	lCD_WriteCommand(0X28);
	
	lCD_WriteCommand(0X0C);
	lCD_WriteCommand(0X01);
	lCD_WriteCommand(0X06);
	lCD_WriteCommand(0X02);
	#endif
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void lCD_WriteCommand(uint8 cmd)
{
	DIO_WriteChannel(LCD_RS_PIN,PIN_LOW);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	#if (LCD_MODE==LCD_4BIT_MODE)
	
	                 /*BIT ACCESS WAY*/
	/*
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd,4));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd,5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd,6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd,7));
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd,0));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd,1));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd,2));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd,3));
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	*/
	
                    	/*MASK WAY*/
	uint8 old_value=0,new_value=0;
	
	DIO_ReadOutputPort(PORT_A,&old_value);
	new_value=((cmd>>1)&DATA_MASK)|(old_value&DATA_PORT_MASK);
	DIO_WritePort(PORT_A,new_value);
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOutputPort(PORT_A,&old_value);
	new_value=((cmd<<3)&DATA_MASK)|(old_value&DATA_PORT_MASK);
	DIO_WritePort(PORT_A,new_value);
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	#endif
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteChar(uint8 chr)
{
		DIO_WriteChannel(LCD_RS_PIN,PIN_HIGH);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	#if (LCD_MODE==LCD_4BIT_MODE)
	
	                 /*BIT ACCESS WAY*/
	/*
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr,4));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr,5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr,6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr,7));
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr,0));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr,1));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr,2));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr,3));
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	*/
	
                    	/*MASK WAY*/
	uint8 old_value=0,new_value=0;
	
	DIO_ReadOutputPort(PORT_A,&old_value);
	new_value=((chr>>1)&DATA_MASK)|(old_value&DATA_PORT_MASK);
	DIO_WritePort(PORT_A,new_value);
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOutputPort(PORT_A,&old_value);
	new_value=((chr<<3)&DATA_MASK)|(old_value&DATA_PORT_MASK);
	DIO_WritePort(PORT_A,new_value);
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	#endif
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_Write_String(uint8 *chr)
{
	uint8 cnt=0;
	while(chr[cnt]!='\0')
	{
		LCD_WriteChar(chr[cnt]);
		cnt++;
	}
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteInteger(sint32 num)
{
	sint32 temp=1;
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	else if(num<0)
	{
		LCD_WriteChar('-');
		num*=-1;
	}
	while(num)
	{
		temp=(temp*10)+(num%10);
		num/=10;
	}
	while(temp!=1)
	{
		LCD_WriteChar((temp%10)+48);
		temp/=10;
	}
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_Clear(void)
{
	lCD_WriteCommand(0X01);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_GOTO(uint8 Row,uint8 Col)
{
	uint8 arr[2]={0X80,0XC0};
	lCD_WriteCommand(arr[Row]+Col);
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_Custom_char(void)
{
	uint8 cus_chr_cnt=0,bytes=0;
	for (cus_chr_cnt=0;cus_chr_cnt<c_char_no;cus_chr_cnt++)
	{
		lCD_WriteCommand(0X40+(cus_chr_cnt*8));
		for(bytes=0;bytes<bytes_no;bytes++)
		{
			LCD_WriteChar(Custom_char[cus_chr_cnt][bytes]);
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/