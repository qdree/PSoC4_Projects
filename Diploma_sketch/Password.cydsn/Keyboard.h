/********************************************************************************/
/*																				*/
/*    FILENAME: 	C:\Cypress PSoC\Tastatur\Tastatur.cydsn\Keyboard.h			*/
/*    VERSION:  1.0																*/
/*    Date: October 2011														*/
/*																				*/
/*	(C) 2011 Jörg Meier Software - Entwicklung									*/
/*	Steinfelder Str. 11 27404 Brümmerhof										*/
/*	All rights resereved														*/
/*	Given to Cypress Community/Developer Forum December 1st 2011				*/
/*	Just as-it-is, no Warranty, use on own risk.								*/
/********************************************************************************/
/*																				*/
/*	De-Bouncing of a Keyboard, Buffering, Key-Repeating							*/
/*																				*/
/********************************************************************************/
#ifndef __Keyboard1h__
#define __Keyboard1h__

void Keyboard_Init(void);
char8 KBD_Char_Ready(void);
char8 Get_KBD_Char(void);

#endif
//[] END OF FILE
