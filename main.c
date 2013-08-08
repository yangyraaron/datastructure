 /* main.c
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "list.h"
#include "stk.h"
#include "lklist.h"
#include "mgsort.h"

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

void test_linklist(const char *desc,ENQ_ANCHOR_p_t list){
	printf("#############################################\n");
	printf("%s\n",desc);
	printf("---------------------------------------------\n");

	if(ENQ_is_list_empty(list)){
		printf("the list %s is empty",list->name);
	}

	ENQ_ITEM_p_t item = ENQ_GET_HEAD(list);
	while(item!=list){
		printf("the item is : %s \n",item->name);
		item = ENQ_GET_NEXT(item);
	}

	printf("##############################################\n");

}

void call_linklist(){
	ENQ_ANCHOR_p_t list =  ENQ_create_list("list_test");

	int i=1;
	char *name=CDA_malloc(sizeof(char *));
	while(i<11){
		sprintf(name,"%d",i);
		ENQ_ITEM_p_t item = ENQ_create_item(name,sizeof(ENQ_ITEM_t));
		ENQ_add_tail(list,item);

		i++;
	}
	CDA_free(name);
	test_linklist("test create item and add to tail",list);

	ENQ_ITEM_p_t item = ENQ_create_item("0",sizeof(ENQ_ITEM_t));
	ENQ_add_header(list,item);
	test_linklist("test add item to header",list);
	
	ENQ_ITEM_p_t item_tail = ENQ_create_item("11",sizeof(ENQ_ITEM_t));
	ENQ_add_tail(list,item_tail);
	test_linklist("test add item to tail",list);
	
	ENQ_ITEM_p_t first = ENQ_GET_HEAD(list);
	ENQ_ITEM_p_t second = ENQ_GET_NEXT(first);
	
	ENQ_ITEM_p_t th_item = ENQ_create_item("03",sizeof(ENQ_ITEM_t));
	ENQ_add_after(th_item,second);
	
	ENQ_ITEM_p_t se_item = ENQ_create_item("02",sizeof(ENQ_ITEM_t));
	ENQ_add_before(se_item,second);
	test_linklist("test add after and before to item",list);
	
	ENQ_ITEM_p_t item_02 = ENQ_deq_item(ENQ_GET_PREV(second));
	ENQ_ITEM_p_t item_03 = ENQ_deq_item(ENQ_GET_NEXT(second));
	
	CDA_ASSERT(ENQ_is_item_enqed(item_02)==CDA_FALSE);
	CDA_ASSERT(ENQ_is_item_enqed(item_03)==CDA_FALSE);
	test_linklist("test enqueue the item",list);

	ENQ_destroy_list(list);


}

int compare_int(const void *value1, const void *value2){
	const int *int_value1 = (const int *) value1;
	const int *int_value2 = (const int *) value2;
	
	int sub = *int_value1-*int_value2;
	if(sub<0) return -1;
	if(sub>0) return 1;
	return sub;
	
}

void call_mergesort(){
	int array[10] = {10,3,7,6,1,5,9,4,8,2};

	mergesort(array,10,sizeof(int),(CMP_PROC_p_t)compare_int);
	
	int i=0;
	for(i=0;i<10;i++){
		printf("%d \n",array[i]);
	}
}

int main(void){
	call_mergesort();

	exit(EXIT_SUCCESS);
}
