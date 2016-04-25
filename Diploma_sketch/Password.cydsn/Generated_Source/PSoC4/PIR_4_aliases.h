/*******************************************************************************
* File Name: PIR_4.h  
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

#if !defined(CY_PINS_PIR_4_ALIASES_H) /* Pins PIR_4_ALIASES_H */
#define CY_PINS_PIR_4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PIR_4_0			(PIR_4__0__PC)
#define PIR_4_0_PS		(PIR_4__0__PS)
#define PIR_4_0_PC		(PIR_4__0__PC)
#define PIR_4_0_DR		(PIR_4__0__DR)
#define PIR_4_0_SHIFT	(PIR_4__0__SHIFT)
#define PIR_4_0_INTR	((uint16)((uint16)0x0003u << (PIR_4__0__SHIFT*2u)))

#define PIR_4_INTR_ALL	 ((uint16)(PIR_4_0_INTR))


#endif /* End Pins PIR_4_ALIASES_H */


/* [] END OF FILE */
