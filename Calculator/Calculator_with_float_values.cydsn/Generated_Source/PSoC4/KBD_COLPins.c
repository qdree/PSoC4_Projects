/*******************************************************************************
* File Name: KBD_COLPins.c  
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
#include "KBD_COLPins.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        KBD_COLPins_PC =   (KBD_COLPins_PC & \
                                (uint32)(~(uint32)(KBD_COLPins_DRIVE_MODE_IND_MASK << (KBD_COLPins_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (KBD_COLPins_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: KBD_COLPins_Write
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
void KBD_COLPins_Write(uint8 value) 
{
    uint8 drVal = (uint8)(KBD_COLPins_DR & (uint8)(~KBD_COLPins_MASK));
    drVal = (drVal | ((uint8)(value << KBD_COLPins_SHIFT) & KBD_COLPins_MASK));
    KBD_COLPins_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: KBD_COLPins_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  KBD_COLPins_DM_STRONG     Strong Drive 
*  KBD_COLPins_DM_OD_HI      Open Drain, Drives High 
*  KBD_COLPins_DM_OD_LO      Open Drain, Drives Low 
*  KBD_COLPins_DM_RES_UP     Resistive Pull Up 
*  KBD_COLPins_DM_RES_DWN    Resistive Pull Down 
*  KBD_COLPins_DM_RES_UPDWN  Resistive Pull Up/Down 
*  KBD_COLPins_DM_DIG_HIZ    High Impedance Digital 
*  KBD_COLPins_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void KBD_COLPins_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(KBD_COLPins__0__SHIFT, mode);
	SetP4PinDriveMode(KBD_COLPins__1__SHIFT, mode);
	SetP4PinDriveMode(KBD_COLPins__2__SHIFT, mode);
	SetP4PinDriveMode(KBD_COLPins__3__SHIFT, mode);
}


/*******************************************************************************
* Function Name: KBD_COLPins_Read
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
*  Macro KBD_COLPins_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 KBD_COLPins_Read(void) 
{
    return (uint8)((KBD_COLPins_PS & KBD_COLPins_MASK) >> KBD_COLPins_SHIFT);
}


/*******************************************************************************
* Function Name: KBD_COLPins_ReadDataReg
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
uint8 KBD_COLPins_ReadDataReg(void) 
{
    return (uint8)((KBD_COLPins_DR & KBD_COLPins_MASK) >> KBD_COLPins_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(KBD_COLPins_INTSTAT) 

    /*******************************************************************************
    * Function Name: KBD_COLPins_ClearInterrupt
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
    uint8 KBD_COLPins_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(KBD_COLPins_INTSTAT & KBD_COLPins_MASK);
		KBD_COLPins_INTSTAT = maskedStatus;
        return maskedStatus >> KBD_COLPins_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
