#include<stdio.h>
#include"darray.h"
#include<assert.h>
#include<stdlib.h>

static const float up_bar=1;
static const float down_bar=0.4;
static const float increment=2;
static const float decrement=0.5;

struct DArray{
	void **array;
	int Size;
	int MaxSize;
	size_t elemtsSz;
};



/*_________Helping Functions__________*/
void Resize(DArray_T oDArray,float TypeOfResize ){
	oDArray->MaxSize=oDArray->MaxSize*TypeOfResize;
	oDArray->array=(void **)realloc(oDArray->array,oDArray->MaxSize*oDArray->elemtsSz);
}

void setSize(DArray_T oDArray){
	int i;
	oDArray->Size=0;
	for(i=0;i<oDArray->MaxSize;i++){
		if(oDArray->array[i]!=NULL){
			oDArray->Size++;
		}
	}
}

void *Copy(const void *item,size_t size){
	char *cItem,*Item;
	int i;
	Item=(char *)item;
	cItem=(char *)malloc(size);
	for(i=0;i<size;i++){
		*(cItem+i)=*(Item+i);
	}
	return (void *)cItem;
	
	
}

/*********Function Implementation*********/
/* Create and return a new DArray_T with iNumElts, each of size
   iEltSize. It is a checked runtime error for iNumElts or iEltSize
   to be negative. 
 */
DArray_T DArray_new(size_t iNumElts, size_t iEltSize){
	DArray_T array;

	assert(iNumElts>=0);
	assert(iEltSize>=0);

	array=(DArray_T)malloc(sizeof(struct DArray));
	array->array=calloc(iNumElts,iEltSize);
	array->Size=0;
	array->MaxSize=iNumElts;
	array->elemtsSz=iEltSize;
	return array;
}

/* Free all memory allocated for oDArray 
 */
void DArray_free(DArray_T oDArray){
	free(oDArray->array);
	free(oDArray);
}


/* Return the number of elements of oDArray. It is a checked runtime
   error for oDArray to be NULL. 
 */
int DArray_getNumElts(DArray_T oDArray){
	
	assert(oDArray);
	setSize(oDArray);
	return oDArray->MaxSize;
}

/* Return the size of each element of oDArray. It is a checked runtime
   error for oDArray to be NULL.
 */
int DArray_getEltSize(DArray_T oDArray){

	assert(oDArray);
	return oDArray->elemtsSz;
}

/* Return a pointer to the iIndex'th element of oDArray.  It is a
   checked runtime error for oDArray to be NULL or empty.  It is a
   checked runtime error for iIndex to be less than 0 or greater than
   or equal to the (current) length of oDArray.
 */
void *DArray_get(DArray_T oDArray, int iIndex){
	void *item;	
	
	assert(oDArray);
	assert(oDArray->Size>0);
	assert(iIndex>=0 && iIndex<oDArray->MaxSize);

	item = oDArray->array[iIndex];
	return item;
}



/* Put a copy of the item pointed to by pvItem to the iIndex'th
   element of oDArray. It is a checked runtime error for oDArray to be
   NULL or empty. It is a checked runtime error for iIndex to be less
   than 0 or greater than or equal to the length of oDArray.
 */
void DArray_put(DArray_T oDArray, int iIndex, const void *pvItem){

	assert(oDArray);
	assert(oDArray->MaxSize>0);


	assert(iIndex>=0);
	assert(iIndex<oDArray->MaxSize);
	
	oDArray->array[iIndex]=Copy(pvItem,oDArray->elemtsSz);
	setSize(oDArray);
	
}


/* Add a copy of the item pointed to by pvItem to the end of oDArray,
   thus incrementing its length, and return the index of the new
   element. It is a checked runtime error for oDArray to be NULL.
 */
int DArray_append(DArray_T oDArray, const void *pvItem){
	int oldMaxSz;
	assert(oDArray);

	oldMaxSz=oDArray->MaxSize;
	Resize(oDArray,increment);
	oDArray->array[oldMaxSz]=Copy(pvItem,oDArray->elemtsSz);
	setSize(oDArray);

	return oldMaxSz;
}



/* Sort oDArray in the order determined by *pfCompare. *pfCompare
   should return -<0, 0, or >0 iff *pvItem1 is less than, equal to, or
   greater than *pvItem2, respectively. It is a checked runtime error
   for oDArray or pfCompare to be NULL. 
 */
void DArray_sort(DArray_T oDArray,
   int (*pfCompare)(const void *pvItem1, const void *pvItem2)){
	assert(oDArray);
	assert(pfCompare);
	qsort(oDArray->array,oDArray->MaxSize,DArray_getEltSize(oDArray),pfCompare);
}


/* Search oDArray for *pvItem using *pfCompare to determine equality.
   Return the index at which *pvItem is found, or -1 if there is no
   such index. pfIsEqual returns 0 if pvItem1 is equal to pvItem2 and
   non-0 otherwise. It is a checked runtime error for oDArray or
   pfCompare to be NULL. 
 */
int DArray_search(DArray_T oDArray, void *pvItem,
   int (*pfIsEqual)(const void *pvItem1, const void *pvItem2)){
	int i;

	assert(oDArray);
	assert(pfIsEqual);

	for(i=0;i<oDArray->MaxSize;i++){
		if((pfIsEqual)(DArray_get(oDArray,i),pvItem)==0){
			return i;
		}
	}
	return -1;
}
