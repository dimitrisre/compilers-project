parser:		parser.o lex.yy.o binary_file.o symbolhash.o scope_functs.o icode.o stack.o darray.o dot_dot.o f_code.o
		gcc -g parser.o lex.yy.o symbolhash.o scope_functs.o icode.o stack.o darray.o f_code.o dot_dot.o binary_file.o -o parser
		cp parser sssstest

parser.o:	parser.c
		gcc -g -c parser.c

binary_file.o:	binary_file.c
	gcc -g -c binary_file.c

binary_file.c:	binary_file.h

dot_dot.o:	dot_dot.c
		gcc -g -c dot_dot.c

parser.c: parser.y 
		bison  -d -o parser.c parser.y

parser.y: scopes.h token.h scanner.h symboltable.h icode.h binary_file.h

lex.yy.o: lex.yy.c
		gcc -g -c lex.yy.c

lex.yy.c: scanner2.l
		flex scanner2.l

scanner2.l: parser.h token.h

scope_functs.o: scope_functs.c
				gcc -g -c scope_functs.c

scope_functs.c:	scopes.h symboltable.h


symbolhash.o:	symbolhash.c 
			gcc -g -c symbolhash.c
			
symbolhash.c:	symboltable.h 

icode.o:	icode.c 
			gcc -g -c icode.c
	
icode.c:    icode.h stack/stack.h

f_code.o:	f_code.c 
			gcc -g -c f_code.c
	
f_code.c:    f_code.h icode.h symboltable.h

stack.o: stack/stack.c
	gcc -g -c stack/stack.c

darray.o:	stack/darray.c
	gcc -g -c stack/darray.c


stack.c: stack/darray.h stack/stack.h

darray.c: stack/darray.h

clean:
		rm *.o
		rm parser
		rm out 
		rm sym
		rm quad.txt
		rm fcode.txt
		rm *.abc

	
	

all:
	bison  -d -o parser.c parser.y
	flex scanner2.l
	gcc -g icode.c parser.c lex.yy.c symbolhash.c scope_functs.c icode.c stack/stack.c stack/darray.c f_code.c dot_dot.c binary_file.c -o parser
