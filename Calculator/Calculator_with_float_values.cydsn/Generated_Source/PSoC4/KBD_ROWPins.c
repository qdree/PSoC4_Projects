/*******************************************************************************
* File Name: KBD_ROWPins.c  
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
#include "KBD_ROWPins.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        KBD_ROWPins_PC =   (KBD_ROWPins_PC & \
                                (uint32)(~(uint32)(KBD_ROWPins_DRIVE_MODE_IND_MASK << (KBD_ROWPins_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (KBD_ROWPins_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: KBD_ROWPins_Write
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
void KBD_ROWPins_Write(uint8 value) 
{
    uint8 drVal = (uint8)(KBD_ROWPins_DR & (uint8)(~KBD_ROWPins_MASK));
    drVal = (drVal | ((uint8)(value << KBD_ROWPins_SHIFT) & KBD_ROWPins_MASK));
    KBD_ROWPins_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: KBD_ROWPins_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  KBD_ROWPins_DM_STRONG     Strong Drive 
*  KBD_ROWPins_DM_OD_HI      Open Drain, Drives High 
*  KBD_ROWPins_DM_OD_LO      Open Drain, Drives Low 
*  KBD_ROWPins_DM_RES_UP     Resistive Pull Up 
*  KBD_ROWPins_DM_RES_DWN    Resistive Pull Down 
*  KBD_ROWPins_DM_RES_UPDWN  Resistive Pull Up/Down 
*  KBD_ROWPins_DM_DIG_HIZ    High Impedance Digital 
*  KBD_ROWPins_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void KBD_ROWPins_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(KBD_ROWPins__0__SHIFT, mode);
	SetP4PinDriveMode(KBD_ROWPins__1__SHIFT, mode);
	SetP4PinDriveMode(KBD_ROWPins__2__SHIFT, mode);
	SetP4PinDriveMode(KBD_ROWPins__3__SHIFT, mode);
}


/*******************************************************************************
* Function Name: KBD_ROWPins_Read
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
*  Macro KBD_ROWPins_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 KBD_ROWPins_Read(void) 
{
    return (uint8)((KBD_ROWPins_PS & KBD_ROWPins_MASK) >> KBD_ROWPins_SHIFT);
}


/*******************************************************************************
* Function Name: KBD_ROWPins_ReadDataReg
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
uint8 KBD_ROWPins_ReadDataReg(void) 
{
    return (uint8)((KBD_ROWPins_DR & KBD_ROWPins_MASK) >> KBD_ROWPins_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(KBD_ROWPins_INTSTAT) 

    /*******************************************************************************
    * Function Name: KBD_ROWPins_ClearInterrupt
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
    uint8 KBD_ROWPins_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(KBD_ROWPins_INTSTAT & KBD_ROWPins_MASK);
		KBD_ROWPins_INTSTAT = maskedStatus;
        return maskedStatus >> KBD_ROWPins_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
