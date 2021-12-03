/*
 * SERVO.c
 *
 *  Created on: Oct 15, 2021
 *      Author: FADY
 */

#include "SERVO.h"

void tim1_pwm(void)				//initialize servo
{
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
	ICR1 = 4999;
}

void servo_write(char angle)	//set servo angle
{
	OCR1A = (int) ((angle * 2.78f) + 125);
}
