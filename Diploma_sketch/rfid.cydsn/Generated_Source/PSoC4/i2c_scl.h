/*******************************************************************************
* File Name: i2c_scl.h  
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

#if !defined(CY_PINS_i2c_scl_H) /* Pins i2c_scl_H */
#define CY_PINS_i2c_scl_H

#include "cytypes.h"
#include "cyfitter.h"
#include "i2c_scl_aliases.h"


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
} i2c_scl_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   i2c_scl_Read(void);
void    i2c_scl_Write(uint8 value);
uint8   i2c_scl_ReadDataReg(void);
#if defined(i2c_scl__PC) || (CY_PSOC4_4200L) 
    void    i2c_scl_SetDriveMode(uint8 mode);
#endif
void    i2c_scl_SetInterruptMode(uint16 position, uint16 mode);
uint8   i2c_scl_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void i2c_scl_Sleep(void); 
void i2c_scl_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(i2c_scl__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define i2c_scl_DRIVE_MODE_BITS        (3)
    #define i2c_scl_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - i2c_scl_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the i2c_scl_SetDriveMode() function.
         *  @{
         */
        #define i2c_scl_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define i2c_scl_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define i2c_scl_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define i2c_scl_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define i2c_scl_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define i2c_scl_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define i2c_scl_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define i2c_scl_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define i2c_scl_MASK               i2c_scl__MASK
#define i2c_scl_SHIFT              i2c_scl__SHIFT
#define i2c_scl_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in i2c_scl_SetInterruptMode() function.
     *  @{
     */
        #define i2c_scl_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define i2c_scl_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define i2c_scl_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define i2c_scl_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(i2c_scl__SIO)
    #define i2c_scl_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(i2c_scl__PC) && (CY_PSOC4_4200L)
    #define i2c_scl_USBIO_ENABLE               ((uint32)0x80000000u)
    #define i2c_scl_USBIO_DISABLE              ((uint32)(~i2c_scl_USBIO_ENABLE))
    #define i2c_scl_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define i2c_scl_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define i2c_scl_USBIO_ENTER_SLEEP          ((uint32)((1u << i2c_scl_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << i2c_scl_USBIO_SUSPEND_DEL_SHIFT)))
    #define i2c_scl_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << i2c_scl_USBIO_SUSPEND_SHIFT)))
    #define i2c_scl_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << i2c_scl_USBIO_SUSPEND_DEL_SHIFT)))
    #define i2c_scl_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(i2c_scl__PC)
    /* Port Configuration */
    #define i2c_scl_PC                 (* (reg32 *) i2c_scl__PC)
#endif
/* Pin State */
#define i2c_scl_PS                     (* (reg32 *) i2c_scl__PS)
/* Data Register */
#define i2c_scl_DR                     (* (reg32 *) i2c_scl__DR)
/* Input Buffer Disable Override */
#define i2c_scl_INP_DIS                (* (reg32 *) i2c_scl__PC2)

/* Interrupt configuration Registers */
#define i2c_scl_INTCFG                 (* (reg32 *) i2c_scl__INTCFG)
#define i2c_scl_INTSTAT                (* (reg32 *) i2c_scl__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define i2c_scl_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(i2c_scl__SIO)
    #define i2c_scl_SIO_REG            (* (reg32 *) i2c_scl__SIO)
#endif /* (i2c_scl__SIO_CFG) */

/* USBIO registers */
#if !defined(i2c_scl__PC) && (CY_PSOC4_4200L)
    #define i2c_scl_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define i2c_scl_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define i2c_scl_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define i2c_scl_DRIVE_MODE_SHIFT       (0x00u)
#define i2c_scl_DRIVE_MODE_MASK        (0x07u << i2c_scl_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins i2c_scl_H */


/* [] END OF FILE */
