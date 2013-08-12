//
//  btree.c
//  datastructure
//
//  Created by aaron on 13-8-9.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#include <stdio.h>
#include "btreep.h"

static void traverse_inorder(BTREE_NODE_p_t node, BTREE_VISIT_PROC_p_t visit_proc);
static void traverse_preorder(BTREE_NODE_p_t node,BTREE_VISIT_PROC_p_t visit_proc);
static void traverse_postorder(BTREE_NODE_p_t node,BTREE_VISIT_PROC_p_t visit_proc);


BTREE_ID_t BTREE_create_tree(void){
    BTREE_CONTROL_p_t tree = CDA_NEW(BTREE_CONTROL_t);
    
    tree->root = NULL;
    
    return tree;
}

BTREE_NODE_ID_t BTREE_add_root(BTREE_ID_t tree, void *data){
    BTREE_NODE_p_t node = CDA_NEW(BTREE_NODE_t);
    
    node->data = data;
    node->tree = tree;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    tree->root = node;
    
    return  node;
}

BTREE_NODE_ID_t BTREE_add_left(BTREE_NODE_ID_t node,void *data){
    CDA_ASSERT(node->left == NULL);
    
    BTREE_NODE_p_t left = CDA_NEW(BTREE_NODE_t);
    left->data = data;
    left->tree = node->tree;
    left->parent = node;
    left->left = NULL;
    left->right = NULL;

    node->left = left;
    
    return  left;
}

BTREE_NODE_ID_t BTREE_add_right(BTREE_NODE_ID_t node,void *data){
    CDA_ASSERT(node->right == NULL);
    
    BTREE_NODE_p_t right = CDA_NEW(BTREE_NODE_t);
    right->data = data;
    right->parent = node;
    right->tree = node->tree;
    right->left = NULL;
    right->right = NULL;
    
    node->right = right;
    
    return right;
}

BTREE_NODE_ID_t BTREE_get_root(BTREE_ID_t tree){
    return  tree->root;
}

void *BTREE_get_data(BTREE_NODE_ID_t node){
    return  node->data;
}

BTREE_NODE_ID_t BTREE_get_left(BTREE_NODE_ID_t node){
    return  node->left;
}

BTREE_NODE_ID_t BTREE_get_right(BTREE_NODE_ID_t node){
    return node->right;
}

CDA_BOOL_t BTREE_is_empty(BTREE_ID_t tree){
    return  tree->root == NULL;
}

CDA_BOOL_t BTREE_is_leaf(BTREE_NODE_ID_t node){
    return (node->left==NULL) && (node->right==NULL);
}

BTREE_ID_t BTREE_traverse_tree(BTREE_ID_t tree,BTREE_TRAVERSE_ORDER_e_t order,BTREE_VISIT_PROC_p_t visit_proc){
    
    switch (order) {
        case BTREE_PREORDER:
            traverse_preorder(tree->root, visit_proc);
            break;
            case BTREE_INORDER:
            traverse_inorder(tree->root, visit_proc);
            break;
            case BTREE_POSTORDER:
            traverse_postorder(tree->root,visit_proc);
            break;
            
        default:
            CDA_ASSERT(CDA_FALSE);
            break;
    }
    
    return tree;
}

static void traverse_inorder(BTREE_NODE_p_t node, BTREE_VISIT_PROC_p_t visit_proc){
    if(node!=NULL){
        traverse_inorder(node->left, visit_proc);
        visit_proc(node->data);
        traverse_inorder(node->right, visit_proc);
    }
}

static void traverse_preorder(BTREE_NODE_p_t node,BTREE_VISIT_PROC_p_t visit_proc){
    if (node!=NULL) {
        visit_proc(node->data);
        traverse_preorder(node->left, visit_proc);
        traverse_preorder(node->right, visit_proc);
    }
}

static void traverse_postorder(BTREE_NODE_p_t node,BTREE_VISIT_PROC_p_t visit_proc){
    if (node!=NULL) {
        traverse_postorder(node->left,visit_proc);
        traverse_postorder(node->right, visit_proc);
        visit_proc(node->data);
    }
}

BTREE_NODE_ID_t BTREE_destroy_subtree(BTREE_NODE_ID_t node,BTREE_DESTROY_PROC_p_t destroy_proc){
    if(node->left!=NULL)
        BTREE_destroy_subtree(node->left,destroy_proc);
    
    if(node->right!=NULL)
        BTREE_destroy_subtree(node->right,destroy_proc);
    
    if (node->data!=NULL) {
        destroy_proc(node->data);
    }
    
    if(node==node->tree->root)
        node->tree->root = NULL;
    else if (node->parent->left==node)
        node->parent->left=NULL;
    else if(node->parent->right==node)
        node->parent->right=NULL;
    else
        CDA_ASSERT(CDA_FALSE);
    
    CDA_free(node);
    
    return BTREE_NODE_NULL_ID;
}

BTREE_ID_t BTREE_destroy(BTREE_ID_t tree,BTREE_DESTROY_PROC_p_t destroy_proc){
    BTREE_destroy_subtree(tree->root, destroy_proc);
    CDA_free(tree);
    
    return BTREE_NULL_ID;
}