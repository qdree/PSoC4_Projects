/*******************************************************************************
* File Name: PIR_4.c  
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
#include "PIR_4.h"

static PIR_4_BACKUP_STRUCT  PIR_4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PIR_4_Sleep
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
*  \snippet PIR_4_SUT.c usage_PIR_4_Sleep_Wakeup
*******************************************************************************/
void PIR_4_Sleep(void)
{
    #if defined(PIR_4__PC)
        PIR_4_backup.pcState = PIR_4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PIR_4_backup.usbState = PIR_4_CR1_REG;
            PIR_4_USB_POWER_REG |= PIR_4_USBIO_ENTER_SLEEP;
            PIR_4_CR1_REG &= PIR_4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PIR_4__SIO)
        PIR_4_backup.sioState = PIR_4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PIR_4_SIO_REG &= (uint32)(~PIR_4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PIR_4_Wakeup
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
*  Refer to PIR_4_Sleep() for an example usage.
*******************************************************************************/
void PIR_4_Wakeup(void)
{
    #if defined(PIR_4__PC)
        PIR_4_PC = PIR_4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PIR_4_USB_POWER_REG &= PIR_4_USBIO_EXIT_SLEEP_PH1;
            PIR_4_CR1_REG = PIR_4_backup.usbState;
            PIR_4_USB_POWER_REG &= PIR_4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PIR_4__SIO)
        PIR_4_SIO_REG = PIR_4_backup.sioState;
    #endif
}


/* [] END OF FILE */
