/*
 * lklist.c
 *
 *  Created on: Aug 7, 2013
 *      Author: wisedulab2
 */


#include "lklistp.h"

ENQ_ANCHOR_p_t ENQ_create_list(const char *name){
	ENQ_ANCHOR_p_t list = CDA_malloc(sizeof(ENQ_ANCHOR_t));

	list->flink = list;
	list->blink = list;
	list->name = CDA_NEW_STR_IF(name);

	return list;
}

 ENQ_ITEM_p_t ENQ_create_item(const char *name,size_t size){
 	ENQ_ITEM_p_t item = (ENQ_ITEM_p_t) CDA_malloc(size);

 	CDA_ASSERT(size>=sizeof(ENQ_ITEM_t));
 	item->flink = item;
 	item->blink = item;
 	item->name = CDA_NEW_STR_IF(name);

 	return item;
 }

 CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item){
 	return item->flink==item?CDA_FALSE:CDA_TRUE;
 }

 CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t list){
 	return list->flink==list?CDA_TRUE:CDA_FALSE;
 }

 ENQ_ITEM_p_t ENQ_add_header(ENQ_ANCHOR_p_t list,ENQ_ITEM_p_t item){
 	CDA_ASSERT(!ENQ_is_item_enqed(item));

 	item->flink = list->flink;
 	item->blink = list;

 	list->flink->blink=item;
 	list->flink = item;

 	return item;
 }

 ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list,ENQ_ITEM_p_t item){
 	CDA_ASSERT(!ENQ_is_item_enqed(item));

 	item->flink = list;
 	item->blink = list->blink;

 	list->blink->flink = item;
 	list->blink = item;

 	return item;
 }

ENQ_ITEM_p_t ENQ_add_after(ENQ_ITEM_p_t item,ENQ_ITEM_p_t after){
	CDA_ASSERT(!ENQ_is_item_enqed(item));

	after->flink->blink = item;
	item->flink = after->flink;
	after->flink=item;
	item->blink = after;

	return item;
}

ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item,ENQ_ITEM_p_t before){
	CDA_ASSERT(!ENQ_is_item_enqed(item));

	before->blink->flink = item;
	item->blink = before->blink;
	item->flink = before;
	before->blink = item;

	return item;
}

ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item){
	item->blink->flink=item->flink;
	item->flink->blink = item->blink;

	item->flink=item;
	item->blink=item;
	
	return item;
}

ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list){
	ENQ_ITEM_p_t item = list->flink;

	list->flink = item->flink;
	list->flink->blink=list;

	item->flink = item;
	item->blink = item;

	return item;
}

ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list){
	ENQ_ITEM_p_t item = list->blink;

	list->blink = item->blink;
	list->blink->flink = list;

	item->flink = item;
	item->blink = item;

	return item;
}

ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t item){
	ENQ_deq_item(item);

	CDA_free(item->name);
	CDA_free(item);

	return NULL;
}

ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list){
	while(!ENQ_is_list_empty(list)){
		ENQ_destroy_item(list->flink);
	}

	return list;
}

ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list){
	ENQ_empty_list(list);

	CDA_free(list->name);
	CDA_free(list);

	return NULL;
}
