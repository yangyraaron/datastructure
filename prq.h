/*
 * prq.h
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */

#ifndef PRQ_H_
#define PRQ_H_

#include "cda.h"
#include "prq.h"
#include "lklist.h"

#define PRQ_NULL_ID (NULL)
typedef struct prq_control_s *PRQ_ID_t;

typedef struct prq_item_s {
	ENQ_ITEM_t enq_item;
	void *data;
	CDA_UINT32_t priority;
} PRQ_ITEM_t, *PRQ_ITEM_p_t;

typedef void PRQ_DESTROY_PROC_t(void *data);
typedef  PRQ_DESTROY_PROC_t *PRQ_DESTROY_PROC_p_t;

PRQ_ID_t PRQ_create_queue(const char *name, CDA_UINT32_t max_priority);
PRQ_ITEM_p_t PRQ_create_item(void *data, CDA_UINT32_t priority);
CDA_BOOL_t PRQ_is_empty(PRQ_ID_t queue);
PRQ_ITEM_p_t PRQ_add_item(PRQ_ID_t queue, PRQ_ITEM_p_t item);
PRQ_ITEM_p_t PRQ_dequeue(PRQ_ID_t queue);
PRQ_ITEM_p_t PRQ_destroy_item(PRQ_ITEM_p_t item);
PRQ_ID_t PRQ_clear(PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc);
PRQ_ID_t PRQ_destroy(PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc);

#define PRQ_GET_DATA(item) ((item)->data)
#define PRQ_GET_PRIORITY(item) ((item)->priority)

#endif /* PRQ_H_ */
