#ifndef __DARRAY_H__
#define __DARRAY_H__
#include<stdio.h>
#include<stdlib.h>
/* A DArray_T is an array whose length can increase dynamically
 */
typedef struct DArray *DArray_T;


/* Create and return a new DArray_T with iNumElts, each of size
   iEltSize. It is a checked runtime error for iNumElts or iEltSize
   to be negative. 
 */
DArray_T DArray_new(size_t iNumElts, size_t iEltSize);


/* Free all memory allocated for oDArray 
 */
void DArray_free(DArray_T oDArray);


/* Return the number of elements of oDArray. It is a checked runtime
   error for oDArray to be NULL. 
 */
int DArray_getNumElts(DArray_T oDArray);


/* Return the size of each element of oDArray. It is a checked runtime
   error for oDArray to be NULL.
 */
int DArray_getEltSize(DArray_T oDArray); 


/* Return a pointer to the iIndex'th element of oDArray.  It is a
   checked runtime error for oDArray to be NULL or empty.  It is a
   checked runtime error for iIndex to be less than 0 or greater than
   or equal to the (current) length of oDArray.
 */
void *DArray_get(DArray_T oDArray, int iIndex);


/* Put a copy of the item pointed to by pvItem to the iIndex'th
   element of oDArray. It is a checked runtime error for oDArray to be
   NULL or empty. It is a checked runtime error for iIndex to be less
   than 0 or greater than or equal to the length of oDArray.
 */
void DArray_put(DArray_T oDArray, int iIndex, const void *pvItem);


/* Add a copy of the item pointed to by pvItem to the end of oDArray,
   thus incrementing its length, and return the index of the new
   element. It is a checked runtime error for oDArray to be NULL.
 */
int DArray_append(DArray_T oDArray, const void *pvItem);


/* Sort oDArray in the order determined by *pfCompare. *pfCompare
   should return -<0, 0, or >0 iff *pvItem1 is less than, equal to, or
   greater than *pvItem2, respectively. It is a checked runtime error
   for oDArray or pfCompare to be NULL. 
 */
void DArray_sort(DArray_T oDArray,
   int (*pfCompare)(const void *pvItem1, const void *pvItem2));


/* Search oDArray for *pvItem using *pfCompare to determine equality.
   Return the index at which *pvItem is found, or -1 if there is no
   such index. pfIsEqual returns 0 if pvItem1 is equal to pvItem2 and
   non-0 otherwise. It is a checked runtime error for oDArray or
   pfCompare to be NULL. 
 */
int DArray_search(DArray_T oDArray, void *pvItem,
   int (*pfIsEqual)(const void *pvItem1, const void *pvItem2));

#endif

