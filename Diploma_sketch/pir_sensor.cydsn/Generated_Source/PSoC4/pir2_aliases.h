/*******************************************************************************
* File Name: pir2.h  
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

#if !defined(CY_PINS_pir2_ALIASES_H) /* Pins pir2_ALIASES_H */
#define CY_PINS_pir2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pir2_0			(pir2__0__PC)
#define pir2_0_PS		(pir2__0__PS)
#define pir2_0_PC		(pir2__0__PC)
#define pir2_0_DR		(pir2__0__DR)
#define pir2_0_SHIFT	(pir2__0__SHIFT)
#define pir2_0_INTR	((uint16)((uint16)0x0003u << (pir2__0__SHIFT*2u)))

#define pir2_INTR_ALL	 ((uint16)(pir2_0_INTR))


#endif /* End Pins pir2_ALIASES_H */


/* [] END OF FILE */
