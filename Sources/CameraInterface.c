

#include "CameraInterface.h"


#define TAOS_CLK_HIGH  GPIOA_PSOR = (1<<12)  
#define TAOS_CLK_LOW   GPIOA_PCOR = (1<<12)  
#define TAOS_SI_HIGH   GPIOA_PSOR = (1<<17) //17
#define TAOS_SI_LOW    GPIOA_PCOR =	(1<<17)//A21

//testing
#define ADC_HIGH		GPIOA_PSOR = (1<<16)
#define ADC_LOW			GPIOA_PCOR = (1<<16)

#define GET_CAMERA_ANALOG_OUT	Read_ADC1(4)			//The camera analog out is connected to PortE0 (channel 5 of Converter 1)
#define CAMERA_LOW_TRIM			200
//loop to set exposure time, can improve later
void ExposureDelay(int delay)
{
	int i;
	for (i=0;i<delay;i++)
		{
		}	
}
int expodelay = 1000;
#define TAOS_EXPOSURE_DELAY ExposureDelay(expodelay)  // 1 ~ 231 us; scale accordingly.

//turns off CLK and SI
void InitTAOS()
{

	SIM_SCGC5 = SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTE_MASK; //Make sure the clock is enabled for PORTA;
	PORTA_PCR12 = PORT_PCR_MUX(1); //| PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for the CLOCK Signal
	PORTA_PCR13 = PORT_PCR_MUX(1); //| PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for SI signal
	//testing
	PORTA_PCR16 = PORT_PCR_MUX(1);
	PORTA_PCR17 = PORT_PCR_MUX(1); //| PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for SI signal

	
	PORTE_PCR0 = PORT_PCR_MUX(0); //| PORT_PCR_DSE_MASK;   //Enable ADC1 channel 4 on the port pin
	
	//Make sure the Clock and SI pins are outputs
    GPIOA_PDDR |= 0x01 << 12;
    GPIOA_PDDR |= 0x01 << 17;
    //testing
    GPIOA_PDDR |= 0x01 << 16; //Tower pin B52
    
   	
	TAOS_CLK_LOW;
	TAOS_SI_LOW;

}
/****** Capture Images:*******
 * 
 * Start Clock  
 * Set frequency
 * loop 128 times 
 * ready
 */

void ImageCapture(unsigned char * ImageData)
{
	unsigned char i;
	
	TAOS_SI_HIGH;
	TAOS_EXPOSURE_DELAY;
	TAOS_EXPOSURE_DELAY;
	TAOS_CLK_HIGH;
	TAOS_EXPOSURE_DELAY;
	TAOS_SI_LOW;
	TAOS_EXPOSURE_DELAY;
	//ImageData[0] = GET_CAMERA_ANALOG_OUT;// inputs data from camera (first pixel)
	if (GET_CAMERA_ANALOG_OUT > CAMERA_LOW_TRIM)
		ImageData[0] = 0;//ADC_LOW;
	else
		ImageData[0] = 1;//ADC_HIGH;
	TAOS_CLK_LOW;
	
	for(i=1;i<128;i++)
	{
		TAOS_EXPOSURE_DELAY;
		TAOS_EXPOSURE_DELAY;
		TAOS_CLK_HIGH;
		TAOS_EXPOSURE_DELAY;
		TAOS_EXPOSURE_DELAY;
		//ImageData[i] = GET_CAMERA_ANALOG_OUT; // inputs data from camera (one pixel each time through loop)
		
		if (GET_CAMERA_ANALOG_OUT > 200)
			ImageData[i] = 0;//ADC_LOW;
		else
			ImageData[i] = 1;//ADC_HIGH;
		TAOS_CLK_LOW;
	}
	
	TAOS_EXPOSURE_DELAY;
	TAOS_EXPOSURE_DELAY;
	TAOS_CLK_HIGH;
	TAOS_EXPOSURE_DELAY;
	TAOS_EXPOSURE_DELAY;
	TAOS_CLK_LOW;	
}
