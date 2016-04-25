/*******************************************************************************
* File Name: noise_buzzer.h  
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

#if !defined(CY_PINS_noise_buzzer_ALIASES_H) /* Pins noise_buzzer_ALIASES_H */
#define CY_PINS_noise_buzzer_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define noise_buzzer_0			(noise_buzzer__0__PC)
#define noise_buzzer_0_PS		(noise_buzzer__0__PS)
#define noise_buzzer_0_PC		(noise_buzzer__0__PC)
#define noise_buzzer_0_DR		(noise_buzzer__0__DR)
#define noise_buzzer_0_SHIFT	(noise_buzzer__0__SHIFT)
#define noise_buzzer_0_INTR	((uint16)((uint16)0x0003u << (noise_buzzer__0__SHIFT*2u)))

#define noise_buzzer_INTR_ALL	 ((uint16)(noise_buzzer_0_INTR))


#endif /* End Pins noise_buzzer_ALIASES_H */


/* [] END OF FILE */
