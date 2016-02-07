/*******************************************************************************
* File Name: Timer_Red_PM.c
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

#include "Timer_Red.h"

static Timer_Red_backupStruct Timer_Red_backup;


/*******************************************************************************
* Function Name: Timer_Red_SaveConfig
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
*  Timer_Red_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Red_SaveConfig(void) 
{
    #if (!Timer_Red_UsingFixedFunction)
        Timer_Red_backup.TimerUdb = Timer_Red_ReadCounter();
        Timer_Red_backup.InterruptMaskValue = Timer_Red_STATUS_MASK;
        #if (Timer_Red_UsingHWCaptureCounter)
            Timer_Red_backup.TimerCaptureCounter = Timer_Red_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Red_UDB_CONTROL_REG_REMOVED)
            Timer_Red_backup.TimerControlRegister = Timer_Red_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Red_RestoreConfig
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
*  Timer_Red_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Red_RestoreConfig(void) 
{   
    #if (!Timer_Red_UsingFixedFunction)

        Timer_Red_WriteCounter(Timer_Red_backup.TimerUdb);
        Timer_Red_STATUS_MASK =Timer_Red_backup.InterruptMaskValue;
        #if (Timer_Red_UsingHWCaptureCounter)
            Timer_Red_SetCaptureCount(Timer_Red_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Red_UDB_CONTROL_REG_REMOVED)
            Timer_Red_WriteControlRegister(Timer_Red_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Red_Sleep
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
*  Timer_Red_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Red_Sleep(void) 
{
    #if(!Timer_Red_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Red_CTRL_ENABLE == (Timer_Red_CONTROL & Timer_Red_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Red_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Red_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Red_Stop();
    Timer_Red_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Red_Wakeup
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
*  Timer_Red_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Red_Wakeup(void) 
{
    Timer_Red_RestoreConfig();
    #if(!Timer_Red_UDB_CONTROL_REG_REMOVED)
        if(Timer_Red_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Red_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
