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
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

const char *key =  "09008B316BD8";
char arr[14];
char buffer[30];
char character;
int ind = 0;
uint32 ch; 
uint16 ms_count = 0;
bool accepted = false;
 
void print_key(uint8 i);
void check_card();

CY_ISR(MY_ISR) 
{
    if(accepted && ++ms_count == 5) 
    {
        accepted = false;
        ms_count = 0;
        
        LED_GREEN_Write(1);
        LED_RED_Write(1);
        UART_UartPutString("\n\r Door closed!\n\r");
    }
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    Timer_Start();
    isr_1_StartEx(MY_ISR);
    
       
    
    for(;;)
    {
        check_card();
    }
        
}

void check_card()
{
     if (!accepted)
        {
            ch = UART_UartGetChar();
            if(ch != 0)
            {
                switch(ch)
                {
                    case '\002':
                        memset(arr, 0, strlen(arr));
                        break;
                    case '\003':
                        if(strcmp(arr, key) == 0)
                        {
                            LED_GREEN_Write(0);
                            LED_RED_Write(1);
                            //UART_UartPutString("Access granted! Card Number: ");
                            //UART_UartPutString(arr);
                            accepted = true;
                        }
                        else
                        {
                            LED_GREEN_Write(1);
                            LED_RED_Write(0);
                            //UART_UartPutString("Access denied! Card Number: ");
                            //UART_UartPutString(arr);
                            accepted = false;
                        }
                        ind = 0;
                        break;
                    default:
                        arr[ind++] = ch; 
                        
                }
            }
            else
            {
                LED_GREEN_Write(1);
                LED_RED_Write(1);
            }

        }
}

void print_key(uint8 i)
{
    if(i != 0)
    {
        UART_UartPutChar(i);
        ind++;
        if(ind == 14)
        {
            UART_UartPutChar('\t');
            ind = 0;
        }
    }
}


/* [] END OF FILE */
