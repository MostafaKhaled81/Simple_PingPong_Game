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
#include "DIO_CORE.h"

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
void DIO_WriteChannel(uint8 pin_num,PIN_VALUE_t Pin_Value)
{
	uint8 port=0,pin=0;
	port=pin_num/NUMBER_OF_EACH_PORT_PINSS;
	pin=pin_num%NUMBER_OF_EACH_PORT_PINSS;
	switch(Pin_Value)
	{
		case PIN_HIGH:
		switch(port)
		{
			case 0:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 1:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 2:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 3:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
		}
		break;
		case PIN_LOW:
		switch(port)
		{
			case 0:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 1:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 2:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 3:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
		}
		break;
	}
}
/******************************************************************************
* \Syntax          : void DIO_ReadChannel(uint8 pin_num,PIN_VALUE_t *PinValue)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_ReadChannel(uint8 pin_num,PIN_VALUE_t *Pin_Value)
{
	uint8 port=0,pin=0;
	port=pin_num/NUMBER_OF_EACH_PORT_PINSS;
	pin=pin_num%NUMBER_OF_EACH_PORT_PINSS;
	
		switch(port)
		{
			case 0:
			*Pin_Value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),pin);
			break;
			case 1:
			*Pin_Value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),pin);
			break;
			case 2:
			*Pin_Value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),pin);
			break;
			case 3:
			*Pin_Value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),pin);
			break;
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
void DIO_FlipChannel(uint8 Pin_Num){
	uint8 Port=0 ,Pin=0;
	Port=Pin_Num/(NUMBER_OF_EACH_PORT_PINSS);
	Pin=Pin_Num % (NUMBER_OF_EACH_PORT_PINSS);
	switch(Port){
		case 0:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 1:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 2:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 3:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		default:
		break;
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
void DIO_WritePort(PORT_NUM PORT,uint8 Port_value){
	switch(PORT){
		case 0:
		PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=Port_value;
		break;
		case 1:
		PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=Port_value;
		break;
		case 2:
		PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=Port_value;
		break;
		case 3:
		PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=Port_value;
		break;
		default:
		break;
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
void DIO_ReadPort(PORT_NUM PORT,uint8 *Port_value){
	switch(PORT){
		case 0:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN);
		break;
		case 1:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN);
		break;
		case 2:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN);
		break;
		case 3:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN);
		break;
		default:
		break;
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
void DIO_ReadOutputPort(PORT_NUM PORT,uint8 *Port_value){
	switch(PORT){
		case 0:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 1:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 2:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 3:
		*Port_value=PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		default:
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
