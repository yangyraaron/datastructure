/*
 * stkp.h
 *
 *  Created on: Aug 6, 2013
 *      Author: wisedulab2
 */

#ifndef STKP_H_
#define STKP_H_

#include "stk.h"

 typedef struct  stack_control_s
 {
 	void **stack;
 	void **sptr;
 	size_t size;
 } STK_CONTROL_t,*STK_CONTROL_p_t;

#endif /* STKP_H_ */
