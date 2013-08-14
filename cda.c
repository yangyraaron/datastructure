/*
 * cda.c
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#include <stdlib.h>
#include "cdap.h"
#include <math.h>

//allocate memory for
void *CDA_malloc(size_t size){
	void *mem = malloc(size);

	if(mem==NULL && size>0)
		abort();

	return mem;
}

void *CDA_calloc(size_t nitems,size_t size){
	void *mem = calloc(nitems,size);

	if(mem == NULL && size>0){
		abort();
	}

	return mem;
}

void *CDA_realloc(void *ptr,size_t size){
	void *mem = realloc(ptr,size);

	if(mem==NULL && size>0)
		abort();

	return mem;
}

void CDA_free( void *mem){
	if(mem!=NULL){
		free(mem);
		mem=NULL;
	}

}

CDA_BOOL_t CDA_is_prime(CDA_UINT16_t num){
    if(num == 2) return CDA_FALSE;
    
    if(num%2==0)
        return CDA_FALSE;
    
    int end_num = sqrt(num);
    
    for (int i=3; i<=end_num; i+=2) {
        if(num%i==0)
            return CDA_FALSE;
    }
    
    return CDA_TRUE;
}

CDA_UINT16_t CDA_next_prime(CDA_UINT16_t num){
    
    if (num%2==0) {
        num+=1;
    }
    
    while (!CDA_is_prime(num)) {
        num+=2;
    }
    
    return num;
}









