/*******************************************************************************
* File Name: Guestroom_PIR.h  
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

#if !defined(CY_PINS_Guestroom_PIR_ALIASES_H) /* Pins Guestroom_PIR_ALIASES_H */
#define CY_PINS_Guestroom_PIR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Guestroom_PIR_0			(Guestroom_PIR__0__PC)
#define Guestroom_PIR_0_PS		(Guestroom_PIR__0__PS)
#define Guestroom_PIR_0_PC		(Guestroom_PIR__0__PC)
#define Guestroom_PIR_0_DR		(Guestroom_PIR__0__DR)
#define Guestroom_PIR_0_SHIFT	(Guestroom_PIR__0__SHIFT)
#define Guestroom_PIR_0_INTR	((uint16)((uint16)0x0003u << (Guestroom_PIR__0__SHIFT*2u)))

#define Guestroom_PIR_INTR_ALL	 ((uint16)(Guestroom_PIR_0_INTR))


#endif /* End Pins Guestroom_PIR_ALIASES_H */


/* [] END OF FILE */
