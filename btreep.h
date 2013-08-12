//
//  btreep.h
//  datastructure
//
//  Created by aaron on 13-8-9.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_btreep_h
#define datastructure_btreep_h

#include "btree.h"

typedef struct btree_node_s *BTREE_NODE_p_t;
typedef struct btree_control_s *BTREE_CONTROL_p_t;

typedef struct btree_node_s{
    void *data;
    BTREE_CONTROL_p_t tree;
    BTREE_NODE_p_t parent;
    BTREE_NODE_p_t left;
    BTREE_NODE_p_t right;
} BTREE_NODE_t;

typedef struct btree_control_s{
    BTREE_NODE_p_t root;
} BTREE_CONTROL_t;

#endif
