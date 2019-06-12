#include "Click_IR_Distance_types.h"


void irdistance_adcInit()
{
    ADC0_Init();
    ADC0_Set_Input_Channel( _ADC_CHANNEL_12 );
}

uint32_t irdistance_readADC()
{
    uint32_t readADC;
    
    readADC = ADC0_Read( 12 );
    
    return readADC;
}