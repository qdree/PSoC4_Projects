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
uint32 a_count = 0;    //alarm interrupt counter in 0.01 miliseconds
uint32 b_count = 0;    //

char pass_arr[18];    //array where to collect entered password
const char* ref_pass = "1111";    //password reference string
uint8 i = 0;    //index of element stored in password array

char id_arr[14];    //array where to collect key id
const char *ref_id =  "09008B316BD8";    //key id reference string
uint j = 0;    //index of element stored in key id array


bool security_active = false;    //state of system
bool is_box_opened = false;   //box with keypad is closed
bool motion_inhall = false;    //motion in hall
bool triggered = false;


typedef enum MotionDetected
{
    NotDetected,
    FrontDoor,
    BackDoor,
    Hall,
    BedRoom,
    GuestRoom,
    Kitchen
} DetectedStatus;

DetectedStatus detected_status = NotDetected;


DetectedStatus motion_detection();
bool password();
bool check_password(const char* a, const char* b);
bool key_id();

void discard(char a[]);
void input_char(const char el);
void beep();
void error();
void confirmed();

bool alarm();
void alarm_hall();
CY_ISR(alarm_countdown);

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
//    Alarm_Timer_Sleep();
    
    LED_GREEN_Write(0);
    LED_RED_Write(1);
    Buzzer_Write(1);
    

    
    setCursor(0,0);
    LCD_print("Adjustment...");   
    CyDelay(6000);
    clear();
    
    setCursor(0,0);
    LCD_print("Not observing");   
    setCursor(0,1);
    
    for(;;)
    {
        if(security_active)
        {
            if (motion_detection())
            {
                if(key_id())
                {
                    if(password())
                    {
                        security_active = false;
                        detected_status = NotDetected;
                        
                        LED_GREEN_Write(0);
                        LED_RED_Write(1);
                        Buzzer_Write(1);
                        
                        clear();
                        setCursor(0,0);
                        LCD_print("Not observing");
                        setCursor(0,1);
                    }
                }
            }
            else if(key_id())
            {
                if(password())
                {
                    security_active = false;
                    detected_status = NotDetected;
                    
                    LED_GREEN_Write(0);
                    LED_RED_Write(1);
                    Buzzer_Write(1);
                    
                    clear();
                    setCursor(0,0);
                    LCD_print("Not observing");
                    setCursor(0,1);
                }
            }
        }
        else if(password()) 
        {
            security_active = true;
            is_box_opened = false;
            detected_status = NotDetected;
            
            LED_GREEN_Write(0);
            LED_RED_Write(1);
            
            clear();
            setCursor(0,0);
            LCD_print("Observing");
            setCursor(0,1);
        }
    }
}

void detected(DetectedStatus status, const char *str)
{
    //Alarm_Timer_Wakeup();
    detected_status = status;

    clear();
    setCursor(0,0);
    LCD_print("Motion triggered");
    setCursor(0,1);
    LCD_print(str);
    
    LED_GREEN_Write(1);
    LED_RED_Write(0);
    
//    if (detected_status != NotDetected && detected_status != Hall) 
    //alarm();
}

bool key_id()
{
    if (!is_box_opened/* && detected_status != NotDetected*/)
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
                        if(detected_status == NotDetected)confirmed();
                        
                        is_box_opened = true;
                        
                        CyDelay(500);
                        clear();
                        LCD_print("Input password:");  
                        setCursor(0,1);
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
//        else
//        {
//            LED_GREEN_Write(1);
//            LED_RED_Write(1);
//        }
    }
    
    return is_box_opened;
}

void input_char(const char el)
{   
    if(detected_status == NotDetected) beep();
    write(el);
    pass_arr[i++] = el;
}

void discard(char a[])
{
    if(detected_status == NotDetected) beep();
    memset(a, 0x00, strlen(a));    
    
    i = 0;
    int d;
    //clear();
    setCursor(0,1);
    for(d = 0; d <= 15; d++) write(' ');
    setCursor(0,1);
}

bool check_password(const char* a,const char* b)
{
    bool result = false;
    if(strcmp(a, b) == 0)
    {
        confirmed();
        clear();
        setCursor(0,0);
        result = true;
    }
    else 
    {
        error();
        clear();
        setCursor(0,0);
        LCD_print("Wrong password");
        setCursor(0,1);
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
        if(Front_door_Read()== 1) detected(FrontDoor, "Frontdoor opened");
        else if(Back_door_Read()== 1) detected(BackDoor, "Backdoor opened");
        else if(Hall_PIR_Read()== 1) detected(Hall, "Hall");
        else if(Bedroom_PIR_Read()== 1) detected(BedRoom, "Bedroom");
        else if(Guestroom_PIR_Read()== 1) detected(GuestRoom, "GuestRoom");
        else if(Kitchen_PIR_Read()== 1) detected(Kitchen, "Kitchen");
        
    }
     
    return detected_status;
}

bool alarm()
{
    if(detected_status != NotDetected)
    {
        triggered = true; 
        if(++a_count == 50000)
        {
            Buzzer_Write(!Buzzer_Read());
            a_count = 0;
        }
    }
    return triggered;
}

CY_ISR(alarm_countdown)
{
    if(alarm())
    {
        if(++b_count == 500000)
        {
            triggered = false;
            detected_status = NotDetected;
            Buzzer_Write(1);
            clear();
            setCursor(0,0);
            if(!security_active) LCD_print("Not observing");
            else LCD_print("Observing");
            setCursor(0,1);
            b_count = 0;
        }
        
    }
}

void beep()
{
    Buzzer_Write(0);
    CyDelay(50);
    Buzzer_Write(1);
}

void confirmed()
{
    Buzzer_Write(0);
    CyDelay(100);
    Buzzer_Write(1);
    CyDelay(100);
    Buzzer_Write(0);
    CyDelay(100);
    Buzzer_Write(1);
}

void error()
{
    Buzzer_Write(0);
    CyDelay(50);
    Buzzer_Write(1);
    CyDelay(100);
    Buzzer_Write(0);
    CyDelay(300);
    Buzzer_Write(1);
}

//void alarm_hall()
//{
//    if(++a_count == 300000)
//    {
//        Buzzer_Write(0);
//        CyDelay(500);
//        Buzzer_Write(1);
//        a_count = 0;
//    }
//}
/* [] END OF FILE */
