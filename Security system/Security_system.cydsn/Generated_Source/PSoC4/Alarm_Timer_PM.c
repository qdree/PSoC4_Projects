/*******************************************************************************
* File Name: Alarm_Timer_PM.c
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

#include "Alarm_Timer.h"

static Alarm_Timer_backupStruct Alarm_Timer_backup;


/*******************************************************************************
* Function Name: Alarm_Timer_SaveConfig
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
*  Alarm_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Alarm_Timer_SaveConfig(void) 
{
    #if (!Alarm_Timer_UsingFixedFunction)
        Alarm_Timer_backup.TimerUdb = Alarm_Timer_ReadCounter();
        Alarm_Timer_backup.InterruptMaskValue = Alarm_Timer_STATUS_MASK;
        #if (Alarm_Timer_UsingHWCaptureCounter)
            Alarm_Timer_backup.TimerCaptureCounter = Alarm_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Alarm_Timer_UDB_CONTROL_REG_REMOVED)
            Alarm_Timer_backup.TimerControlRegister = Alarm_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Alarm_Timer_RestoreConfig
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
*  Alarm_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Alarm_Timer_RestoreConfig(void) 
{   
    #if (!Alarm_Timer_UsingFixedFunction)

        Alarm_Timer_WriteCounter(Alarm_Timer_backup.TimerUdb);
        Alarm_Timer_STATUS_MASK =Alarm_Timer_backup.InterruptMaskValue;
        #if (Alarm_Timer_UsingHWCaptureCounter)
            Alarm_Timer_SetCaptureCount(Alarm_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Alarm_Timer_UDB_CONTROL_REG_REMOVED)
            Alarm_Timer_WriteControlRegister(Alarm_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Alarm_Timer_Sleep
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
*  Alarm_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Alarm_Timer_Sleep(void) 
{
    #if(!Alarm_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Alarm_Timer_CTRL_ENABLE == (Alarm_Timer_CONTROL & Alarm_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Alarm_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Alarm_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Alarm_Timer_Stop();
    Alarm_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Alarm_Timer_Wakeup
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
*  Alarm_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Alarm_Timer_Wakeup(void) 
{
    Alarm_Timer_RestoreConfig();
    #if(!Alarm_Timer_UDB_CONTROL_REG_REMOVED)
        if(Alarm_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Alarm_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
