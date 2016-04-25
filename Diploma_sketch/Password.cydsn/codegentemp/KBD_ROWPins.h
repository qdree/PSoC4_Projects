/*******************************************************************************
* File Name: KBD_ROWPins.h  
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

#if !defined(CY_PINS_KBD_ROWPins_H) /* Pins KBD_ROWPins_H */
#define CY_PINS_KBD_ROWPins_H

#include "cytypes.h"
#include "cyfitter.h"
#include "KBD_ROWPins_aliases.h"


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
} KBD_ROWPins_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   KBD_ROWPins_Read(void);
void    KBD_ROWPins_Write(uint8 value);
uint8   KBD_ROWPins_ReadDataReg(void);
#if defined(KBD_ROWPins__PC) || (CY_PSOC4_4200L) 
    void    KBD_ROWPins_SetDriveMode(uint8 mode);
#endif
void    KBD_ROWPins_SetInterruptMode(uint16 position, uint16 mode);
uint8   KBD_ROWPins_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void KBD_ROWPins_Sleep(void); 
void KBD_ROWPins_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(KBD_ROWPins__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define KBD_ROWPins_DRIVE_MODE_BITS        (3)
    #define KBD_ROWPins_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - KBD_ROWPins_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the KBD_ROWPins_SetDriveMode() function.
         *  @{
         */
        #define KBD_ROWPins_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define KBD_ROWPins_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define KBD_ROWPins_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define KBD_ROWPins_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define KBD_ROWPins_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define KBD_ROWPins_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define KBD_ROWPins_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define KBD_ROWPins_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define KBD_ROWPins_MASK               KBD_ROWPins__MASK
#define KBD_ROWPins_SHIFT              KBD_ROWPins__SHIFT
#define KBD_ROWPins_WIDTH              4u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in KBD_ROWPins_SetInterruptMode() function.
     *  @{
     */
        #define KBD_ROWPins_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define KBD_ROWPins_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define KBD_ROWPins_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define KBD_ROWPins_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(KBD_ROWPins__SIO)
    #define KBD_ROWPins_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(KBD_ROWPins__PC) && (CY_PSOC4_4200L)
    #define KBD_ROWPins_USBIO_ENABLE               ((uint32)0x80000000u)
    #define KBD_ROWPins_USBIO_DISABLE              ((uint32)(~KBD_ROWPins_USBIO_ENABLE))
    #define KBD_ROWPins_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define KBD_ROWPins_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define KBD_ROWPins_USBIO_ENTER_SLEEP          ((uint32)((1u << KBD_ROWPins_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << KBD_ROWPins_USBIO_SUSPEND_DEL_SHIFT)))
    #define KBD_ROWPins_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << KBD_ROWPins_USBIO_SUSPEND_SHIFT)))
    #define KBD_ROWPins_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << KBD_ROWPins_USBIO_SUSPEND_DEL_SHIFT)))
    #define KBD_ROWPins_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(KBD_ROWPins__PC)
    /* Port Configuration */
    #define KBD_ROWPins_PC                 (* (reg32 *) KBD_ROWPins__PC)
#endif
/* Pin State */
#define KBD_ROWPins_PS                     (* (reg32 *) KBD_ROWPins__PS)
/* Data Register */
#define KBD_ROWPins_DR                     (* (reg32 *) KBD_ROWPins__DR)
/* Input Buffer Disable Override */
#define KBD_ROWPins_INP_DIS                (* (reg32 *) KBD_ROWPins__PC2)

/* Interrupt configuration Registers */
#define KBD_ROWPins_INTCFG                 (* (reg32 *) KBD_ROWPins__INTCFG)
#define KBD_ROWPins_INTSTAT                (* (reg32 *) KBD_ROWPins__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define KBD_ROWPins_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(KBD_ROWPins__SIO)
    #define KBD_ROWPins_SIO_REG            (* (reg32 *) KBD_ROWPins__SIO)
#endif /* (KBD_ROWPins__SIO_CFG) */

/* USBIO registers */
#if !defined(KBD_ROWPins__PC) && (CY_PSOC4_4200L)
    #define KBD_ROWPins_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define KBD_ROWPins_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define KBD_ROWPins_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define KBD_ROWPins_DRIVE_MODE_SHIFT       (0x00u)
#define KBD_ROWPins_DRIVE_MODE_MASK        (0x07u << KBD_ROWPins_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins KBD_ROWPins_H */


/* [] END OF FILE */
