/*******************************************************************************
* File Name: i2c_I2C.c
* Version 3.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  I2C mode.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "i2c_PVT.h"
#include "i2c_I2C_PVT.h"


/***************************************
*      I2C Private Vars
***************************************/

volatile uint8 i2c_state;  /* Current state of I2C FSM */

#if(i2c_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    /* Constant configuration of I2C */
    const i2c_I2C_INIT_STRUCT i2c_configI2C =
    {
        i2c_I2C_MODE,
        i2c_I2C_OVS_FACTOR_LOW,
        i2c_I2C_OVS_FACTOR_HIGH,
        i2c_I2C_MEDIAN_FILTER_ENABLE,
        i2c_I2C_SLAVE_ADDRESS,
        i2c_I2C_SLAVE_ADDRESS_MASK,
        i2c_I2C_ACCEPT_ADDRESS,
        i2c_I2C_WAKE_ENABLE,
        i2c_I2C_BYTE_MODE_ENABLE,
        i2c_I2C_DATA_RATE,
        i2c_I2C_ACCEPT_GENERAL_CALL,
    };

    /*******************************************************************************
    * Function Name: i2c_I2CInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for I2C operation.
    *
    * Parameters:
    *  config:  Pointer to a structure that contains the following ordered list of
    *           fields. These fields match the selections available in the
    *           customizer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void i2c_I2CInit(const i2c_I2C_INIT_STRUCT *config)
    {
        uint32 medianFilter;
        uint32 locEnableWake;

        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            i2c_SetPins(i2c_SCB_MODE_I2C, i2c_DUMMY_PARAM,
                                     i2c_DUMMY_PARAM);

            /* Store internal configuration */
            i2c_scbMode       = (uint8) i2c_SCB_MODE_I2C;
            i2c_scbEnableWake = (uint8) config->enableWake;
            i2c_scbEnableIntr = (uint8) i2c_SCB_IRQ_INTERNAL;

            i2c_mode          = (uint8) config->mode;
            i2c_acceptAddr    = (uint8) config->acceptAddr;

        #if (i2c_CY_SCBIP_V0)
            /* Adjust SDA filter settings. Ticket ID#150521 */
            i2c_SET_I2C_CFG_SDA_FILT_TRIM(i2c_EC_AM_I2C_CFG_SDA_FILT_TRIM);
        #endif /* (i2c_CY_SCBIP_V0) */

            /* Adjust AF and DF filter settings. Ticket ID#176179 */
            if (((i2c_I2C_MODE_SLAVE != config->mode) &&
                 (config->dataRate <= i2c_I2C_DATA_RATE_FS_MODE_MAX)) ||
                 (i2c_I2C_MODE_SLAVE == config->mode))
            {
                /* AF = 1, DF = 0 */
                i2c_I2C_CFG_ANALOG_FITER_ENABLE;
                medianFilter = i2c_DIGITAL_FILTER_DISABLE;
            }
            else
            {
                /* AF = 0, DF = 1 */
                i2c_I2C_CFG_ANALOG_FITER_DISABLE;
                medianFilter = i2c_DIGITAL_FILTER_ENABLE;
            }

        #if (!i2c_CY_SCBIP_V0)
            locEnableWake = (i2c_I2C_MULTI_MASTER_SLAVE) ? (0u) : (config->enableWake);
        #else
            locEnableWake = config->enableWake;
        #endif /* (!i2c_CY_SCBIP_V0) */

            /* Configure I2C interface */
            i2c_CTRL_REG     = i2c_GET_CTRL_BYTE_MODE  (config->enableByteMode) |
                                            i2c_GET_CTRL_ADDR_ACCEPT(config->acceptAddr)     |
                                            i2c_GET_CTRL_EC_AM_MODE (locEnableWake);

            i2c_I2C_CTRL_REG = i2c_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                    i2c_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)                          |
                    i2c_GET_I2C_CTRL_S_GENERAL_IGNORE((uint32)(0u == config->acceptGeneralAddr))    |
                    i2c_GET_I2C_CTRL_SL_MSTR_MODE  (config->mode);

            /* Configure RX direction */
            i2c_RX_CTRL_REG      = i2c_GET_RX_CTRL_MEDIAN(medianFilter) |
                                                i2c_I2C_RX_CTRL;
            i2c_RX_FIFO_CTRL_REG = i2c_CLEAR_REG;

            /* Set default address and mask */
            i2c_RX_MATCH_REG    = ((i2c_I2C_SLAVE) ?
                                                (i2c_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                                 i2c_GET_RX_MATCH_MASK(config->slaveAddrMask)) :
                                                (i2c_CLEAR_REG));


            /* Configure TX direction */
            i2c_TX_CTRL_REG      = i2c_I2C_TX_CTRL;
            i2c_TX_FIFO_CTRL_REG = i2c_CLEAR_REG;

            /* Configure interrupt with I2C handler but do not enable it */
            CyIntDisable    (i2c_ISR_NUMBER);
            CyIntSetPriority(i2c_ISR_NUMBER, i2c_ISR_PRIORITY);
            (void) CyIntSetVector(i2c_ISR_NUMBER, &i2c_I2C_ISR);

            /* Configure interrupt sources */
        #if(!i2c_CY_SCBIP_V1)
            i2c_INTR_SPI_EC_MASK_REG = i2c_NO_INTR_SOURCES;
        #endif /* (!i2c_CY_SCBIP_V1) */

            i2c_INTR_I2C_EC_MASK_REG = i2c_NO_INTR_SOURCES;
            i2c_INTR_RX_MASK_REG     = i2c_NO_INTR_SOURCES;
            i2c_INTR_TX_MASK_REG     = i2c_NO_INTR_SOURCES;

            i2c_INTR_SLAVE_MASK_REG  = ((i2c_I2C_SLAVE) ?
                            (i2c_GET_INTR_SLAVE_I2C_GENERAL(config->acceptGeneralAddr) |
                             i2c_I2C_INTR_SLAVE_MASK) : (i2c_CLEAR_REG));

            i2c_INTR_MASTER_MASK_REG = ((i2c_I2C_MASTER) ?
                                                     (i2c_I2C_INTR_MASTER_MASK) :
                                                     (i2c_CLEAR_REG));

            /* Configure global variables */
            i2c_state = i2c_I2C_FSM_IDLE;

            /* Internal slave variables */
            i2c_slStatus        = 0u;
            i2c_slRdBufIndex    = 0u;
            i2c_slWrBufIndex    = 0u;
            i2c_slOverFlowCount = 0u;

            /* Internal master variables */
            i2c_mstrStatus     = 0u;
            i2c_mstrRdBufIndex = 0u;
            i2c_mstrWrBufIndex = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: i2c_I2CInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for the I2C operation.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void i2c_I2CInit(void)
    {
    #if(i2c_CY_SCBIP_V0)
        /* Adjust SDA filter settings. Ticket ID#150521 */
        i2c_SET_I2C_CFG_SDA_FILT_TRIM(i2c_EC_AM_I2C_CFG_SDA_FILT_TRIM);
    #endif /* (i2c_CY_SCBIP_V0) */

        /* Adjust AF and DF filter settings. Ticket ID#176179 */
        i2c_I2C_CFG_ANALOG_FITER_ENABLE_ADJ;

        /* Configure I2C interface */
        i2c_CTRL_REG     = i2c_I2C_DEFAULT_CTRL;
        i2c_I2C_CTRL_REG = i2c_I2C_DEFAULT_I2C_CTRL;

        /* Configure RX direction */
        i2c_RX_CTRL_REG      = i2c_I2C_DEFAULT_RX_CTRL;
        i2c_RX_FIFO_CTRL_REG = i2c_I2C_DEFAULT_RX_FIFO_CTRL;

        /* Set default address and mask */
        i2c_RX_MATCH_REG     = i2c_I2C_DEFAULT_RX_MATCH;

        /* Configure TX direction */
        i2c_TX_CTRL_REG      = i2c_I2C_DEFAULT_TX_CTRL;
        i2c_TX_FIFO_CTRL_REG = i2c_I2C_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with I2C handler but do not enable it */
        CyIntDisable    (i2c_ISR_NUMBER);
        CyIntSetPriority(i2c_ISR_NUMBER, i2c_ISR_PRIORITY);
    #if(!i2c_I2C_EXTERN_INTR_HANDLER)
        (void) CyIntSetVector(i2c_ISR_NUMBER, &i2c_I2C_ISR);
    #endif /* (i2c_I2C_EXTERN_INTR_HANDLER) */

        /* Configure interrupt sources */
    #if(!i2c_CY_SCBIP_V1)
        i2c_INTR_SPI_EC_MASK_REG = i2c_I2C_DEFAULT_INTR_SPI_EC_MASK;
    #endif /* (!i2c_CY_SCBIP_V1) */

        i2c_INTR_I2C_EC_MASK_REG = i2c_I2C_DEFAULT_INTR_I2C_EC_MASK;
        i2c_INTR_SLAVE_MASK_REG  = i2c_I2C_DEFAULT_INTR_SLAVE_MASK;
        i2c_INTR_MASTER_MASK_REG = i2c_I2C_DEFAULT_INTR_MASTER_MASK;
        i2c_INTR_RX_MASK_REG     = i2c_I2C_DEFAULT_INTR_RX_MASK;
        i2c_INTR_TX_MASK_REG     = i2c_I2C_DEFAULT_INTR_TX_MASK;

        /* Configure global variables */
        i2c_state = i2c_I2C_FSM_IDLE;

    #if(i2c_I2C_SLAVE)
        /* Internal slave variable */
        i2c_slStatus        = 0u;
        i2c_slRdBufIndex    = 0u;
        i2c_slWrBufIndex    = 0u;
        i2c_slOverFlowCount = 0u;
    #endif /* (i2c_I2C_SLAVE) */

    #if(i2c_I2C_MASTER)
    /* Internal master variable */
        i2c_mstrStatus     = 0u;
        i2c_mstrRdBufIndex = 0u;
        i2c_mstrWrBufIndex = 0u;
    #endif /* (i2c_I2C_MASTER) */
    }
#endif /* (i2c_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: i2c_I2CStop
********************************************************************************
*
* Summary:
*  Resets the I2C FSM into the default state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void i2c_I2CStop(void)
{
    i2c_state = i2c_I2C_FSM_IDLE;
}


#if(i2c_I2C_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: i2c_I2CSaveConfig
    ********************************************************************************
    *
    * Summary:
    *  Enables i2c_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void i2c_I2CSaveConfig(void)
    {
    #if (!i2c_CY_SCBIP_V0)
        #if (i2c_I2C_MULTI_MASTER_SLAVE_CONST && i2c_I2C_WAKE_ENABLE_CONST)
            /* Enable externally clocked address match if it was not enabled before.
            * This applicable only for Multi-Master-Slave. Ticket ID#192742 */
            if (0u == (i2c_CTRL_REG & i2c_CTRL_EC_AM_MODE))
            {
                /* Enable external address match logic */
                i2c_Stop();
                i2c_CTRL_REG |= i2c_CTRL_EC_AM_MODE;
                i2c_Enable();
            }
        #endif /* (i2c_I2C_MULTI_MASTER_SLAVE_CONST) */

        #if (i2c_SCB_CLK_INTERNAL)
            /* Disable clock to internal address match logic. Ticket ID#187931 */
            i2c_SCBCLK_Stop();
        #endif /* (i2c_SCB_CLK_INTERNAL) */
    #endif /* (!i2c_CY_SCBIP_V0) */

        i2c_SetI2CExtClkInterruptMode(i2c_INTR_I2C_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: i2c_I2CRestoreConfig
    ********************************************************************************
    *
    * Summary:
    *  Disables i2c_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void i2c_I2CRestoreConfig(void)
    {
        /* Disable wakeup interrupt on address match */
        i2c_SetI2CExtClkInterruptMode(i2c_NO_INTR_SOURCES);

    #if (!i2c_CY_SCBIP_V0)
        #if (i2c_SCB_CLK_INTERNAL)
            /* Enable clock to internal address match logic. Ticket ID#187931 */
            i2c_SCBCLK_Start();
        #endif /* (i2c_SCB_CLK_INTERNAL) */
    #endif /* (!i2c_CY_SCBIP_V0) */
    }
#endif /* (i2c_I2C_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
