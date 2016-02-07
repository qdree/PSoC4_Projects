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
#include <project.h>
#include "stdlib.h"

#define SLIDER_POS_TO_COMPARE_SHIFT    (4u)

void cleaner();
void CapSense_DisplayState(void);
void CapSense_activity(void);

uint16 curPos, oldPos;

int main()
{
    CyGlobalIntEnable;
    PWM_Start();
    LCD_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    for(;;)
    {
        CapSense_UpdateEnabledBaselines();
        CapSense_ScanEnabledWidgets();
        
    	while(CapSense_IsBusy() != 0)
    	{
    		/* Loop until condition true */
    	}
        CapSense_DisplayState();      
    }
}

int char_to_int(char char_value)
{
  return ((int) char_value) - 48;
}

void cleaner()
{
int b;
for( b = 0; b < 16; b++ )
    {
        LCD_Position(1,b);
        LCD_PutChar(' ');   
    }
}




void CapSense_DisplayState(void)
{
    uint16 i = PWM_ReadCompare();
    /* Find Slider Position */
    curPos = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);    
    
    /* Reset position */
    if(curPos == 0xFFFFu)
    {
        curPos = 0u;
    }
                
    /* Move bargraph */
    if (curPos != oldPos)
    {
        oldPos = curPos;
        /* Display Slider bargraph */
        if (curPos != 0u)
        {
            LCD_ClearDisplay();
            PWM_WriteCompare((uint32)curPos << SLIDER_POS_TO_COMPARE_SHIFT);
            i = curPos; 
            
            if(i == 100)
            {
                LCD_ClearDisplay();
                LCD_PrintString("Volume lvl: MAX");
            }
            else if(i == 1)
            {
                LCD_ClearDisplay();
                LCD_PrintString("Volume lvl: MIN");
            }
            else
            {           
                LCD_ClearDisplay();
                LCD_PrintString("Volume lvl: ");
                LCD_PrintNumber(i);
                LCD_PutChar('%');
            }
            
            
        }
    }


}

