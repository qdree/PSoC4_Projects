/*******************************************************************************
* File Name: Back_door.h  
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

#if !defined(CY_PINS_Back_door_H) /* Pins Back_door_H */
#define CY_PINS_Back_door_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Back_door_aliases.h"


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
} Back_door_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Back_door_Read(void);
void    Back_door_Write(uint8 value);
uint8   Back_door_ReadDataReg(void);
#if defined(Back_door__PC) || (CY_PSOC4_4200L) 
    void    Back_door_SetDriveMode(uint8 mode);
#endif
void    Back_door_SetInterruptMode(uint16 position, uint16 mode);
uint8   Back_door_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Back_door_Sleep(void); 
void Back_door_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Back_door__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Back_door_DRIVE_MODE_BITS        (3)
    #define Back_door_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Back_door_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Back_door_SetDriveMode() function.
         *  @{
         */
        #define Back_door_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Back_door_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Back_door_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Back_door_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Back_door_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Back_door_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Back_door_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Back_door_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Back_door_MASK               Back_door__MASK
#define Back_door_SHIFT              Back_door__SHIFT
#define Back_door_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Back_door_SetInterruptMode() function.
     *  @{
     */
        #define Back_door_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Back_door_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Back_door_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Back_door_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Back_door__SIO)
    #define Back_door_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Back_door__PC) && (CY_PSOC4_4200L)
    #define Back_door_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Back_door_USBIO_DISABLE              ((uint32)(~Back_door_USBIO_ENABLE))
    #define Back_door_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Back_door_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Back_door_USBIO_ENTER_SLEEP          ((uint32)((1u << Back_door_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Back_door_USBIO_SUSPEND_DEL_SHIFT)))
    #define Back_door_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Back_door_USBIO_SUSPEND_SHIFT)))
    #define Back_door_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Back_door_USBIO_SUSPEND_DEL_SHIFT)))
    #define Back_door_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Back_door__PC)
    /* Port Configuration */
    #define Back_door_PC                 (* (reg32 *) Back_door__PC)
#endif
/* Pin State */
#define Back_door_PS                     (* (reg32 *) Back_door__PS)
/* Data Register */
#define Back_door_DR                     (* (reg32 *) Back_door__DR)
/* Input Buffer Disable Override */
#define Back_door_INP_DIS                (* (reg32 *) Back_door__PC2)

/* Interrupt configuration Registers */
#define Back_door_INTCFG                 (* (reg32 *) Back_door__INTCFG)
#define Back_door_INTSTAT                (* (reg32 *) Back_door__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Back_door_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Back_door__SIO)
    #define Back_door_SIO_REG            (* (reg32 *) Back_door__SIO)
#endif /* (Back_door__SIO_CFG) */

/* USBIO registers */
#if !defined(Back_door__PC) && (CY_PSOC4_4200L)
    #define Back_door_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Back_door_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Back_door_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Back_door_DRIVE_MODE_SHIFT       (0x00u)
#define Back_door_DRIVE_MODE_MASK        (0x07u << Back_door_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Back_door_H */


/* [] END OF FILE */
