/*
    __irdistance_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__irdistance_driver.h"
#include "__irdistance_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __IRDISTANCE_DRV_I2C__
static uint8_t _slaveAddress;
#endif


const uint16_t _IRDISTANCE_RESOLUTION_10_BIT          = 1024;
const uint16_t _IRDISTANCE_RESOLUTION_12_BIT          = 4096;
const float _IRDISTANCE_VCC_3_3                       = 3300.0;
const float _IRDISTANCE_VCC_5_0                       = 5000.0;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __IRDISTANCE_DRV_SPI__

void irdistance_spiDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __IRDISTANCE_DRV_I2C__

void irdistance_i2cDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __IRDISTANCE_DRV_UART__

void irdistance_uartDriverInit(T_IRDISTANCE_P gpioObj, T_IRDISTANCE_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void irdistance_gpioDriverInit(T_IRDISTANCE_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

/* Enable ir sensor function */
void irdistance_enable()
{
    hal_gpio_rstSet( 1 );
}

/* Disable ir sensor function */
void irdistance_disable()
{
    hal_gpio_rstSet( 0 );
}

/* Get the voltage output of the sensor function */
float irdistance_getVoltageOut( uint32_t adcValue, uint16_t resolutionValue, float vccValue )
{
    float vOut;

    vOut = ( float ) adcValue;
    vOut *= vccValue;
    vOut /= resolutionValue;

    return vOut;
}





/* -------------------------------------------------------------------------- */
/*
  __irdistance_driver.c

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