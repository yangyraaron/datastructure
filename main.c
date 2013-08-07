/*
 * main.c
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "list.h"
#include "stk.h"

void print_item(void *item){
	char *data = (char *) item;

	printf("item value is %s\n", data);
}

void clear(void *item){
	memset((char *)item,0,10);
}

void test_list(LIST_ID_t list){
	printf("the list is empty %s\n", LIST_is_list_empty(list)?"true":"false");
	printf("the list is full %s\n", LIST_is_list_full(list)?"true":"false");
	printf("the list size is %d\n", (int)LIST_get_list_size(list));
}

void call_list(){
	LIST_ID_t list = LIST_create_list(10,10,"list_test");

	LIST_add_entry(list,"test1");
	LIST_add_entry(list,"test2");
	LIST_add_entry(list,"test3");
	LIST_add_entry(list,"test4");
	LIST_add_entry(list,"test5");

	test_list(list);

	CDA_ASSERT(LIST_get_list_size(list)==5);

	LIST_DESTROY_PROC_p_t print = print_item;
	LIST_traversal_list(list,print);
	LIST_clear_list(list,clear);

	test_list(list);
	CDA_ASSERT(LIST_get_list_size(list)==0);

	LIST_destroy_list(list,clear);

	test_list(list);
	//list=NULL;
	CDA_ASSERT(list==NULL);
}

void test_stack(STK_ID_t stack){
	printf(" the stack is empty %s\n", STK_is_empty(stack)?"true":"false");
	printf(" the stack is full %s\n", STK_is_full(stack)?"true":"false");
}

void call_stack(){
	STK_ID_t stack = STK_create_stack(10);

	STK_push_item(stack,"test1");
	STK_push_item(stack,"test2");
	STK_MARK_t mark3 = STK_push_item(stack,"test3");

	test_stack(stack);

	printf("the top item is : %s\n", (char *)STK_peek_item(stack));
	printf("the third item is : %s\n",(char *)STK_get_item(stack,mark3,0));

	STK_change_item(stack,mark3,0,"reset_test3");

	while(!STK_is_empty(stack)){
		printf("the next item : %s\n", (char *)STK_pop_item(stack));
	}

	STK_clear(stack);
	test_stack(stack);

	STK_destroy(stack);

	CDA_ASSERT(stack==NULL);

	test_stack(stack);

}



int main(void){

	call_stack();

	exit(EXIT_SUCCESS);
}
