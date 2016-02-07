/*******************************************************************************
* File Name: KBD_COLPins.h  
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

#if !defined(CY_PINS_KBD_COLPins_H) /* Pins KBD_COLPins_H */
#define CY_PINS_KBD_COLPins_H

#include "cytypes.h"
#include "cyfitter.h"
#include "KBD_COLPins_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    KBD_COLPins_Write(uint8 value) ;
void    KBD_COLPins_SetDriveMode(uint8 mode) ;
uint8   KBD_COLPins_ReadDataReg(void) ;
uint8   KBD_COLPins_Read(void) ;
uint8   KBD_COLPins_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KBD_COLPins_DRIVE_MODE_BITS        (3)
#define KBD_COLPins_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - KBD_COLPins_DRIVE_MODE_BITS))

#define KBD_COLPins_DM_ALG_HIZ         (0x00u)
#define KBD_COLPins_DM_DIG_HIZ         (0x01u)
#define KBD_COLPins_DM_RES_UP          (0x02u)
#define KBD_COLPins_DM_RES_DWN         (0x03u)
#define KBD_COLPins_DM_OD_LO           (0x04u)
#define KBD_COLPins_DM_OD_HI           (0x05u)
#define KBD_COLPins_DM_STRONG          (0x06u)
#define KBD_COLPins_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define KBD_COLPins_MASK               KBD_COLPins__MASK
#define KBD_COLPins_SHIFT              KBD_COLPins__SHIFT
#define KBD_COLPins_WIDTH              4u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KBD_COLPins_PS                     (* (reg32 *) KBD_COLPins__PS)
/* Port Configuration */
#define KBD_COLPins_PC                     (* (reg32 *) KBD_COLPins__PC)
/* Data Register */
#define KBD_COLPins_DR                     (* (reg32 *) KBD_COLPins__DR)
/* Input Buffer Disable Override */
#define KBD_COLPins_INP_DIS                (* (reg32 *) KBD_COLPins__PC2)


#if defined(KBD_COLPins__INTSTAT)  /* Interrupt Registers */

    #define KBD_COLPins_INTSTAT                (* (reg32 *) KBD_COLPins__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define KBD_COLPins_DRIVE_MODE_SHIFT       (0x00u)
#define KBD_COLPins_DRIVE_MODE_MASK        (0x07u << KBD_COLPins_DRIVE_MODE_SHIFT)


#endif /* End Pins KBD_COLPins_H */


/* [] END OF FILE */
