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



char pin[5];
char* check = "1111";
uint32_t Addr = 0x27;
uint8 i = 0;
uint8 Key;
bool password = false;
bool security_active = true;


void input_pin(const char el);
void compare(char a[], char b[]);
void accept(char a[], char b[]);
void discard(char a[]);
void alarm();
void pass();

int main()
{
    Keyboard_Init();
    I2C_Start();
    LiquidCrystal_I2C_init(Addr,16,2,0);
    begin();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    setCursor(0,1);
    
    
    for(;;)
    {
        //alarm();
        pass();
        
    }
}


void input_pin(const char el)
{    
    write(el);
    pin[i++] = el;
}

void discard(char a[])
{
    memset(a,'\0',strlen(a));
    i = 0;
    clear();
    setCursor(0,1);
}

void accept(char a[],char b[])
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
        switch(Key)                 //Recognition of pressed key
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


void alarm()
{
    if(security_active && (PIR_4_Read()==1))
    {
        clear();
        setCursor(0,1);
        LCD_print("Motion cought");
        LED_GREEN_Write(1);
        LED_RED_Write(0);
    }
    else if(security_active && (PIR_4_Read()==0))
    {
        clear();
        setCursor(14,1);
        LCD_print("OK");
        LED_GREEN_Write(0);
        LED_RED_Write(1);
    }
    else 
    {
        LED_GREEN_Write(0);
        LED_RED_Write(1);
    }
    
}


/* [] END OF FILE */
