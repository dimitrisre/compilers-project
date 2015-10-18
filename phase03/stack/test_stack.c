#include"stack.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	Stack_T stack;
	double i,a,b,c,d;
	
	stack=newStack(500,sizeof(double));

	for(i=0;i<10000;i++){
		
		
		push(&i,stack);
		
	}
	
	for(i=0;i<10000;i=i+1.0){
		b=*(double *)pop(stack);
		printf("%lf--->%lf\n",i,b);
	}

	return 0;
}
