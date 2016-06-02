/*******************************************************************************
* File Name: pir4.c  
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
#include "pir4.h"

static pir4_BACKUP_STRUCT  pir4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: pir4_Sleep
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
*  \snippet pir4_SUT.c usage_pir4_Sleep_Wakeup
*******************************************************************************/
void pir4_Sleep(void)
{
    #if defined(pir4__PC)
        pir4_backup.pcState = pir4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            pir4_backup.usbState = pir4_CR1_REG;
            pir4_USB_POWER_REG |= pir4_USBIO_ENTER_SLEEP;
            pir4_CR1_REG &= pir4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pir4__SIO)
        pir4_backup.sioState = pir4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        pir4_SIO_REG &= (uint32)(~pir4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: pir4_Wakeup
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
*  Refer to pir4_Sleep() for an example usage.
*******************************************************************************/
void pir4_Wakeup(void)
{
    #if defined(pir4__PC)
        pir4_PC = pir4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            pir4_USB_POWER_REG &= pir4_USBIO_EXIT_SLEEP_PH1;
            pir4_CR1_REG = pir4_backup.usbState;
            pir4_USB_POWER_REG &= pir4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pir4__SIO)
        pir4_SIO_REG = pir4_backup.sioState;
    #endif
}


/* [] END OF FILE */
