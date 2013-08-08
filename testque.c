/*
 * testque.c
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */
#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "que.h"

static QUE_TRAVERSE_PROC_t traverse;
static QUE_DESTROY_PROC_t destroy;

static const char *itemNames[]={ "hydrogen", "helium","lithium","beryllium","boron","carbon","nitrogen", "oxygen","fluorine","neon"};

void test_que(){
	int *data = NULL;
	QUE_ID_t  que = QUE_NULL_ID;
	QUE_ITEM_p_t item = NULL;
	int inx = 0;

	que = QUE_create_que("test");
	for (inx = 0; inx < CDA_CARD(itemNames); ++inx)
	{
		data = CDA_malloc(sizeof(int));
		*data = inx;
		item = QUE_Create_item(itemNames[inx],data);

		QUE_append(que,item);
	}

	QUE_traverse_queue(que,traverse);
	int length = CDA_CARD(itemNames)/2;

	for (inx = 0; inx < length; ++inx)
	{
		item = QUE_dequeue(que);
		printf("dequeue item :%s\n", item->item.name);
		CDA_free(item->data);
		QUE_destroy_item(item);
	}

	QUE_destroy_queue(que,destroy);
}

static void traverse(void *data){
	int *idata = data;
	printf("traversing %d\n",*idata );
}

static void destroy(void *data){
	int *idata = data;
	printf("destroying data %d\n", *idata);
	CDA_free(idata);
}
