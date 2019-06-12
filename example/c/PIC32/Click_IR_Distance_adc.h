#include "Click_IR_Distance_types.h"


void irdistance_adcInit()
{
    ADC1_Init();
}

uint32_t irdistance_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}