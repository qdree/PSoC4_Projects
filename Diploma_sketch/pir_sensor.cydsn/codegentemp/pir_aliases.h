/*******************************************************************************
* File Name: pir.h  
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

#if !defined(CY_PINS_pir_ALIASES_H) /* Pins pir_ALIASES_H */
#define CY_PINS_pir_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pir_0			(pir__0__PC)
#define pir_0_PS		(pir__0__PS)
#define pir_0_PC		(pir__0__PC)
#define pir_0_DR		(pir__0__DR)
#define pir_0_SHIFT	(pir__0__SHIFT)
#define pir_0_INTR	((uint16)((uint16)0x0003u << (pir__0__SHIFT*2u)))

#define pir_INTR_ALL	 ((uint16)(pir_0_INTR))


#endif /* End Pins pir_ALIASES_H */


/* [] END OF FILE */
