/*******************************************************************************
* File Name: KBD_ROWPins.h  
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

#if !defined(CY_PINS_KBD_ROWPins_ALIASES_H) /* Pins KBD_ROWPins_ALIASES_H */
#define CY_PINS_KBD_ROWPins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define KBD_ROWPins_0			(KBD_ROWPins__0__PC)
#define KBD_ROWPins_0_PS		(KBD_ROWPins__0__PS)
#define KBD_ROWPins_0_PC		(KBD_ROWPins__0__PC)
#define KBD_ROWPins_0_DR		(KBD_ROWPins__0__DR)
#define KBD_ROWPins_0_SHIFT	(KBD_ROWPins__0__SHIFT)
#define KBD_ROWPins_0_INTR	((uint16)((uint16)0x0003u << (KBD_ROWPins__0__SHIFT*2u)))

#define KBD_ROWPins_1			(KBD_ROWPins__1__PC)
#define KBD_ROWPins_1_PS		(KBD_ROWPins__1__PS)
#define KBD_ROWPins_1_PC		(KBD_ROWPins__1__PC)
#define KBD_ROWPins_1_DR		(KBD_ROWPins__1__DR)
#define KBD_ROWPins_1_SHIFT	(KBD_ROWPins__1__SHIFT)
#define KBD_ROWPins_1_INTR	((uint16)((uint16)0x0003u << (KBD_ROWPins__1__SHIFT*2u)))

#define KBD_ROWPins_2			(KBD_ROWPins__2__PC)
#define KBD_ROWPins_2_PS		(KBD_ROWPins__2__PS)
#define KBD_ROWPins_2_PC		(KBD_ROWPins__2__PC)
#define KBD_ROWPins_2_DR		(KBD_ROWPins__2__DR)
#define KBD_ROWPins_2_SHIFT	(KBD_ROWPins__2__SHIFT)
#define KBD_ROWPins_2_INTR	((uint16)((uint16)0x0003u << (KBD_ROWPins__2__SHIFT*2u)))

#define KBD_ROWPins_3			(KBD_ROWPins__3__PC)
#define KBD_ROWPins_3_PS		(KBD_ROWPins__3__PS)
#define KBD_ROWPins_3_PC		(KBD_ROWPins__3__PC)
#define KBD_ROWPins_3_DR		(KBD_ROWPins__3__DR)
#define KBD_ROWPins_3_SHIFT	(KBD_ROWPins__3__SHIFT)
#define KBD_ROWPins_3_INTR	((uint16)((uint16)0x0003u << (KBD_ROWPins__3__SHIFT*2u)))

#define KBD_ROWPins_INTR_ALL	 ((uint16)(KBD_ROWPins_0_INTR| KBD_ROWPins_1_INTR| KBD_ROWPins_2_INTR| KBD_ROWPins_3_INTR))


#endif /* End Pins KBD_ROWPins_ALIASES_H */


/* [] END OF FILE */
