/*******************************************************************************
* File Name: bzz.h  
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

#if !defined(CY_PINS_bzz_ALIASES_H) /* Pins bzz_ALIASES_H */
#define CY_PINS_bzz_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define bzz_0			(bzz__0__PC)
#define bzz_0_PS		(bzz__0__PS)
#define bzz_0_PC		(bzz__0__PC)
#define bzz_0_DR		(bzz__0__DR)
#define bzz_0_SHIFT	(bzz__0__SHIFT)
#define bzz_0_INTR	((uint16)((uint16)0x0003u << (bzz__0__SHIFT*2u)))

#define bzz_INTR_ALL	 ((uint16)(bzz_0_INTR))


#endif /* End Pins bzz_ALIASES_H */


/* [] END OF FILE */
