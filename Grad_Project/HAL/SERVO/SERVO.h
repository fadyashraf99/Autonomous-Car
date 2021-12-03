/*
 * SERVO.h
 *
 *  Created on: Oct 15, 2021
 *      Author: FADY
 */

#ifndef HAL_SERVO_SERVO_H_
#define HAL_SERVO_SERVO_H_

#include <avr/io.h>
#include <avr/interrupt.h>

void tim1_pwm(void);
void servo_write(char angle);

#endif /* HAL_SERVO_SERVO_H_ */
