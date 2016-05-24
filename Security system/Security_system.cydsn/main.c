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


uint32_t Addr = 0x27;    //i2c address of LCD
uint8 Key;    
uint32 ch; 
uint32 a_count = 0;    //alarm enable count in 0.01 miliseconds

char pass_arr[18];    //array where to collect entered password
const char* ref_pass = "1111";    //password reference string
uint8 i = 0;    //index of element stored in password array

char id_arr[14];    //array where to collect key id
const char *ref_id =  "09008B316BD8";    //key id reference string
uint j = 0;    //index of element stored in key id array


bool security_active = true;    //state of system
bool motion_detected = false;    //state of motion sensors(true for caught)
bool box_closed = true;   //box with keypad is closed
bool keys_locked = false;    //password input is forbidden
bool password_accepted = false;    //confirmed password
bool compared = false;    //key ids compared



CY_ISR(MY_ISR);
void motion_detection();
void password();
void input_char(const char el);
void discard(char a[]);
void accept(char a[],const char b[]);
void key_id();

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Keyboard_Init();
    LiquidCrystal_I2C_init(Addr,16,2,0);
    begin();
    Alarm_Timer_Start();
    I2C_Start();
    UART_Start();
    Alarm_Int_StartEx(MY_ISR);
    
    
    clear();
    setCursor(0,1);
    
    LED_GREEN_Write(1);
    LED_RED_Write(1);
    Buzzer_Write(1);

    for(;;)
    {
        motion_detection();
        if(security_active && motion_detected)
        {
            key_id();
            if(!box_closed)
            {
                password();
                if(password_accepted == true)
                {
                    security_active = false;
                    motion_detected = false;
                }
                
            }
        }

    }
}


CY_ISR(MY_ISR) 
{
    if(motion_detected && security_active && ++a_count == 1000000) 
    {
        box_closed = true;
        motion_detected = false;
        a_count = 0;
        clear();   
        LED_GREEN_Write(1);
        LED_RED_Write(0);
        setCursor(0,1);
        LCD_print("ALARM!");
        Buzzer_Write(0);
        //CyDelay(500);
    }
}

void key_id()
{
     if (box_closed)
        {
            ch = UART_UartGetChar();
            if(ch != 0)
            {
                switch(ch)
                {
                    case '\002':
                        memset(id_arr, 0, strlen(id_arr));
                        break;
                    case '\003':
                        if(strcmp(id_arr, ref_id) == 0)
                        {   
                            clear();
                            setCursor(0,0);
                            LCD_print("Box opened");
                            setCursor(0,1);
                            LCD_print("ID: ");
                            LCD_print(id_arr);
                            LED_GREEN_Write(0);
                            LED_RED_Write(1);
                            box_closed = false;
                        }
                        else
                        {
                            clear();
                            setCursor(0,0);
                            LCD_print("Wrong key");
                            setCursor(0,1);
                            LCD_print("ID: ");
                            LCD_print(id_arr);
                            LED_GREEN_Write(1);
                            LED_RED_Write(0);
                        }
                        j = 0;
                        compared = true;
                        break;
                    default:
                        id_arr[j++] = ch; 
                        
                }
            }
            else
            {
                LED_GREEN_Write(1);
                LED_RED_Write(1);
                Buzzer_Write(1);
            }

        }
}

void input_char(const char el)
{    
    write(el);
    pass_arr[i++] = el;
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
            password_accepted = true;
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

void password()
{
    Key = Get_KBD_Char();		//Value recieved from Matrix
        switch(Key)             //Recognition of pressed key
        {              
            case '*':
                accept(pass_arr, ref_pass);
                break;
            case '#':
                discard(pass_arr);
                break;
            case '1':
                input_char('1');
                break;
            case '2':
                input_char('2');
                break;
            case '3':
                input_char('3');
                break;
            case '4':
                input_char('4');
                break;
            case '5':
                input_char('5');
                break;
            case '6':
                input_char('6');
                break;
            case '7':
                input_char('7');
                break;
            case '8':
                input_char('8');
                break;
            case '9':
                input_char('9');
                break;
            case '0':
                input_char('0');
                break;

            default:
                memset(pass_arr,'\0', strlen(pass_arr));
                write(' ');
                break;
        }
}

void motion_detection()
{
    if(security_active)
    {
        if(PIR_1_Read()==1)
        {
            clear();
            setCursor(0,0);
            motion_detected = true;
            LCD_print("Guestroom ALARM!");
            LED_GREEN_Write(1);
            LED_RED_Write(0);
            Buzzer_Write(!Buzzer_Read());
            CyDelay(200);
        }
        else if(PIR_2_Read()==1)
        {
            clear();
            setCursor(0,0);
            motion_detected = true;
            LCD_print("Bedroom ALARM!");
            LED_GREEN_Write(1);
            LED_RED_Write(0);
            Buzzer_Write(!Buzzer_Read());
            CyDelay(200);
        }
//        else if(PIR_3_Read()==1)
//        {
//            clear();
//            setCursor(0,0);
//            motion_detected = true;
//            LCD_print("Hall ALARM!");
////            LED_GREEN_Write(1);
////            LED_RED_Write(0);
////            Buzzer_Write(!Buzzer_Read());
////            CyDelay(200);
//        }
//        else if(PIR_4_Read()==1)
//        {
//            clear();
//            setCursor(0,0);
//            motion_detected = true;
//            LCD_print("Kitchen ALARM!");
////            LED_GREEN_Write(1);
////            LED_RED_Write(0);
////            Buzzer_Write(!Buzzer_Read());
////            CyDelay(200);
//        }
    }
    else if(security_active && ((PIR_1_Read()==0) || (PIR_2_Read()==0) || (PIR_3_Read()==0) || (PIR_4_Read()==0)))
    {
        clear();
        setCursor(1,0);
        motion_detected = false;
        LCD_print("NO MOTION");
        LED_GREEN_Write(0);
        LED_RED_Write(1);
        Buzzer_Write(1);
        CyDelay(200);
    }
    else 
    {   
        motion_detected = false;
        LED_GREEN_Write(0);
        LED_RED_Write(1);
    }
    
}

/* [] END OF FILE */
