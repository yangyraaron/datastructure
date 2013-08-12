/*
 * stk.c
 *
 *  Created on: Aug 6, 2013
 *      Author: wisedulab2
 */


#include "cda.h"
#include "stkp.h"

STK_ID_t STK_create_stack(size_t size){
	STK_CONTROL_p_t stack = CDA_NEW(STK_CONTROL_t);

	stack->stack = CDA_calloc(size,sizeof(void *));
	stack->sptr = stack->stack;
	stack->size = size;

	return (STK_ID_t)stack;
}

void STK_clear(STK_ID_t stack){
	stack->sptr=stack->stack;
}

STK_ID_t STK_destroy(STK_ID_t stack){
	CDA_free(stack->stack);
	stack->sptr=NULL;
	CDA_free(stack);

	return STK_NULL_ID;
}

void *STK_peek_item(STK_ID_t stack){
	CDA_ASSERT(stack->sptr!=stack->stack);

	return *(stack->sptr-1);
}

void *STK_pop_item(STK_ID_t stack){
	void *item = *(stack->sptr-1);

	stack->sptr = stack->sptr-1;
	*(stack->sptr+1)=NULL;

	return item;
}

STK_MARK_t STK_push_item(STK_ID_t stack, void *item){

	if(stack->sptr-stack->stack>stack->size){
		abort();
	}

	*stack->sptr=item;
	stack->sptr = stack->sptr+1;

	return (int)(stack->sptr-stack->stack-1);
}

CDA_BOOL_t STK_is_empty(STK_ID_t stack){
	return stack->sptr == stack->stack?CDA_TRUE:CDA_FALSE;
}

CDA_BOOL_t STK_is_full(STK_ID_t stack){
	return stack->sptr-stack->stack==stack->size?CDA_TRUE:CDA_FALSE;
}

void *STK_get_item(STK_ID_t stack,STK_MARK_t mark,int offset){
	CDA_ASSERT(stack->stack+mark>=stack->stack);
	CDA_ASSERT(stack->stack+mark<stack->sptr);
	CDA_ASSERT(stack->stack+mark+offset>=stack->stack);
	CDA_ASSERT(stack->stack+mark+offset<stack->sptr);

	return *(stack->stack+mark+offset);
}

void STK_change_item(STK_ID_t stack,STK_MARK_t mark,int offset,void *val){
	CDA_ASSERT(stack->stack+mark>=stack->stack);
	CDA_ASSERT(stack->stack+mark<stack->sptr);
	CDA_ASSERT(stack->stack+mark+offset>=stack->stack);
	CDA_ASSERT(stack->stack+mark+offset<stack->sptr);

	*(stack->stack+mark+offset)=val;
}

void STK_clear_to_mark(STK_ID_t stack,STK_MARK_t mark){
	CDA_ASSERT(stack->stack+mark>=stack->stack);
	CDA_ASSERT(stack->stack+mark<stack->sptr);

	stack->sptr = stack->stack+mark;
}

STK_MARK_t STK_grab_space(STK_ID_t stack,int num_slots,STK_MARK_p_t bottom_mark){
	if(stack->sptr+num_slots>stack->stack+stack->size)
		abort();

	if(bottom_mark!=NULL)
		*bottom_mark = (int)(stack->sptr-stack->stack);

	stack->sptr+=num_slots;

	return (int)(stack->sptr-stack->stack-1);
}
