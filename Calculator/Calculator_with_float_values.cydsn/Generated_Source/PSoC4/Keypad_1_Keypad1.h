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

//#if !defined(Keypad_1_H)
//#define Keypad_1_H

uint8 Keypad_1_GetCol(void);		//Returns value of column if a button is pressed

uint8 Keypad_1_GetRow(void);		//Returns value of row if a button is pressed

uint8 Keypad_1_GetButton(void);		//Returns the corresponding character from the Key array

char Keypad_1_Key [4][4];							//Define the matrix array

//#endif

//[] END OF FILE
