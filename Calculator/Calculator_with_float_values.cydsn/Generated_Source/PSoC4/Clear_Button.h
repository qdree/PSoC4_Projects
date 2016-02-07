/*******************************************************************************
* File Name: Clear_Button.h  
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

#if !defined(CY_PINS_Clear_Button_H) /* Pins Clear_Button_H */
#define CY_PINS_Clear_Button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Clear_Button_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Clear_Button_Write(uint8 value) ;
void    Clear_Button_SetDriveMode(uint8 mode) ;
uint8   Clear_Button_ReadDataReg(void) ;
uint8   Clear_Button_Read(void) ;
uint8   Clear_Button_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Clear_Button_DRIVE_MODE_BITS        (3)
#define Clear_Button_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Clear_Button_DRIVE_MODE_BITS))

#define Clear_Button_DM_ALG_HIZ         (0x00u)
#define Clear_Button_DM_DIG_HIZ         (0x01u)
#define Clear_Button_DM_RES_UP          (0x02u)
#define Clear_Button_DM_RES_DWN         (0x03u)
#define Clear_Button_DM_OD_LO           (0x04u)
#define Clear_Button_DM_OD_HI           (0x05u)
#define Clear_Button_DM_STRONG          (0x06u)
#define Clear_Button_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Clear_Button_MASK               Clear_Button__MASK
#define Clear_Button_SHIFT              Clear_Button__SHIFT
#define Clear_Button_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Clear_Button_PS                     (* (reg32 *) Clear_Button__PS)
/* Port Configuration */
#define Clear_Button_PC                     (* (reg32 *) Clear_Button__PC)
/* Data Register */
#define Clear_Button_DR                     (* (reg32 *) Clear_Button__DR)
/* Input Buffer Disable Override */
#define Clear_Button_INP_DIS                (* (reg32 *) Clear_Button__PC2)


#if defined(Clear_Button__INTSTAT)  /* Interrupt Registers */

    #define Clear_Button_INTSTAT                (* (reg32 *) Clear_Button__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Clear_Button_DRIVE_MODE_SHIFT       (0x00u)
#define Clear_Button_DRIVE_MODE_MASK        (0x07u << Clear_Button_DRIVE_MODE_SHIFT)


#endif /* End Pins Clear_Button_H */


/* [] END OF FILE */
