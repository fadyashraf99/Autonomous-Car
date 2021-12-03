/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: FADY
 */

#include "MCAL/Dio/Dio.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/timer/timer.h"
#include "HAL/SERVO/SERVO.h"
#include "HAL/LCD/LCD.h"
#include "HAL/ultrasonic/ultrasonic.h"
#include "HAL/DC/DC.h"

extern uint32_t distance;

int main() {
	Dio_init();				//initialize dio
	lcd_init();				//initialize LCD
	ultrasonic_init();		//initialize ultrasonic
	tim1_pwm();				//initialize servo
	sei();

	//initial states for start up
	Dio_write(SS, HIGH);		//set H enable 1 (named according to the name of pin on board)
	Dio_write(MOSI, HIGH);		//set H enable 2 (named according to the name of pin on board)
	servo_write(90);			//set servo initial angle
	_delay_ms(500);

	while (1) {
		ultra_triger();			//take reading of ultrasonic and print on LCD
		_delay_ms(15);
		servo_write(90);
		forward();
		_delay_ms(100);

		if (distance <= 20) {
			lcd_clear();
			lcd_write_word("obstacle detected");
			_delay_ms(10);
			stop();
			servo_write(45);		//look left
			_delay_ms(1000);
			lcd_clear();
			ultra_triger();
			if (distance <= 20) {
				lcd_clear();
				lcd_write_word("obstacle detected");
				_delay_ms(10);
				servo_write(135);	//look right
				_delay_ms(1000);
				lcd_clear();
				ultra_triger();
				if (distance <= 20) {
					lcd_clear();
					lcd_write_word("obstacle detected");
					_delay_ms(10);
					backward();
					_delay_ms(1000);
					right();
					_delay_ms(500);
					stop();
					_delay_ms(500);
					lcd_clear();
					servo_write(90);
					ultra_triger();
				} else {
					lcd_clear();
					lcd_write_word("no obstacle detected");
					_delay_ms(10);
					left();
					_delay_ms(500);
					lcd_clear();
					servo_write(90);
				}
			} else {
				lcd_clear();
				lcd_write_word("no obstacle detected");
				_delay_ms(10);
				right();
				_delay_ms(500);
				lcd_clear();
				servo_write(90);
			}
		}
		lcd_clear();
		lcd_write_word("no obstacle detected");
		_delay_ms(100);
		lcd_clear();
	}
	return 0;
}
