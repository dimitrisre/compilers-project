#include "scanner.h"
#include "token.h"

int main(int argc,char **argv){
	
	
	void *token_ptr ; 
	struct alpha_token_t * new = malloc(sizeof(struct alpha_token_t));
	enum TYPE i;
	int count=0;
 
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));

	token_ptr = (void *) new;

	

	if( argc<2 ){
		printf("Error.No input file\n");
		return 1;
	}
	else{
		if(argc==2){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the file\n");
				return 1;
			}
			yyout=stdout;
		}
		if(argc==3){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				printf("Error while opening the output file\n");
				return 1;
			}

		}
	}
	

	while((i=alpha_yylex( token_ptr ))!=ENDOF){
		count++;
		switch(i){

			case INTCONST:
				fprintf(yyout,"lineno:%d , ayxwn:%d ,  INTCONST (%d): \"%d\"\n",new->lineno,count,new->type,new->int_value);
				break;
			case FLOATCONST:
				fprintf(yyout,"lineno:%d , ayxwn:%d , FLOATCONST(%d): \"%lf\"\n",new->lineno,count,new->type,new->d_value);
				break;
			case IF_KEYWORD:
			case FOR_KEYWORD:
			case ELSE_KEYWORD:
			case FUNCTION_KEYWORD:
			case WHILE_KEYWORD:
			case RETURN_KEYWORD:
			case BREAK_KEYWORD:
			case CONTINUE_KEYWORD:
			case LOCAL_KEYWORD:
			case TRUE_KEYWORD:
			case FALSE_KEYWORD:
			case NIL_KEYWORD:
			case AND_KEYWORD:
			case OR_KEYWORD:
			case NOT_KEYWORD:
			case GLOBAL_KEYWORD:
			fprintf(yyout,"lineno:%d , ayxwn:%d , KEYWORD(%d): \"%s\"\n",new->lineno,count,new->type,new->s_value);
				break;
			case PLUSPLUS_OP: 
			case SUBSUB_OP:
		        case MULL_OP: 
			case DIV_OP: 
			case EQ_OP:
			case PLUS_OP:
			case SUB_OP: 
			case ASS_OP:
			case NEQ_OP: 
			case MOD_OP:
			case GEQ_OP:
			case LEQ_OP:
			case GRE_OP:
			case LESS_OP:

				fprintf(yyout,"lineno:%d , ayxwn:%d , OPERATOR(%d): \"%s\"\n",new->lineno,count,new->type,new->s_value);
				break;
			case STRING:
				fprintf(yyout,"lineno:%d , ayxwn:%d , STRING(%d): %s\n",new->lineno,count,new->type,new->s_value);
				break;
			case L_PAR: 
                        case R_PAR: 
                        case L_AG: 
                        case R_AG: 
                        case L_BR: 
                        case R_BR: 
                        case COMMA: 
                        case SEMICOL:
                        case FULLST:
                        case D_FULLST: 
				fprintf(yyout,"lineno:%d , ayxwn:%d , PANCTUATION(%d): \"%s\"\n",new->lineno,count,new->type,new->s_value);
				break;
			case ID:
				fprintf(yyout,"lineno:%d , ayxwn:%d , IDENTIFIER(%d): \"%s\"\n",new->lineno,count,new->type,new->s_value);
				break;
			case ILLEGAL:
				fprintf(yyout,"lineno:%d , ayxwn:%d , ILLEGAL(%d): \"%s\"\n",new->lineno,count,new->type,new->s_value);
				break;
			default:
				break;
		}
	}

	free(new->s_value);
	free(new);
	return 0;

}
