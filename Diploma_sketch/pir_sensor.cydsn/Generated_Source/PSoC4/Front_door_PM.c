/*******************************************************************************
* File Name: Front_door.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Front_door.h"

static Front_door_BACKUP_STRUCT  Front_door_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Front_door_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Front_door_SUT.c usage_Front_door_Sleep_Wakeup
*******************************************************************************/
void Front_door_Sleep(void)
{
    #if defined(Front_door__PC)
        Front_door_backup.pcState = Front_door_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Front_door_backup.usbState = Front_door_CR1_REG;
            Front_door_USB_POWER_REG |= Front_door_USBIO_ENTER_SLEEP;
            Front_door_CR1_REG &= Front_door_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Front_door__SIO)
        Front_door_backup.sioState = Front_door_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Front_door_SIO_REG &= (uint32)(~Front_door_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Front_door_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Front_door_Sleep() for an example usage.
*******************************************************************************/
void Front_door_Wakeup(void)
{
    #if defined(Front_door__PC)
        Front_door_PC = Front_door_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Front_door_USB_POWER_REG &= Front_door_USBIO_EXIT_SLEEP_PH1;
            Front_door_CR1_REG = Front_door_backup.usbState;
            Front_door_USB_POWER_REG &= Front_door_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Front_door__SIO)
        Front_door_SIO_REG = Front_door_backup.sioState;
    #endif
}


/* [] END OF FILE */
