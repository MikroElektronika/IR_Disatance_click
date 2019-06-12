![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# IR_Distance Click

- **CIC Prefix**  : IRDISTANCE
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Mar 2019.

---


### Software Support

We provide a library for the IR_Distance Click on our [LibStock](https://libstock.mikroe.com/projects/view/1581/ir-distance-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control IR Distance click board.
IR Distance click communicates with the target board via analog ( AN ) pin. 
This library contains drivers for read ADC value of  the Sharp’s GP2Y0A60SZ0F distance measuring sensor
on IR Distance click board.

Key functions :

- ``` void irdistance_enable() ``` - Enable IR sensor function.
- ``` void irdistance_disable() ``` - Disable IR sensor function.
- ``` float irdistance_getVoltageOut( uint32_t adcValue, uint16_t resolutionValue, float vccValue ) ``` - Get the voltage output of the sensor function.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures,
    sets AN pin as input, RST pin as output and starts write log.
- Application Initialization - Initialization driver enables GPIO,
    enable IR sensor, initialization ADC, also write log.
- Application Task - (code snippet) This is an example which demonstrates the use of IR Distance click board.
    IR Distance click reads and displays ADC value.
    Results are being sent to the Usart Terminal where you can track their changes.
    All data logs on USB uart change for every 1 sec.


```.c

void applicationTask()
{
    adcVal = irdistance_readADC();
    WordToStr( adcVal, logText );
    
    mikrobus_logWrite( " ADC value : ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
    Delay_1sec();
}

```

Additional Functions :

- ``` void irdistance_adcInit() ``` - Function ADC initialization.
- ``` uint32_t irdistance_readADC() ``` - Function read ADC value.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1581/ir-distance-click) page.

Other mikroE Libraries used in the example:

- ADC
- UART
- Conversion

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
