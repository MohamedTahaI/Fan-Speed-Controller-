/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	VOLT_REF_AREF,
	VOLT_REF_AVCC,
	VOLT_REF_RESERVED,
	VOLT_REF_2V56,
	VOLT_REF_NUM
}ADC_ReferenceVolatge;

typedef enum
{
	DIV_FACT_1,
	DIV_FACT_2,
	DIV_FACT_4,
	DIV_FACT_8,
	DIV_FACT_16,
	DIV_FACT_32,
	DIV_FACT_64,
	DIV_FACT_128,
	DIV_FACT_NUM
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
