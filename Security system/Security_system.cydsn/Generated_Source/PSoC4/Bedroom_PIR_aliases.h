/*******************************************************************************
* File Name: Bedroom_PIR.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Bedroom_PIR_ALIASES_H) /* Pins Bedroom_PIR_ALIASES_H */
#define CY_PINS_Bedroom_PIR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Bedroom_PIR_0			(Bedroom_PIR__0__PC)
#define Bedroom_PIR_0_PS		(Bedroom_PIR__0__PS)
#define Bedroom_PIR_0_PC		(Bedroom_PIR__0__PC)
#define Bedroom_PIR_0_DR		(Bedroom_PIR__0__DR)
#define Bedroom_PIR_0_SHIFT	(Bedroom_PIR__0__SHIFT)
#define Bedroom_PIR_0_INTR	((uint16)((uint16)0x0003u << (Bedroom_PIR__0__SHIFT*2u)))

#define Bedroom_PIR_INTR_ALL	 ((uint16)(Bedroom_PIR_0_INTR))


#endif /* End Pins Bedroom_PIR_ALIASES_H */


/* [] END OF FILE */
