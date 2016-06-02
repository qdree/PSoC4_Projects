/*******************************************************************************
* File Name: pir3.h  
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

#if !defined(CY_PINS_pir3_H) /* Pins pir3_H */
#define CY_PINS_pir3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pir3_aliases.h"


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
} pir3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pir3_Read(void);
void    pir3_Write(uint8 value);
uint8   pir3_ReadDataReg(void);
#if defined(pir3__PC) || (CY_PSOC4_4200L) 
    void    pir3_SetDriveMode(uint8 mode);
#endif
void    pir3_SetInterruptMode(uint16 position, uint16 mode);
uint8   pir3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pir3_Sleep(void); 
void pir3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pir3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pir3_DRIVE_MODE_BITS        (3)
    #define pir3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pir3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pir3_SetDriveMode() function.
         *  @{
         */
        #define pir3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pir3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pir3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pir3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pir3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pir3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pir3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pir3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pir3_MASK               pir3__MASK
#define pir3_SHIFT              pir3__SHIFT
#define pir3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pir3_SetInterruptMode() function.
     *  @{
     */
        #define pir3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pir3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pir3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pir3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pir3__SIO)
    #define pir3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pir3__PC) && (CY_PSOC4_4200L)
    #define pir3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pir3_USBIO_DISABLE              ((uint32)(~pir3_USBIO_ENABLE))
    #define pir3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pir3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pir3_USBIO_ENTER_SLEEP          ((uint32)((1u << pir3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pir3_USBIO_SUSPEND_DEL_SHIFT)))
    #define pir3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pir3_USBIO_SUSPEND_SHIFT)))
    #define pir3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pir3_USBIO_SUSPEND_DEL_SHIFT)))
    #define pir3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pir3__PC)
    /* Port Configuration */
    #define pir3_PC                 (* (reg32 *) pir3__PC)
#endif
/* Pin State */
#define pir3_PS                     (* (reg32 *) pir3__PS)
/* Data Register */
#define pir3_DR                     (* (reg32 *) pir3__DR)
/* Input Buffer Disable Override */
#define pir3_INP_DIS                (* (reg32 *) pir3__PC2)

/* Interrupt configuration Registers */
#define pir3_INTCFG                 (* (reg32 *) pir3__INTCFG)
#define pir3_INTSTAT                (* (reg32 *) pir3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pir3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pir3__SIO)
    #define pir3_SIO_REG            (* (reg32 *) pir3__SIO)
#endif /* (pir3__SIO_CFG) */

/* USBIO registers */
#if !defined(pir3__PC) && (CY_PSOC4_4200L)
    #define pir3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pir3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pir3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pir3_DRIVE_MODE_SHIFT       (0x00u)
#define pir3_DRIVE_MODE_MASK        (0x07u << pir3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pir3_H */


/* [] END OF FILE */
