//
//  btree.h
//  datastructure
//
//  Created by aaron on 13-8-9.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_btree_h
#define datastructure_btree_h

#include "cda.h"

#define BTREE_NULL_ID (NULL)
#define BTREE_NODE_NULL_ID (NULL)

typedef void BTREE_DESTROY_PROC_t(void *data);
typedef BTREE_DESTROY_PROC_t *BTREE_DESTROY_PROC_p_t;

typedef void BTREE_VISIT_PROC_t(void *data);
typedef BTREE_VISIT_PROC_t *BTREE_VISIT_PROC_p_t;

typedef struct btree_control_s *BTREE_ID_t;
typedef struct btree_node_s * BTREE_NODE_ID_t;

typedef enum btree_traverse_order_e{
    BTREE_PREORDER,
    BTREE_INORDER,
    BTREE_POSTORDER,
} BTREE_TRAVERSE_ORDER_e_t;

BTREE_ID_t BTREE_create_tree(void);
BTREE_NODE_ID_t BTREE_add_root(BTREE_ID_t tree, void *data);
BTREE_NODE_ID_t BTREE_add_left(BTREE_NODE_ID_t node,void *data);
BTREE_NODE_ID_t BTREE_add_right(BTREE_NODE_ID_t node,void *data);
BTREE_NODE_ID_t BTREE_get_root(BTREE_ID_t tree);
void *BTREE_get_data(BTREE_NODE_ID_t node);
BTREE_NODE_ID_t BTREE_get_left(BTREE_NODE_ID_t node);
BTREE_NODE_ID_t BTREE_get_right(BTREE_NODE_ID_t node);
CDA_BOOL_t BTREE_is_empty(BTREE_ID_t tree);
CDA_BOOL_t BTREE_is_leaf(BTREE_NODE_ID_t node);
BTREE_ID_t BTREE_traverse_tree(BTREE_ID_t tree,BTREE_TRAVERSE_ORDER_e_t order,BTREE_VISIT_PROC_p_t visit_proc);
BTREE_NODE_ID_t BTREE_destroy_subtree(BTREE_NODE_ID_t node,BTREE_DESTROY_PROC_p_t destroy_proc);
BTREE_ID_t BTREE_destroy(BTREE_ID_t tree,BTREE_DESTROY_PROC_p_t destroy_proc);

#endif
