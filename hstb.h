//
//  hstb.h
//  datastructure
//
//  Created by aaron on 13-8-12.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_hstb_h
#define datastructure_hstb_h
#include "cda.h"

#define HASH_TABLE_NULL_ID (NULL)

typedef struct list_node *node_ptr;
typedef struct hash_table *HASH_TABLE_ID_t;
typedef void H_destroy_proc(CDA_UINT16_t index, void *data);
typedef H_destroy_proc *H_destroy_proc_p;

HASH_TABLE_ID_t H_create(CDA_UINT16_t size);
void *H_get(const char *key,HASH_TABLE_ID_t hashtable);
void H_set(const char *key, void *data,HASH_TABLE_ID_t hashtable);
HASH_TABLE_ID_t H_destroy(HASH_TABLE_ID_t hashtable,H_destroy_proc_p destroy_proc);

#endif
