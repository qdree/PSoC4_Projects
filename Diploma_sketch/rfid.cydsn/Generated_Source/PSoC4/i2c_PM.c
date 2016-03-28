/*******************************************************************************
* File Name: i2c_PM.c
* Version 3.10
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "i2c.h"
#include "i2c_PVT.h"

#if(i2c_SCB_MODE_I2C_INC)
    #include "i2c_I2C_PVT.h"
#endif /* (i2c_SCB_MODE_I2C_INC) */

#if(i2c_SCB_MODE_EZI2C_INC)
    #include "i2c_EZI2C_PVT.h"
#endif /* (i2c_SCB_MODE_EZI2C_INC) */

#if(i2c_SCB_MODE_SPI_INC || i2c_SCB_MODE_UART_INC)
    #include "i2c_SPI_UART_PVT.h"
#endif /* (i2c_SCB_MODE_SPI_INC || i2c_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(i2c_SCB_MODE_UNCONFIG_CONST_CFG || \
   (i2c_SCB_MODE_I2C_CONST_CFG   && (!i2c_I2C_WAKE_ENABLE_CONST))   || \
   (i2c_SCB_MODE_EZI2C_CONST_CFG && (!i2c_EZI2C_WAKE_ENABLE_CONST)) || \
   (i2c_SCB_MODE_SPI_CONST_CFG   && (!i2c_SPI_WAKE_ENABLE_CONST))   || \
   (i2c_SCB_MODE_UART_CONST_CFG  && (!i2c_UART_WAKE_ENABLE_CONST)))

    i2c_BACKUP_STRUCT i2c_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: i2c_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void i2c_Sleep(void)
{
#if(i2c_SCB_MODE_UNCONFIG_CONST_CFG)

    if(i2c_SCB_WAKE_ENABLE_CHECK)
    {
        if(i2c_SCB_MODE_I2C_RUNTM_CFG)
        {
            i2c_I2CSaveConfig();
        }
        else if(i2c_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            i2c_EzI2CSaveConfig();
        }
    #if(!i2c_CY_SCBIP_V1)
        else if(i2c_SCB_MODE_SPI_RUNTM_CFG)
        {
            i2c_SpiSaveConfig();
        }
        else if(i2c_SCB_MODE_UART_RUNTM_CFG)
        {
            i2c_UartSaveConfig();
        }
    #endif /* (!i2c_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        i2c_backup.enableState = (uint8) i2c_GET_CTRL_ENABLED;

        if(0u != i2c_backup.enableState)
        {
            i2c_Stop();
        }
    }

#else

    #if (i2c_SCB_MODE_I2C_CONST_CFG && i2c_I2C_WAKE_ENABLE_CONST)
        i2c_I2CSaveConfig();

    #elif (i2c_SCB_MODE_EZI2C_CONST_CFG && i2c_EZI2C_WAKE_ENABLE_CONST)
        i2c_EzI2CSaveConfig();

    #elif (i2c_SCB_MODE_SPI_CONST_CFG && i2c_SPI_WAKE_ENABLE_CONST)
        i2c_SpiSaveConfig();

    #elif (i2c_SCB_MODE_UART_CONST_CFG && i2c_UART_WAKE_ENABLE_CONST)
        i2c_UartSaveConfig();

    #else

        i2c_backup.enableState = (uint8) i2c_GET_CTRL_ENABLED;

        if(0u != i2c_backup.enableState)
        {
            i2c_Stop();
        }

    #endif /* defined (i2c_SCB_MODE_I2C_CONST_CFG) && (i2c_I2C_WAKE_ENABLE_CONST) */

#endif /* (i2c_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: i2c_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void i2c_Wakeup(void)
{
#if(i2c_SCB_MODE_UNCONFIG_CONST_CFG)

    if(i2c_SCB_WAKE_ENABLE_CHECK)
    {
        if(i2c_SCB_MODE_I2C_RUNTM_CFG)
        {
            i2c_I2CRestoreConfig();
        }
        else if(i2c_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            i2c_EzI2CRestoreConfig();
        }
    #if(!i2c_CY_SCBIP_V1)
        else if(i2c_SCB_MODE_SPI_RUNTM_CFG)
        {
            i2c_SpiRestoreConfig();
        }
        else if(i2c_SCB_MODE_UART_RUNTM_CFG)
        {
            i2c_UartRestoreConfig();
        }
    #endif /* (!i2c_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != i2c_backup.enableState)
        {
            i2c_Enable();
        }
    }

#else

    #if (i2c_SCB_MODE_I2C_CONST_CFG  && i2c_I2C_WAKE_ENABLE_CONST)
        i2c_I2CRestoreConfig();

    #elif (i2c_SCB_MODE_EZI2C_CONST_CFG && i2c_EZI2C_WAKE_ENABLE_CONST)
        i2c_EzI2CRestoreConfig();

    #elif (i2c_SCB_MODE_SPI_CONST_CFG && i2c_SPI_WAKE_ENABLE_CONST)
        i2c_SpiRestoreConfig();

    #elif (i2c_SCB_MODE_UART_CONST_CFG && i2c_UART_WAKE_ENABLE_CONST)
        i2c_UartRestoreConfig();

    #else

        if(0u != i2c_backup.enableState)
        {
            i2c_Enable();
        }

    #endif /* (i2c_I2C_WAKE_ENABLE_CONST) */

#endif /* (i2c_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
