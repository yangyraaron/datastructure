#include "mgsortp.h"
#include "cda.h"

#define COPY_ELEMENT(temp_array,knx,array,inx,element_size) \
memcpy(((temp_array)+(knx)*(element_size)),\
((array)+(inx)*(element_size)),(element_size))
		   
void SORT_merge(void *array,size_t num_elements,size_t element_size,CMP_PROC_p_t cmp_proc)
{
	if(cmp_proc==NULL)
		return;
	if(num_elements<2)
		return;
	size_t low_half = num_elements/2;
	size_t high_half = num_elements-low_half;
	//the left array address
	BYTE_t *array1 = array;
	//the right array address
	BYTE_t *array2 = array+low_half*element_size;
	//merge sort the left array
	mergesort(array1,low_half,element_size,cmp_proc);
	//merge sort the right array
	mergesort(array2,high_half,element_size,cmp_proc);
	
	/*after complete the merge sorting left ,right array
	merge the left and right array*/
	int inx,inj,knx;
	inx=inj=knx=0;
	//allocate the all element space
	void *temp_array = CDA_malloc(num_elements*element_size);
	while(inx<low_half && inj<high_half) {
		BYTE_t *adr1 = array1+inx*element_size;
		BYTE_t *adr2 = array2+inj*element_size;
		if(cmp_proc(adr1,adr2)<0) {
			//memcpy(temp_array+knx*element_size,adr1,element_size);
			COPY_ELEMENT(temp_array,knx,array1,inx,element_size);
			inx++;
		} else {
			//memcpy(temp_array+knx*element_size,adr2,element_size);
			COPY_ELEMENT(temp_array,knx,array2,inj,element_size);
			inj++;
		}
		knx++;
	}
	//merge all remain left array elements
	while(inx<low_half) {
		//memcpy(temp_array+knx*element_size,array1+inx*element_size,element_size);
		COPY_ELEMENT(temp_array,knx,array1,inx,element_size);
		inx++;
		knx++;
	}
	//merge all remian right array elements
	while(inj<high_half) {
		//memcpy(temp_array+knx*element_size,array2+inj*element_size,element_size);
		COPY_ELEMENT(temp_array,knx,array2,inj,element_size);
		inj++;
		knx++;
	}
	
	memcpy(array,temp_array,num_elements*element_size);
	//free temp array space
	CDA_free(temp_array);
}
