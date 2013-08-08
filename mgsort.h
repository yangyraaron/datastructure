#ifndef MG_SORT_H_
#define MG_SORT_H_

#include <stdlib.h>

typedef int CMP_PROC_t(const void*,const void*);
typedef CMP_PROC_t *CMP_PROC_p_t;
typedef unsigned char BYTE_t;
void mergesort(void *array,size_t num_elements,size_t elment_size,CMP_PROC_p_t cmp_proc);

#endif