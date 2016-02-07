/*******************************************************************************
* File Name: sw.h  
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

#if !defined(CY_PINS_sw_H) /* Pins sw_H */
#define CY_PINS_sw_H

#include "cytypes.h"
#include "cyfitter.h"
#include "sw_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    sw_Write(uint8 value) ;
void    sw_SetDriveMode(uint8 mode) ;
uint8   sw_ReadDataReg(void) ;
uint8   sw_Read(void) ;
uint8   sw_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define sw_DRIVE_MODE_BITS        (3)
#define sw_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - sw_DRIVE_MODE_BITS))

#define sw_DM_ALG_HIZ         (0x00u)
#define sw_DM_DIG_HIZ         (0x01u)
#define sw_DM_RES_UP          (0x02u)
#define sw_DM_RES_DWN         (0x03u)
#define sw_DM_OD_LO           (0x04u)
#define sw_DM_OD_HI           (0x05u)
#define sw_DM_STRONG          (0x06u)
#define sw_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define sw_MASK               sw__MASK
#define sw_SHIFT              sw__SHIFT
#define sw_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sw_PS                     (* (reg32 *) sw__PS)
/* Port Configuration */
#define sw_PC                     (* (reg32 *) sw__PC)
/* Data Register */
#define sw_DR                     (* (reg32 *) sw__DR)
/* Input Buffer Disable Override */
#define sw_INP_DIS                (* (reg32 *) sw__PC2)


#if defined(sw__INTSTAT)  /* Interrupt Registers */

    #define sw_INTSTAT                (* (reg32 *) sw__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define sw_DRIVE_MODE_SHIFT       (0x00u)
#define sw_DRIVE_MODE_MASK        (0x07u << sw_DRIVE_MODE_SHIFT)


#endif /* End Pins sw_H */


/* [] END OF FILE */
