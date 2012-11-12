/*
 * servo.h
 *
 *  Created on: Oct 19, 2012
 *      Author: ulab
 */

#ifndef SERVO_H_
#define SERVO_H_

#define FTM0_CLK_PRESCALE	1
#define FTM0_CLK_SOURCE		1
#define FTM0_MOD_VALUE		4999 //5 kHz

#define FTM1_CLK_PRESCALE	4
#define FTM1_CLK_SOURCE		1
#define FTM1_MOD_VALUE		31249 //20ms

//H-Bridge PWM
#define FTM0_C0V_MIN_VALUE	0
#define FTM0_C0V_MAX_VALUE	4500
#define FTM0_C1V_MIN_VALUE	0
#define	FTM0_C1V_MAX_VALUE	4500

//Servo PWM
#define FTM1_C0V_MID_VALUE	2100	
#define FTM1_C0V_MAX_VALUE	2780 //trimmed value so servo doesn't over exert
#define FTM1_C0V_MIN_VALUE	1800 //trimmed value so servo doesn't over exert

void Init_FTM0(void);
void Init_FTM1(void);
void Change_FTM0_C0V_PWM(int newCount);
void Change_FTM0_C1V_PWM(int newCount);
void Change_FTM1_C0V_PWM(int newCount);


#endif /* SERVO_H_ */
