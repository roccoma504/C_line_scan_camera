/*
 * initTSI.c
 *
 *  Created on: Nov 8, 2012
 *      Author: ulab
 */


#include "initTSI.h"



 
unsigned short baselineValue[2];
unsigned char currentElectrode;
void InitLEDsGPIO(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	//Initialize red LED (PTB18)
	PORTB_PCR18 = PORT_PCR_MUX(1);
	GPIOB_PSOR |= GPIO_PIN(RED_LED);
	GPIOB_PDDR |= GPIO_PIN(RED_LED);
	
	PORTB_PCR19 = PORT_PCR_MUX(1);
	GPIOB_PSOR |= GPIO_PIN(RED_LED); 
	GPIOB_PDDR |= GPIO_PIN(GREEN_LED);
	
	PORTD_PCR1 = PORT_PCR_MUX(1);
	GPIOD_PSOR = GPIO_PIN(BLUE_LED);
	GPIOD_PDDR |= GPIO_PIN(BLUE_LED);
}

void InitTSI(void)
{
	SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;
	
	PORTB_PCR16 = PORT_PCR_MUX(0);
	PORTB_PCR17 = PORT_PCR_MUX(0);
	
	TSI0_GENCS |= (TSI_GENCS_ESOR_MASK
			|TSI_GENCS_MODE(0)
			|TSI_GENCS_REFCHRG(4)
			|TSI_GENCS_DVOLT(0)
			|TSI_GENCS_EXTCHRG(7)
			|TSI_GENCS_PS(4)
			|TSI_GENCS_NSCN(11)
			|TSI_GENCS_STPE_MASK
			);
	TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;
	
		//CalibrateTSI();
}

void ScanTSI(void)
{
	short delta;
	unsigned short conversionCount[2];
	
	//TSI0_DATA |= TSI_DATA_SWTS_MASK;
}


