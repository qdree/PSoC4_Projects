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
#include <stdbool.h>
#include <string.h>


char pin[5];
char* check = "1111";
uint8 i = 0;
uint8 Key;
bool password = false;
bool security_active = true;


void input_pin(const char el);
void compare(char a[], char b[]);
void accept(char a[], char b[]);
void discard(char a[]);

int main()
{
    Keyboard_Init();
    LCD_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Position(1,0);
    
    
    for(;;)
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
                LCD_PutChar(' ');
                break;
                
        }
    }
}


void input_pin(const char el)
{    
    LCD_PutChar('*');
    pin[i++] = el;
}

void discard(char a[])
{
    memset(a,'\0',strlen(a));
    i = 0;
    LCD_ClearDisplay();
    LCD_Position(1,0);
}

void accept(char a[],char b[])
{
    
    if(strcmp(a, b) == 0)
    {
        LCD_ClearDisplay();
        LCD_Position(0,1);
        if(security_active)
        {
            LCD_PrintString("Alarm disabled");
            security_active = false;
        }
        else if(!security_active)
        {
            LCD_PrintString("Alarm enabled");
            security_active = true;
        }
        
    }
    else 
    {
        LCD_ClearDisplay();
        LCD_Position(0,1);
        LCD_PrintString("Wrong password");
    }
    memset(a,'\0',strlen(a));
    i = 0;
    LCD_Position(1,0);
}

/* [] END OF FILE */
