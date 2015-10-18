test: stack.o test_stack.o darray.o
	gcc -DNDEBUG -g stack.o test_stack.o darray.o -o test

test_stack.o: test_stack.c
	gcc -g -c test_stack.c

test_stack.c: stack.h

stack.o: stack.c
	gcc -g -c stack.c

darray.o:	darray.c
	gcc -g -c darray.c

stack.c: darray.h stack.h

darray.c: darray.h

clean:
	rm *.o

all:
	gcc -g -DNDEBUG darray.c stack.c test_stack.c -o test
