/*
 * cda.h
 *
 *  Created on: Aug 5, 2013
 *      Author: wisedulab2
 */

#ifndef CDA_H_
#define CDA_H_

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define CDA_TRUE (1)
#define CDA_FALSE (0)

#define CDA_ASSERT(exp) (assert((exp)))
#define CDA_CARD(arr) (sizeof((arr))/sizeof(*(arr)))

#define CDA_NEW(type) ((type *)CDA_malloc(sizeof(type)))

#define CDA_NEW_STR(str) (strcpy((char *)CDA_malloc(strlen((str))+1),(str)))
#define CDA_NEW_STR_IF(str) ((str)==NULL?NULL:CDA_NEW_STR((str)))

typedef int CDA_BOOL_t;

typedef signed char CDA_INT8_t;
typedef unsigned char CDA_UINT8_t;

typedef int CDA_INT16_t;
typedef unsigned int CDA_UINT16_t;

typedef long CDA_INT32_t;
typedef unsigned long CDA_UINT32_t;

void *CDA_malloc(size_t size);
void *CDA_calloc(size_t nitems,size_t size);
void *CDA_realloc(void *ptr,size_t size);
void CDA_free( void *mem);

CDA_BOOL_t CDA_is_prime(CDA_UINT16_t num);
CDA_UINT16_t CDA_next_prime(CDA_UINT16_t num);

#endif /* CDA_H_ */
