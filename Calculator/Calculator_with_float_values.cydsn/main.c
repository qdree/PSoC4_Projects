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
#include <device.h>
#include <Keyboard.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define LCD_LINELENGTH 16

typedef enum Operation
{
    Operator_None      = 0,
    Operator_Plus      = '+',
    Operator_Minus     = '-',
    Operator_Multiply  = '*',
    Operator_Division  = '/'
} Operation;

Operation mode = Operator_None;

void input_number(const char num);
void set_operation(const char* op, Operation m);

void init();
void print_result(double result);

bool is_pressed_equal = true;
bool is_first = false;
uint8 Key;
uint8 firstOperand  = 0;
uint8 secondOperand = 0;
uint8 LCD_Index = 0;

char buffer[32];
char value1[16];
char value2[16];
uint8 i = 0;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
    Keyboard_Init();   
    
    init();
      
    for(;;)
    {
        
        Key = Get_KBD_Char();		//Value recieved from Matrix      
        switch(Key)
        {             
            case '+':
                set_operation("+", Operator_Plus);
                break;
                
            case '-':
                set_operation("-", Operator_Minus);
                break;
                
            case '*':
                set_operation("*", Operator_Multiply);
                break;
                
            case '/':
                set_operation("/", Operator_Division);
                break;
                
            case '=':
                LCD_Position(1,0);
                LCD_PrintString("=");
                if (mode == Operator_Plus) 
                    print_result(atof(value1) + atof(value2));
                else if (mode == Operator_Minus)
                    print_result(atof(value1) - atof(value2));
                else if (mode == Operator_Multiply)
                    print_result(atof(value1) * atof(value2));
                else if (mode == Operator_Division)
                    print_result(atof(value1) / atof(value2));
                else 
                {
                    init();
                    LCD_Position(0,5);LCD_PrintString("error");
                }
                break;
           
            case '.':
                input_number('.');
                break;   
            case '1':
                input_number('1');
                break;   
            case '2':
                input_number('2');
                break;     
            case '3':
                input_number('3');
                break;     
            case '4':
                input_number('4');
                break;     
            case '5':
                input_number('5');
                break;     
            case '6':
                input_number('6');
                break;
            case '7':
                input_number('7');
                break;     
            case '8':
                input_number('8');
                break;     
            case '9':
                input_number('9');
                break;     
            case '0':
                input_number('0');
                break;   
            
            default:
                memset(buffer,0,16);
                LCD_Position(0,0);
                LCD_PrintString("INPUT SMTH");
        }
    }
}     


void init()
{
    memset(value1,0,sizeof(value1));
    memset(value2,0,sizeof(value2));
    memset(buffer,0, sizeof(buffer));
    is_first = true;
    i = 0;
    mode = Operator_None;
    LCD_ClearDisplay();
}


void set_operation(const char* op, Operation m)
{
    if(mode != Operator_None) return;
    LCD_PrintString(op);
    mode = m;
    
    is_first = !is_first;
    i = 0;
}

void input_number(const char num)
{
    	LCD_PutChar(num);
        if(is_first)
        {      
            value1[i++] = num;
        }
        else
        {
            value2[i++] = num;
        }
 
}

void print_result(double result)
{     
    sprintf( buffer, "%.2f", result);
    LCD_PrintString(buffer);
}




//int char_to_int(char char_value)
//{
//  return ((int) char_value) - 48;
//}

//void plus_operation()
//{   
//    int res = atoi(value1) + atoi(value2);    
//    itoa(res,buffer,10);
//    
//    LCD_PrintString(buffer);
//}

//
//void plus_operation(char a, char b)
//{   
//    
//    int res =  char_to_int(a) + char_to_int(b);
//    itoa(res,buffer,10);
//    LCD_PrintString(buffer);
//}
//void minus_operation(char a, char b)
//{   
//    int res =  char_to_int(a) - char_to_int(b);
//    itoa(res,buffer,10);
//    LCD_PrintString(buffer);
//}
//void mult_operation(char a, char b)
//{   
//    int res =  char_to_int(a) * char_to_int(b);
//    itoa(res,buffer,10);
//    LCD_PrintString(buffer);
//}
//
//void div_operation(char a, char b)
//{   
//    int res =  char_to_int(a) / char_to_int(b);
//    itoa(res,buffer,10);
//    LCD_PrintString(buffer);
//}