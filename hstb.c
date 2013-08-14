//
//  hstb.c
//  datastructure
//
//  Created by aaron on 13-8-12.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "hstbp.h"

static INDEX H_p_hash(const char *key,CDA_UINT16_t size);
static node_ptr H_p_find(const char *key,HASH_TABLE_ID_t hashtable);

INDEX H_p_hash(const char *key,CDA_UINT16_t size){
    CDA_UINT16_t hash_val = 0;
    
    while (*key!='\0') {
        hash_val = (hash_val<<5)+*key++;
    }
    
    return  hash_val%size;
}

HASH_TABLE_ID_t H_create(CDA_UINT16_t size){
    HASH_TABLE_p_t table = CDA_NEW(HASH_TABLE_t);
    
    if(table != HASH_TABLE_NULL_ID){
        table->table_size = CDA_next_prime(size);
        table->lists = (LIST *)CDA_malloc(sizeof(LIST)*table->table_size);
        //table->lists = (LIST *)CDA_malloc(sizeof(struct list_node)*table->table_size);
        
        for (int i=0; i<table->table_size; ++i) {
            table->lists[i] = CDA_malloc(sizeof(LIST_t));
            table->lists[i]->next = LIST_NODE_NULL_ID;
        }
    }
    
    return table;
}

static node_ptr H_p_find(const char *key,HASH_TABLE_ID_t hashtable){
    INDEX index = H_p_hash(key, hashtable->table_size);
    
    //get the head of the list corresponding to the index
    LIST node = hashtable->lists[index];
    
    node = node->next;
    
    while (node!=LIST_NODE_NULL_ID) {
        if(strcmp(node->key, key)==0){
            return node;
        }
        
        node = node->next;
    }
    
    return LIST_NODE_NULL_ID;
}

void *H_get(const char *key,HASH_TABLE_ID_t hashtable){
    LIST node = H_p_find(key, hashtable);
    
    if (node==LIST_NODE_NULL_ID) {
        return NULL;
    }
    
    return node->data;
}

void H_set(const char *key, void *data,HASH_TABLE_ID_t hashtable){
    LIST node = H_p_find(key, hashtable);
    
    if(node!=NULL)
        return;
    
    INDEX index = H_p_hash(key, hashtable->table_size);
    
    LIST head = hashtable->lists[index];
    node = CDA_NEW(LIST_t);
    node->key = CDA_NEW_STR(key);
    node->data = data;
    node->next = head->next;
    
    head->next = node;
}


HASH_TABLE_ID_t H_destroy(HASH_TABLE_ID_t hashtable,H_destroy_proc_p destroy_proc){
    for (int i=0; i<hashtable->table_size; ++i) {
        LIST head = hashtable->lists[i];
        LIST node = head->next;
        
        //free the nodes in the list
        while (node!=LIST_NODE_NULL_ID) {
            //make head points to the next node of current node
            head->next = node->next;
            
            //destroy the data
            if(destroy_proc!=NULL)
                destroy_proc(i,node->data);
            
            //destroy the key
            CDA_free(node->key);
            //destroy the node
            CDA_free(node);
            
            node=head->next;
            
        }
    }
    
    CDA_free(hashtable->lists);
    CDA_free(hashtable);
    
    return  HASH_TABLE_NULL_ID;
}


