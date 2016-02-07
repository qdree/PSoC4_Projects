/*******************************************************************************
* File Name: Clear_Button.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Clear_Button.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Clear_Button_PC =   (Clear_Button_PC & \
                                (uint32)(~(uint32)(Clear_Button_DRIVE_MODE_IND_MASK << (Clear_Button_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Clear_Button_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Clear_Button_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Clear_Button_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Clear_Button_DR & (uint8)(~Clear_Button_MASK));
    drVal = (drVal | ((uint8)(value << Clear_Button_SHIFT) & Clear_Button_MASK));
    Clear_Button_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Clear_Button_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Clear_Button_DM_STRONG     Strong Drive 
*  Clear_Button_DM_OD_HI      Open Drain, Drives High 
*  Clear_Button_DM_OD_LO      Open Drain, Drives Low 
*  Clear_Button_DM_RES_UP     Resistive Pull Up 
*  Clear_Button_DM_RES_DWN    Resistive Pull Down 
*  Clear_Button_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Clear_Button_DM_DIG_HIZ    High Impedance Digital 
*  Clear_Button_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Clear_Button_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Clear_Button__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Clear_Button_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Clear_Button_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Clear_Button_Read(void) 
{
    return (uint8)((Clear_Button_PS & Clear_Button_MASK) >> Clear_Button_SHIFT);
}


/*******************************************************************************
* Function Name: Clear_Button_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Clear_Button_ReadDataReg(void) 
{
    return (uint8)((Clear_Button_DR & Clear_Button_MASK) >> Clear_Button_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Clear_Button_INTSTAT) 

    /*******************************************************************************
    * Function Name: Clear_Button_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Clear_Button_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Clear_Button_INTSTAT & Clear_Button_MASK);
		Clear_Button_INTSTAT = maskedStatus;
        return maskedStatus >> Clear_Button_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
