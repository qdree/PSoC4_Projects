/*******************************************************************************
* File Name: KBD_ROWPins.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
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
*        Function Prototypes             
***************************************/    

void    KBD_ROWPins_Write(uint8 value) ;
void    KBD_ROWPins_SetDriveMode(uint8 mode) ;
uint8   KBD_ROWPins_ReadDataReg(void) ;
uint8   KBD_ROWPins_Read(void) ;
uint8   KBD_ROWPins_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KBD_ROWPins_DRIVE_MODE_BITS        (3)
#define KBD_ROWPins_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - KBD_ROWPins_DRIVE_MODE_BITS))

#define KBD_ROWPins_DM_ALG_HIZ         (0x00u)
#define KBD_ROWPins_DM_DIG_HIZ         (0x01u)
#define KBD_ROWPins_DM_RES_UP          (0x02u)
#define KBD_ROWPins_DM_RES_DWN         (0x03u)
#define KBD_ROWPins_DM_OD_LO           (0x04u)
#define KBD_ROWPins_DM_OD_HI           (0x05u)
#define KBD_ROWPins_DM_STRONG          (0x06u)
#define KBD_ROWPins_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define KBD_ROWPins_MASK               KBD_ROWPins__MASK
#define KBD_ROWPins_SHIFT              KBD_ROWPins__SHIFT
#define KBD_ROWPins_WIDTH              4u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KBD_ROWPins_PS                     (* (reg32 *) KBD_ROWPins__PS)
/* Port Configuration */
#define KBD_ROWPins_PC                     (* (reg32 *) KBD_ROWPins__PC)
/* Data Register */
#define KBD_ROWPins_DR                     (* (reg32 *) KBD_ROWPins__DR)
/* Input Buffer Disable Override */
#define KBD_ROWPins_INP_DIS                (* (reg32 *) KBD_ROWPins__PC2)


#if defined(KBD_ROWPins__INTSTAT)  /* Interrupt Registers */

    #define KBD_ROWPins_INTSTAT                (* (reg32 *) KBD_ROWPins__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define KBD_ROWPins_DRIVE_MODE_SHIFT       (0x00u)
#define KBD_ROWPins_DRIVE_MODE_MASK        (0x07u << KBD_ROWPins_DRIVE_MODE_SHIFT)


#endif /* End Pins KBD_ROWPins_H */


/* [] END OF FILE */
