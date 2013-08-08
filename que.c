/*
 * que.c
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */
#include "quep.h"

QUE_ID_t QUE_create_que(const char *name){
	QUE_CONTROL_p_t que = CDA_NEW(QUE_CONTROL_t);
	que->anchor = ENQ_create_list(name);

	return que;
}

QUE_ITEM_p_t QUE_Create_item(const char *name,void *data){
	QUE_ITEM_p_t item = (QUE_ITEM_p_t)ENQ_create_item(name,sizeof(QUE_ITEM_t));
	item->data = data;

	return item;
}

QUE_ID_t QUE_clear(QUE_ID_t que,QUE_DESTROY_PROC_p_t destroy_proc){
	QUE_ITEM_p_t item = NULL;
	while(!ENQ_is_list_empty(que->anchor)){
		item = (QUE_ITEM_p_t)ENQ_GET_HEAD(que->anchor);
		if(destroy_proc!=NULL)
			destroy_proc(item->data);
		QUE_destroy_item(item);
	}

	return que;
}

QUE_ITEM_p_t QUE_append(QUE_ID_t que,QUE_ITEM_p_t item){
	ENQ_add_tail(que->anchor,(ENQ_ITEM_p_t)item);

	return item;
}

CDA_BOOL_t QUE_is_empty(QUE_ID_t que){
	return ENQ_is_list_empty(que->anchor);
}

CDA_BOOL_t QUE_is_full(QUE_ID_t que){
	return CDA_FALSE;
}

QUE_ITEM_p_t QUE_destroy_item(QUE_ITEM_p_t item){
	ENQ_destroy_item((ENQ_ITEM_p_t) item);

	return NULL;
}
QUE_ID_t QUE_destroy_queue(QUE_ID_t que,QUE_DESTROY_PROC_p_t destroy_proc){
	QUE_clear(que,destroy_proc);
	ENQ_destroy_list(que->anchor);
	CDA_free(que);

	return QUE_NULL_ID;
}

QUE_ITEM_p_t QUE_dequeue(QUE_ID_t que){
	if(QUE_is_empty(que))
		return NULL;
	return (QUE_ITEM_p_t) ENQ_deq_head(que->anchor);
}

QUE_ITEM_p_t QUE_retrieve(QUE_ID_t que){
	if(QUE_is_empty(que))
		return NULL;
	return (QUE_ITEM_p_t) ENQ_GET_HEAD(que->anchor);
}

QUE_ID_t QUE_traverse_queue(QUE_ID_t que,QUE_TRAVERSE_PROC_p_t traverse_proc){
	if(QUE_is_empty(que))
		return que;

	QUE_ITEM_p_t item = (QUE_ITEM_p_t)ENQ_GET_HEAD(que->anchor);
	QUE_ITEM_p_t tail = (QUE_ITEM_p_t)ENQ_GET_TAIL(que->anchor);
	traverse_proc(item->data);
	while(item!=tail){
		item = (QUE_ITEM_p_t) ENQ_GET_NEXT((ENQ_ITEM_p_t)item);

		traverse_proc(item->data);
	}
	return que;
}
