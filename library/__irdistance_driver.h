/*
    __irdistance_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __irdistance_driver.h
@brief    IR_Distance Driver
@mainpage IR_Distance Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   IRDISTANCE
@brief      IR_Distance Click Driver
@{

| Global Library Prefix | **IRDISTANCE** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Mar 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _IRDISTANCE_H_
#define _IRDISTANCE_H_

/** 
 * @macro T_IRDISTANCE_P
 * @brief Driver Abstract type 
 */
#define T_IRDISTANCE_P    const uint8_t*

/** @defgroup IRDISTANCE_COMPILE Compilation Config */              /** @{ */

//  #define   __IRDISTANCE_DRV_SPI__                            /**<     @macro __IRDISTANCE_DRV_SPI__  @brief SPI driver selector */
//  #define   __IRDISTANCE_DRV_I2C__                            /**<     @macro __IRDISTANCE_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __IRDISTANCE_DRV_UART__                           /**<     @macro __IRDISTANCE_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup IRDISTANCE_VAR Variables */                           /** @{ */

extern const uint16_t _IRDISTANCE_RESOLUTION_10_BIT;
extern const uint16_t _IRDISTANCE_RESOLUTION_12_BIT;
extern const float _IRDISTANCE_VCC_3_3;
extern const float _IRDISTANCE_VCC_5_0;

                                                                       /** @} */
/** @defgroup IRDISTANCE_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup IRDISTANCE_INIT Driver Initialization */              /** @{ */

#ifdef   __IRDISTANCE_DRV_SPI__
void irdistance_spiDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P spiObj);
#endif
#ifdef   __IRDISTANCE_DRV_I2C__
void irdistance_i2cDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P i2cObj, uint8_t slave);
#endif
#ifdef   __IRDISTANCE_DRV_UART__
void irdistance_uartDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void irdistance_gpioDriverInit(T_IRDISTANCE_P gpioObj);
                                                                       /** @} */
/** @defgroup IRDISTANCE_FUNC Driver Functions */                   /** @{ */




/**
 * @brief Enable IR sensor function
 *
 * Function enable Sharp’s GP2Y0A60SZ0F distance measuring sensor
 * by set RST pin on Stretch click board.
*/
void irdistance_enable();

/**
 * @brief Disable IR sensor function
 *
 * Function disable Sharp’s GP2Y0A60SZ0F distance measuring sensor
 * by clear RST pin on Stretch click board.
*/
void irdistance_disable();

/**
 * @brief Get the voltage output of the sensor function
 *
 * @param[in] adcValue                       
 * the measurement adc value
 *
 * @param[in] resolutionValue                       
 * - 1024 : 10bit resolution;
 * - 4096 : 12bit resolution;
 *
 * @param[in] vccValue
 * - 3300 : 3.3V VCC;
 * - 5000 : 5.0V VCC;
 *
 * @return
 * float value of the sensor voltage output
 *
 * Function calculate the voltage output of the Sharp’s GP2Y0A60SZ0F distance measuring sensor
 * on IR Distance click board.
*/

float irdistance_getVoltageOut( uint32_t adcValue, uint16_t resolutionValue, float vccValue );



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_IR_Distance_STM.c
    @example Click_IR_Distance_TIVA.c
    @example Click_IR_Distance_CEC.c
    @example Click_IR_Distance_KINETIS.c
    @example Click_IR_Distance_MSP.c
    @example Click_IR_Distance_PIC.c
    @example Click_IR_Distance_PIC32.c
    @example Click_IR_Distance_DSPIC.c
    @example Click_IR_Distance_AVR.c
    @example Click_IR_Distance_FT90x.c
    @example Click_IR_Distance_STM.mbas
    @example Click_IR_Distance_TIVA.mbas
    @example Click_IR_Distance_CEC.mbas
    @example Click_IR_Distance_KINETIS.mbas
    @example Click_IR_Distance_MSP.mbas
    @example Click_IR_Distance_PIC.mbas
    @example Click_IR_Distance_PIC32.mbas
    @example Click_IR_Distance_DSPIC.mbas
    @example Click_IR_Distance_AVR.mbas
    @example Click_IR_Distance_FT90x.mbas
    @example Click_IR_Distance_STM.mpas
    @example Click_IR_Distance_TIVA.mpas
    @example Click_IR_Distance_CEC.mpas
    @example Click_IR_Distance_KINETIS.mpas
    @example Click_IR_Distance_MSP.mpas
    @example Click_IR_Distance_PIC.mpas
    @example Click_IR_Distance_PIC32.mpas
    @example Click_IR_Distance_DSPIC.mpas
    @example Click_IR_Distance_AVR.mpas
    @example Click_IR_Distance_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __irdistance_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */