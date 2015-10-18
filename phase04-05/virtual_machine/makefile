avm:	avm.o binary_file.o 
		#Makefile for alpha virtual machine
		gcc -g avm.o binary_file.o -o avm


avm.o:	avm.c 	
	gcc -g -c avm.c
binary_file.o:	../binary_file.c
	gcc -g -c ../binary_file.c

binary_file.c:	../binary_file.h

avm.c: avm.h 


clean:
		#clean
		rm *.o

