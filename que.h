/*
 * que.h
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */

#ifndef QUE_H_
#define QUE_H_
#include "lklist.h"

#define QUE_NULL_ID (NULL)
typedef struct que_control_s *QUE_ID_t;
typedef void QUE_DESTROY_PROC_t(void *data);
typedef QUE_DESTROY_PROC_t *QUE_DESTROY_PROC_p_t;
typedef void QUE_TRAVERSE_PROC_t(void *data);
typedef QUE_TRAVERSE_PROC_t *QUE_TRAVERSE_PROC_p_t;

typedef struct que_item_s
{
	ENQ_ITEM_t item;
	void *data;
}QUE_ITEM_t,*QUE_ITEM_p_t;

QUE_ID_t QUE_create_que(const char *name);
QUE_ITEM_p_t QUE_Create_item(const char *name,void *data);
QUE_ID_t QUE_clear(QUE_ID_t que,QUE_DESTROY_PROC_p_t destroy);
QUE_ITEM_p_t QUE_append(QUE_ID_t que,QUE_ITEM_p_t item);
CDA_BOOL_t QUE_is_empty(QUE_ID_t que);
CDA_BOOL_t QUE_is_full(QUE_ID_t que);
QUE_ITEM_p_t QUE_destroy_item(QUE_ITEM_p_t item);
QUE_ID_t QUE_destroy_queue(QUE_ID_t que,QUE_DESTROY_PROC_p_t destroy_proc);
QUE_ITEM_p_t QUE_dequeue(QUE_ID_t que);
QUE_ITEM_p_t QUE_retrieve(QUE_ID_t que);
QUE_ID_t QUE_traverse_queue(QUE_ID_t que,QUE_TRAVERSE_PROC_p_t traverse_proc);

#endif /* QUE_H_ */
