#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"
#include"darray.h"

struct Stack{
	DArray_T darray;
	int top;
};


Stack_T newStack(int NumOfEls,int SizeOfEls){

	struct Stack *newStack=(struct Stack *)malloc(sizeof(struct Stack));
	
	newStack->darray=DArray_new(NumOfEls,SizeOfEls);
	newStack->top = 0;
	return newStack;
}

void *top_s(Stack_T s){
	void *ret = pop(s);
	push(ret,s);
	return ret;
}

void push(void *newEl,Stack_T stack){
	assert(stack);
	
	DArray_put(stack->darray,stack->top++,newEl);
	
}

void *pop(Stack_T stack){
	void *retVal;
	assert(stack);
	assert(stack->top!=0);
	stack->top--;
	retVal = DArray_get(stack->darray,stack->top);
	

	return retVal;
}

void freeStack(Stack_T stack){
	assert(stack);
	
	DArray_free(stack->darray);
	
}

int getNumOfEls(Stack_T stack){
	assert(stack);
	
	return stack->top;
}
