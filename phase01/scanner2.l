%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include"token.h"	
	#define YY_DECL int alpha_yylex(yylval) void * yylval; 

	
	void squeeze_str(void);
	FILE *out_put=stdout;
	char c;	
	int comment_caller;
	int flag2=0;
	int flag=0;
	int com,com2;
	int start=0;
	   
	
%}

%option noyywrap
%option yylineno
%option header-file="./scanner.h"


string ["\""]([^\"^\\]|"\\\""|("\\".))*["\""]

id [_]*[[:alpha:]][A-Za-z0-9_]*
sp [[:space:]]

%x COMMENT COMMENT2

%%

[0-9]+		    	    {	( (ALP) yylval)->int_value = atoi(yytext);
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =INTCONST ;
							return INTCONST; 
						}
[0-9]+"."[0-9]+		    {	 
				 			( (ALP)yylval)->d_value = atof(yytext);			
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =FLOATCONST ;
				 			return FLOATCONST;
						}
if			    		{	
							
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =IF_KEYWORD ;
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							return IF_KEYWORD; 
						}

for					    {   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =FOR_KEYWORD ;
	
							 return FOR_KEYWORD;
						 }

else	                 {  
							 strcpy(((ALP) yylval)->s_value , yytext ) ;
							 ( (ALP) yylval)->lineno = yylineno;
				 			 ( (ALP) yylval)->type =ELSE_KEYWORD ;

				 			 return ELSE_KEYWORD;
						 }


function            	{ 	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =FUNCTION_KEYWORD ;

							return FUNCTION_KEYWORD;
						}


while         		    {   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =WHILE_KEYWORD ;

							return WHILE_KEYWORD;	
						}



return 			        {  
						   strcpy(((ALP) yylval)->s_value , yytext ) ;
						   ( (ALP) yylval)->lineno = yylineno;
				 		   ( (ALP) yylval)->type =RETURN_KEYWORD ;

						   return RETURN_KEYWORD;
						}

break 			    	{  
						   strcpy(((ALP) yylval)->s_value , yytext ) ;
						   ( (ALP) yylval)->lineno = yylineno;
				           ( (ALP) yylval)->type =BREAK_KEYWORD ;

							return BREAK_KEYWORD;
						}


continue 		    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =CONTINUE_KEYWORD ;

							return CONTINUE_KEYWORD;
						}
	


local  			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =LOCAL_KEYWORD ;

							return LOCAL_KEYWORD;
						}


true 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =TRUE_KEYWORD ;

							return TRUE_KEYWORD;
						}


false 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =FALSE_KEYWORD ;

							return FALSE_KEYWORD;
						} 


nil 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =NIL_KEYWORD ;

							return NIL_KEYWORD;
						}


and 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =AND_KEYWORD ;

							return AND_KEYWORD;
						}


or 			    		{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =OR_KEYWORD ;

							return OR_KEYWORD;
						}
	


not 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =NOT_KEYWORD ;

							return NOT_KEYWORD;
						}


global 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =GLOBAL_KEYWORD ;

							return GLOBAL_KEYWORD;
						}
	


"++" 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =PLUSPLUS_OP ;

							return PLUSPLUS_OP;
						}


"--" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =SUBSUB_OP ;

							return SUBSUB_OP;
						}


"*" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = MULL_OP;

							return MULL_OP;
						}


"/" 			    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =DIV_OP ;

							return DIV_OP;
						}


"=="	    		    {	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =EQ_OP ;

							return EQ_OP;
						}


"+" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =PLUS_OP ;

							return PLUS_OP;
						}


"-" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =SUB_OP ;

							return SUB_OP;
						}


"=" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =ASS_OP ;

							return ASS_OP;
						}


"!=" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =NEQ_OP ;
	
							return NEQ_OP;
						}


"%" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =MOD_OP ;

							return MOD_OP;
						}


">=" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type=GEQ_OP  ;

							return GEQ_OP;
						}


"<=" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =LEQ_OP ;

							return LEQ_OP;
						}


">" 			    	{	
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type =GRE_OP ;

							return GRE_OP;
						}


"<"		 	    		{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = LESS_OP;

							return LESS_OP;
						}    


"(" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = L_PAR;

							return L_PAR;
						}


")" 		            {   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = R_PAR;

							return R_PAR;
						}


"{" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = L_AG;

							return L_AG;
						}


"}" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = R_AG;

							return R_AG;
						}


"[" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = L_BR;
	
							return L_BR;
						}


"]" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = R_BR;

							return R_BR;
						}


"," 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = COMMA;

							return COMMA;
						}


";" 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = SEMICOL;

							return SEMICOL;
						}


"." 		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = FULLST;

							return FULLST;
						}


":"      	 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = D_FULLST;

							return D_FULLST;
						}


{string}	 	    	{   
							squeeze_str();
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = STRING;

							return STRING;
						}



{id}		 	    	{   
							strcpy(((ALP) yylval)->s_value , yytext ) ;
							( (ALP) yylval)->lineno = yylineno;
				 			( (ALP) yylval)->type = ID;

							return ID;
						}


{sp}			    	{			;			}


"//".*			    	{   fprintf(yyout,"Ignoring \"//\" comments\n");			}
"#".*			    	{	fprintf(yyout,"Ignoring \"#\" comments\n");			}

<INITIAL,COMMENT,COMMENT2>"/*"	    {   fprintf(yyout,"Start ignoring comments\n");
										flag++;
										BEGIN(COMMENT);
				        				com=COMMENT;
										start=INITIAL;
									}
<COMMENT>\n		    	    		{                 ;                  	}
<COMMENT>.		            		{		      	  ;			 			}
<COMMENT>"*/"	            	    {   fprintf(yyout,"Finished ignoring commnets\n");
					 					flag--;
					 					comment_caller=Call_back();
					 					BEGIN(comment_caller);
									}
<INITIAL,COMMENT,COMMENT2>"(*" 	    {   fprintf(yyout,"Start ignoring comments2\n");
										com2=COMMENT2;
					 					flag2++;
										BEGIN(COMMENT2);
					
					 					start=INITIAL;
									}
<COMMENT2>\n		    	    	{                   ;                	}
<COMMENT2>.		            		{                   ;                	}
<COMMENT2>"*)"	            	    {   fprintf(yyout,"Finished ignoring commnets2\n");
										flag2--;
										comment_caller=Call_back();
										BEGIN(comment_caller);            
									}
.			            			{   
										   strcpy(((ALP) yylval)->s_value , yytext ) ;
				   						   ( (ALP) yylval)->lineno = yylineno;
				 						   ( (ALP) yylval)->type = ILLEGAL;

										   return ILLEGAL;
									}

<COMMENT,COMMENT2,INITIAL><<EOF>>	{	   if(flag!=0)fprintf(yyout,"Unfinished comments1\n");		
										   if(flag2!=0)fprintf(yyout,"Unfinished comments2\n");
										   return ENDOF;
									}

%%

int Call_back(){
	
	if(flag!=0 && flag2==0){

		return com;
	}
	else if(flag==0 && flag2!=0){
		return com2;
	}
	
	return start;
}

void squeeze_str(void){
	char *tmp;
	int i,j=0;

	tmp=(char *)malloc((strlen(yytext)*sizeof(char))+1);
	for(i=0;i<strlen(yytext);i++){
		if(yytext[i]!='\n'){
			tmp[j++]=yytext[i];
		}
	}
	strcpy(yytext,tmp);
	free(tmp);
}
