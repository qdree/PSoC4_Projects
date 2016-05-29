/*******************************************************************************
* File Name: Guestroom_PIR.h  
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

#if !defined(CY_PINS_Guestroom_PIR_H) /* Pins Guestroom_PIR_H */
#define CY_PINS_Guestroom_PIR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Guestroom_PIR_aliases.h"


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
} Guestroom_PIR_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Guestroom_PIR_Read(void);
void    Guestroom_PIR_Write(uint8 value);
uint8   Guestroom_PIR_ReadDataReg(void);
#if defined(Guestroom_PIR__PC) || (CY_PSOC4_4200L) 
    void    Guestroom_PIR_SetDriveMode(uint8 mode);
#endif
void    Guestroom_PIR_SetInterruptMode(uint16 position, uint16 mode);
uint8   Guestroom_PIR_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Guestroom_PIR_Sleep(void); 
void Guestroom_PIR_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Guestroom_PIR__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Guestroom_PIR_DRIVE_MODE_BITS        (3)
    #define Guestroom_PIR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Guestroom_PIR_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Guestroom_PIR_SetDriveMode() function.
         *  @{
         */
        #define Guestroom_PIR_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Guestroom_PIR_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Guestroom_PIR_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Guestroom_PIR_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Guestroom_PIR_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Guestroom_PIR_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Guestroom_PIR_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Guestroom_PIR_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Guestroom_PIR_MASK               Guestroom_PIR__MASK
#define Guestroom_PIR_SHIFT              Guestroom_PIR__SHIFT
#define Guestroom_PIR_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Guestroom_PIR_SetInterruptMode() function.
     *  @{
     */
        #define Guestroom_PIR_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Guestroom_PIR_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Guestroom_PIR_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Guestroom_PIR_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Guestroom_PIR__SIO)
    #define Guestroom_PIR_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Guestroom_PIR__PC) && (CY_PSOC4_4200L)
    #define Guestroom_PIR_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Guestroom_PIR_USBIO_DISABLE              ((uint32)(~Guestroom_PIR_USBIO_ENABLE))
    #define Guestroom_PIR_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Guestroom_PIR_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Guestroom_PIR_USBIO_ENTER_SLEEP          ((uint32)((1u << Guestroom_PIR_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Guestroom_PIR_USBIO_SUSPEND_DEL_SHIFT)))
    #define Guestroom_PIR_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Guestroom_PIR_USBIO_SUSPEND_SHIFT)))
    #define Guestroom_PIR_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Guestroom_PIR_USBIO_SUSPEND_DEL_SHIFT)))
    #define Guestroom_PIR_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Guestroom_PIR__PC)
    /* Port Configuration */
    #define Guestroom_PIR_PC                 (* (reg32 *) Guestroom_PIR__PC)
#endif
/* Pin State */
#define Guestroom_PIR_PS                     (* (reg32 *) Guestroom_PIR__PS)
/* Data Register */
#define Guestroom_PIR_DR                     (* (reg32 *) Guestroom_PIR__DR)
/* Input Buffer Disable Override */
#define Guestroom_PIR_INP_DIS                (* (reg32 *) Guestroom_PIR__PC2)

/* Interrupt configuration Registers */
#define Guestroom_PIR_INTCFG                 (* (reg32 *) Guestroom_PIR__INTCFG)
#define Guestroom_PIR_INTSTAT                (* (reg32 *) Guestroom_PIR__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Guestroom_PIR_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Guestroom_PIR__SIO)
    #define Guestroom_PIR_SIO_REG            (* (reg32 *) Guestroom_PIR__SIO)
#endif /* (Guestroom_PIR__SIO_CFG) */

/* USBIO registers */
#if !defined(Guestroom_PIR__PC) && (CY_PSOC4_4200L)
    #define Guestroom_PIR_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Guestroom_PIR_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Guestroom_PIR_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Guestroom_PIR_DRIVE_MODE_SHIFT       (0x00u)
#define Guestroom_PIR_DRIVE_MODE_MASK        (0x07u << Guestroom_PIR_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Guestroom_PIR_H */


/* [] END OF FILE */
