%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include"scanner.h"
	#include"token.h"
	#include"symboltable.h"
	#include"scopes.h"
	#include <time.h>

	extern int   yylineno;
	extern char *yytext;
	extern FILE *yyin,*yyout;
	extern int MaxScope;
	int yyerror(char *);
	struct alpha_token_t *new;
	int Scope = 0,upScope=0,upScope2=0;
	FILE *sym_file;
	char * func_name, *id_tmp;
	
	
%}
%union token_A{

	  int ival;
	  float fval;
	  char *sval;
}

%start programm
%token <ival> INTCONST  
%token <fval> FLOATCONST 
%token <sval> STRING ID IF_KEYWORD FOR_KEYWORD ELSE_KEYWORD FUNCTION_KEYWORD WHILE_KEYWORD 
%token <sval> RETURN_KEYWORD BREAK_KEYWORD CONTINUE_KEYWORD 
%token <sval> LOCAL_KEYWORD TRUE_KEYWORD FALSE_KEYWORD NIL_KEYWORD AND_KEYWORD OR_KEYWORD 
%token <sval> NOT_KEYWORD GLOBAL_KEYWORD PLUSPLUS_OP SUBSUB_OP MULL_OP DIV_OP EQ_OP PLUS_OP 
%token <sval> SUB_OP ASS_OP NEQ_OP MOD_OP GEQ_OP LEQ_OP GRE_OP LESS_OP L_PAR R_PAR L_AG R_AG 
%token <sval> L_BR R_BR COMMA SEMICOL FULLST D_FULLST ILLEGAL

%type  <sval> programm stmts stmt expr term assignexpr primary lvalue
%type  <sval> tableitem call elist elist1s elist1 indexed ind1s ind1
%type  <sval> indexedelem tablemake tsize block funcdef fid const
%type  <sval> idlist id1 id1s ifstmt elsestmt whilestmt forstmt
%type  <sval> returnstmt prexpr
  

%right ASS_OP
%left OR_KEYWORD
%left AND_KEYWORD
%nonassoc EQ_OP  NEQ_OP
%nonassoc GRE_OP GEQ_OP LESS_OP LEQ_OP
%left PLUS_OP SUB_OP
%left MULL_OP DIV_OP MOD_OP
%right NOT_KEYWORD PLUSPLUS_OP SUBSUB_OP UMINUS
%left FULLST
%left L_AG R_AG
%left L_BR R_BR
%left L_PAR R_PAR


%%

programm: stmts						{fprintf(yyout,"rule:programm->stmts\n");  }
		  ;

stmts:	stmt stmts					{fprintf(yyout,"rule:stmts->stmt stmts\n");}
		|							{fprintf(yyout,"rule:stmts->empty\n");	   }
      	
		;
		
stmt: error    stmt                 {yyerrok;} 
     | ILLEGAL						{yyerror("Parse error invalid character ");}
	 | expr SEMICOL					{fprintf(yyout,"rule:stmt->expr ;\n");	   }
     | ifstmt						{fprintf(yyout,"rule:stmt->ifstmt\n");     }
	 | whilestmt					{fprintf(yyout,"rule:stmt->whilestmt\n");  }
	 | forstmt						{fprintf(yyout,"rule:stmt->forstmt\n");	   }
	 | returnstmt					{fprintf(yyout,"rule:stmt->returnstmt\n"); }
	 | BREAK_KEYWORD SEMICOL		{fprintf(yyout,"rule:stmt->break;\n");     }	
	 | CONTINUE_KEYWORD SEMICOL		{fprintf(yyout,"rule:stmt->continue;\n");  }
	 | block						{fprintf(yyout,"rule:stmt->block\n");      }
	 | funcdef						{fprintf(yyout,"rule:stmt->funcdef\n");	   }
	 | SEMICOL						{fprintf(yyout,"rule:stmt->;\n");		   }
 	 ;

expr: assignexpr					{fprintf(yyout,"rule:expr->assignexpr\n");   }
	  | expr PLUS_OP expr			{fprintf(yyout,"rule:expr->expr + expr\n");  }
	  | expr SUB_OP expr			{fprintf(yyout,"rule:expr->expr - expr\n");  }
	  | expr MULL_OP expr			{fprintf(yyout,"rule:expr->expr * expr\n");  }
	  | expr DIV_OP expr			{fprintf(yyout,"rule:expr->expr / expr\n");  }
	  | expr EQ_OP expr				{fprintf(yyout,"rule:expr->expr == expr\n"); }
	  | expr NEQ_OP expr			{fprintf(yyout,"rule:expr->expr != expr\n"); }
	  | expr MOD_OP expr			{fprintf(yyout,"rule:expr->expr \% expr\n"); }
	  | expr GEQ_OP expr			{fprintf(yyout,"rule:expr->expr >= expr\n"); }
	  | expr LEQ_OP expr			{fprintf(yyout,"rule:expr->expr <= expr\n"); }
	  | expr GRE_OP expr			{fprintf(yyout,"rule:expr->expr > expr\n");  }
	  | expr LESS_OP expr			{fprintf(yyout,"rule:expr->expr < expr\n");  }
	  | expr AND_KEYWORD expr		{fprintf(yyout,"rule:expr->expr and expr\n");}
	  | expr OR_KEYWORD expr		{fprintf(yyout,"rule:expr->expr or expr\n"); }
	  | term						{fprintf(yyout,"rule:expr->term\n");		 }
	  ;


term:  L_PAR expr R_PAR				{fprintf(yyout,"rule:term -> ( expr )\n"); }
       | SUB_OP expr %prec UMINUS	{fprintf(yyout,"rule:term -> - expr\n");   }
	   | NOT_KEYWORD expr			{fprintf(yyout,"rule:term -> not expr\n"); }
	   | PLUSPLUS_OP lvalue			{fprintf(yyout,"rule:term -> ++ lvalue\n");}
	   | lvalue PLUSPLUS_OP			{fprintf(yyout,"rule:term -> lvalue ++\n");}
	   | SUBSUB_OP lvalue			{fprintf(yyout,"rule:term -> -- lvalue\n");}
	   | lvalue SUBSUB_OP			{fprintf(yyout,"rule:term -> lvalue --\n");}
	   | primary					{fprintf(yyout,"rule:term -> primary\n");  }
       	;
	   
assignexpr: lvalue ASS_OP expr %prec UMINUS		{fprintf(yyout,"rule:assignexpr -> lvalue = expr\n");}
			;
       
primary: lvalue 					{fprintf(yyout,"rule:primary -> lvalue\n");		}
       | call						{fprintf(yyout,"rule:primary -> call\n");		}
	   | tablemake					{fprintf(yyout,"rule:primary -> tablemake\n");	}
	   | L_PAR funcdef R_PAR		{fprintf(yyout,"rule:primary -> ( funcdef )\n");}
	   | const						{fprintf(yyout,"rule:primary -> const\n");		}
	   ;

lvalue:	ID 							{ id_scope($1,Scope,upScope,upScope2);
									  fprintf(yyout,"rule:lvalue -> ID\n"); 
									}				
		
	   | LOCAL_KEYWORD ID			{ local_id_scope($2,Scope);
									  fprintf(yyout,"rule:lvalue -> local ID\n");
									}
									
	   | glbl ID					{ global_id_scope($2,Scope);
	   								  fprintf(yyout,"rule:lvalue -> global ID\n");
									}
									 
	   | tableitem					{fprintf(yyout,"rule:lvalue -> tableitem\n");}


	   ;

glbl: GLOBAL_KEYWORD
	  | D_FULLST D_FULLST
	;
tableitem: lvalue FULLST ID			{ upScope=search_actFunc(Scope);
									  fprintf(yyout,"rule:tableitem -> lvalue . ID\n");
									}
									
       |lvalue L_BR expr R_BR		{fprintf(yyout,"rule:tableitem -> lvalue ( expr )\n");}
									
	   |call FULLST ID 				{ 
	   								  	upScope=search_actFunc(Scope);
										tableitem_scope($3,Scope,upScope);
										fprintf(yyout,"rule:tableitem -> call . ID\n");
									}
									
	   |call L_BR expr R_BR			{fprintf(yyout,"rule:tableitem -> call ( expr )\n");}
	   ;	
	 
call:  call L_PAR elist R_PAR		{fprintf(yyout,"rule:call -> call ( elist )\n");}
       |lvalue L_PAR elist R_PAR	{fprintf(yyout,"rule:call -> lvalue ( elist)\n");}
	   |L_PAR funcdef R_PAR L_PAR elist R_PAR 	{fprintf(yyout,"rule:call -> ( funcdef ) ( elist )\n");}
	   ;

elist:  expr elist1s			{fprintf(yyout,"rule:elist -> expr elist1s\n");}
		|						{fprintf(yyout,"rule:elist -> empty\n");	   }
		;

elist1s: elist1 elist1s			{fprintf(yyout,"rule:elist1s -> elist1 elist1s\n");}
		 |						{fprintf(yyout,"rule:elist1s -> empty\n");		   }
		 ;

elist1: COMMA expr				{fprintf(yyout,"rule:elist1 -> COMMA expr\n");}
		;

indexed: indexedelem ind1s		{fprintf(yyout,"rule:indexed -> indexedelem ind1s\n");}	
        ;

ind1s: ind1 ind1s				{fprintf(yyout,"rule:ind1s -> ind1 ind1s\n");}
		|						{fprintf(yyout,"rule:ind1s -> empty");		 }
		;
ind1: COMMA indexedelem			{fprintf(yyout,"rule:ind1 -> COMMA indexedelem\n");}

		; 
		
indexedelem: L_AG expr D_FULLST expr R_AG {fprintf(yyout,"rule:indexedelem -> { expr : expr }\n");}
         ;    

tablemake: L_BR tsize R_BR	{fprintf(yyout,"rule:tablemake -> [ tsize ]\n");}  
		   ;
		   
tsize: elist				{fprintf(yyout,"rule:tsize ->  elist \n");} 
	   |indexed				{fprintf(yyout,"rule:tsize -> indexed\n");} 
	   ;

block: L_AG {++MaxScope; Scope++; } stmts R_AG	{	 Hide(Scope);
													 Scope--;
										 			fprintf(yyout,"rule:block -> { stmts }\n");
												}
		;
		
funcdef:FUNCTION_KEYWORD fid  L_PAR{++MaxScope; Scope++;} idlist R_PAR{insert_arguments(Scope);} block{
												Hide(Scope--);
												fprintf(yyout,"rule:funcdef -> function fid ( idlist ) block\n");
											}
 		;
fid: ID 		{	 	
						func_name = strdup($1);
						upScope=search_actFunc(Scope);
						fid_scope( func_name, Scope , upScope );
						fprintf(yyout,"rule:fid -> ID\n");
				
				}
				
 	  | 		{	   
	  					func_name = create_funcName(func_name);
	  					if (!lookup(func_name,Scope,2) )
						insert(Scope,func_name,yylineno,2);	
						fprintf(yyout,"rule:fid -> empty\n");
				}
	  ;
 
const: INTCONST			{fprintf(yyout,"rule:const -> INTCONST\n");  }
       |FLOATCONST		{fprintf(yyout,"rule:const -> FLOATCONST\n");}
	   |STRING			{fprintf(yyout,"rule:const -> STRING\n");    }
	   |NIL_KEYWORD		{fprintf(yyout,"rule:const -> nil\n");		 }
	   |TRUE_KEYWORD	{fprintf(yyout,"rule:const -> true\n");		 }
	   |FALSE_KEYWORD	{fprintf(yyout,"rule:const -> false\n");	 }
	   ;

idlist: ID id1s	                {  
									if(!lookup($1,Scope,1) &&
									!lookup($1,Scope-1,2))
										insert(Scope,$1,yylineno,1);
									else
										fprintf(stderr,"Redifine id:%s at line:%d\n",$1,yylineno);
										
									fprintf(yyout,"rule:idlist -> ID id1s\n");
								}
								
		|						{fprintf(yyout,"rule:idlist -> empty\n");}
		;
		
		
id1: COMMA ID			{   if(!lookup($2,Scope,1) && !lookup($2,Scope-1,2))
								insert(Scope,$2,yylineno,1);
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",$2,yylineno);
								
							fprintf(yyout,"rule:id1 -> , ID\n");
						}
	;
	
id1s: id1 id1s			{fprintf(yyout,"rule:id1s -> id1 id1s\n");}
	  |					{fprintf(yyout,"rule:id1s -> empty\n");	  }	
	  ;

ifstmt:IF_KEYWORD L_PAR expr R_PAR stmt elsestmt		{fprintf(yyout,"rule:ifstmt -> if ( expr ) stmt elsestmt\n");}
		;
		
elsestmt: ELSE_KEYWORD stmt			{fprintf(yyout,"rule:elsestmt -> else stmt\n");}
		  |							{fprintf(yyout,"rule:elsestmt -> empty");	   }
		  ;
		
whilestmt:WHILE_KEYWORD L_PAR expr R_PAR stmt		{fprintf(yyout,"rule:whilestmt -> while ( expr ) stmt\n");}		
		;
		
forstmt: FOR_KEYWORD L_PAR elist SEMICOL expr SEMICOL elist R_PAR stmt	{fprintf(yyout,"rule:forstmt -> for ( elist ; expr ; elist ) stmt\n");}
		;
		
returnstmt: RETURN_KEYWORD prexpr SEMICOL	{fprintf(yyout,"rule:returnstmt -> return prexpr ;\n");}
		;
		
prexpr: expr	{fprintf(yyout,"rule:prexpr -> expr\n"); }
		|		{fprintf(yyout,"rule:prexpr -> empty\n");}
		;


%%

int main(int argc,char **argv){

	srand(time(NULL));

	new =(struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	
 
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));

	ayylval = (void *) new;

	
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
			sym_file=stdout;
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
			sym_file=stdout;

		}
		if(argc==4){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				printf("Error while opening the output file\n");
				return 1;
			}
			if((sym_file=fopen(argv[3],"w+"))==NULL){
				printf("Error while opening the sym file file\n");
				return 1;
			}

		}

	}


	Init_symbolTable();
	
	yyparse();
	
	print();
	
    destroy_symboltable();
	
	free(new->s_value);
	
	free(new);
	
	fclose(yyin);
	
	fclose(yyout);
	
	fclose(sym_file);
	
	return 0;
}


int yyerror(char *yaccProvideMessage){
	fprintf(stderr,"%s at line %d ,before token:%s\n",yaccProvideMessage,yylineno,yytext);
	return 0;
}
