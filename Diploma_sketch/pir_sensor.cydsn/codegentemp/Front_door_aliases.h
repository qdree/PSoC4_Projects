/*******************************************************************************
* File Name: Front_door.h  
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

#if !defined(CY_PINS_Front_door_ALIASES_H) /* Pins Front_door_ALIASES_H */
#define CY_PINS_Front_door_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Front_door_0			(Front_door__0__PC)
#define Front_door_0_PS		(Front_door__0__PS)
#define Front_door_0_PC		(Front_door__0__PC)
#define Front_door_0_DR		(Front_door__0__DR)
#define Front_door_0_SHIFT	(Front_door__0__SHIFT)
#define Front_door_0_INTR	((uint16)((uint16)0x0003u << (Front_door__0__SHIFT*2u)))

#define Front_door_INTR_ALL	 ((uint16)(Front_door_0_INTR))


#endif /* End Pins Front_door_ALIASES_H */


/* [] END OF FILE */
