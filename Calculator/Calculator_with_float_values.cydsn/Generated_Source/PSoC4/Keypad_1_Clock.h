/*******************************************************************************
* File Name: Keypad_1_Clock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Keypad_1_Clock_H)
#define CY_CLOCK_Keypad_1_Clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Keypad_1_Clock_StartEx(uint32 alignClkDiv);
#define Keypad_1_Clock_Start() \
    Keypad_1_Clock_StartEx(Keypad_1_Clock__PA_DIV_ID)

#else

void Keypad_1_Clock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Keypad_1_Clock_Stop(void);

void Keypad_1_Clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Keypad_1_Clock_GetDividerRegister(void);
uint8  Keypad_1_Clock_GetFractionalDividerRegister(void);

#define Keypad_1_Clock_Enable()                         Keypad_1_Clock_Start()
#define Keypad_1_Clock_Disable()                        Keypad_1_Clock_Stop()
#define Keypad_1_Clock_SetDividerRegister(clkDivider, reset)  \
    Keypad_1_Clock_SetFractionalDividerRegister((clkDivider), 0u)
#define Keypad_1_Clock_SetDivider(clkDivider)           Keypad_1_Clock_SetDividerRegister((clkDivider), 1u)
#define Keypad_1_Clock_SetDividerValue(clkDivider)      Keypad_1_Clock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Keypad_1_Clock_DIV_ID     Keypad_1_Clock__DIV_ID

#define Keypad_1_Clock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Keypad_1_Clock_CTRL_REG   (*(reg32 *)Keypad_1_Clock__CTRL_REGISTER)
#define Keypad_1_Clock_DIV_REG    (*(reg32 *)Keypad_1_Clock__DIV_REGISTER)

#define Keypad_1_Clock_CMD_DIV_SHIFT          (0u)
#define Keypad_1_Clock_CMD_PA_DIV_SHIFT       (8u)
#define Keypad_1_Clock_CMD_DISABLE_SHIFT      (30u)
#define Keypad_1_Clock_CMD_ENABLE_SHIFT       (31u)

#define Keypad_1_Clock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Keypad_1_Clock_CMD_DISABLE_SHIFT))
#define Keypad_1_Clock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Keypad_1_Clock_CMD_ENABLE_SHIFT))

#define Keypad_1_Clock_DIV_FRAC_MASK  (0x000000F8u)
#define Keypad_1_Clock_DIV_FRAC_SHIFT (3u)
#define Keypad_1_Clock_DIV_INT_MASK   (0xFFFFFF00u)
#define Keypad_1_Clock_DIV_INT_SHIFT  (8u)

#else 

#define Keypad_1_Clock_DIV_REG        (*(reg32 *)Keypad_1_Clock__REGISTER)
#define Keypad_1_Clock_ENABLE_REG     Keypad_1_Clock_DIV_REG
#define Keypad_1_Clock_DIV_FRAC_MASK  Keypad_1_Clock__FRAC_MASK
#define Keypad_1_Clock_DIV_FRAC_SHIFT (16u)
#define Keypad_1_Clock_DIV_INT_MASK   Keypad_1_Clock__DIVIDER_MASK
#define Keypad_1_Clock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Keypad_1_Clock_H) */

/* [] END OF FILE */
