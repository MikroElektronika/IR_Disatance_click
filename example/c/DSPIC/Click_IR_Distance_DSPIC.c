/*
Example for IR_Distance Click

    Date          : Mar 2019.
    Author        : Nenad Filipovic

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures,
    sets AN pin as input, RST pin as output and starts write log.
- Application Initialization - Initialization driver enables GPIO,
    enable IR sensor, initialization ADC, also write log.
- Application Task - (code snippet) This is an example which demonstrates the use of IR Distance click board.
    IR Distance click reads and displays ADC value.
    Results are being sent to the Usart Terminal where you can track their changes.
    All data logs on USB uart change for every 1 sec.

Additional Functions :

- void irdistance_adcInit() - Function ADC initialization.
- uint32_t irdistance_readADC() - Function read ADC value.

*/

#include "Click_IR_Distance_types.h"
#include "Click_IR_Distance_config.h"
#include "Click_IR_Distance_adc.h"

uint16_t adcVal;
char logText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( " IR Distance click ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
    Delay_100ms();
}

void applicationInit()
{
    irdistance_gpioDriverInit( (T_IRDISTANCE_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( "  Enable IR sensor ", _LOG_LINE );
    irdistance_enable();
    Delay_100ms();
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    mikrobus_logWrite( "Initialization  ADC", _LOG_LINE );
    irdistance_adcInit();
    Delay_100ms();
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    Delay_100ms();
}

void applicationTask()
{
    adcVal = irdistance_readADC();
    WordToStr( adcVal, logText );
    
    mikrobus_logWrite( " ADC value : ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}