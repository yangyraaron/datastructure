/*
 * list.c
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */
#include <stdlib.h>
#include "cda.h"
#include "listp.h"


 LIST_ID_t LIST_create_list(size_t max_list_size,size_t entry_size,const char *name){
 	LIST_CONTROL_p_t list = CDA_NEW(LIST_CONTROL_t);

 	list->array = CDA_calloc(max_list_size,entry_size);
 	list->max_size = max_list_size;
 	list->entry_size = entry_size;
 	list->next = 0;
 	list->name = CDA_NEW_STR_IF(name);

 	return list;
 }

 LIST_ID_t LIST_add_entry(LIST_ID_t list,const void *data){
 	LIST_ENTRY_p_t nextEntry = list->array+list->next*list->entry_size;

 	if(list->next>=(int)list->max_size)
 		abort();

 	memmove(nextEntry,data,strlen(data));
 	++list->next;

 	return list;
 }

LIST_ID_t LIST_traversal_list(LIST_ID_t list,LIST_TRAVERSAL_PROC_p_t traversal_proc){
	LIST_ENTRY_p_t entry = list->array;

	if(traversal_proc==NULL)
		return list;

	int i=0;
	for (i=0; i < list->next; ++i)
	{
		traversal_proc(entry);
		entry += list->entry_size;
	}
	return list;
}

CDA_BOOL_t LIST_is_list_empty(LIST_ID_t list){
	return list->next==CDA_FALSE;
}

CDA_BOOL_t LIST_is_list_full(LIST_ID_t list){
	return list->next == list->max_size-1;
}

size_t LIST_get_list_size(LIST_ID_t list){
	size_t size = (size_t) list->next;

	return size;
}

LIST_ID_t LIST_clear_list(LIST_ID_t list,LIST_DESTROY_PROC_p_t destroy_proc){
	if(destroy_proc!=NULL){
		int i=0;
		for (i = 0; i < list->next; ++i)
		{
			destroy_proc(list->array+i*list->entry_size);
		}
	}

	list->next = 0;
	return list;
}

void LIST_destroy_list(LIST_ID_t list,LIST_DESTROY_PROC_p_t destroy_proc){
	LIST_clear_list(list,destroy_proc);

	CDA_free(list->array);
	CDA_free(list->name);
	CDA_free(list);
}

