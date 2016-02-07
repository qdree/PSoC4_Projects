#include <project.h>

#define LED_ON 0
#define LED_OFF 1

uint32 red_count = 0;
uint32 ms_count = 0;

void enable_green(uint32 state);
void enable_red(uint32 state);

int is_green_enabled = 1;
int is_green_disabled = 0;




CY_ISR(MY_ISR) 
{
    ms_count++;
    if(ms_count == 1000)
    {
        if(is_green_enabled)
        {
            red_count++;
            if(red_count == 2 ) 
            {
                enable_green(0);   
                enable_red(1);
            }
        }
        else
        {
            red_count++;
            if(red_count == 5 ) 
            {
                enable_green(1);   
                enable_red(0);
            }
        }
        ms_count = 0;
    }

}
CY_ISR(ISR_SW)
{       
        Green_LED_Write(LED_ON);
        Red_LED_Write(LED_OFF);
        isr_1_StartEx(MY_ISR); 
        Timer_Green_Start();
        Pin_SW_ClearInterrupt();
}

int main()
{
    SW_Int_StartEx(ISR_SW);    
    CyGlobalIntEnable; 
     
    for(;;);
}
 
void enable_red(uint32 state)
{
    red_count = 0;
    Red_LED_Write(state ? LED_ON : LED_OFF);        
}

void enable_green(uint32 state)
{
    Green_LED_Write(state ? LED_ON : LED_OFF);
    is_green_enabled = state;
}