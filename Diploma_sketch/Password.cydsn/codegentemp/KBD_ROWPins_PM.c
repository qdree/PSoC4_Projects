/*******************************************************************************
* File Name: KBD_ROWPins.c  
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
#include "KBD_ROWPins.h"

static KBD_ROWPins_BACKUP_STRUCT  KBD_ROWPins_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: KBD_ROWPins_Sleep
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
*  \snippet KBD_ROWPins_SUT.c usage_KBD_ROWPins_Sleep_Wakeup
*******************************************************************************/
void KBD_ROWPins_Sleep(void)
{
    #if defined(KBD_ROWPins__PC)
        KBD_ROWPins_backup.pcState = KBD_ROWPins_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            KBD_ROWPins_backup.usbState = KBD_ROWPins_CR1_REG;
            KBD_ROWPins_USB_POWER_REG |= KBD_ROWPins_USBIO_ENTER_SLEEP;
            KBD_ROWPins_CR1_REG &= KBD_ROWPins_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(KBD_ROWPins__SIO)
        KBD_ROWPins_backup.sioState = KBD_ROWPins_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        KBD_ROWPins_SIO_REG &= (uint32)(~KBD_ROWPins_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: KBD_ROWPins_Wakeup
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
*  Refer to KBD_ROWPins_Sleep() for an example usage.
*******************************************************************************/
void KBD_ROWPins_Wakeup(void)
{
    #if defined(KBD_ROWPins__PC)
        KBD_ROWPins_PC = KBD_ROWPins_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            KBD_ROWPins_USB_POWER_REG &= KBD_ROWPins_USBIO_EXIT_SLEEP_PH1;
            KBD_ROWPins_CR1_REG = KBD_ROWPins_backup.usbState;
            KBD_ROWPins_USB_POWER_REG &= KBD_ROWPins_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(KBD_ROWPins__SIO)
        KBD_ROWPins_SIO_REG = KBD_ROWPins_backup.sioState;
    #endif
}


/* [] END OF FILE */
