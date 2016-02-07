/*******************************************************************************
* File Name: Switch_Pin.c  
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
#include "Switch_Pin.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Switch_Pin_PC =   (Switch_Pin_PC & \
                                (uint32)(~(uint32)(Switch_Pin_DRIVE_MODE_IND_MASK << (Switch_Pin_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Switch_Pin_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Switch_Pin_Write
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
void Switch_Pin_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Switch_Pin_DR & (uint8)(~Switch_Pin_MASK));
    drVal = (drVal | ((uint8)(value << Switch_Pin_SHIFT) & Switch_Pin_MASK));
    Switch_Pin_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Switch_Pin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Switch_Pin_DM_STRONG     Strong Drive 
*  Switch_Pin_DM_OD_HI      Open Drain, Drives High 
*  Switch_Pin_DM_OD_LO      Open Drain, Drives Low 
*  Switch_Pin_DM_RES_UP     Resistive Pull Up 
*  Switch_Pin_DM_RES_DWN    Resistive Pull Down 
*  Switch_Pin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Switch_Pin_DM_DIG_HIZ    High Impedance Digital 
*  Switch_Pin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Switch_Pin_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Switch_Pin__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Switch_Pin_Read
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
*  Macro Switch_Pin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Switch_Pin_Read(void) 
{
    return (uint8)((Switch_Pin_PS & Switch_Pin_MASK) >> Switch_Pin_SHIFT);
}


/*******************************************************************************
* Function Name: Switch_Pin_ReadDataReg
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
uint8 Switch_Pin_ReadDataReg(void) 
{
    return (uint8)((Switch_Pin_DR & Switch_Pin_MASK) >> Switch_Pin_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Switch_Pin_INTSTAT) 

    /*******************************************************************************
    * Function Name: Switch_Pin_ClearInterrupt
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
    uint8 Switch_Pin_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Switch_Pin_INTSTAT & Switch_Pin_MASK);
		Switch_Pin_INTSTAT = maskedStatus;
        return maskedStatus >> Switch_Pin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
