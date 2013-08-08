/*
 * prq.c
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */

//#include "cda.h"
#include "prqp.h"

PRQ_ID_t PRQ_create_queue(const char *name,CDA_UINT32_t max_priority){
	PRQ_CONTROL_p_t queue= CDA_malloc(sizeof(PRQ_CONTROL_t));

	queue->anchor = ENQ_create_list(name);
	queue->max_priority = max_priority;

	return queue;
}

PRQ_ITEM_p_t PRQ_create_item(void *data,CDA_UINT32_t priority){
	PRQ_ITEM_p_t item = (PRQ_ITEM_p_t)ENQ_create_item(NULL,sizeof(PRQ_ITEM_t));
	item->data = data;
	item->priority = priority;

	return item;
}

CDA_BOOL_t PRQ_is_empty(PRQ_ID_t queue){
	return ENQ_is_list_empty(queue->anchor);
}

PRQ_ITEM_p_t PRQ_add_item(PRQ_ID_t queue,PRQ_ITEM_p_t item){
	if(item->priority>queue->max_priority)
		abort();

	PRQ_ITEM_p_t temp = (PRQ_ITEM_p_t)ENQ_GET_HEAD(queue->anchor);

	while(temp!=NULL && temp->priority>=item->priority){
		//at the end of the queue
		if(temp == (PRQ_ITEM_p_t) queue->anchor)
			temp = NULL;
		else
			temp = (PRQ_ITEM_p_t)ENQ_GET_NEXT(((ENQ_ITEM_p_t)temp));
	}

	if(temp==NULL)
		ENQ_add_tail(queue->anchor,(ENQ_ITEM_p_t) item);
	else
		ENQ_add_before((ENQ_ITEM_p_t)item,(ENQ_ITEM_p_t)temp);

	return item;
}

PRQ_ITEM_p_t PRQ_dequeue(PRQ_ID_t queue){
	ENQ_ANCHOR_p_t anchor = queue->anchor;
	ENQ_ITEM_p_t item = ENQ_deq_head(anchor);

	if(item == anchor)
		return NULL;

	return (PRQ_ITEM_p_t)item;
}

PRQ_ITEM_p_t PRQ_destroy_item(PRQ_ITEM_p_t item){
	ENQ_destroy_item((ENQ_ITEM_p_t) item);

	return NULL;
}

PRQ_ID_t PRQ_clear(PRQ_ID_t queue,PRQ_DESTROY_PROC_t destroy_proc){
	PRQ_ITEM_p_t head = NULL;

    while(!ENQ_is_list_empty(queue->anchor)){
    	 head = (PRQ_ITEM_p_t)ENQ_GET_HEAD(queue->anchor);

    	if(destroy_proc!=NULL)
    		destroy_proc(head->data);

    	ENQ_destroy_item((ENQ_ITEM_p_t)head);
    }

    return queue;
}

PRQ_ID_t PRQ_destroy(PRQ_ID_t queue,PRQ_DESTROY_PROC_t destroy_proc){
	PRQ_clear(queue,destroy_proc);
	ENQ_destroy_list(queue->anchor);

	CDA_free(queue);

	return PRQ_NULL_ID;
}
