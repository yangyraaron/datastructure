/*
 * list.h
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#ifndef LIST_H_
#define LIST_H_

#define LIST_NULL_ID (NULL)

typedef struct list_control_s *LIST_ID_t;

typedef void LIST_DESTROY_PROC_t(void *);
typedef LIST_DESTROY_PROC_t *LIST_DESTROY_PROC_p_t;

typedef void LIST_TRAVERSAL_PROC_t(void *);
typedef LIST_TRAVERSAL_PROC_t *LIST_TRAVERSAL_PROC_p_t;

LIST_ID_t LIST_create_list(size_t max_list_size, size_t entry_size,
		const char *name);
LIST_ID_t LIST_add_entry(LIST_ID_t list, const void *data);
LIST_ID_t LIST_traversal_list(LIST_ID_t list,
		LIST_TRAVERSAL_PROC_p_t traversal_proc);
CDA_BOOL_t LIST_is_list_empty(LIST_ID_t list);
CDA_BOOL_t LIST_is_list_full(LIST_ID_t list);
size_t LIST_get_list_size(LIST_ID_t list);
LIST_ID_t LIST_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc);
void LIST_destroy_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc);

#endif /* LIST_H_ */
