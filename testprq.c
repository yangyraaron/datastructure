/*
 * testprq.c
 *
 *  Created on: Aug 8, 2013
 *      Author: wisedulab2
 */


#include <stdio.h>
#include "cda.h"
#include "prq.h"

#define DEL_PRI (0)
#define MOD_PRI (1)
#define ADD_PRI (2)
#define MAX_PRI (ADD_PRI)

typedef enum operation_e{
	del,
	mod,
	add
} OPERATION_e_t;

typedef struct queue_data_s
{
	OPERATION_e_t operation;
	void *data;
} QUEUE_DATA_t,*QUEUE_DATA_p_t;

static PRQ_DESTROY_PROC_t destroy_proc;
static PRQ_ID_t queue_ = PRQ_NULL_ID;

void TRANS_init(void){
	CDA_ASSERT(queue_ == PRQ_NULL_ID);

	queue_ = PRQ_create_queue("transaction queue",MAX_PRI);
}

void TRANS_shutdown(void){
	if(queue_!=PRQ_NULL_ID)
		PRQ_destroy(queue_,destroy_proc);

	queue_ = NULL;
}

void TRANS_enq_transaction(void *data,const char *operation){
	CDA_UINT32_t pri = 0;
	QUEUE_DATA_p_t pdata = CDA_NEW(QUEUE_DATA_t);
	PRQ_ITEM_p_t item = NULL;

	pdata->data = data;

	if(strcmp(operation,"delete")==0){
		pri = DEL_PRI;
		pdata->operation = del;
	}else if(strcmp(operation,"modify")==0){
		pri = MOD_PRI;
		pdata->operation = mod;
	}else if(strcmp(operation,"add")==0){
		pri = ADD_PRI;
		pdata->operation = add;
	}else
		abort();

	item = PRQ_create_item(pdata,pri);
	PRQ_add_item(queue_,item);
}

void *TRANS_get_transaction(const char **operation){
	QUEUE_DATA_p_t qdata = NULL;
	void *data = NULL;
	PRQ_ITEM_p_t item = PRQ_dequeue(queue_);

	if(item!=NULL){
		qdata = (QUEUE_DATA_p_t)PRQ_GET_DATA(item);
		data = qdata->data;

		switch(qdata->operation){
			case del:
				*operation = "delete";
				break;
			case mod:
				*operation = "modify";
				break;
			case add:
				*operation = "add";
				break;
			default:
				break;
		}

		CDA_free(qdata);
		PRQ_destroy_item(item);
	}

	return data;
}

static void destroy_proc(void *data){
	QUEUE_DATA_p_t pdata = data;
	printf("destroying transaction type %d\n", pdata->operation );

	CDA_free(pdata);
}

void TRANS_prq(){
	TRANS_init();

	TRANS_enq_transaction("add 1","add");
	TRANS_enq_transaction("mod 2","modify");
	TRANS_enq_transaction("del 1","delete");
	TRANS_enq_transaction("mod 2","modify");
	TRANS_enq_transaction("add 3","add");
	TRANS_enq_transaction("add 4","add");
	TRANS_enq_transaction("mod 3","modify");
	TRANS_enq_transaction("del 3","delete");
	TRANS_enq_transaction("del 4","delete");

	const char **p=CDA_malloc(sizeof(char *));

	while(!PRQ_is_empty(queue_)){
		char *data = (char *)TRANS_get_transaction(p);

		printf("the data is %s  priority is %s \n",data,*p);
	}

	CDA_free(p);
	TRANS_shutdown();
}
