/*******************************************************************************
* File Name: KBD_COLPins.h  
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

#if !defined(CY_PINS_KBD_COLPins_ALIASES_H) /* Pins KBD_COLPins_ALIASES_H */
#define CY_PINS_KBD_COLPins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define KBD_COLPins_0			(KBD_COLPins__0__PC)
#define KBD_COLPins_0_PS		(KBD_COLPins__0__PS)
#define KBD_COLPins_0_PC		(KBD_COLPins__0__PC)
#define KBD_COLPins_0_DR		(KBD_COLPins__0__DR)
#define KBD_COLPins_0_SHIFT	(KBD_COLPins__0__SHIFT)
#define KBD_COLPins_0_INTR	((uint16)((uint16)0x0003u << (KBD_COLPins__0__SHIFT*2u)))

#define KBD_COLPins_1			(KBD_COLPins__1__PC)
#define KBD_COLPins_1_PS		(KBD_COLPins__1__PS)
#define KBD_COLPins_1_PC		(KBD_COLPins__1__PC)
#define KBD_COLPins_1_DR		(KBD_COLPins__1__DR)
#define KBD_COLPins_1_SHIFT	(KBD_COLPins__1__SHIFT)
#define KBD_COLPins_1_INTR	((uint16)((uint16)0x0003u << (KBD_COLPins__1__SHIFT*2u)))

#define KBD_COLPins_2			(KBD_COLPins__2__PC)
#define KBD_COLPins_2_PS		(KBD_COLPins__2__PS)
#define KBD_COLPins_2_PC		(KBD_COLPins__2__PC)
#define KBD_COLPins_2_DR		(KBD_COLPins__2__DR)
#define KBD_COLPins_2_SHIFT	(KBD_COLPins__2__SHIFT)
#define KBD_COLPins_2_INTR	((uint16)((uint16)0x0003u << (KBD_COLPins__2__SHIFT*2u)))

#define KBD_COLPins_INTR_ALL	 ((uint16)(KBD_COLPins_0_INTR| KBD_COLPins_1_INTR| KBD_COLPins_2_INTR))


#endif /* End Pins KBD_COLPins_ALIASES_H */


/* [] END OF FILE */
