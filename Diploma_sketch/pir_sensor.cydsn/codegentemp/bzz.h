/*******************************************************************************
* File Name: bzz.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_bzz_H) /* Pins bzz_H */
#define CY_PINS_bzz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "bzz_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} bzz_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   bzz_Read(void);
void    bzz_Write(uint8 value);
uint8   bzz_ReadDataReg(void);
#if defined(bzz__PC) || (CY_PSOC4_4200L) 
    void    bzz_SetDriveMode(uint8 mode);
#endif
void    bzz_SetInterruptMode(uint16 position, uint16 mode);
uint8   bzz_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void bzz_Sleep(void); 
void bzz_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(bzz__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define bzz_DRIVE_MODE_BITS        (3)
    #define bzz_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - bzz_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the bzz_SetDriveMode() function.
         *  @{
         */
        #define bzz_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define bzz_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define bzz_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define bzz_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define bzz_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define bzz_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define bzz_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define bzz_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define bzz_MASK               bzz__MASK
#define bzz_SHIFT              bzz__SHIFT
#define bzz_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bzz_SetInterruptMode() function.
     *  @{
     */
        #define bzz_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define bzz_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define bzz_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define bzz_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(bzz__SIO)
    #define bzz_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(bzz__PC) && (CY_PSOC4_4200L)
    #define bzz_USBIO_ENABLE               ((uint32)0x80000000u)
    #define bzz_USBIO_DISABLE              ((uint32)(~bzz_USBIO_ENABLE))
    #define bzz_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define bzz_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define bzz_USBIO_ENTER_SLEEP          ((uint32)((1u << bzz_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << bzz_USBIO_SUSPEND_DEL_SHIFT)))
    #define bzz_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << bzz_USBIO_SUSPEND_SHIFT)))
    #define bzz_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << bzz_USBIO_SUSPEND_DEL_SHIFT)))
    #define bzz_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(bzz__PC)
    /* Port Configuration */
    #define bzz_PC                 (* (reg32 *) bzz__PC)
#endif
/* Pin State */
#define bzz_PS                     (* (reg32 *) bzz__PS)
/* Data Register */
#define bzz_DR                     (* (reg32 *) bzz__DR)
/* Input Buffer Disable Override */
#define bzz_INP_DIS                (* (reg32 *) bzz__PC2)

/* Interrupt configuration Registers */
#define bzz_INTCFG                 (* (reg32 *) bzz__INTCFG)
#define bzz_INTSTAT                (* (reg32 *) bzz__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define bzz_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(bzz__SIO)
    #define bzz_SIO_REG            (* (reg32 *) bzz__SIO)
#endif /* (bzz__SIO_CFG) */

/* USBIO registers */
#if !defined(bzz__PC) && (CY_PSOC4_4200L)
    #define bzz_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define bzz_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define bzz_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define bzz_DRIVE_MODE_SHIFT       (0x00u)
#define bzz_DRIVE_MODE_MASK        (0x07u << bzz_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins bzz_H */


/* [] END OF FILE */
