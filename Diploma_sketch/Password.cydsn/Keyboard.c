/********************************************************************************/
/*																				*/
/*    FILENAME:		C:\Cypress PSoC\Tastatur\Tastatur.cydsn\Keyboard.c			*/
/*    VERSION:  	1.0															*/
/*    Date:			October 2011												*/
/*																				*/
/*	(C) 2011 Jörg Meier Software - Entwicklung									*/
/*	Steinfelder Str. 11 27404 Brümmerhof										*/
/*	All rights resereved														*/
/********************************************************************************/
/*																				*/
/*	De-Bouncing of a Keyboard, Buffering, Key-Repeating							*/
/*																				*/
/*	Given to Cypress Community/Developer Forum December 1st 2011				*/
/*	Just as-it-is, no Warranty, use on own risk.								*/
/********************************************************************************/
/*																				*/
/*	Timer to call Debounce_Switches is called at a rate of 2.5ms				*/
/*																				*/
/********************************************************************************/
#include <device.h>
#define TIMER_INTERVAL 50	//5 ms
#define MAX_CHECKS 10 		// Number of Samples Before Key is De-bounced
#define REPEAT_RATE (200/TIMER_INTERVAL)	// 400 ms Key Repeat Rate
#define INITIAL_DELAY (600/TIMER_INTERVAL - REPEAT_RATE) // 600 ms Wait-Time Before Key first Repeated
/********************************************************************************/
//#define Debug	//Test purposes													*/
/********************************************************************************/

CY_ISR_PROTO(Key_Debounce);


uint8 Debounced_Key = 0; // Last Debounced Key

/********** Key Buffer **********************/
#define KEYBUFFSIZE 10	// Number of Keypresses to buffer
/********************************************/
uint8 KBD_WriteIndex = 0;					
uint8 KBD_ReadIndex = 0;
char8 KBD_Buffer[KEYBUFFSIZE];
/********************************************/

//********** Definition of the Keyboard Matrix ************//
#define KEYROWS 4
#define KEYCOLS	3
#define KEYRWIDTH 2		// Number of bits to encode KEYROWS-1
#define KEYCWIDTH 2		// Number of bits to encode KEYCOLS-1
// Resulting bit pattern is 0000CCRR with a max value of 0b0000 1011 = 0x0b +1 = 0x0c = 12
//********** End of Matrix Definition *********************//
#define MAXKEYVALUE (((KEYCOLS-1) | ((KEYROWS -1) << KEYCWIDTH)))+1
#define KEYROWMASK ((1 << KEYROWS)-1)
#define KEYCOLMASK ((1 << KEYCOLS)-1)

CYCODE const char8 TranslateTable[MAXKEYVALUE] = {
					'1','4','7',
                    '*','2','5',
					'8','0','3',
					'6','9','#'
												 };
								 
void Keyboard_Init(void)
{
	Debounce_Int_StartEx(Key_Debounce);
	Debounce_Timer_Start();
}

void Put_KBD_Char(char8 Ch)
{
	KBD_Buffer[KBD_WriteIndex++] = TranslateTable[Ch-1];
	if (KBD_WriteIndex >= KEYBUFFSIZE) KBD_WriteIndex = 0;
}

char8 KBD_Char_Ready(void)
{
	return (KBD_WriteIndex != KBD_ReadIndex);
}

char8 Get_KBD_Char(void)
{
char8 Result;
	while (!KBD_Char_Ready());
	Result = KBD_Buffer[KBD_ReadIndex++];
	if (KBD_ReadIndex >= KEYBUFFSIZE) KBD_ReadIndex = 0;
	return Result;
}

uint8 LowestBitPosition(uint8 Val)
{
uint8 ii;
	for (ii=0; ii < 8;ii++,Val >>= 1)
	{
		if (Val & 0x01u) return ii;
	}
	return 0xffu;
}

uint8 ReadMatrix(void) 
{
char8	Row;
char8	Column;
	//*** Get Row ***//
	KBD_ROWPins_Write(KEYROWMASK);
	KBD_COLPins_Write(~KEYCOLMASK);
	if ((Row=KBD_ROWPins_Read()) == KEYROWMASK) return 0;
	//*** Get Column ***//
	KBD_COLPins_Write(KEYCOLMASK);
	KBD_ROWPins_Write(Row);
	if ((Column = KBD_COLPins_Read()) == KEYCOLMASK) return 0;

	return (LowestBitPosition(~Row) | (LowestBitPosition(~Column) << 2))+1; // max is 0b0000 1011 = 11 dec + 1
}

//***********************************************//
//* Service routine called by a timer interrupt	**/
//***********************************************//
void Key_Debounce(void)
{
static uint8 State[MAX_CHECKS];			// 	Array that maintains bounce status
static uint8 StateIndex = 0;			//	Index into State
static uint8 Key_Pressed_Delay	= 0;	//	Delay for continous pressed Key before first keystroke is generated
static uint8 Key_Generate_Delay	= 0;	//	Delay for generating next Keystroke when key is pressed continously
uint8 ii;								//	used as a loop-index
uint8 NewKey;							//	New key pressed /released state

	Debounce_Timer_ReadStatusRegister();		// Clear Interrupt source
	State[StateIndex++] = ReadMatrix();			
	if(StateIndex >= MAX_CHECKS)StateIndex = 0;	// Wrap around

	for(ii=0,NewKey=0xff; ii<MAX_CHECKS;NewKey &= State[ii++]);

/***** NewKey is new, Debounced_Key is old *****/
/*	new old 									*/
/*	0	0	 	nothing happened	!new & !old	*/
/*  0   1		key released		!new &  old	*/
/*	1	0		key pressed			 new & !old	*/
/*	1	1		continued keypress	 new &  old	*/
/************************************************/

	if ((uint8)((~NewKey) & (~Debounced_Key))== 0xffu)	// Nothing has happened
	{
		Debounced_Key = NewKey;
		return;
	}
	
	if ((uint8)(~NewKey & Debounced_Key)!= 0x00u)		// Any key released
	{
		Debounced_Key = NewKey;
		Key_Pressed_Delay = 0;
		return;
	}
	
	if ((uint8)(NewKey & ~Debounced_Key)!= 0x00u)		// Key pressed seen first time
	{
		Put_KBD_Char(NewKey);
		Key_Pressed_Delay = 0;
		Debounced_Key = NewKey;
		return;
	}
	
	if ((uint8)(NewKey & Debounced_Key)!= 0x00u)		// Key is continously pressed
	{
		if (Key_Pressed_Delay < INITIAL_DELAY)
		{
			Key_Pressed_Delay++;
			Key_Generate_Delay = 0;
		}
		else
		{
			Key_Generate_Delay++;
			if (Key_Generate_Delay >= REPEAT_RATE)
			{
				Key_Generate_Delay = 0;
				Put_KBD_Char(NewKey);
			}
		}
		Debounced_Key = NewKey;	
	}
}

/* [] END OF FILE */
