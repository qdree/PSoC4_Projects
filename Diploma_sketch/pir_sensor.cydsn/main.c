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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   
    for(;;)
    {
        if(pir1_Read() == 0)
        {
            green_Write(0);
            red_Write(1);
            blue_Write(1);
            
        }
        else if(pir2_Read() == 0) 
        {
            green_Write(1);
            red_Write(0);
            blue_Write(1);
            
        }
        else if(pir3_Read() == 0) 
        {
            green_Write(1);
            red_Write(1);
            blue_Write(0);
        }
        else if(pir4_Read() == 0) 
        {
            green_Write(1);
            red_Write(0);
            blue_Write(0);
        }
        else if(Front_door_Read() == 1)
        {
            green_Write(0);
            red_Write(0);
            blue_Write(1);
        }
        else
        {
            green_Write(0);
            red_Write(0);
            blue_Write(0);
        }
    }
}

/* [] END OF FILE */
