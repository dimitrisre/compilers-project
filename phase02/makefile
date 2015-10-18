parser:	parser.o lex.yy.o symbolhash.o scope_functs.o
		gcc -g parser.o lex.yy.o symbolhash.o scope_functs.o -o parser
		cp parser test_dir/

parser.o:	parser.c
		gcc -g -c parser.c

parser.c: parser.y 
		bison -v -d -o parser.c parser.y

parser.y: scopes.h token.h scanner.h symboltable.h

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


clean:
		rm *.o

all:
	bison -v -d -o parser.c parser.y
	flex scanner2.l
	gcc -g parser.c lex.yy.c symbolhash.c scope_functs.c -o parser
