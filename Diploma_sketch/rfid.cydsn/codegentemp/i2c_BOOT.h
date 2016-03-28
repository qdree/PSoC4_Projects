/*******************************************************************************
* File Name: i2c_BOOT.h
* Version 3.10
*
* Description:
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_i2c_H)
#define CY_SCB_BOOT_i2c_H

#include "i2c_PVT.h"

#if (i2c_SCB_MODE_I2C_INC)
    #include "i2c_I2C.h"
#endif /* (i2c_SCB_MODE_I2C_INC) */

#if (i2c_SCB_MODE_EZI2C_INC)
    #include "i2c_EZI2C.h"
#endif /* (i2c_SCB_MODE_EZI2C_INC) */

#if (i2c_SCB_MODE_SPI_INC || i2c_SCB_MODE_UART_INC)
    #include "i2c_SPI_UART.h"
#endif /* (i2c_SCB_MODE_SPI_INC || i2c_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define i2c_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_i2c) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (i2c_SCB_MODE_I2C_INC)
    #define i2c_I2C_BTLDR_COMM_ENABLED     (i2c_BTLDR_COMM_ENABLED && \
                                                            (i2c_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             i2c_I2C_SLAVE_CONST))
#else
     #define i2c_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (i2c_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (i2c_SCB_MODE_EZI2C_INC)
    #define i2c_EZI2C_BTLDR_COMM_ENABLED   (i2c_BTLDR_COMM_ENABLED && \
                                                         i2c_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define i2c_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (i2c_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (i2c_SCB_MODE_SPI_INC)
    #define i2c_SPI_BTLDR_COMM_ENABLED     (i2c_BTLDR_COMM_ENABLED && \
                                                            (i2c_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             i2c_SPI_SLAVE_CONST))
#else
        #define i2c_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (i2c_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (i2c_SCB_MODE_UART_INC)
       #define i2c_UART_BTLDR_COMM_ENABLED    (i2c_BTLDR_COMM_ENABLED && \
                                                            (i2c_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (i2c_UART_RX_DIRECTION && \
                                                              i2c_UART_TX_DIRECTION)))
#else
     #define i2c_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (i2c_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define i2c_BTLDR_COMM_MODE_ENABLED    (i2c_I2C_BTLDR_COMM_ENABLED   || \
                                                     i2c_SPI_BTLDR_COMM_ENABLED   || \
                                                     i2c_EZI2C_BTLDR_COMM_ENABLED || \
                                                     i2c_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void i2c_I2CCyBtldrCommStart(void);
    void i2c_I2CCyBtldrCommStop (void);
    void i2c_I2CCyBtldrCommReset(void);
    cystatus i2c_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus i2c_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (i2c_SCB_MODE_I2C_CONST_CFG)
        #define i2c_CyBtldrCommStart   i2c_I2CCyBtldrCommStart
        #define i2c_CyBtldrCommStop    i2c_I2CCyBtldrCommStop
        #define i2c_CyBtldrCommReset   i2c_I2CCyBtldrCommReset
        #define i2c_CyBtldrCommRead    i2c_I2CCyBtldrCommRead
        #define i2c_CyBtldrCommWrite   i2c_I2CCyBtldrCommWrite
    #endif /* (i2c_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void i2c_EzI2CCyBtldrCommStart(void);
    void i2c_EzI2CCyBtldrCommStop (void);
    void i2c_EzI2CCyBtldrCommReset(void);
    cystatus i2c_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus i2c_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (i2c_SCB_MODE_EZI2C_CONST_CFG)
        #define i2c_CyBtldrCommStart   i2c_EzI2CCyBtldrCommStart
        #define i2c_CyBtldrCommStop    i2c_EzI2CCyBtldrCommStop
        #define i2c_CyBtldrCommReset   i2c_EzI2CCyBtldrCommReset
        #define i2c_CyBtldrCommRead    i2c_EzI2CCyBtldrCommRead
        #define i2c_CyBtldrCommWrite   i2c_EzI2CCyBtldrCommWrite
    #endif /* (i2c_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void i2c_SpiCyBtldrCommStart(void);
    void i2c_SpiCyBtldrCommStop (void);
    void i2c_SpiCyBtldrCommReset(void);
    cystatus i2c_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus i2c_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (i2c_SCB_MODE_SPI_CONST_CFG)
        #define i2c_CyBtldrCommStart   i2c_SpiCyBtldrCommStart
        #define i2c_CyBtldrCommStop    i2c_SpiCyBtldrCommStop
        #define i2c_CyBtldrCommReset   i2c_SpiCyBtldrCommReset
        #define i2c_CyBtldrCommRead    i2c_SpiCyBtldrCommRead
        #define i2c_CyBtldrCommWrite   i2c_SpiCyBtldrCommWrite
    #endif /* (i2c_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void i2c_UartCyBtldrCommStart(void);
    void i2c_UartCyBtldrCommStop (void);
    void i2c_UartCyBtldrCommReset(void);
    cystatus i2c_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus i2c_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (i2c_SCB_MODE_UART_CONST_CFG)
        #define i2c_CyBtldrCommStart   i2c_UartCyBtldrCommStart
        #define i2c_CyBtldrCommStop    i2c_UartCyBtldrCommStop
        #define i2c_CyBtldrCommReset   i2c_UartCyBtldrCommReset
        #define i2c_CyBtldrCommRead    i2c_UartCyBtldrCommRead
        #define i2c_CyBtldrCommWrite   i2c_UartCyBtldrCommWrite
    #endif /* (i2c_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_UART_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_BTLDR_COMM_ENABLED)
    #if (i2c_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void i2c_CyBtldrCommStart(void);
        void i2c_CyBtldrCommStop (void);
        void i2c_CyBtldrCommReset(void);
        cystatus i2c_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus i2c_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (i2c_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_i2c)
        #define CyBtldrCommStart    i2c_CyBtldrCommStart
        #define CyBtldrCommStop     i2c_CyBtldrCommStop
        #define CyBtldrCommReset    i2c_CyBtldrCommReset
        #define CyBtldrCommWrite    i2c_CyBtldrCommWrite
        #define CyBtldrCommRead     i2c_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_i2c) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_BTLDR_COMM_ENABLED) */


/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define i2c_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define i2c_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define i2c_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define i2c_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef i2c_SPI_BYTE_TO_BYTE
    #define i2c_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef i2c_UART_BYTE_TO_BYTE
    #define i2c_UART_BYTE_TO_BYTE  (2500u)
#endif /* i2c_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_i2c_H) */


/* [] END OF FILE */
