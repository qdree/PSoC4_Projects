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
#include <Keyboard.h>
#include "LiquidCrystal_I2C.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>



char pin[5];
const char* check = "1111";
uint32_t Addr = 0x27;
uint8 i = 0;
uint8 Key;
bool security_active = true;
//bool alarm = false;
bool accepted = false;

const char *card_id =  "09008B316BD8";
char arr[14];
char buffer[30];
char character;
int ind = 0;
uint32 ch; 
uint32 ms_count = 0;

 
void print_card_id(uint8 i);
void check_card();


void input_pin(const char el);
void compare(char a[], char b[]);
void accept(char a[],const char b[]);
void discard(char a[]);
void security();
void pass();


CY_ISR(MY_ISR) 
{
    if(accepted && ++ms_count == 50000) 
    {
        accepted = false;
        ms_count = 0;
        clear();   
        LED_GREEN_Write(1);
        LED_RED_Write(1);
        setCursor(0,1);
        LCD_print("Door closed!");
    }
}

int main()
{
    Keyboard_Init();
    I2C_Start();
    UART_Start();
    Timer_Start();
    isr_1_StartEx(MY_ISR);
    LiquidCrystal_I2C_init(Addr,16,2,0);
    begin();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    setCursor(0,1);
    
    
    for(;;)
    {
        //security();
        check_card();

    }
}


void input_pin(const char el)
{    
    write(el);
    pin[i++] = el;
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
                        if(strcmp(arr, card_id) == 0)
                        {   
                            clear();
                            setCursor(0,0);
                            LCD_print("Access granted!");
                            setCursor(0,1);
                            LCD_print("ID: ");
                            LCD_print(arr);
                            LED_GREEN_Write(0);
                            LED_RED_Write(1);
                            accepted = true;
                        }
                        else
                        {
                            clear();
                            setCursor(0,0);
                            LCD_print("Access denied!");
                            setCursor(0,1);
                            LCD_print("ID: ");
                            LED_GREEN_Write(1);
                            LED_RED_Write(0);
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

void discard(char a[])
{
    memset(a,'\0',strlen(a));
    i = 0;
    clear();
    setCursor(0,1);
}

void accept(char a[],const char b[])
{
    
    if(strcmp(a, b) == 0)
    {
        clear();
        setCursor(1,0);
        if(security_active)
        {
            LCD_print("Alarm disabled");
            LED_GREEN_Write(0);
            LED_RED_Write(1);
            security_active = false;
        }
        else if(!security_active)
        {
            LCD_print("Alarm enabled");
            security_active = true;
        }
        
    }
    else 
    {
        clear();
        setCursor(1,0);
        LCD_print("Wrong password");
    }
    memset(a,'\0',strlen(a));
    i = 0;
    setCursor(0,1);
}

void pass()
{
    Key = Get_KBD_Char();		//Value recieved from Matrix
        switch(Key)                 //Recognition of pressed card_id
        {              
            case '*':
                accept(pin, check);
                break;
            case '#':
                discard(pin);
                break;
            case '1':
                input_pin('1');
                break;
            case '2':
                input_pin('2');
                break;
            case '3':
                input_pin('3');
                break;
            case '4':
                input_pin('4');
                break;
            case '5':
                input_pin('5');
                break;
            case '6':
                input_pin('6');
                break;
            case '7':
                input_pin('7');
                break;
            case '8':
                input_pin('8');
                break;
            case '9':
                input_pin('9');
                break;
            case '0':
                input_pin('0');
                break;

            default:
                memset(pin,'\0', strlen(pin));
                write(' ');
                break;
        }
}


void security()
{
    if(security_active && (PIR_4_Read()==1))
    {
        clear();
        setCursor(1,0);
        //alarm = true;
        LED_GREEN_Write(1);
        LED_RED_Write(0);
    }
    else if(security_active && (PIR_4_Read()==0))
    {
        clear();
        setCursor(5,0);
        //alarm = false;
        LED_GREEN_Write(0);
        LED_RED_Write(1);
    }
    else 
    {   
        //alarm = false;
        LED_GREEN_Write(0);
        LED_RED_Write(1);
    }
    
}



/* [] END OF FILE */
