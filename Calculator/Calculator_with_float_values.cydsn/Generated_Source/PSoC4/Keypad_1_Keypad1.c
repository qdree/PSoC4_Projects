/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cyfitter.h"
#include <device.h>

uint8 Keypad_1_GetCol(void)
{
	uint8 Col;
		
	while(!(Keypad_1_Status_Reg_Read() & 0x10));	//Wait for a valid press of button
	
	if(Keypad_1_Status_Reg_Read() & 0x10)			//Check for a valid press of button
	{
		Col = Keypad_1_Status_Reg_Read();
	}
	
	Col = (Col & 0x03);										//Extract correct Column
	
	return (Col);
}

uint8 Keypad_1_GetRow(void)
{
	uint8 Row;
	
	while(!(Keypad_1_Status_Reg_Read() & 0x10));	//Wait for a valid press of button
	
	if(Keypad_1_Status_Reg_Read() & 0x10)			//Check for a valid press of button
	{
		Row = Keypad_1_Status_Reg_Read();
	}
		
	Row = (Row & 0x0C) >> 2;								//Extract correct Row
	
	return Row;
}

uint8 Keypad_1_GetButton(void)
{
	char8 Button;
	
	uint8 x,y;
	
	x = Keypad_1_GetCol();
	
	y = Keypad_1_GetRow();

	Button=Keypad_1_Key[y][x];										//Assign correct Character
	
	while(!(Keypad_1_Status_Reg_Read() & 0x10));	//Wait for a valid press of button
	
	return Button;
}

/* [] END OF FILE */
