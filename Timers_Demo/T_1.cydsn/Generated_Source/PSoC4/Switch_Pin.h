/*******************************************************************************
* File Name: Switch_Pin.h  
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

#if !defined(CY_PINS_Switch_Pin_H) /* Pins Switch_Pin_H */
#define CY_PINS_Switch_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Switch_Pin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Switch_Pin_Write(uint8 value) ;
void    Switch_Pin_SetDriveMode(uint8 mode) ;
uint8   Switch_Pin_ReadDataReg(void) ;
uint8   Switch_Pin_Read(void) ;
uint8   Switch_Pin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Switch_Pin_DRIVE_MODE_BITS        (3)
#define Switch_Pin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Switch_Pin_DRIVE_MODE_BITS))

#define Switch_Pin_DM_ALG_HIZ         (0x00u)
#define Switch_Pin_DM_DIG_HIZ         (0x01u)
#define Switch_Pin_DM_RES_UP          (0x02u)
#define Switch_Pin_DM_RES_DWN         (0x03u)
#define Switch_Pin_DM_OD_LO           (0x04u)
#define Switch_Pin_DM_OD_HI           (0x05u)
#define Switch_Pin_DM_STRONG          (0x06u)
#define Switch_Pin_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Switch_Pin_MASK               Switch_Pin__MASK
#define Switch_Pin_SHIFT              Switch_Pin__SHIFT
#define Switch_Pin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Switch_Pin_PS                     (* (reg32 *) Switch_Pin__PS)
/* Port Configuration */
#define Switch_Pin_PC                     (* (reg32 *) Switch_Pin__PC)
/* Data Register */
#define Switch_Pin_DR                     (* (reg32 *) Switch_Pin__DR)
/* Input Buffer Disable Override */
#define Switch_Pin_INP_DIS                (* (reg32 *) Switch_Pin__PC2)


#if defined(Switch_Pin__INTSTAT)  /* Interrupt Registers */

    #define Switch_Pin_INTSTAT                (* (reg32 *) Switch_Pin__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Switch_Pin_DRIVE_MODE_SHIFT       (0x00u)
#define Switch_Pin_DRIVE_MODE_MASK        (0x07u << Switch_Pin_DRIVE_MODE_SHIFT)


#endif /* End Pins Switch_Pin_H */


/* [] END OF FILE */
