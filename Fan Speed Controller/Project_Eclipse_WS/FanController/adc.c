/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

// user select mode to Reference volt and ADC Prescaler Selections

void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	if(Config_Ptr->ref_volt < VOLT_REF_NUM)
	{
		switch(Config_Ptr->ref_volt )
		{
		case VOLT_REF_AREF :
			CLEAR_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case VOLT_REF_AVCC :
			SET_BIT(ADMUX,REFS0);
			CLEAR_BIT(ADMUX,REFS1);
			break;
		case VOLT_REF_RESERVED :
			CLEAR_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		case VOLT_REF_2V56 :
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);

			break;
		default:
			// nothing
			break;

		}
	}
	else
	{
		// nothing
	}

// user
	if(Config_Ptr->prescaler < DIV_FACT_NUM)
	{
		switch(Config_Ptr->prescaler )
		{
		case DIV_FACT_1 :
			CLEAR_BIT(ADCSRA,ADPS0);
			CLEAR_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_2 :
			SET_BIT(ADCSRA,ADPS0);
			CLEAR_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_4 :
			CLEAR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_8 :
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLEAR_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_16 :
			CLEAR_BIT(ADCSRA,ADPS0);
			CLEAR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_32 :
			SET_BIT(ADCSRA,ADPS0);
			CLEAR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_64 :
			CLEAR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		case DIV_FACT_128 :
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
		default:
			// nothing
			break;
		}
	}
	else
	{
		// nothing
	}




	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = ADMUX & 0xE0;

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 */
	ADCSRA |= (1<<ADEN) ;
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
