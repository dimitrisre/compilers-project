al:	b_al.o b_scanner.o
	gcc b_al.o b_scanner.o -o al

b_al.o:	b_al.c b_token.h 
		gcc -Wall  -c b_al.c

b_al.c: b_token.h

b_scanner.o:	b_scanner.c b_scanner.h b_token.h
		gcc -Wall -c b_scanner.c

b_scanner.c: 	b_token.h b_scanner.h

clean:
	rm *o
