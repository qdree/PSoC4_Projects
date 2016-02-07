/*******************************************************************************
* File Name: BZZ.h  
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

#if !defined(CY_PINS_BZZ_H) /* Pins BZZ_H */
#define CY_PINS_BZZ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BZZ_aliases.h"


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
} BZZ_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BZZ_Read(void);
void    BZZ_Write(uint8 value);
uint8   BZZ_ReadDataReg(void);
#if defined(BZZ__PC) || (CY_PSOC4_4200L) 
    void    BZZ_SetDriveMode(uint8 mode);
#endif
void    BZZ_SetInterruptMode(uint16 position, uint16 mode);
uint8   BZZ_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BZZ_Sleep(void); 
void BZZ_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BZZ__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BZZ_DRIVE_MODE_BITS        (3)
    #define BZZ_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BZZ_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BZZ_SetDriveMode() function.
         *  @{
         */
        #define BZZ_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BZZ_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BZZ_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BZZ_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BZZ_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BZZ_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BZZ_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BZZ_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BZZ_MASK               BZZ__MASK
#define BZZ_SHIFT              BZZ__SHIFT
#define BZZ_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BZZ_SetInterruptMode() function.
     *  @{
     */
        #define BZZ_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BZZ_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BZZ_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BZZ_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BZZ__SIO)
    #define BZZ_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BZZ__PC) && (CY_PSOC4_4200L)
    #define BZZ_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BZZ_USBIO_DISABLE              ((uint32)(~BZZ_USBIO_ENABLE))
    #define BZZ_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BZZ_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BZZ_USBIO_ENTER_SLEEP          ((uint32)((1u << BZZ_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BZZ_USBIO_SUSPEND_DEL_SHIFT)))
    #define BZZ_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BZZ_USBIO_SUSPEND_SHIFT)))
    #define BZZ_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BZZ_USBIO_SUSPEND_DEL_SHIFT)))
    #define BZZ_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BZZ__PC)
    /* Port Configuration */
    #define BZZ_PC                 (* (reg32 *) BZZ__PC)
#endif
/* Pin State */
#define BZZ_PS                     (* (reg32 *) BZZ__PS)
/* Data Register */
#define BZZ_DR                     (* (reg32 *) BZZ__DR)
/* Input Buffer Disable Override */
#define BZZ_INP_DIS                (* (reg32 *) BZZ__PC2)

/* Interrupt configuration Registers */
#define BZZ_INTCFG                 (* (reg32 *) BZZ__INTCFG)
#define BZZ_INTSTAT                (* (reg32 *) BZZ__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BZZ_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BZZ__SIO)
    #define BZZ_SIO_REG            (* (reg32 *) BZZ__SIO)
#endif /* (BZZ__SIO_CFG) */

/* USBIO registers */
#if !defined(BZZ__PC) && (CY_PSOC4_4200L)
    #define BZZ_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BZZ_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BZZ_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BZZ_DRIVE_MODE_SHIFT       (0x00u)
#define BZZ_DRIVE_MODE_MASK        (0x07u << BZZ_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BZZ_H */


/* [] END OF FILE */
