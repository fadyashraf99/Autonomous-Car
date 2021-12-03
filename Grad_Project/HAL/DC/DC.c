/*
 * DC.c
 *
 *  Created on: Dec 3, 2021
 *      Author: FADY
 */

#include "DC.h"

void forward (void){	//set motor to move forward
	Dio_write(H_A1, HIGH);
	Dio_write(H_A3, HIGH);
	Dio_write(H_A2, LOW);
	Dio_write(H_A4, LOW);
}

void backward (void){//set motor to move backward
	Dio_write(H_A1, LOW);
	Dio_write(H_A3, LOW);
	Dio_write(H_A2, HIGH);
	Dio_write(H_A4, HIGH);

}

void left (void){//set motor to move left
	Dio_write(H_A1, HIGH);
	Dio_write(H_A3, LOW);
	Dio_write(H_A2, LOW);
	Dio_write(H_A4, HIGH);

}

void right (void){//set motor to move right
	Dio_write(H_A1, LOW);
	Dio_write(H_A3, HIGH);
	Dio_write(H_A2, HIGH);
	Dio_write(H_A4, LOW);

}

void stop (void){//set motor to stop moving
	Dio_write(H_A1, LOW);
	Dio_write(H_A3, LOW);
	Dio_write(H_A2, LOW);
	Dio_write(H_A4, LOW);

}

