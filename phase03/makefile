parser:	parser.o lex.yy.o symbolhash.o scope_functs.o icode.o stack.o darray.o dot_dot.o
		gcc -g parser.o lex.yy.o symbolhash.o scope_functs.o icode.o stack.o darray.o dot_dot.o -o parser
		
parser.o:	parser.c
		gcc -g -c parser.c

dot_dot.o:	dot_dot.c
		gcc -g -c dot_dot.c

parser.c: parser.y 
		bison  -d -o parser.c parser.y

parser.y: scopes.h token.h scanner.h symboltable.h icode.h

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



stack.o: stack/stack.c
	gcc -g -c stack/stack.c

darray.o:	stack/darray.c
	gcc -g -c stack/darray.c

stack.c: stack/darray.h stack/stack.h

darray.c: stack/darray.h

clean:
		rm *.o
		rm out 
		rm sym
		rm parser

all:
	bison  -d -o parser.c parser.y
	flex scanner2.l
	gcc -g icode.c parser.c lex.yy.c symbolhash.c scope_functs.c -o parser
