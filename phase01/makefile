al:	al.o lex.yy.o
	gcc al.o lex.yy.o -o al

al.o: al.c
	gcc -c al.c

al.c: scanner.h token.h

lex.yy.o: lex.yy.c 
	gcc -c lex.yy.c

lex.yy.c: scanner2.l
	flex scanner2.l

clean:
	rm *.o
