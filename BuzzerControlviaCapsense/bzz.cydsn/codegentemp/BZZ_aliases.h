/*******************************************************************************
* File Name: BZZ.h  
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

#if !defined(CY_PINS_BZZ_ALIASES_H) /* Pins BZZ_ALIASES_H */
#define CY_PINS_BZZ_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BZZ_0			(BZZ__0__PC)
#define BZZ_0_PS		(BZZ__0__PS)
#define BZZ_0_PC		(BZZ__0__PC)
#define BZZ_0_DR		(BZZ__0__DR)
#define BZZ_0_SHIFT	(BZZ__0__SHIFT)
#define BZZ_0_INTR	((uint16)((uint16)0x0003u << (BZZ__0__SHIFT*2u)))

#define BZZ_INTR_ALL	 ((uint16)(BZZ_0_INTR))


#endif /* End Pins BZZ_ALIASES_H */


/* [] END OF FILE */
