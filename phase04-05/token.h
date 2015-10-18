#ifndef _TOKEN_H_
#define _TOKEN_H_

#define MAX_LEXEME 2048

struct alpha_token_t{

	int lineno;
	int type;
	int int_value;
	double d_value;
	char * s_value;
};	

typedef struct alpha_token_t* ALP;
void *ayylval ; 


#endif
