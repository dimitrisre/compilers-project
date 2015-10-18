%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include"token.h"	
	#include"parser.h"
//	#define YY_DECL int alpha_yylex(ayylval) void * ayylval; 

	
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

[0-9]+		    	    {	yylval.ival=atoi(yytext);
							( (ALP) ayylval)->int_value = atoi(yytext);
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =INTCONST ;
							return INTCONST; 
						}
[0-9]+"."[0-9]+		    {	 
							yylval.fval=atof(yytext);
				 			( (ALP)ayylval)->d_value = atof(yytext);			
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =FLOATCONST ;
				 			return FLOATCONST;
						}
if			    		{	
							yylval.sval=strdup(yytext);
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =IF_KEYWORD ;
							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							return IF_KEYWORD; 
						}

for					    {  	yylval.sval=strdup(yytext);
 
							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =FOR_KEYWORD ;
	
							 return FOR_KEYWORD;
						 }

else	                 { 	yylval.sval=strdup(yytext);

							 strcpy(((ALP) ayylval)->s_value , yytext ) ;
							 ( (ALP) ayylval)->lineno = yylineno;
				 			 ( (ALP) ayylval)->type =ELSE_KEYWORD ;

				 			 return ELSE_KEYWORD;
						 }


function            	{ 	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =FUNCTION_KEYWORD ;

							return FUNCTION_KEYWORD;
						}


while         		    {   
							yylval.sval=strdup(yytext);
					
							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =WHILE_KEYWORD ;

						  return WHILE_KEYWORD;	
						}



return 			        {  
							yylval.sval=strdup(yytext);

						   strcpy(((ALP) ayylval)->s_value , yytext ) ;
						   ( (ALP) ayylval)->lineno = yylineno;
				 		   ( (ALP) ayylval)->type =RETURN_KEYWORD ;

						   return RETURN_KEYWORD;
						}

break 			    	{  
							yylval.sval=strdup(yytext);

						   strcpy(((ALP) ayylval)->s_value , yytext ) ;
						   ( (ALP) ayylval)->lineno = yylineno;
				           ( (ALP) ayylval)->type =BREAK_KEYWORD ;

						  return BREAK_KEYWORD;
						}


continue 		    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =CONTINUE_KEYWORD ;

							return CONTINUE_KEYWORD;
						}
	


local  			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =LOCAL_KEYWORD ;

							return LOCAL_KEYWORD;
						}


true 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =TRUE_KEYWORD ;

							return TRUE_KEYWORD;
						}


false 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =FALSE_KEYWORD ;

							return FALSE_KEYWORD;
						} 


nil 			    	{  
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =NIL_KEYWORD ;

							return NIL_KEYWORD;
						}


and 			    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =AND_KEYWORD ;

							return AND_KEYWORD;
						}


or 			    		{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =OR_KEYWORD ;

							return OR_KEYWORD;
						}
	


not 			    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =NOT_KEYWORD ;

							return NOT_KEYWORD;
						}


global 			    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =GLOBAL_KEYWORD ;

							return GLOBAL_KEYWORD;
						}
	


"++" 			    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =PLUSPLUS_OP ;

							return PLUSPLUS_OP;
						}


"--" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =SUBSUB_OP ;

							return SUBSUB_OP;
						}


"*" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = MULL_OP;

							return MULL_OP;
						}


"/" 			    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =DIV_OP ;

							return DIV_OP;
						}


"=="	    		    {
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =EQ_OP ;

							return EQ_OP;
						}


"+" 			    	{
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =PLUS_OP ;

							return PLUS_OP;
						}


"-" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =SUB_OP ;

							return SUB_OP;
						}


"=" 			    	{
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =ASS_OP ;

							return ASS_OP;
						}


"!=" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =NEQ_OP ;
	
							return NEQ_OP;
						}


"%" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =MOD_OP ;

							return MOD_OP;
						}


">=" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type=GEQ_OP  ;

							return GEQ_OP;
						}


"<=" 			    	{	
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =LEQ_OP ;

							return LEQ_OP;
						}


">" 			    	{
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type =GRE_OP ;

							return GRE_OP;
						}


"<"		 	    		{  
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = LESS_OP;

							return LESS_OP;
						}    


"(" 		 	    	{   
							yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = L_PAR;

							return L_PAR;
						}


")" 		            {   yylval.sval=strdup(yytext);


							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = R_PAR;

							return R_PAR;
						}


"{" 		 	    	{   
							yylval.sval=strdup(yytext);
							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = L_AG;

							return L_AG;
						}

"}" 		 	    	{  	yylval.sval=strdup(yytext);
 
							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = R_AG;

							return R_AG;
						}


"[" 		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = L_BR;
	
							return L_BR;
						}


"]" 		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = R_BR;

							return R_BR;
						}


"," 		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = COMMA;

							return COMMA;
						}


";" 		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = SEMICOL;

							return SEMICOL;
						}


"." 		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = FULLST;

							return FULLST;
						}


":"      	 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = D_FULLST;

							return D_FULLST;
						}


{string}	 	    	{   yylval.sval=strdup(yytext);

							squeeze_str();

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = STRING;

							return STRING;
						}



{id}		 	    	{   yylval.sval=strdup(yytext);

							strcpy(((ALP) ayylval)->s_value , yytext ) ;
							( (ALP) ayylval)->lineno = yylineno;
				 			( (ALP) ayylval)->type = ID;
						//	printf("yylval=%s",yylval.sval);
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
<COMMENT,COMMENT2,INITIAL><<EOF>>	{	   if(flag!=0)fprintf(yyout,"Unfinished comments1\n");		
										   if(flag2!=0)fprintf(yyout,"Unfinished comments2\n");
										   return EOF;
									}

.			            			{  
										   strcpy(((ALP) ayylval)->s_value , yytext ) ;
				   						   ( (ALP) ayylval)->lineno = yylineno;
				 						   ( (ALP) ayylval)->type = ILLEGAL;

										   return ILLEGAL;
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

	tmp=(char *)malloc((strlen(yytext)+1)*sizeof(char));
	for(i=0;i<strlen(yytext);i++){
		if(yytext[i]!='\n'){
			tmp[j++]=yytext[i];
		}
	}
	tmp[j]='\0';
	yytext=strcpy(yytext,tmp);
	free(tmp);
}
