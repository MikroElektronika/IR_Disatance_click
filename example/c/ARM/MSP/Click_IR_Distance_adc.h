#include "Click_IR_Distance_types.h"


void irdistance_adcInit()
{
    ADC_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_15 );
}

uint32_t irdistance_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 15 );
    
    return readADC;
}