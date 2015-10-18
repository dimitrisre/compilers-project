#ifndef _STACK_H_
#define _STACK_H_

typedef struct Stack * Stack_T;

Stack_T  newStack(int , int );

void push(void *,Stack_T);

void *pop(Stack_T);

void freeStack(Stack_T);

int getNumOfEls(Stack_T);
#endif
