#include "Click_IR_Distance_types.h"


void irdistance_adcInit()
{
    ADC_Init();
}

uint32_t irdistance_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}