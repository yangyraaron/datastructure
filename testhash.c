//
//  testhash.c
//  datastructure
//
//  Created by aaron on 13-8-13.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#include <stdio.h>
#include "hstb.h"

static void TEST_destroy_hashtable(CDA_UINT16_t,void *);

void TEST_hashtable(){
    HASH_TABLE_ID_t hashtable = H_create(10);
    
    char *key = CDA_malloc(sizeof(char*));
    char *value = NULL;
    int i=0;
    for (i=0; i<10; ++i) {
        sprintf(key, "key_%d",i);
        value = CDA_malloc(sizeof(char *));
        sprintf(value, "value_%d",i);
        
        H_set(key, value, hashtable);
    }
    
    for (i=0; i<10; ++i) {
        sprintf(key, "key_%d",i);
        char *data = (char *) H_get(key, hashtable);
        
        printf("key : %s value : %s\n",key,data);
    }
    
    H_destroy(hashtable, TEST_destroy_hashtable);
    
    CDA_free(key);
    
}

static void TEST_destroy_hashtable(CDA_UINT16_t index, void *data){
    printf("destroying index : %d data : %s\n",index, (char *)data);
    
    CDA_free(data);
}
