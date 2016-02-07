/*******************************************************************************
* File Name: Timer_Green_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_Green.h"

static Timer_Green_backupStruct Timer_Green_backup;


/*******************************************************************************
* Function Name: Timer_Green_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Green_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Green_SaveConfig(void) 
{
    #if (!Timer_Green_UsingFixedFunction)
        Timer_Green_backup.TimerUdb = Timer_Green_ReadCounter();
        Timer_Green_backup.InterruptMaskValue = Timer_Green_STATUS_MASK;
        #if (Timer_Green_UsingHWCaptureCounter)
            Timer_Green_backup.TimerCaptureCounter = Timer_Green_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Green_UDB_CONTROL_REG_REMOVED)
            Timer_Green_backup.TimerControlRegister = Timer_Green_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Green_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Green_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Green_RestoreConfig(void) 
{   
    #if (!Timer_Green_UsingFixedFunction)

        Timer_Green_WriteCounter(Timer_Green_backup.TimerUdb);
        Timer_Green_STATUS_MASK =Timer_Green_backup.InterruptMaskValue;
        #if (Timer_Green_UsingHWCaptureCounter)
            Timer_Green_SetCaptureCount(Timer_Green_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Green_UDB_CONTROL_REG_REMOVED)
            Timer_Green_WriteControlRegister(Timer_Green_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Green_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Green_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Green_Sleep(void) 
{
    #if(!Timer_Green_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Green_CTRL_ENABLE == (Timer_Green_CONTROL & Timer_Green_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Green_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Green_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Green_Stop();
    Timer_Green_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Green_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Green_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Green_Wakeup(void) 
{
    Timer_Green_RestoreConfig();
    #if(!Timer_Green_UDB_CONTROL_REG_REMOVED)
        if(Timer_Green_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Green_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
