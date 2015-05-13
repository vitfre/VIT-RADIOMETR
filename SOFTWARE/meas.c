/*
 * meas.c
 *
 * Created: 18.10.2013 12:20:42
 *  Author: vmk
 */

#include "meas.h"

//***************************************************************************************
//��������� �� ��������� ������
//***************************************************************************************
unsigned int read_adc(unsigned char adc_input)
{
	unsigned int ADC_RESULT;
	ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	// Delay needed for the stabilization of the ADC input voltage
	_delay_us(20);
	// Start the AD conversion
	ADCSRA|=0x40;
	// Wait for the AD conversion to complete
	while ((ADCSRA & 0x10)==0);
	ADCSRA|=0x10;
	ADC_RESULT=ADCL;
	ADC_RESULT=ADC_RESULT+(ADCH<<8);
	return ADC_RESULT;
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************