#ifndef _TOKEN_H_
#define _TOKEN_H_

/*#define INTCONST   0
#define FLOATCONST 1


#define STRING     2
#define ID         3

#define ILLEGAL    44
#define ENDOF 	  -1
#define IF_KEYWORD 4
#define FOR_KEYWORD 5
#define ELSE_KEYWORD 6
#define FUNCTION_KEYWORD 7
#define WHILE_KEYWORD 8
#define RETURN_KEYWORD 9
#define BREAK_KEYWORD 10
#define CONTINUE_KEYWORD 11 
#define LOCAL_KEYWORD 12 
#define TRUE_KEYWORD 13
#define FALSE_KEYWORD 14 
#define NIL_KEYWORD 15
#define AND_KEYWORD 16
#define OR_KEYWORD 17
#define NOT_KEYWORD 18
#define GLOBAL_KEYWORD 19
#define PLUSPLUS_OP 20
#define SUBSUB_OP 21
#define MULL_OP 22
#define DIV_OP 23
#define EQ_OP 24
#define PLUS_OP 25 
#define SUB_OP 26
#define ASS_OP 27
#define NEQ_OP 28
#define MOD_OP 29 
#define GEQ_OP 30
#define LEQ_OP 31
#define GRE_OP 32
#define LESS_OP 33
#define L_PAR 34
#define R_PAR 35 
#define L_AG 36 
#define R_AG 37
#define L_BR 38
#define R_BR 39 
#define COMMA 40
#define SEMICOL 41
#define FULLST 42
#define D_FULLST 43
*/
#define MAX_LEXEME 2048

struct alpha_token_t{

	int lineno;
	int type;
	int int_value;
	double d_value;
	char * s_value;
};	

typedef struct alpha_token_t* ALP;
enum TYPE {
			 ENDOF = -1,INTCONST, FLOATCONST,STRING,ID,IF_KEYWORD,FOR_KEYWORD,ELSE_KEYWORD,
 			 FUNCTION_KEYWORD,WHILE_KEYWORD,RETURN_KEYWORD,BREAK_KEYWORD,CONTINUE_KEYWORD,
			 LOCAL_KEYWORD,TRUE_KEYWORD,FALSE_KEYWORD,NIL_KEYWORD,AND_KEYWORD,OR_KEYWORD,
			 NOT_KEYWORD,GLOBAL_KEYWORD,PLUSPLUS_OP,SUBSUB_OP,MULL_OP,DIV_OP,EQ_OP,PLUS_OP,
			 SUB_OP,ASS_OP,NEQ_OP,MOD_OP,GEQ_OP,LEQ_OP,GRE_OP,LESS_OP,L_PAR,R_PAR,L_AG,R_AG,
			 L_BR,R_BR,COMMA,SEMICOL,FULLST,D_FULLST,ILLEGAL
		 
};


#endif
