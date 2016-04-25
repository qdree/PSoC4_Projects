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
#include <WinDows.h>

int main()
{
    SYSTEMTIME stime;   //structure to store system time (in usual time format)
    FILETIME ltime;     //structure to store local time (local time in 64 bits)
    FILETIME ftTimeStamp;
    char TimeStamp[256];//to store TimeStamp information
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
   

    for(;;)
    {   
        while (true){
        ////Prepare data needed to output the time stamp:
        GetSystemTimeAsFileTime(&ftTimeStamp); // Gets the current system time
        FileTimeToLocalFileTime (&ftTimeStamp,&ltime);//convert in local time and store in ltime
        FileTimeToSystemTime(&ltime,&stime);//convert in system time and store in stime

        sprintf(TimeStamp, "%d:%d:%d, %d.%d.%d \r",stime.wHour,stime.wMinute,stime.wSecond, stime.wDay,stime.wMonth,stime.wYear);
        
        LCD_Position(0,0);
        LCD_PrintString(TimeStamp);
        LCD_Position(1,0);
        LCD_PrintString("System:");
        LCD_Position(1,8);
        LCD_PrintString("inactive");
    }
}

/* [] END OF FILE */
