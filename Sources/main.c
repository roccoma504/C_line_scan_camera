/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include <stdio.h>
#include "derivative.h" /* include peripheral declarations */
#include "servo.h"
#include "CameraInterface.h"
#include "Clock.h"
#include "SysTick.h"

#include "adc16.h"

volatile sLine Line;
int servo = FTM1_C0V_MID_VALUE;
int dc0 = FTM0_C0V_MIN_VALUE;
int dc1 = FTM0_C1V_MIN_VALUE;
unsigned char ImageData[128];
unsigned int track_offset;

void Delay(long value) {
	long i;
	
	for(i = 0; i < value; i++){
		
	}
}

unsigned int FlattenArray(unsigned char * inArray)
{
	unsigned int flattenedArray = 0 ;
	int i;
	int length = sizeof(inArray)/sizeof(inArray[0]);
	for (i=0; i< (length); i++){
		flattenedArray << inArray[i];
	}
	return flattenedArray;
}

//unsigned int midSectionAverage(unsigned char * Array, int numOfPoints)
//{
//	unsigned char * testArray;
//	testArray[0]=Array;
//	int  totalSum=0;
//	int average;
//	int i;
//	int length = sizeof(Array[0])/sizeof(Array[0]);
//	
//	for (i = 0; i < length; i++)
//	{
//		totalSum += testArray[i];
//	}
//	
//	average = totalSum / numOfPoints;
//	return average;
//		
//}	

	



int main(void)
{
	Init_FTM0();
	Init_FTM1();
	InitTAOS();
	InitADCs();
	//Delays
	//Read from ADC
	//Store in array
	//servo = FTM1_C0V_MID_VALUE;
	//dc0 = FTM0_C0V_MIN_VALUE;
	//dc1 = FTM0_C1V_MIN_VALUE;

	//TESTING
	while (1)
	{
	int i;
	Change_FTM0_C0V_PWM(dc0);
	Change_FTM0_C1V_PWM(dc1);
	Change_FTM1_C0V_PWM(servo);
	Delay(1);
	
	
	ImageCapture(&ImageData[0]);
	track_offset = FlattenArray(&ImageData[0]);
	int x;
	for (x = 0; x < 45; x++)
	{
		unsigned char newArray[x] = FlattenedArray[x];
	}
	midSectionAverage(newArray[0],45);
	
	
	
	}
	return 0;
}
	
	

