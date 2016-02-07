/*******************************************************************************
* File Name: Debounce_Int.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Debounce_Int_H)
#define CY_ISR_Debounce_Int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Debounce_Int_Start(void);
void Debounce_Int_StartEx(cyisraddress address);
void Debounce_Int_Stop(void);

CY_ISR_PROTO(Debounce_Int_Interrupt);

void Debounce_Int_SetVector(cyisraddress address);
cyisraddress Debounce_Int_GetVector(void);

void Debounce_Int_SetPriority(uint8 priority);
uint8 Debounce_Int_GetPriority(void);

void Debounce_Int_Enable(void);
uint8 Debounce_Int_GetState(void);
void Debounce_Int_Disable(void);

void Debounce_Int_SetPending(void);
void Debounce_Int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Debounce_Int ISR. */
#define Debounce_Int_INTC_VECTOR            ((reg32 *) Debounce_Int__INTC_VECT)

/* Address of the Debounce_Int ISR priority. */
#define Debounce_Int_INTC_PRIOR             ((reg32 *) Debounce_Int__INTC_PRIOR_REG)

/* Priority of the Debounce_Int interrupt. */
#define Debounce_Int_INTC_PRIOR_NUMBER      Debounce_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Debounce_Int interrupt. */
#define Debounce_Int_INTC_SET_EN            ((reg32 *) Debounce_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Debounce_Int interrupt. */
#define Debounce_Int_INTC_CLR_EN            ((reg32 *) Debounce_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Debounce_Int interrupt state to pending. */
#define Debounce_Int_INTC_SET_PD            ((reg32 *) Debounce_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Debounce_Int interrupt. */
#define Debounce_Int_INTC_CLR_PD            ((reg32 *) Debounce_Int__INTC_CLR_PD_REG)



#endif /* CY_ISR_Debounce_Int_H */


/* [] END OF FILE */
