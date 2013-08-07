/*
 * stk.h
 *
 *  Created on: Aug 6, 2013
 *      Author: wisedulab2
 */

#ifndef STK_H_
#define STK_H_
#include <stdlib.h>
#include "cda.h"

#define STK_NULL_ID (NULL)
typedef struct stack_control_s *STK_ID_t;
typedef int STK_MARK_t, *STK_MARK_p_t;

STK_ID_t STK_create_stack(size_t size);
STK_MARK_t STK_push_item(STK_ID_t stack,void *item);
void *STK_pop_item(STK_ID_t stack);
void *STK_peek_item(STK_ID_t stack);
CDA_BOOL_t STK_is_empty(STK_ID_t stack);
CDA_BOOL_t STK_is_full(STK_ID_t stack);
void STK_clear(STK_ID_t stack);
STK_ID_t STK_destroy(STK_ID_t stack);
void *STK_get_item(STK_ID_t stack,STK_MARK_t mark,int offset);
void STK_change_item(STK_ID_t stack,STK_MARK_t mark,int offset,void *val);
void STK_clear_to_mark(STK_ID_t stack,STK_MARK_t mark);
STK_MARK_t STK_grab_space(STK_ID_t stack,int num_slots,STK_MARK_p_t bottom_mark);

#endif /* STK_H_ */
