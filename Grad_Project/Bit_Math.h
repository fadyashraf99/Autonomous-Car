/*
 * Bit_Math.h
 *
 *  Created on: Sep 10, 2021
 *      Author: FADY
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(u8Var,BitNo)	u8Var |= (1<<BitNo)
#define CLR_BIT(u8Var,BitNo)	u8Var &= ~(1<<BitNo)
#define TOGGLE_BIT(u8Var,BitNo)	u8Var ^= (1<<BitNo)
#define GET_BIT(u8Var,BitNo)	((u8Var >> BitNo) & 0b00000001)

#endif /* BIT_MATH_H_ */
