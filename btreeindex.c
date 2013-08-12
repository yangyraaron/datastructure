//
//  btreeindex.c
//  datastructure
//
//  Created by aaron on 13-8-9.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "btree.h"
#include "cda.h"

typedef struct data_s{
    char *key;
    int position;
}DATA_t,*DATA_p_t;

static void create_tree(const char **recs,int num_recs);
static void add(DATA_p_t data,BTREE_NODE_ID_t node);
static int get_from_btree(const char *key);
static int get_pos(const char *key,BTREE_NODE_ID_t node);
static void traverse_proc(void *data);
static void destroy_proc(void *data);

static const char *test_data[] =
{ "washington",   "lincoln",      "abbey",        "shmabbey",
    "gettysburg",   "alabama",      "zulu",         "yorkshire",
    "xerxes",       "wonderland",   "tiparary",     "sayville",
    "montana",      "eratosthenes", "pythagoras",   "aristotle",
    "kant"
};

static void traverse_proc(void *data){
    DATA_p_t pdata = (DATA_p_t) data;
    
    printf("the data is %s\n",pdata->key);
}

static void destroy_proc(void * data){
    DATA_p_t pdata = (DATA_p_t) data;
    printf("freeing data %s\n",pdata->key);
    
    CDA_free(data);
}

static BTREE_ID_t tree = BTREE_NULL_ID;

void btreeindex_show(){
    create_tree(test_data, CDA_CARD(test_data));
    
    BTREE_traverse_tree(tree, BTREE_PREORDER, traverse_proc);
    
    //BTREE_destroy(tree, destroy_proc);
    
    const char **p = test_data;
    while (*p!=NULL) {
        int pos = get_from_btree(*p);
        
        printf("the key %s\'s position is %d\n",*p,pos);
        
        ++p;
    }
    
}


static void create_tree(const char **recs,int num_recs){
    DATA_p_t data = CDA_NEW(DATA_t);
    BTREE_NODE_ID_t root = BTREE_NODE_NULL_ID;
    int inx = 0;
    
    if (num_recs>1) {
        data->key = CDA_NEW_STR(recs[0]);
        data->position = 0;
        tree = BTREE_create_tree();
        root = BTREE_add_root(tree, data);
        
        for (inx=1; inx<num_recs; ++inx) {
            data = CDA_NEW(DATA_t);
            data->key = CDA_NEW_STR(recs[inx]);
            data->position = inx;
            add(data, root);
        }
    }
}

static void add(DATA_p_t data,BTREE_NODE_ID_t node){
    DATA_p_t node_data = BTREE_get_data(node);
    BTREE_NODE_ID_t temp_node = BTREE_NODE_NULL_ID;
    int strc = 0;
    
    strc = strcmp(data->key, node_data->key);
    CDA_ASSERT(strc!=0);
    
    if (strc<0) {
        temp_node = BTREE_get_left(node);
        
        if(temp_node == BTREE_NODE_NULL_ID)
            BTREE_add_left(node, data);
        else
            add(data, temp_node);
    }else{
        temp_node = BTREE_get_right(node);
        
        if(temp_node == BTREE_NODE_NULL_ID)
            BTREE_add_right(node, data);
        else
            add(data,temp_node);
    }
}

static int get_from_btree(const char *key){
    BTREE_NODE_ID_t root = BTREE_get_root(tree);
    
    int rcode = 0;
    rcode = get_pos(key, root);
    
    return rcode;
}


static int get_pos(const char *key,BTREE_NODE_ID_t node){
    DATA_p_t data = BTREE_get_data(node);
    BTREE_NODE_ID_t temp_node = BTREE_NODE_NULL_ID;
    int strc=0;
    int rcode = -1;
    
    strc = strcmp(key, data->key);
    if(strc == 0){
        rcode = data->position;
    }else if(strc<0){
        temp_node = BTREE_get_left(node);
        if(temp_node!=BTREE_NODE_NULL_ID)
            rcode = get_pos(key, temp_node);
    }else{
        temp_node = BTREE_get_right(node);
        if(temp_node!=BTREE_NODE_NULL_ID)
            rcode = get_pos(key, temp_node);
    }
    
    return  rcode;
}












