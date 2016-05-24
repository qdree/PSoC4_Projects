/*******************************************************************************
* File Name: Debounce_Timer_PM.c
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

#include "Debounce_Timer.h"

static Debounce_Timer_backupStruct Debounce_Timer_backup;


/*******************************************************************************
* Function Name: Debounce_Timer_SaveConfig
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
*  Debounce_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Debounce_Timer_SaveConfig(void) 
{
    #if (!Debounce_Timer_UsingFixedFunction)
        Debounce_Timer_backup.TimerUdb = Debounce_Timer_ReadCounter();
        Debounce_Timer_backup.InterruptMaskValue = Debounce_Timer_STATUS_MASK;
        #if (Debounce_Timer_UsingHWCaptureCounter)
            Debounce_Timer_backup.TimerCaptureCounter = Debounce_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Debounce_Timer_UDB_CONTROL_REG_REMOVED)
            Debounce_Timer_backup.TimerControlRegister = Debounce_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Debounce_Timer_RestoreConfig
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
*  Debounce_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Debounce_Timer_RestoreConfig(void) 
{   
    #if (!Debounce_Timer_UsingFixedFunction)

        Debounce_Timer_WriteCounter(Debounce_Timer_backup.TimerUdb);
        Debounce_Timer_STATUS_MASK =Debounce_Timer_backup.InterruptMaskValue;
        #if (Debounce_Timer_UsingHWCaptureCounter)
            Debounce_Timer_SetCaptureCount(Debounce_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Debounce_Timer_UDB_CONTROL_REG_REMOVED)
            Debounce_Timer_WriteControlRegister(Debounce_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Debounce_Timer_Sleep
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
*  Debounce_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Debounce_Timer_Sleep(void) 
{
    #if(!Debounce_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Debounce_Timer_CTRL_ENABLE == (Debounce_Timer_CONTROL & Debounce_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Debounce_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Debounce_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Debounce_Timer_Stop();
    Debounce_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Debounce_Timer_Wakeup
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
*  Debounce_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Debounce_Timer_Wakeup(void) 
{
    Debounce_Timer_RestoreConfig();
    #if(!Debounce_Timer_UDB_CONTROL_REG_REMOVED)
        if(Debounce_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Debounce_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
