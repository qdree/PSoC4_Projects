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
#include <stdlib.h>


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


bool security_active = false;    //state of system
bool is_box_opened = false;   //box with keypad is closed
bool motion_inhall = false;    //motion in hall

typedef enum MotionDetected
{
    NotDetected,
    Hall,
    BedRoom,
    GuestRoom,
    Kitchen
} DetectedStatus;

DetectedStatus detected_status = NotDetected;

void alarm_countdown();
DetectedStatus motion_detection();
bool password();
bool check_password(const char* a, const char* b);
bool key_id();

void discard(char a[]);
void input_char(const char el);

void alarm();
void alarm_hall();

int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_Start();
    I2C_Start();
    Keyboard_Init();
    LiquidCrystal_I2C_init(Addr,16,2,0);
    begin();
    
    Alarm_Timer_Start();
    Alarm_Int_StartEx(alarm_countdown);
    
    LED_GREEN_Write(0);
    LED_RED_Write(0);
    Buzzer_Write(1);

    clear();
    setCursor(0,1);
    LCD_print("Adjustment...");   
    
    CyDelay(10000);
    setCursor(0,1);
    LCD_print("Not observing");   
    CyDelay(2000);
    
    clear();
    
      
    for(;;)
    {
        if(security_active)
        {
            if (motion_detection())
            {
                if (key_id())
                {
                    //clear
                   //...
                    if (password())
                    {
                        security_active = false;
                                              
                        LED_GREEN_Write(0);
                        LED_RED_Write(1);
                        Buzzer_Write(1);
                        
                        clear();
                        LCD_print("Not observing");
                        setCursor(0,1);
                    }
                }
                else
                {
                    // wrong key
                }
            }
        }
        else if(password()) 
        {
            security_active = true;
            
            is_box_opened = false;
            motion_inhall = false;
            
            detected_status = NotDetected;
            
            LED_GREEN_Write(0);
            LED_RED_Write(0);
                       
            clear();
            LCD_print("Observing");
            setCursor(0,1);
        }
    }
}

void detected(DetectedStatus status, const char *str)
{
    detected_status = status;
    
    clear();
    setCursor(0,0);
    LCD_print("Motion triggered");
    setCursor(0,1);
    LCD_print(str);
    
    LED_GREEN_Write(1);
    LED_RED_Write(0);
    
    //clear();
    
    if (detected_status == Hall) alarm_hall();
    else alarm();    
}

void alarm_hall()
{
    Buzzer_Write(0);
    CyDelay(500);
    Buzzer_Write(1);
    CyDelay(3000);
}

void alarm()
{
    Buzzer_Write(!Buzzer_Read());
    CyDelay(200);
}

//void alarm_countdown()
//{
//    if(motion_inhall && security_active && ++a_count == 1000000) 
//    {
//        is_box_opened = true;
//        a_count = 0;
//        
//        alarm(Hall, "Hall ALARM!");
//    }
//}

void alarm_countdown()
{
    if(detected_status == Hall && security_active && ++a_count == 1000000) 
    {
        //is_box_opened = false;
        a_count = 0;        
        alarm();
    }
}

bool key_id()
{
    if (detected_status != NotDetected && !is_box_opened)
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
                        
                        is_box_opened = true;
                        
                        CyDelay(2000);
                        clear();
                    }
                    else
                    {
                        clear();
                        setCursor(0,0);
                        LCD_print("Wrong key");
                        setCursor(0,1);
                        LCD_print("ID: ");
                        LCD_print(id_arr);
                    }
                    j = 0;
                    break;
                default:
                    id_arr[j++] = ch; 
                    
            }
        }
        else
        {
            LED_GREEN_Write(1);
            LED_RED_Write(1);
            Buzzer_Write(0);
        }
    }
    
    return is_box_opened;
}

void input_char(const char el)
{    
    write(el);
    pass_arr[i++] = el;
}

void discard(char a[])
{
    //memset(a,'\0',strlen(a));
    memset(a, 0x00, strlen(a));    
    
    i = 0;
    clear();
    setCursor(0,1);
}

bool check_password(const char* a,const char* b)
{
    bool result = false;
    if(strcmp(a, b) == 0)
    {
        clear();
        setCursor(0,0);
        result = true;
    }
    else 
    {
        clear();
        setCursor(0,0);
        LCD_print("Wrong password");
    }
    
    //memset(a,'\0',strlen(a));
    memset(a, 0x00, strlen(a));    
    i = 0;
    setCursor(0,1);
    
    return result;        
}

bool password()
{
    bool is_correct_password = false;
    
    Key = Get_KBD_Char();		//Value recieved from Matrix
    switch(Key)             //Recognition of pressed key
    {              
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
            
        case '*':
            is_correct_password = check_password(pass_arr, ref_pass);
            break;
            
        default:
            memset(pass_arr,'\0', strlen(pass_arr));
            write(' ');
            break;
    }
    
    return is_correct_password;
}

DetectedStatus motion_detection()
{
    if (detected_status == NotDetected)
    {
        if(Hall_PIR_Read()==1) detected(Hall, "Hall");
        else if(Bedroom_PIR_Read()==1) detected(BedRoom, "Bedroom");
//        else if(Guestroom_PIR_Read()==1) detected(GuestRoom, "GuestRoom");
//        else if(Kitchen_PIR_Read()==1) detected(Kitchen, "Kitchen");
    }
    
    return detected_status;
}

//void motion_detection()
//{
//    if(security_active == true)
//    {
//        if(Hall_PIR_Read()==1)
//        {
//            clear();
//            setCursor(0,0);
//            motion_inhall = true;
//            LCD_print("Door opened!");
//            LED_GREEN_Write(1);
//            LED_RED_Write(0);
//            Buzzer_Write(0);
//            CyDelay(500);
//            write(a_count/100000);
//            Buzzer_Write(1);
//            CyDelay(3000);
//        }
//        else if(Bedroom_PIR_Read()==1)
//        {
//            alarm("Bedroom alarm!");
//        }
//        else if(Guestroom_PIR_Read()==1)
//        {
//            alarm("Guestroom alarm!");
//        }
//        else if(Kitchen_PIR_Read()==1)
//        {
//            alarm("Kitchen alarm!");
//        }
//    }
//    else if ( Hall_PIR_Read() == 1 || 
//              Bedroom_PIR_Read() == 1 || 
//              Guestroom_PIR_Read() == 1 || 
//              Kitchen_PIR_Read() == 1 )
//    {
//        motion_detected = false;
//        LED_GREEN_Write(0);
//        LED_RED_Write(0);
//        Buzzer_Write(1);
//    }
//    else 
//    {   
//        motion_detected = false;
//        LED_GREEN_Write(1);
//        LED_RED_Write(1);
//        Buzzer_Write(1);
//        clear();
//    }
//    
//}

/* [] END OF FILE */
