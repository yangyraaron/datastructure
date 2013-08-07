/*
 * listp.h
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#ifndef LISTP_H_
#define LISTP_H_

#include "list.h"

 typedef char *LIST_ENTRY_p_t;
 typedef struct list_control_s
 {
 	LIST_ENTRY_p_t array;
 	size_t max_size;
 	size_t entry_size;
 	int next;
 	char *name;
 } LIST_CONTROL_t,*LIST_CONTROL_p_t;

#endif /* LISTP_H_ */
