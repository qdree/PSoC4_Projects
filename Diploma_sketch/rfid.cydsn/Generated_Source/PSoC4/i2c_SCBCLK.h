/*******************************************************************************
* File Name: i2c_SCBCLK.h
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

#if !defined(CY_CLOCK_i2c_SCBCLK_H)
#define CY_CLOCK_i2c_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void i2c_SCBCLK_StartEx(uint32 alignClkDiv);
#define i2c_SCBCLK_Start() \
    i2c_SCBCLK_StartEx(i2c_SCBCLK__PA_DIV_ID)

#else

void i2c_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void i2c_SCBCLK_Stop(void);

void i2c_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 i2c_SCBCLK_GetDividerRegister(void);
uint8  i2c_SCBCLK_GetFractionalDividerRegister(void);

#define i2c_SCBCLK_Enable()                         i2c_SCBCLK_Start()
#define i2c_SCBCLK_Disable()                        i2c_SCBCLK_Stop()
#define i2c_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    i2c_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define i2c_SCBCLK_SetDivider(clkDivider)           i2c_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define i2c_SCBCLK_SetDividerValue(clkDivider)      i2c_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define i2c_SCBCLK_DIV_ID     i2c_SCBCLK__DIV_ID

#define i2c_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define i2c_SCBCLK_CTRL_REG   (*(reg32 *)i2c_SCBCLK__CTRL_REGISTER)
#define i2c_SCBCLK_DIV_REG    (*(reg32 *)i2c_SCBCLK__DIV_REGISTER)

#define i2c_SCBCLK_CMD_DIV_SHIFT          (0u)
#define i2c_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define i2c_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define i2c_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define i2c_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << i2c_SCBCLK_CMD_DISABLE_SHIFT))
#define i2c_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << i2c_SCBCLK_CMD_ENABLE_SHIFT))

#define i2c_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define i2c_SCBCLK_DIV_FRAC_SHIFT (3u)
#define i2c_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define i2c_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define i2c_SCBCLK_DIV_REG        (*(reg32 *)i2c_SCBCLK__REGISTER)
#define i2c_SCBCLK_ENABLE_REG     i2c_SCBCLK_DIV_REG
#define i2c_SCBCLK_DIV_FRAC_MASK  i2c_SCBCLK__FRAC_MASK
#define i2c_SCBCLK_DIV_FRAC_SHIFT (16u)
#define i2c_SCBCLK_DIV_INT_MASK   i2c_SCBCLK__DIVIDER_MASK
#define i2c_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_i2c_SCBCLK_H) */

/* [] END OF FILE */
