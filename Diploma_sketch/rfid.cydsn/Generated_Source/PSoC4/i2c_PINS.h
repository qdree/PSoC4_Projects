/*******************************************************************************
* File Name: i2c_PINS.h
* Version 3.10
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_i2c_H)
#define CY_SCB_PINS_i2c_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define i2c_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define i2c_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define i2c_REMOVE_TX_SDA_MISO_PIN      (1u)
#define i2c_REMOVE_SCLK_PIN      (1u)
#define i2c_REMOVE_SS0_PIN      (1u)
#define i2c_REMOVE_SS1_PIN                 (1u)
#define i2c_REMOVE_SS2_PIN                 (1u)
#define i2c_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define i2c_REMOVE_I2C_PINS                (0u)
#define i2c_REMOVE_SPI_MASTER_PINS         (1u)
#define i2c_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define i2c_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define i2c_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define i2c_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define i2c_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define i2c_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define i2c_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define i2c_REMOVE_SPI_SLAVE_PINS          (1u)
#define i2c_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define i2c_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define i2c_REMOVE_UART_TX_PIN             (1u)
#define i2c_REMOVE_UART_RX_TX_PIN          (1u)
#define i2c_REMOVE_UART_RX_PIN             (1u)
#define i2c_REMOVE_UART_RX_WAKE_PIN        (1u)
#define i2c_REMOVE_UART_RTS_PIN            (1u)
#define i2c_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define i2c_RX_WAKE_SCL_MOSI_PIN (0u == i2c_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define i2c_RX_SCL_MOSI_PIN     (0u == i2c_REMOVE_RX_SCL_MOSI_PIN)
#define i2c_TX_SDA_MISO_PIN     (0u == i2c_REMOVE_TX_SDA_MISO_PIN)
#define i2c_SCLK_PIN     (0u == i2c_REMOVE_SCLK_PIN)
#define i2c_SS0_PIN     (0u == i2c_REMOVE_SS0_PIN)
#define i2c_SS1_PIN                (0u == i2c_REMOVE_SS1_PIN)
#define i2c_SS2_PIN                (0u == i2c_REMOVE_SS2_PIN)
#define i2c_SS3_PIN                (0u == i2c_REMOVE_SS3_PIN)

/* Mode defined pins */
#define i2c_I2C_PINS               (0u == i2c_REMOVE_I2C_PINS)
#define i2c_SPI_MASTER_PINS        (0u == i2c_REMOVE_SPI_MASTER_PINS)
#define i2c_SPI_MASTER_SCLK_PIN    (0u == i2c_REMOVE_SPI_MASTER_SCLK_PIN)
#define i2c_SPI_MASTER_MOSI_PIN    (0u == i2c_REMOVE_SPI_MASTER_MOSI_PIN)
#define i2c_SPI_MASTER_MISO_PIN    (0u == i2c_REMOVE_SPI_MASTER_MISO_PIN)
#define i2c_SPI_MASTER_SS0_PIN     (0u == i2c_REMOVE_SPI_MASTER_SS0_PIN)
#define i2c_SPI_MASTER_SS1_PIN     (0u == i2c_REMOVE_SPI_MASTER_SS1_PIN)
#define i2c_SPI_MASTER_SS2_PIN     (0u == i2c_REMOVE_SPI_MASTER_SS2_PIN)
#define i2c_SPI_MASTER_SS3_PIN     (0u == i2c_REMOVE_SPI_MASTER_SS3_PIN)
#define i2c_SPI_SLAVE_PINS         (0u == i2c_REMOVE_SPI_SLAVE_PINS)
#define i2c_SPI_SLAVE_MOSI_PIN     (0u == i2c_REMOVE_SPI_SLAVE_MOSI_PIN)
#define i2c_SPI_SLAVE_MISO_PIN     (0u == i2c_REMOVE_SPI_SLAVE_MISO_PIN)
#define i2c_UART_TX_PIN            (0u == i2c_REMOVE_UART_TX_PIN)
#define i2c_UART_RX_TX_PIN         (0u == i2c_REMOVE_UART_RX_TX_PIN)
#define i2c_UART_RX_PIN            (0u == i2c_REMOVE_UART_RX_PIN)
#define i2c_UART_RX_WAKE_PIN       (0u == i2c_REMOVE_UART_RX_WAKE_PIN)
#define i2c_UART_RTS_PIN           (0u == i2c_REMOVE_UART_RTS_PIN)
#define i2c_UART_CTS_PIN           (0u == i2c_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (i2c_RX_WAKE_SCL_MOSI_PIN)
    #include "i2c_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (i2c_RX_SCL_MOSI) */

#if (i2c_RX_SCL_MOSI_PIN)
    #include "i2c_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (i2c_RX_SCL_MOSI) */

#if (i2c_TX_SDA_MISO_PIN)
    #include "i2c_uart_tx_i2c_sda_spi_miso.h"
#endif /* (i2c_TX_SDA_MISO) */

#if (i2c_SCLK_PIN)
    #include "i2c_spi_sclk.h"
#endif /* (i2c_SCLK) */

#if (i2c_SS0_PIN)
    #include "i2c_spi_ss0.h"
#endif /* (i2c_SS0_PIN) */

#if (i2c_SS1_PIN)
    #include "i2c_spi_ss1.h"
#endif /* (i2c_SS1_PIN) */

#if (i2c_SS2_PIN)
    #include "i2c_spi_ss2.h"
#endif /* (i2c_SS2_PIN) */

#if (i2c_SS3_PIN)
    #include "i2c_spi_ss3.h"
#endif /* (i2c_SS3_PIN) */

#if (i2c_I2C_PINS)
    #include "i2c_scl.h"
    #include "i2c_sda.h"
#endif /* (i2c_I2C_PINS) */

#if (i2c_SPI_MASTER_PINS)
#if (i2c_SPI_MASTER_SCLK_PIN)
    #include "i2c_sclk_m.h"
#endif /* (i2c_SPI_MASTER_SCLK_PIN) */

#if (i2c_SPI_MASTER_MOSI_PIN)
    #include "i2c_mosi_m.h"
#endif /* (i2c_SPI_MASTER_MOSI_PIN) */

#if (i2c_SPI_MASTER_MISO_PIN)
    #include "i2c_miso_m.h"
#endif /*(i2c_SPI_MASTER_MISO_PIN) */
#endif /* (i2c_SPI_MASTER_PINS) */

#if (i2c_SPI_SLAVE_PINS)
    #include "i2c_sclk_s.h"
    #include "i2c_ss_s.h"

#if (i2c_SPI_SLAVE_MOSI_PIN)
    #include "i2c_mosi_s.h"
#endif /* (i2c_SPI_SLAVE_MOSI_PIN) */

#if (i2c_SPI_SLAVE_MISO_PIN)
    #include "i2c_miso_s.h"
#endif /*(i2c_SPI_SLAVE_MISO_PIN) */
#endif /* (i2c_SPI_SLAVE_PINS) */

#if (i2c_SPI_MASTER_SS0_PIN)
    #include "i2c_ss0_m.h"
#endif /* (i2c_SPI_MASTER_SS0_PIN) */

#if (i2c_SPI_MASTER_SS1_PIN)
    #include "i2c_ss1_m.h"
#endif /* (i2c_SPI_MASTER_SS1_PIN) */

#if (i2c_SPI_MASTER_SS2_PIN)
    #include "i2c_ss2_m.h"
#endif /* (i2c_SPI_MASTER_SS2_PIN) */

#if (i2c_SPI_MASTER_SS3_PIN)
    #include "i2c_ss3_m.h"
#endif /* (i2c_SPI_MASTER_SS3_PIN) */

#if (i2c_UART_TX_PIN)
    #include "i2c_tx.h"
#endif /* (i2c_UART_TX_PIN) */

#if (i2c_UART_RX_TX_PIN)
    #include "i2c_rx_tx.h"
#endif /* (i2c_UART_RX_TX_PIN) */

#if (i2c_UART_RX_PIN)
    #include "i2c_rx.h"
#endif /* (i2c_UART_RX_PIN) */

#if (i2c_UART_RX_WAKE_PIN)
    #include "i2c_rx_wake.h"
#endif /* (i2c_UART_RX_WAKE_PIN) */

#if (i2c_UART_RTS_PIN)
    #include "i2c_rts.h"
#endif /* (i2c_UART_RTS_PIN) */

#if (i2c_UART_CTS_PIN)
    #include "i2c_cts.h"
#endif /* (i2c_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (i2c_RX_WAKE_SCL_MOSI_PIN)
    #define i2c_RX_WAKE_SCL_MOSI_HSIOM_REG \
                            (*(reg32 *) i2c_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_RX_WAKE_SCL_MOSI_HSIOM_PTR \
                            ( (reg32 *) i2c_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_RX_WAKE_SCL_MOSI_HSIOM_MASK \
                            (i2c_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define i2c_RX_WAKE_SCL_MOSI_HSIOM_POS \
                            (i2c_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)

    #define i2c_RX_WAKE_SCL_MOSI_INTCFG_REG \
                            (*(reg32 *) i2c_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define i2c_RX_WAKE_SCL_MOSI_INTCFG_PTR \
                            ( (reg32 *) i2c_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define i2c_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (i2c_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define i2c_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK \
                            ((uint32) i2c_INTCFG_TYPE_MASK << \
                                      i2c_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#endif /* (i2c_RX_WAKE_SCL_MOSI_PIN) */

#if (i2c_RX_SCL_MOSI_PIN)
    #define i2c_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) i2c_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) i2c_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_RX_SCL_MOSI_HSIOM_MASK  (i2c_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define i2c_RX_SCL_MOSI_HSIOM_POS   (i2c_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
#endif /* (i2c_RX_SCL_MOSI_PIN) */

#if (i2c_TX_SDA_MISO_PIN)
    #define i2c_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) i2c_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define i2c_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) i2c_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define i2c_TX_SDA_MISO_HSIOM_MASK  (i2c_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define i2c_TX_SDA_MISO_HSIOM_POS   (i2c_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
#endif /* (i2c_TX_SDA_MISO_PIN) */

#if (i2c_SCLK_PIN)
    #define i2c_SCLK_HSIOM_REG   (*(reg32 *) i2c_spi_sclk__0__HSIOM)
    #define i2c_SCLK_HSIOM_PTR   ( (reg32 *) i2c_spi_sclk__0__HSIOM)
    #define i2c_SCLK_HSIOM_MASK  (i2c_spi_sclk__0__HSIOM_MASK)
    #define i2c_SCLK_HSIOM_POS   (i2c_spi_sclk__0__HSIOM_SHIFT)
#endif /* (i2c_SCLK_PIN) */

#if (i2c_SS0_PIN)
    #define i2c_SS0_HSIOM_REG   (*(reg32 *) i2c_spi_ss0__0__HSIOM)
    #define i2c_SS0_HSIOM_PTR   ( (reg32 *) i2c_spi_ss0__0__HSIOM)
    #define i2c_SS0_HSIOM_MASK  (i2c_spi_ss0__0__HSIOM_MASK)
    #define i2c_SS0_HSIOM_POS   (i2c_spi_ss0__0__HSIOM_SHIFT)
#endif /* (i2c_SS0_PIN) */

#if (i2c_SS1_PIN)
    #define i2c_SS1_HSIOM_REG      (*(reg32 *) i2c_spi_ss1__0__HSIOM)
    #define i2c_SS1_HSIOM_PTR      ( (reg32 *) i2c_spi_ss1__0__HSIOM)
    #define i2c_SS1_HSIOM_MASK     (i2c_spi_ss1__0__HSIOM_MASK)
    #define i2c_SS1_HSIOM_POS      (i2c_spi_ss1__0__HSIOM_SHIFT)
#endif /* (i2c_SS1_PIN) */

#if (i2c_SS2_PIN)
    #define i2c_SS2_HSIOM_REG     (*(reg32 *) i2c_spi_ss2__0__HSIOM)
    #define i2c_SS2_HSIOM_PTR     ( (reg32 *) i2c_spi_ss2__0__HSIOM)
    #define i2c_SS2_HSIOM_MASK    (i2c_spi_ss2__0__HSIOM_MASK)
    #define i2c_SS2_HSIOM_POS     (i2c_spi_ss2__0__HSIOM_SHIFT)
#endif /* (i2c_SS2_PIN) */

#if (i2c_SS3_PIN)
    #define i2c_SS3_HSIOM_REG     (*(reg32 *) i2c_spi_ss3__0__HSIOM)
    #define i2c_SS3_HSIOM_PTR     ( (reg32 *) i2c_spi_ss3__0__HSIOM)
    #define i2c_SS3_HSIOM_MASK    (i2c_spi_ss3__0__HSIOM_MASK)
    #define i2c_SS3_HSIOM_POS     (i2c_spi_ss3__0__HSIOM_SHIFT)
#endif /* (i2c_SS3_PIN) */

#if (i2c_I2C_PINS)
    #define i2c_SCL_HSIOM_REG     (*(reg32 *) i2c_scl__0__HSIOM)
    #define i2c_SCL_HSIOM_PTR     ( (reg32 *) i2c_scl__0__HSIOM)
    #define i2c_SCL_HSIOM_MASK    (i2c_scl__0__HSIOM_MASK)
    #define i2c_SCL_HSIOM_POS     (i2c_scl__0__HSIOM_SHIFT)

    #define i2c_SDA_HSIOM_REG     (*(reg32 *) i2c_sda__0__HSIOM)
    #define i2c_SDA_HSIOM_PTR     ( (reg32 *) i2c_sda__0__HSIOM)
    #define i2c_SDA_HSIOM_MASK    (i2c_sda__0__HSIOM_MASK)
    #define i2c_SDA_HSIOM_POS     (i2c_sda__0__HSIOM_SHIFT)
#endif /* (i2c_I2C_PINS) */

#if (i2c_SPI_MASTER_SCLK_PIN)
    #define i2c_SCLK_M_HSIOM_REG   (*(reg32 *) i2c_sclk_m__0__HSIOM)
    #define i2c_SCLK_M_HSIOM_PTR   ( (reg32 *) i2c_sclk_m__0__HSIOM)
    #define i2c_SCLK_M_HSIOM_MASK  (i2c_sclk_m__0__HSIOM_MASK)
    #define i2c_SCLK_M_HSIOM_POS   (i2c_sclk_m__0__HSIOM_SHIFT)
#endif /* (i2c_SPI_MASTER_SCLK_PIN) */

#if (i2c_SPI_MASTER_SS0_PIN)
    #define i2c_SS0_M_HSIOM_REG    (*(reg32 *) i2c_ss0_m__0__HSIOM)
    #define i2c_SS0_M_HSIOM_PTR    ( (reg32 *) i2c_ss0_m__0__HSIOM)
    #define i2c_SS0_M_HSIOM_MASK   (i2c_ss0_m__0__HSIOM_MASK)
    #define i2c_SS0_M_HSIOM_POS    (i2c_ss0_m__0__HSIOM_SHIFT)
#endif /* (i2c_SPI_MASTER_SS0_PIN) */

#if (i2c_SPI_MASTER_SS1_PIN)
    #define i2c_SS1_M_HSIOM_REG    (*(reg32 *) i2c_ss1_m__0__HSIOM)
    #define i2c_SS1_M_HSIOM_PTR    ( (reg32 *) i2c_ss1_m__0__HSIOM)
    #define i2c_SS1_M_HSIOM_MASK   (i2c_ss1_m__0__HSIOM_MASK)
    #define i2c_SS1_M_HSIOM_POS    (i2c_ss1_m__0__HSIOM_SHIFT)
#endif /* (i2c_SPI_MASTER_SS1_PIN) */

#if (i2c_SPI_MASTER_SS2_PIN)
    #define i2c_SS2_M_HSIOM_REG    (*(reg32 *) i2c_ss2_m__0__HSIOM)
    #define i2c_SS2_M_HSIOM_PTR    ( (reg32 *) i2c_ss2_m__0__HSIOM)
    #define i2c_SS2_M_HSIOM_MASK   (i2c_ss2_m__0__HSIOM_MASK)
    #define i2c_SS2_M_HSIOM_POS    (i2c_ss2_m__0__HSIOM_SHIFT)
#endif /* (i2c_SPI_MASTER_SS2_PIN) */

#if (i2c_SPI_MASTER_SS3_PIN)
    #define i2c_SS3_M_HSIOM_REG    (*(reg32 *) i2c_ss3_m__0__HSIOM)
    #define i2c_SS3_M_HSIOM_PTR    ( (reg32 *) i2c_ss3_m__0__HSIOM)
    #define i2c_SS3_M_HSIOM_MASK   (i2c_ss3_m__0__HSIOM_MASK)
    #define i2c_SS3_M_HSIOM_POS    (i2c_ss3_m__0__HSIOM_SHIFT)
#endif /* (i2c_SPI_MASTER_SS3_PIN) */

#if (i2c_UART_TX_PIN)
    #define i2c_TX_HSIOM_REG   (*(reg32 *) i2c_tx__0__HSIOM)
    #define i2c_TX_HSIOM_PTR   ( (reg32 *) i2c_tx_0__HSIOM)
    #define i2c_TX_HSIOM_MASK  (i2c_tx__0__HSIOM_MASK)
    #define i2c_TX_HSIOM_POS   (i2c_tx__0__HSIOM_SHIFT)
#endif /* (i2c_UART_TX_PIN) */

#if (i2c_UART_RTS_PIN)
    #define i2c_RTS_HSIOM_REG  (*(reg32 *) i2c_rts__0__HSIOM)
    #define i2c_RTS_HSIOM_PTR  ( (reg32 *) i2c_rts__0__HSIOM)
    #define i2c_RTS_HSIOM_MASK (i2c_rts__0__HSIOM_MASK)
    #define i2c_RTS_HSIOM_POS  (i2c_rts__0__HSIOM_SHIFT)
#endif /* (i2c_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define i2c_HSIOM_DEF_SEL      (0x00u)
#define i2c_HSIOM_GPIO_SEL     (0x00u)
#define i2c_HSIOM_UART_SEL     (0x09u)
#define i2c_HSIOM_I2C_SEL      (0x0Eu)
#define i2c_HSIOM_SPI_SEL      (0x0Fu)

#define i2c_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define i2c_RX_SCL_MOSI_PIN_INDEX       (0u)
#define i2c_TX_SDA_MISO_PIN_INDEX       (1u)
#define i2c_SCLK_PIN_INDEX       (2u)
#define i2c_SS0_PIN_INDEX       (3u)
#define i2c_SS1_PIN_INDEX                  (4u)
#define i2c_SS2_PIN_INDEX                  (5u)
#define i2c_SS3_PIN_INDEX                  (6u)

#define i2c_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << i2c_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define i2c_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << i2c_RX_SCL_MOSI_PIN_INDEX)
#define i2c_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << i2c_TX_SDA_MISO_PIN_INDEX)
#define i2c_SCLK_PIN_MASK     ((uint32) 0x01u << i2c_SCLK_PIN_INDEX)
#define i2c_SS0_PIN_MASK     ((uint32) 0x01u << i2c_SS0_PIN_INDEX)
#define i2c_SS1_PIN_MASK                ((uint32) 0x01u << i2c_SS1_PIN_INDEX)
#define i2c_SS2_PIN_MASK                ((uint32) 0x01u << i2c_SS2_PIN_INDEX)
#define i2c_SS3_PIN_MASK                ((uint32) 0x01u << i2c_SS3_PIN_INDEX)

/* Pin interrupt constants */
#define i2c_INTCFG_TYPE_MASK           (0x03u)
#define i2c_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants */
#define i2c_PIN_DM_ALG_HIZ  (0u)
#define i2c_PIN_DM_DIG_HIZ  (1u)
#define i2c_PIN_DM_OD_LO    (4u)
#define i2c_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define i2c_DM_MASK    (0x7u)
#define i2c_DM_SIZE    (3)
#define i2c_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) i2c_DM_MASK << (i2c_DM_SIZE * (pos)))) >> \
                                                              (i2c_DM_SIZE * (pos)) )

#if (i2c_TX_SDA_MISO_PIN)
    #define i2c_CHECK_TX_SDA_MISO_PIN_USED \
                (i2c_PIN_DM_ALG_HIZ != \
                    i2c_GET_P4_PIN_DM(i2c_uart_tx_i2c_sda_spi_miso_PC, \
                                                   i2c_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (i2c_TX_SDA_MISO_PIN) */

#if (i2c_SS0_PIN)
    #define i2c_CHECK_SS0_PIN_USED \
                (i2c_PIN_DM_ALG_HIZ != \
                    i2c_GET_P4_PIN_DM(i2c_spi_ss0_PC, \
                                                   i2c_spi_ss0_SHIFT))
#endif /* (i2c_SS0_PIN) */

/* Set bits-mask in register */
#define i2c_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define i2c_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define i2c_SET_HSIOM_SEL(reg, mask, pos, sel) i2c_SET_REGISTER_BITS(reg, mask, pos, sel)
#define i2c_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        i2c_SET_REGISTER_BITS(reg, mask, pos, intType)
#define i2c_SET_INP_DIS(reg, mask, val) i2c_SET_REGISTER_BIT(reg, mask, val)

/* i2c_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  i2c_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (i2c_CY_SCBIP_V0)
#if (i2c_I2C_PINS)
    #define i2c_SET_I2C_SCL_DR(val) i2c_scl_Write(val)

    #define i2c_SET_I2C_SCL_HSIOM_SEL(sel) \
                          i2c_SET_HSIOM_SEL(i2c_SCL_HSIOM_REG,  \
                                                         i2c_SCL_HSIOM_MASK, \
                                                         i2c_SCL_HSIOM_POS,  \
                                                         (sel))
    #define i2c_WAIT_SCL_SET_HIGH  (0u == i2c_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (i2c_RX_WAKE_SCL_MOSI_PIN)
    #define i2c_SET_I2C_SCL_DR(val) \
                            i2c_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define i2c_SET_I2C_SCL_HSIOM_SEL(sel) \
                    i2c_SET_HSIOM_SEL(i2c_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   i2c_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   i2c_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define i2c_WAIT_SCL_SET_HIGH  (0u == i2c_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (i2c_RX_SCL_MOSI_PIN)
    #define i2c_SET_I2C_SCL_DR(val) \
                            i2c_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define i2c_SET_I2C_SCL_HSIOM_SEL(sel) \
                            i2c_SET_HSIOM_SEL(i2c_RX_SCL_MOSI_HSIOM_REG,  \
                                                           i2c_RX_SCL_MOSI_HSIOM_MASK, \
                                                           i2c_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define i2c_WAIT_SCL_SET_HIGH  (0u == i2c_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define i2c_SET_I2C_SCL_DR(val) \
                                                    do{ /* Does nothing */ }while(0)
    #define i2c_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ /* Does nothing */ }while(0)

    #define i2c_WAIT_SCL_SET_HIGH  (0u)
#endif /* (i2c_I2C_PINS) */

/* SCB I2C: sda signal */
#if (i2c_I2C_PINS)
    #define i2c_WAIT_SDA_SET_HIGH  (0u == i2c_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (i2c_TX_SDA_MISO_PIN)
    #define i2c_WAIT_SDA_SET_HIGH  (0u == i2c_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define i2c_WAIT_SDA_SET_HIGH  (0u)
#endif /* (i2c_MOSI_SCL_RX_PIN) */
#endif /* (i2c_CY_SCBIP_V0) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define i2c_REMOVE_MOSI_SCL_RX_WAKE_PIN    i2c_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define i2c_REMOVE_MOSI_SCL_RX_PIN         i2c_REMOVE_RX_SCL_MOSI_PIN
#define i2c_REMOVE_MISO_SDA_TX_PIN         i2c_REMOVE_TX_SDA_MISO_PIN
#ifndef i2c_REMOVE_SCLK_PIN
#define i2c_REMOVE_SCLK_PIN                i2c_REMOVE_SCLK_PIN
#endif /* i2c_REMOVE_SCLK_PIN */
#ifndef i2c_REMOVE_SS0_PIN
#define i2c_REMOVE_SS0_PIN                 i2c_REMOVE_SS0_PIN
#endif /* i2c_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define i2c_MOSI_SCL_RX_WAKE_PIN   i2c_RX_WAKE_SCL_MOSI_PIN
#define i2c_MOSI_SCL_RX_PIN        i2c_RX_SCL_MOSI_PIN
#define i2c_MISO_SDA_TX_PIN        i2c_TX_SDA_MISO_PIN
#ifndef i2c_SCLK_PIN
#define i2c_SCLK_PIN               i2c_SCLK_PIN
#endif /* i2c_SCLK_PIN */
#ifndef i2c_SS0_PIN
#define i2c_SS0_PIN                i2c_SS0_PIN
#endif /* i2c_SS0_PIN */

#if (i2c_MOSI_SCL_RX_WAKE_PIN)
    #define i2c_MOSI_SCL_RX_WAKE_HSIOM_REG     i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_WAKE_HSIOM_PTR     i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_WAKE_HSIOM_MASK    i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_WAKE_HSIOM_POS     i2c_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define i2c_MOSI_SCL_RX_WAKE_INTCFG_REG    i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_WAKE_INTCFG_PTR    i2c_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define i2c_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  i2c_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (i2c_RX_WAKE_SCL_MOSI_PIN) */

#if (i2c_MOSI_SCL_RX_PIN)
    #define i2c_MOSI_SCL_RX_HSIOM_REG      i2c_RX_SCL_MOSI_HSIOM_REG
    #define i2c_MOSI_SCL_RX_HSIOM_PTR      i2c_RX_SCL_MOSI_HSIOM_PTR
    #define i2c_MOSI_SCL_RX_HSIOM_MASK     i2c_RX_SCL_MOSI_HSIOM_MASK
    #define i2c_MOSI_SCL_RX_HSIOM_POS      i2c_RX_SCL_MOSI_HSIOM_POS
#endif /* (i2c_MOSI_SCL_RX_PIN) */

#if (i2c_MISO_SDA_TX_PIN)
    #define i2c_MISO_SDA_TX_HSIOM_REG      i2c_TX_SDA_MISO_HSIOM_REG
    #define i2c_MISO_SDA_TX_HSIOM_PTR      i2c_TX_SDA_MISO_HSIOM_REG
    #define i2c_MISO_SDA_TX_HSIOM_MASK     i2c_TX_SDA_MISO_HSIOM_REG
    #define i2c_MISO_SDA_TX_HSIOM_POS      i2c_TX_SDA_MISO_HSIOM_REG
#endif /* (i2c_MISO_SDA_TX_PIN_PIN) */

#if (i2c_SCLK_PIN)
    #ifndef i2c_SCLK_HSIOM_REG
    #define i2c_SCLK_HSIOM_REG     i2c_SCLK_HSIOM_REG
    #define i2c_SCLK_HSIOM_PTR     i2c_SCLK_HSIOM_PTR
    #define i2c_SCLK_HSIOM_MASK    i2c_SCLK_HSIOM_MASK
    #define i2c_SCLK_HSIOM_POS     i2c_SCLK_HSIOM_POS
    #endif /* i2c_SCLK_HSIOM_REG */
#endif /* (i2c_SCLK_PIN) */

#if (i2c_SS0_PIN)
    #ifndef i2c_SS0_HSIOM_REG
    #define i2c_SS0_HSIOM_REG      i2c_SS0_HSIOM_REG
    #define i2c_SS0_HSIOM_PTR      i2c_SS0_HSIOM_PTR
    #define i2c_SS0_HSIOM_MASK     i2c_SS0_HSIOM_MASK
    #define i2c_SS0_HSIOM_POS      i2c_SS0_HSIOM_POS
    #endif /* i2c_SS0_HSIOM_REG */
#endif /* (i2c_SS0_PIN) */

#define i2c_MOSI_SCL_RX_WAKE_PIN_INDEX i2c_RX_WAKE_SCL_MOSI_PIN_INDEX
#define i2c_MOSI_SCL_RX_PIN_INDEX      i2c_RX_SCL_MOSI_PIN_INDEX
#define i2c_MISO_SDA_TX_PIN_INDEX      i2c_TX_SDA_MISO_PIN_INDEX
#ifndef i2c_SCLK_PIN_INDEX
#define i2c_SCLK_PIN_INDEX             i2c_SCLK_PIN_INDEX
#endif /* i2c_SCLK_PIN_INDEX */
#ifndef i2c_SS0_PIN_INDEX
#define i2c_SS0_PIN_INDEX              i2c_SS0_PIN_INDEX
#endif /* i2c_SS0_PIN_INDEX */

#define i2c_MOSI_SCL_RX_WAKE_PIN_MASK i2c_RX_WAKE_SCL_MOSI_PIN_MASK
#define i2c_MOSI_SCL_RX_PIN_MASK      i2c_RX_SCL_MOSI_PIN_MASK
#define i2c_MISO_SDA_TX_PIN_MASK      i2c_TX_SDA_MISO_PIN_MASK
#ifndef i2c_SCLK_PIN_MASK
#define i2c_SCLK_PIN_MASK             i2c_SCLK_PIN_MASK
#endif /* i2c_SCLK_PIN_MASK */
#ifndef i2c_SS0_PIN_MASK
#define i2c_SS0_PIN_MASK              i2c_SS0_PIN_MASK
#endif /* i2c_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_i2c_H) */


/* [] END OF FILE */
