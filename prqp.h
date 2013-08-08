/*
 * prqp.h
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */

#ifndef PRQP_H_
#define PRQP_H_
#include "prq.h"

 typedef struct prq_control_s
 { 
 	ENQ_ANCHOR_p_t anchor;
 	CDA_UINT32_t max_priority;
 } PRQ_CONTROL_t,*PRQ_CONTROL_p_t;

#endif /* PRQP_H_ */
