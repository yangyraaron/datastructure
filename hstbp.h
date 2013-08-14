//
//  hstbp.h
//  datastructure
//
//  Created by aaron on 13-8-12.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_hstbp_h
#define datastructure_hstbp_h

#define LIST_NODE_NULL_ID (NULL)

#include "hstb.h"

typedef CDA_UINT16_t INDEX;

typedef struct list_node{
    char *key;
    void *data;
    node_ptr next;
} LIST_t, *LIST;

typedef struct hash_table{
    CDA_UINT16_t table_size;
    LIST *lists;
} HASH_TABLE_t,*HASH_TABLE_p_t;

#endif
