/*
File:		servo.c
Author:		Craig Huther (nanoCortex4200)
Last Revision: 10/24

*/

#include "derivative.h"
#include "servo.h"

//variable definitions



void Init_FTM0(void) {

	//enable clock to Port Module's
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	//enable clock to module 
	SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;	
	
	//set PTC1 for output from FTM0 channel 0 - goes to Data0 on H-Bridge
	PORTC_PCR1 = PORT_PCR_MUX(4);  	//select function
	GPIOC_PDDR |= 0x01 << 1;		//set pin to output. THIS IS A40 ON TOWER!!!	
	//set PTC2 for output from FTM0 channel 1 - goes to Data2 on H-Bridge
	PORTC_PCR2 = PORT_PCR_MUX(4);  	//select function
	GPIOC_PDDR |= 0x01 << 4;		//set pin to output. THIS IS A39 ON TOWER!!!		


	//turn off write protection
	FTM0_MODE |= FTM_MODE_WPDIS_MASK;

	//make sure clock is disabled
	FTM0_SC = 0;

	//load starting values of counter and counter position
	FTM0_CNTIN = 	0;
	FTM0_CNT = 		0;

	//set mode on channel0,1,3 to edge-alined PWM with true pulse on output
	FTM0_C0SC  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK; 
	FTM0_C1SC  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;


	//load modulo value
	FTM0_MOD = FTM0_MOD_VALUE;

	//load zero count value for H-bridge PWM's
	FTM0_C0V = FTM0_C0V_MIN_VALUE;
	FTM0_C1V = FTM0_C1V_MIN_VALUE;
	//load middle count value for Servo
	//FTM0_C3V = FTM0_C3V_MID_VALUE;
	
	
	
	//debug mode
	FTM0_CONF = FTM_CONF_BDMMODE(3);

	//set prescaler to 4
	FTM0_SC |= FTM_SC_PS(FTM0_CLK_PRESCALE);

	//enable system clock to module
	FTM0_SC |= FTM_SC_CLKS(FTM0_CLK_SOURCE);
}

void Init_FTM1(void){

	//enable clock to module 
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	//enable clock to Port Module's
	SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;
	
	
	//Set PTA8 as output from FTM1 CH0
	PORTA_PCR8 = PORT_PCR_MUX(3);  	//select function
	GPIOA_PDDR |= 0x01 << 8;		//set pin to output. THIS IS A34 ON TOWER!!!
	
	//turn off write protection
	FTM1_MODE |= FTM_MODE_WPDIS_MASK;

	//make sure clock is disabled
	FTM1_SC = 0;

	//load starting values of counter and counter position
	FTM1_CNTIN = 	0;
	FTM1_CNT = 		0;

	//set mode on channel 1 to edge-alined PWM with true pulse on output
	FTM1_C0SC  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK; 
	

	//load modulo value
	FTM1_MOD = FTM1_MOD_VALUE;	
	
	//load middle count value for Servo
	FTM1_C0V = FTM1_C0V_MID_VALUE;
	//debug mode
	FTM1_CONF = FTM_CONF_BDMMODE(3);

	//set prescaler to 4
	FTM1_SC |= FTM_SC_PS(FTM1_CLK_PRESCALE);

	//enable system clock to module
	FTM1_SC |= FTM_SC_CLKS(FTM1_CLK_SOURCE);
}

void Change_FTM0_C0V_PWM(int newCount){
	int count = newCount;
	if (newCount < FTM0_C0V_MIN_VALUE)
		count = FTM0_C0V_MIN_VALUE;
	if (newCount > FTM0_C0V_MAX_VALUE)
		count = FTM0_C0V_MAX_VALUE;
	//load the value
	FTM0_C0V = count;
}

void Change_FTM0_C1V_PWM(int newCount){
	int count = newCount;
	if (newCount < FTM0_C1V_MIN_VALUE)
		count = FTM0_C1V_MIN_VALUE;
	if (newCount > FTM0_C1V_MAX_VALUE)
		count = FTM0_C1V_MAX_VALUE;
	//load the value
	FTM0_C1V = count;
}

void Change_FTM1_C0V_PWM(int newCount){
	int count = newCount;
	if (newCount < FTM1_C0V_MIN_VALUE)
		count = FTM1_C0V_MIN_VALUE;
	if (newCount > FTM1_C0V_MAX_VALUE)
		count = FTM1_C0V_MAX_VALUE;
	//load the value
	FTM1_C0V = count;
}