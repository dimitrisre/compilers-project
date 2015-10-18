%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include <time.h>

	#include "scanner.h"
	#include "token.h"
	#include "symboltable.h"
	#include "scopes.h"
	#include "icode.h"
	#include "f_code.h"
	#include "stack/stack.h"
	
	#define MAXSIZE 300000


	extern int   yylineno , ScopeSpaceCounter;
	extern char *yytext;
	extern FILE *yyin,*yyout;
	extern int MaxScope;
	extern unsigned int quadCnt;
	extern unsigned totalNumConsts;
	extern unsigned totalStringConsts;
	extern unsigned totalNameLibFuncs;
	extern unsigned totalUserFuncs;
	extern struct instruction avm_incode[MAXSIZE];
	extern double * numConsts;
	extern char ** stringConsts;
	extern struct userfunc * userFuncs[1000];
	extern char ** nameLibFuncs;
	extern int curr_incode;
	extern int create_binary( char *filename,struct userfunc* userFuncs[],char *NameLibFuncs[],char *stringConsts[],double *numConsts,
		struct instruction avm_incode[],int num_of_programm_vars,unsigned int quadCnt, unsigned totalNumConsts,unsigned totalStringConsts,unsigned totalNameLibFuncs,unsigned totalUserFuncs);

	struct expr *elist_head=NULL;
	struct expr *index_head=NULL;
	extern void Loading(void);
	int flag_error = 0;
	int loop = 0 , cont_loop = 0;
	int yyerror(char *);
	struct alpha_token_t *new;
	int    Scope = 0,upScope=0,upScope2=0,fn_i=0;
	FILE * sym_file, *quad_ofile,*fcode_ofile;
	char * func_name, *id_tmp;
	char * fun_names[100]={"_?_"};
	char * file_name;
	int func_flag = 0;
    int varsFlag =0; 
	int funcVars=0;
	int oof_counter = 0;
	
//	Stack_T oof_st = NULL;

	
%}

%union token_A{

	  struct expr eval;
	  int ival;
	  float fval;
	  char *sval;
	
}

%start alpha_source_code
%token <ival> INTCONST  
%token <fval> FLOATCONST 
%token <sval> STRING ID IF_KEYWORD FOR_KEYWORD ELSE_KEYWORD FUNCTION_KEYWORD WHILE_KEYWORD 
%token <sval> RETURN_KEYWORD BREAK_KEYWORD CONTINUE_KEYWORD 
%token <sval> LOCAL_KEYWORD TRUE_KEYWORD FALSE_KEYWORD NIL_KEYWORD AND_KEYWORD OR_KEYWORD 
%token <sval> NOT_KEYWORD GLOBAL_KEYWORD PLUSPLUS_OP SUBSUB_OP MULL_OP DIV_OP EQ_OP PLUS_OP 
%token <sval> SUB_OP ASS_OP NEQ_OP MOD_OP GEQ_OP LEQ_OP GRE_OP LESS_OP L_PAR R_PAR L_AG R_AG 
%token <sval> L_BR R_BR COMMA SEMICOL FULLST D_FULLST ILLEGAL

%type  <eval> alpha_source_code stmts stmt expr term assignexpr primary lvalue
%type  <eval> tableitem call elist elist1s elist1 indexed ind1s ind1
%type  <eval> indexedelem tablemake tsize block funcdef fid const
%type  <eval> idlist id1 id1s ifstmt elsestmt whilestmt forstmt
%type  <eval> returnstmt prexpr a
  

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


%expect 1


%%

alpha_source_code: stmts			{fprintf(yyout,"rule:programm->stmts\n");  }
		  		  ;

stmts:	stmt stmts					{ fprintf(yyout,"rule:stmts->stmt stmts\n");}
		|							{fprintf(yyout,"rule:stmts->empty\n");	   }
      	
		;
		
stmt: error    stmt                 {yyerrok;} 
     | ILLEGAL						{yyerror("Parse error invalid character ");}
	 | expr SEMICOL					{fprintf(yyout,"rule:stmt->expr ;\n");}
     | ifstmt						{fprintf(yyout,"rule:stmt->ifstmt\n");}
	 | whilestmt					{fprintf(yyout,"rule:stmt->whilestmt\n");  }
	 | forstmt						{fprintf(yyout,"rule:stmt->forstmt\n");	   }
	 | returnstmt					{fprintf(yyout,"rule:stmt->returnstmt\n"); }
	 | BREAK_KEYWORD SEMICOL		{
	 								 if( Num_of_StackEls(break_s) == 0 ){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : break statement out of loop (no operation produced)\n",file_name,yylineno);
	
									 }else{
									 	emit(jump,NULL,NULL,NULL,0,yylineno);
	 								 	insert_jump_point(0,break_s);
									 }
	 								 fprintf(yyout,"rule:stmt->break;\n");     }	
	 | CONTINUE_KEYWORD SEMICOL		{
	 								 if(Num_of_StackEls(continue_s) == 0){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : continue statement out of loop (no operation produced)\n",file_name,yylineno);
										
									 }
									 else{
									 	cont_loop = get_cont_point(0);
	 								    emit(jump,NULL,NULL,NULL,cont_loop,yylineno);
									  }
	 								  fprintf(yyout,"rule:stmt->continue;\n");  }
	 | block						{
	                                    if(varsFlag>0){
	                                     funcVars+=count_funcVars(Scope);
                           			    }


	 								  Hide(Scope);Scope--;
   									  resetTemp();
	 								  reset_fun_cnt();
	 								  fprintf(yyout,"rule:stmt->block\n");     
									}
	 | funcdef						{fprintf(yyout,"rule:stmt->funcdef\n");	   }
	 | SEMICOL						{fprintf(yyout,"rule:stmt->;\n");		   }
 	 ;

									
expr: assignexpr					{	if($1.sym != NULL){
											$$ = $1; 
											free(&$1); 
										}
										else{
											$$.sym = NULL;
										}
										fprintf(yyout,"rule:expr->assignexpr\n");   }

	  | expr PLUS_OP expr			{   if ( $1.sym != NULL && $3.sym != NULL ){
	  								  		$$ = op_expr(add,&$1,&$3);
										}
										else
											$$.sym = NULL;

									  fprintf(yyout,"rule:expr->expr + expr\n");  }

	  | expr SUB_OP expr			{  if ( $1.sym != NULL && $3.sym != NULL ){
	  								 	$$ = op_expr(sub,&$1,&$3);
	  								 	free(&$1);
									 	free(&$3);
										}
										else
											$$.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr - expr\n");  }

	  | expr MULL_OP expr			{  if ( $1.sym != NULL && $3.sym != NULL ){
	  								 		$$ = op_expr(mul,&$1,&$3);
									 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr * expr\n");  }

	  | expr DIV_OP expr			{	if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$ = op_expr(div_a,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr / expr\n");  }

	  | expr EQ_OP expr				{	if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$ = eq_neq_oper(if_eq,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr == expr\n"); }
									
	  | expr NEQ_OP expr			{  if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$ = eq_neq_oper(if_noteq,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3); 
										}
										else
											$$.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr != expr\n"); }

	  | expr MOD_OP expr			{	if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$ = op_expr(mod,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr \% expr\n"); }

	  | expr GEQ_OP expr			{
	  									if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$=bool_oper(if_greatereq,&$1,&$3);
	                                 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr >= expr\n"); }

	  | expr LEQ_OP expr			{	if ( $1.sym != NULL && $3.sym != NULL ){
	  
	  										$$=bool_oper(if_lesseq,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr <= expr\n"); }

	  | expr GRE_OP expr			{	if ( $1.sym != NULL && $3.sym != NULL ){
	  
	  										$$=bool_oper(if_greater,&$1,&$3);
	  								 		free(&$1);
											free(&$3);
											}
										else
											$$.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr > expr\n");  }

	  | expr LESS_OP expr			{	if ( $1.sym != NULL && $3.sym != NULL ){
	  
	 	 									 $$=bool_oper(if_less,&$1,&$3);
	  										 free(&$1);
											 free(&$3);
											}
										else
											$$.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr < expr\n");  }

	  | expr AND_KEYWORD expr		{	if ( $1.sym != NULL && $3.sym != NULL ){
	  
	  										 $$=op_expr(and,&$1,&$3);
	  										 free(&$1);
											 free(&$3);

										}
										else
											$$.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr and expr\n");}

	  | expr OR_KEYWORD expr		{	if ( $1.sym != NULL && $3.sym != NULL ){
	  										$$=op_expr(or,&$1,&$3);
	  								 		free(&$1);
									 		free(&$3);
										}
										else
											$$.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr or expr\n"); }

	  | term						{$$ = $1;fprintf(yyout,"rule:expr->term\n");
	  								 free(&$1);
									 }
	
	  ;


term:  L_PAR expr R_PAR				{ $$ = $2; free(&$2);fprintf(yyout,"rule:term -> ( expr )\n"); }
       | SUB_OP expr %prec UMINUS	{ 
	   								  if ( $2.sym != NULL ){
	   								  	$$ = term_expr(uminus,&$2);
	  									free(&$2);
										}
										else
											$$.sym = NULL;
									  fprintf(yyout,"rule:term -> - expr\n");   
									}
	   | NOT_KEYWORD expr			{	if ( $2.sym != NULL){
	   										$$=andor_oper(not,&$2,NULL);
	   									    free(&$2);
									 	}
										else
											$$.sym = NULL;
	   									fprintf(yyout,"rule:term -> not expr\n"); }
	   
	   | PLUSPLUS_OP lvalue			{struct expr *const_new = new_IntExpr(1);
	                                 
									 if ( $2.sym != NULL ){
									 		$$ = lvalue_prefix(add,&$2,const_new);
									 	 free(&$2);
										}
										else
											$$.sym = NULL;
										 free(const_new);
	                                 fprintf(yyout,"rule:term -> ++ lvalue\n");}
	   
	   | lvalue PLUSPLUS_OP			{ 
	   								  char * tmp_var = new_tmp_var();
									  struct expr * new_tmp;
									  S_entry sym;
									  

                                      if ( $1.sym != NULL ){
									     if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									      }
									      sym = find_rec( tmp_var , Scope, 1);

									  	 if(sym != NULL)
									  	     new_tmp = new_VarE( sym );
									  
									      emit(assign, &$1, NULL, new_tmp, 0, yylineno);
									  
									      $$ = *new_tmp;
									  
									      //free(new_tmp);
									      //free(tmp_var);

									      lvalue_prefix(add,&$1,new_IntExpr(1));
									  
									      free(&$1);
									  }
										else
											$$.sym = NULL;
	   								  fprintf(yyout,"rule:term -> lvalue ++\n");}
	   | SUBSUB_OP lvalue			{
	   									struct expr *const_new = new_IntExpr(1);
	                                if ( $2.sym != NULL ){	
	   								    $$ = lvalue_prefix(sub,&$2,const_new);
										
										 free(const_new);
										 free(&$2);
									 }
										else
											$$.sym = NULL;
	   								  fprintf(yyout,"rule:term -> -- lvalue\n");}

	   | lvalue SUBSUB_OP			{ 
	   								  char * tmp_var = new_tmp_var();
									  struct expr * new_tmp;
 									  S_entry sym;

                                    if ( $1.sym != NULL ){
									     if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym = find_rec( tmp_var , Scope, 1);

									     if(sym != NULL)
									   		new_tmp = new_VarE( sym );
									  
									  	 emit(assign, &$1, NULL, new_tmp, 0, yylineno);
									  
									     $$ = *new_tmp;
									  	 free(new_tmp);
									  	 lvalue_prefix(sub,&$1,new_IntExpr(1));
										 free(&$1);
	   									 free(tmp_var);
									 }
										else
											$$.sym = NULL;
	   
	   									fprintf(yyout,"rule:term -> lvalue --\n");}
	   | primary					{ $$ = $1; fprintf(yyout,"rule:term -> primary\n");  
	   									free(&$1);
									}
       ;
	   
assignexpr: lvalue ASS_OP expr   	{  struct expr * new_tmp;
	   								   char * tmp_var = new_tmp_var();


										if($1.sym!=NULL && $3.sym!=NULL){

		  									if ( $1.e_type == tableitem_e ){
		  										emit(tablesetelem,$1.index,&$3,&$1,0,yylineno);
											}
											else if($3.e_type == tableitem_e){
		  										emit(tablegetelem,&$3,$3.index,&$1,0,yylineno);
											
											}
											else{
												
												emit(assign,&$3,NULL,&$1,0,yylineno);
												 S_entry sym,sym2;
									 										  
										 if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym2 = find_rec( tmp_var , Scope, 1);

									     if(sym2 != NULL)
									   		new_tmp = new_VarE( sym2 );
									  
									  	 
										 emit(assign, &$1, NULL, new_tmp, 0, yylineno);
											
											}
											$$ = $1;											
											free(&$1);
											free(&$3);
										}
										else 
										   $$.sym=NULL;
											
										fprintf(yyout,"rule:assignexpr -> lvalue = expr\n");}
			;				
       
primary: lvalue 					{$$ = $1;
	   								 free(&$1);
									 fprintf(yyout,"rule:primary -> lvalue\n");}

       | call                		{$$ = $1; fprintf(yyout,"rule:primary -> call\n");		}
	   | tablemake					{$$ = $1; fprintf(yyout,"rule:primary -> tablemake\n");	}
	   | L_PAR funcdef R_PAR		{$$ = $2; fprintf(yyout,"rule:primary -> ( funcdef )\n");}
	   | const						{$$ = const_expr(assign,&$1);
	   									fprintf(yyout,"rule:primary -> const\n");		
										free(&$1);
									}
	   ;

lvalue:	ID 							{ int i;
	  								  struct expr *new_lval;
									  S_entry sym,sym2;
									  struct expr * new_tmp;
	   								  //char * tmp_var = new_tmp_var();
									  i = id_scope($1,Scope,upScope,upScope2);
									  
										/* if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym2 = find_rec( tmp_var , Scope, 1);

									     if(sym2 != NULL)
									   		new_tmp = new_VarE( sym2 );
									  */
									  	 
									  if ( i == 1 ){

									  		sym = find_rec($1,Scope,1);
									  		if(sym == NULL){
									  			sym = find_rec($1,Scope,2);
									  		}
									  		if( sym != NULL ){
									  	   		 new_lval = new_VarE(sym);
										 		$$ = *new_lval;
											    //emit(assign, new_lval, NULL, new_tmp, 0, yylineno);

										 		free(new_lval);
									  	 		free(&$1);

									  	  	}
																									
									   }
									   else
										  $$.sym = NULL;
									 
									  
									  fprintf(yyout,"rule:lvalue -> ID\n"); 
									}				
		
	   | LOCAL_KEYWORD ID			{ int res;
	                                  struct expr *new_lval;
									  S_entry sym,sym2;
									  struct expr * new_tmp;
	   								  char * tmp_var = new_tmp_var();
									  
									  if( !lookup( tmp_var, Scope, 1 ) ){
									  	insert( Scope, tmp_var, yylineno, 1 );
									  }
									  sym2 = find_rec( tmp_var , Scope, 1);

									  if(sym2 != NULL)
									  	new_tmp = new_VarE( sym2 );

	                                  res=local_id_scope($2,Scope);
	   								  if(res==1){
									    
									  							 
									 	sym = find_rec($2,Scope,1);
									  
									  	if(sym != NULL){

									  		 new_lval = new_VarE(sym);
									     	$$ = *new_lval;
									  	}
										//emit(assign, new_lval, NULL, new_tmp, 0, yylineno);

										free(new_lval);
										free(&$2);
									}
									else 
									   $$.sym=NULL;

									 fprintf(yyout,"rule:lvalue -> local ID\n");
									}
									
	   | glbl ID					{int res; 
	   								 S_entry sym; 
									 struct expr *new_lval;
									 S_entry sym2;
									 struct expr * new_tmp;
	   								 char * tmp_var = new_tmp_var();
								
									 if( !lookup( tmp_var, Scope, 1 ) ){
									  	insert( Scope, tmp_var, yylineno, 1 );
									 }
									 sym2 = find_rec( tmp_var , Scope, 1);

									 if(sym2 != NULL)
									 	new_tmp = new_VarE( sym2 );

	                                 res=global_id_scope($2,Scope);

									  if(res!=0){							 
									  	sym = find_rec($2,0,1);
									  
									  	if(sym != NULL){
									  	 	new_lval = new_VarE(sym);
  										 	$$ = *new_lval;
									  	}
										//emit(assign, new_lval, NULL, new_tmp, 0, yylineno);
										free(&$2);
										free(new_lval);
									 }
									 else
									    $$.sym=NULL;
	   								  
									  fprintf(yyout,"rule:lvalue -> global ID\n");
									}
									 
	   | tableitem					{$$ = $1;fprintf(yyout,"rule:lvalue -> tableitem\n");}


	   ;

glbl: GLOBAL_KEYWORD				{fprintf(yyout,"rule:glbl -> global\n");}
	  | D_FULLST D_FULLST			{fprintf(yyout,"rule:glbl -> ::\n");}
	  ;

tableitem: lvalue FULLST ID			{ if( $1.sym != NULL){

		 								struct expr * table = new_expr(tableitem_e);
 										char  * tmp_var;
										struct expr * index ;
										struct expr * res;
  								  	  	struct expr *up;
 										S_entry sym; 
		 							  	table->sym = $1.sym;
									  
										index = new_StrExpr($3);
									  	table->index = index;
									  
										up = new_expr(tableitem_e);
 									
										
									  
										tmp_var = new_tmp_var();
									  									   
									  	if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									  	sym = find_rec( tmp_var , Scope, 1);
									  	
										if(sym != NULL){
									  		res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,index,res,0,yylineno);
									  	$$ = *up;
									  }
									  else
									  	$$.sym = NULL;
		 							 fprintf(yyout,"rule:tableitem -> lvalue . ID\n");}
									
       |lvalue L_BR expr R_BR		{ 
	   								  if( $1.sym != NULL && $3.sym != NULL){
	   								  	struct expr * table = new_expr(tableitem_e);
		 							  
									  	//struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										//S_entry sym;
										
										//char  * tmp_var = new_tmp_var();
									  	
										table->sym = $1.sym;
										table->index = Expr_cpy(table->index,&$3) ;								  
									  		
	
									  	//if( !lookup( tmp_var, Scope, 1 ) ){
									  //		insert( Scope, tmp_var, yylineno, 1 );
									  //	}
									   	//sym= find_rec( tmp_var , Scope, 1);
									  	///if(sym != NULL){
									  	//	res = new_VarE( sym );
										//	res->index = table->index;								  
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  //	}
									  //	emit(tablegetelem,table,&$3,res,0,yylineno);
									  	$$ = *table;
									 }
									 else
									 	$$.sym = NULL;
	   			
	   									fprintf(yyout,"rule:tableitem -> lvalue ( expr )\n");}
									
	   |call FULLST ID 				{ if( $1.sym != NULL){
	   								  	struct expr * table = new_expr(tableitem_e);
									  	struct expr * index ;
									  	struct expr * res;
  								  	 	struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
									  	char  * tmp_var = new_tmp_var();
	                                    table->index = index;
									  	index = new_StrExpr($3);
										table->sym = $1.sym;
									  	
										if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									   	sym= find_rec( tmp_var , Scope, 1);
									  	if(sym != NULL){
									 	 	res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,index,res,0,yylineno);
									  	$$ = *up;
									  }
									  else
									  	$$.sym = NULL;
									  fprintf(yyout,"rule:tableitem -> call . ID\n");
									}
									
	   |call L_BR expr R_BR			{ if( $1.sym != NULL){

	   								  	struct expr * table = new_expr(tableitem_e);
		 							    struct expr * res;
  								  	 	struct expr *up = new_expr(tableitem_e);
										S_entry sym; 	
										char  * tmp_var = new_tmp_var();

                                    	table->sym = $1.sym;
									  	table->index = Expr_cpy(table->index,&$3) ;
									  									   
									  	if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									  	sym= find_rec( tmp_var , Scope, 1);
									  	if(sym != NULL){
									  		res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,&$3,res,0,yylineno);
									  	$$ = *up;
	   
	   								 }
									 else
									 	$$.sym = NULL;
	   								  fprintf(yyout,"rule:tableitem -> call ( expr )\n");}
	   ;	
	 
call:  call L_PAR elist R_PAR		{ 	int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										struct expr * tmp;
										
										if($1.sym != NULL){
									    	while( i <= Scope ){
												if (lookup(find_name($1.sym,1),i,1)){
													search = 1;
													break;
												}
												i++;

											}
										}
										if ( search == 1 ){
										
										  	new_lval = new_VarE($1.sym);
									    	new_lval = Expr_cpy( new_lval , &$1 );

										    $$ =  * call_expr( new_lval , elist_head);
																									
											free(new_lval);
											elist_head = NULL;
											free(&$1);
										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno);
										}
										fprintf(yyout,"rule:call -> call ( elist )\n");
										
										}

       |ID L_PAR elist R_PAR	{  	    int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										
									    while( i <= Scope ){
											if (lookup($1,i,2)){
												search = 1;
												break;
											}
											i++;
										}

										if(search ==0 ){
											if(lookup($1,0,3))
												search = 1;
										}
										
										if ( search == 1 ){
											sym = find_rec($1,Scope,2);
											if(sym == NULL){
												sym = find_rec($1,0,3);
											}
									  		new_lval = new_FuncE(sym);
									    	$$ = *call_expr(new_lval,elist_head);
											elist_head = NULL;
										}
										else{
											$$.sym = NULL;
											printf("Undifined call of Function at line:%d\n",yylineno);
										}
	   									fprintf(yyout,"rule:call -> lvalue ( elist)\n");}


		|glbl ID  L_PAR elist R_PAR	{  	int i=0;
										int search = 0;
                                     	S_entry sym;
										struct expr * new_lval;
										
									    
										if (lookup($2,0,2) ){
												search = 1;
												
										}

										if(search == 0 ){
											if(lookup($2,0,3))
												search = 1;
										}

										if ( search == 1 ){
											sym = find_rec($2,Scope,2);
											if(sym == NULL){
												sym = find_rec($2,0,3);
											}

									  		new_lval = new_FuncE(sym);
									    	$$ = *call_expr(new_lval,elist_head);
											elist_head = NULL;


										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}


										
									    fprintf(yyout,"rule:call -> lvalue ( elist)\n");}


		|LOCAL_KEYWORD ID L_PAR elist R_PAR	{  	int i=0;
												int search = 0;
												S_entry sym;
												struct expr * new_lval;
										
										if (lookup($2,Scope,2)){
												search = 1;
											
										}
											
										if ( search == 1 ){
											sym = find_rec($2,Scope,2);
									  		new_lval = new_FuncE(sym);
									    	$$ = *call_expr(new_lval,elist_head);
											elist_head = NULL;

										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}

                                       	fprintf(yyout,"rule:call -> lvalue ( elist)\n");}


		|tableitem  L_PAR elist R_PAR	{  	int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										
										if($1.sym!=NULL){
									       $$ = *call_expr(&$1,elist_head);
										   elist_head = NULL;
										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}

										fprintf(yyout,"rule:call -> lvalue ( elist)\n");}
								
								
								

	   |L_PAR funcdef R_PAR L_PAR elist R_PAR 	

	   								{  $$ = *call_expr(&$2,elist_head);
										elist_head = NULL;
	   								fprintf(yyout,"rule:call -> ( funcdef ) ( elist )\n");}
	   ;

	 							 
elist:  expr elist1s			{ 	if($1.e_type == tableitem_e){
										struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
										char  * tmp_var = new_tmp_var();
									  	
										//table->sym = $1.sym;
										//table->index = Expr_cpy(table->index,&$3) ;								  
									  		
	
									  		if( !lookup( tmp_var, Scope, 1 ) ){
									  			insert( Scope, tmp_var, yylineno, 1 );
									  		}
									   		sym= find_rec( tmp_var , Scope, 1);
									  		if(sym != NULL){
									  			res = new_VarE( sym );
											//res->index = Expr_cpy(res->index,$2.index);
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  		}
									    	emit(tablegetelem,&$1,$1.index,res,0,yylineno);
											$$ = *res;
	 
	 							  		if( elist_head == NULL ){
								  		elist_head = Expr_cpy(elist_head,res);
								  		}
								  		else{
								  			res->next = elist_head;
											elist_head = Expr_cpy(elist_head,res);
								  		}
								  }
								  else{
										if( elist_head == NULL ){
								  			elist_head = Expr_cpy(elist_head,&$1);
								  		}
								  		else{
								  			$1.next = elist_head;
											elist_head = Expr_cpy(elist_head,&$1);
								  		}
								    }
	                              		fprintf(yyout,"rule:elist -> expr elist1s\n");}
		|						{elist_head = NULL;fprintf(yyout,"rule:elist -> empty\n");	   }
		;

elist1s: elist1 elist1s			{
								  
	   							  if(elist_head == NULL){
								  	elist_head = Expr_cpy(elist_head,&$1);
								  	
								  }
								  else{
								  	$1.next = elist_head;
								  	elist_head = Expr_cpy(elist_head,&$1);

								  }
	   							fprintf(yyout,"rule:elist1s -> elist1 elist1s\n");}
		 |						{elist_head = (struct expr *)0;fprintf(yyout,"rule:elist1s -> empty\n");		   }
		 ;

elist1: COMMA expr				{	
								 	if($2.e_type == tableitem_e){
										struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
										char  * tmp_var = new_tmp_var();
									  	
										//table->sym = $1.sym;
										//table->index = Expr_cpy(table->index,&$3) ;								  
									  		
	
									  		if( !lookup( tmp_var, Scope, 1 ) ){
									  			insert( Scope, tmp_var, yylineno, 1 );
									  		}
									   		sym= find_rec( tmp_var , Scope, 1);
									  		if(sym != NULL){
									  			res = new_VarE( sym );
											//res->index = Expr_cpy(res->index,$2.index);
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  		}
									    	emit(tablegetelem,&$2,$2.index,res,0,yylineno);
											$$ = *res;
										}
										else
	  										$$ = $2;
	  								fprintf(yyout,"rule:elist1 -> COMMA expr\n");}
		;

indexed: indexedelem ind1s		{ 
	   							  if( index_head == NULL ){
								  	index_head = Expr_cpy(index_head,&$1);
								  }
								  else{
								  	$1.next = index_head;
									index_head = Expr_cpy(index_head,&$1);
								  }

	   							 fprintf(yyout,"rule:indexed -> indexedelem ind1s\n");}	
        ;

ind1s: ind1 ind1s				{ if(index_head == NULL){
								  	index_head = Expr_cpy(index_head,&$1);
								  	
								  }
								  else{
								  	$1.next = index_head;
								  	index_head = Expr_cpy(index_head,&$1);

								  }

	 							 fprintf(yyout,"rule:ind1s -> ind1 ind1s\n");}
		|						{index_head = NULL;fprintf(yyout,"rule:ind1s -> empty");		 }
		;
ind1: COMMA indexedelem			{	$$ = $2;
									fprintf(yyout,"rule:ind1 -> COMMA indexedelem\n");}

		; 
		
indexedelem: L_AG expr D_FULLST expr R_AG { $2.index = Expr_cpy($2.index,&$4);
		   									$$ = $2;
		   									fprintf(yyout,"rule:indexedelem -> { expr : expr }\n");
										  }
         ;    
tablemake: L_BR tsize R_BR	{ $$ = $2; fprintf(yyout,"rule:tablemake -> [ tsize ]\n");}  
		   ;
		   
tsize: elist				{ struct expr * table = new_expr(newtable_e);
	 						  struct expr * new_tmp;
		 					  S_entry sym;	
		 					  char  * tmp_var =  new_tmp_var();
                              struct expr * tmp;
							  int i = 0;
							  
							  if( !lookup( tmp_var , Scope, 1 ) ){
									  	insert( Scope, tmp_var , yylineno, 1 );
							  }
							  sym = find_rec( tmp_var ,Scope, 1);
							  table->sym = sym;
						
							  emit(tablecreate,NULL,NULL,table,0,yylineno);
							  
							 
							  for(tmp = elist_head; tmp!=NULL; tmp=tmp->next)
									emit(tablesetelem,new_IntExpr(i++),tmp,table,0,yylineno);

							  $$ = *table;
							  fprintf(yyout,"rule:tsize ->  elist \n"); } 

	   |indexed				{ 
	   						  struct expr * table = new_expr(newtable_e);
	 						  struct expr * new_tmp;
	  						  S_entry sym; 
                              struct expr * tmp;
							  int i = 0;
                              char  * tmp_var =  new_tmp_var();
							  
							  if( !lookup( tmp_var , Scope, 1 ) ){
									  	insert( Scope, tmp_var , yylineno, 1 );
							  }
						      sym= find_rec( tmp_var ,Scope, 1);
							  table->sym = sym;
						
							  emit(tablecreate,NULL,NULL,table,0,yylineno);
							  
							
							  for(tmp = index_head; tmp!=NULL; tmp=tmp->next){
									emit(tablesetelem,tmp,tmp->index,table,0,yylineno);
                              }
							  $$ = *table;
	   						  fprintf(yyout,"rule:tsize -> indexed\n"); 

							  } 
	   ;


block: L_AG {++MaxScope; Scope++; } stmts R_AG	{fprintf(yyout,"rule:block -> { stmts }\n");
												}
		;
		
funcdef: FUNCTION_KEYWORD fid { //push(&oof_counter,oof_st);
								//oof_counter = 0;
								insert_jump_point(1,ret_s);
								func_flag += 1; funcVars=0; varsFlag++; 

	   							if( $2.sym != NULL){
									//kainoyrio
									//emit(ret,NULL,NULL,&$2,0,yylineno);
									emit(jump,NULL,NULL,NULL,0,yylineno);
	 								insert_jump_point(0,ret_s);
									
									emit(funcstart,&$2,NULL,NULL,0,yylineno);
									$$ = $2;
								}
								else
									$$.sym = NULL;
								
								
							  }	
	   L_PAR                  { ++MaxScope; Scope++; ScopeSpaceCounter++;} 
	   idlist R_PAR           { insert_arguments(Scope); ScopeSpaceCounter++;} 
	   block				  {	//int tmp_oof = oof_counter;
								//oof_counter = 0;

								func_name = fun_names[--fn_i];

								funcVars+=count_funcVars(Scope);
								set_sumOfVars(funcVars,Scope);

								Hide(Scope);
								Scope--;
								Hide(Scope--);
								ScopeSpaceCounter -= 2;
								
								if( $2.sym != NULL ){
								  	backpatch(ret_s); 									
									emit(funcend,&$2,NULL,NULL,0,yylineno);
									
									$$ = $2;
									free(&$2);
									free(func_name);
									free(fun_names[fn_i]);
								}
								else
									$$.sym = NULL;

								varsFlag--;
								func_flag -= 1;
								funcVars=0;
								//oof_counter = tmp_oof;
								//oof_counter = *(int *)pop(oof_st);
								fprintf(yyout,"rule:funcdef -> function fid ( idlist ) block\n");
							}
 		;
						
fid: ID 		{	 	int result,cmp_res;
						func_name = strdup($1);
						
						if(fn_i==0)
						   fn_i=1;
						
						if(strcmp(func_name,fun_names[fn_i-1])!=0){
							
						
							fun_names[fn_i++]= strdup(func_name);
							upScope=search_actFunc(Scope);
							result = fid_scope( func_name, Scope , upScope );
						
							if ( result == 1 ){
						
							struct expr *new_lval;
							S_entry sym = find_rec($1,Scope,2);
									  
							if(sym != NULL){
								new_lval = new_FuncE(sym);
																
							}
							$$ = *new_lval;
							free(new_lval);
							free(&$1);

							}
							else{
								$$.sym = NULL;
					      	}
						}
						else{
						   
							  fprintf(stderr,"Redifine symbol:%s at line:%d\n",func_name,yylineno);
						}
						fprintf(yyout,"rule:fid -> ID\n");
						
				}
				
 	  | 		{	  	struct expr *new_lval;
						S_entry sym ; 
	  					func_name = create_funcName();
						fun_names[fn_i++]= strdup(func_name);
	  					if (!lookup(func_name,Scope,2) )
							insert(Scope,func_name,yylineno,2);	

					    sym = find_rec(func_name,Scope,2); 
									  
						if(sym != NULL){
							new_lval = new_FuncE(sym);
							
						}
						$$ = *new_lval;
						

						fprintf(yyout,"rule:fid -> empty\n");
				}
	  ;
 
const: INTCONST			{struct expr *const_new = new_IntExpr($1);  $$ = *const_new; free(&$1); free(const_new); fprintf(yyout,"rule:const -> INTCONST\n");  }
       |FLOATCONST		{struct expr *const_new = new_FltExpr($1);  $$ = *const_new; free(&$1); free(const_new);fprintf(yyout,"rule:const -> FLOATCONST\n");}
	   |STRING			{struct expr *const_new = new_StrExpr($1);  $$ = *const_new; free(&$1); free(const_new);fprintf(yyout,"rule:const -> STRING\n");    }
	   |NIL_KEYWORD		{struct expr *const_new = new_NillExpr($1); $$ = *const_new; free(&$1); fprintf(yyout,"rule:const -> nil\n");						 							 }	
	   |TRUE_KEYWORD	{struct expr *const_new = new_BoolExpr(1u); $$ = *const_new; free(const_new); fprintf(yyout,"rule:const -> true\n");	 	 }
	   |FALSE_KEYWORD	{struct expr *const_new = new_BoolExpr(0u); $$ = *const_new; free(const_new);fprintf(yyout,"rule:const -> false\n");	 }
	   ;

idlist: ID id1s	        {  		
	  						if( !lookup($1,Scope,1) && !lookup($1,Scope-1,2) )
								
								insert(Scope,$1,yylineno,1);
								
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",$1,yylineno);
							
							fprintf(yyout,"rule:idlist -> ID id1s\n");
						}
								
		|				{fprintf(yyout,"rule:idlist -> empty\n");}
		;
		
		
id1: COMMA ID			{   if (!lookup($2,Scope,1) && !lookup($2,Scope-1,2))
								insert(Scope,$2,yylineno,1);
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",$2,yylineno);
								
							fprintf(yyout,"rule:id1 -> , ID\n");
						}
	;
	
id1s: id1 id1s			{fprintf(yyout,"rule:id1s -> id1 id1s\n");}
	  |					{fprintf(yyout,"rule:id1s -> empty\n");	  }	
	  ;


whilestmt: WHILE_KEYWORD a expr R_PAR      { emit(if_eq,&$3,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);}
					 stmt 		           { cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 						 emit(jump,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  		 backpatch(back_s); 
											 backpatch(break_s);
											 free(&$3);
							  		  		 fprintf(yyout,"rule:whilestmt -> while ( expr ) stmt\n");}		
		;

a: L_PAR {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad(); insert_cont_point(&cont_loop);}
 ;


ifstmt:IF_KEYWORD L_PAR expr R_PAR  {emit(if_eq,&$3,new_BoolExpr(0u),NULL,0,yylineno); 
	  								insert_jump_point(0,back_s); }
		stmt elsestmt	{free(&$3);fprintf(yyout,"rule:ifstmt -> if ( expr ) stmt elsestmt\n");}
		;
		
elsestmt: ELSE_KEYWORD  {emit(jump,NULL,NULL,NULL,0,yylineno);backpatch(back_s);insert_jump_point(0,back_s);}stmt	{backpatch(back_s);fprintf(yyout,"rule:elsestmt -> else stmt\n");}
		  |									{backpatch(back_s);fprintf(yyout,"rule:elsestmt -> empty");	   }
		  ;
		

		
forstmt: FOR_KEYWORD L_PAR elist b expr {emit(if_eq,&$5,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);} SEMICOL elist R_PAR	stmt	{
										 cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 					 emit(jump,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  	 backpatch(back_s); 
										 backpatch(break_s);
										 free(&$5);
										 fprintf(yyout,"rule:forstmt -> for ( elist ; expr ; elist ) stmt\n");}
		;

b: SEMICOL {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad();
	   									  insert_cont_point(&cont_loop);}
	 ;
		
returnstmt: RETURN_KEYWORD prexpr SEMICOL {	if( func_flag > 0 ){
		  										emit(ret,NULL,NULL,&$2,0,yylineno);
											 	emit(jump,NULL,NULL,NULL,0,yylineno);
	 								 			insert_jump_point(0,ret_s);
									 	  	}
											else{
												emit(nop,NULL,NULL,NULL,0,yylineno);
									 	        fprintf(stderr,"%s: line %d: ---> Warning : return statement out of function (no operation produced)\n",file_name,yylineno);
												 
											}
											$$ = $2;free(&$2); 
											fprintf(yyout,"rule:returnstmt -> return prexpr ;\n");
										   }
		;
		
prexpr: expr	{$$ = $1;free(&$1);fprintf(yyout,"rule:prexpr -> expr\n"); }
		|		{fprintf(yyout,"rule:prexpr -> empty\n");}
		;


%%
int main(int argc,char **argv){

	int lk , skata;
	struct expr * tmp;
	char **LF,**SC;
	double *NC;
	struct userfunc **UF;
	struct instruction *IN;
	new = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));
	ayylval = (void *) new;
	char *binary_filename;
	//oof_st = newStack(1024,sizeof( int ));
	
	if( argc<2 ){
		fprintf(stderr,"Error.No input file\n");
		return 1;
	}
	else{
	
		if(argc==2){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the file\n");
				return 1;
			}
			yyout=stdout;
			sym_file=stdout;
		}
		if(argc==3){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				fprintf(stderr,"Error while opening the output file\n");
				return 1;
			}
			sym_file=stdout;

		}
		if(argc==4){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				fprintf(stderr,"Error while opening the output file\n");
				return 1;
			}
			if((sym_file=fopen(argv[3],"w+"))==NULL){
				fprintf(stderr,"Error while opening the sym file file\n");
				return 1;
			}

		}

	}
	
	if((quad_ofile= fopen("quad.txt","w+")) == NULL){
		fprintf(stderr,"Cannot open quads.txt\n");
		exit(1);
	}
	
	if((fcode_ofile= fopen("fcode.txt","w+")) == NULL){
		fprintf(stderr,"Cannot open fcode.txt\n");
		exit(1);
	}

	file_name = strdup( argv[1]);
	binary_filename = (char *)malloc( strlen( file_name )*sizeof( char )+5 );
	binary_filename = strcpy(binary_filename,file_name);
	binary_filename = strcat(binary_filename,".abc");
	
	Init_symbolTable();
	
	yyparse();
	emit(nop,NULL,NULL,NULL,0,yylineno);

	print();


	print_to_file();
	
	//print_quads();
	
    generate_all();
	//print2_final_code();
	if(flag_error != 1){

	print_fcode();

	create_binary( binary_filename,userFuncs,nameLibFuncs,stringConsts,numConsts,
					avm_incode,oof_counter,curr_incode,totalNumConsts,totalStringConsts,totalNameLibFuncs,totalUserFuncs);
	
	
//	print_str_array(LF);
	}
	else{
		fprintf(stderr,"No executable produced.\n");
	}
	fclose(fcode_ofile);
	destroy_symboltable();
	free(new->s_value);
	free(new);
	fclose(yyin);
	fclose(yyout);
	
	fclose(sym_file);
	fclose(quad_ofile);

	
	//free(userFuncs);
	//fclose(fcode_ofile);
	return 0;
}


int yyerror(char *yaccProvideMessage){
	fprintf(stderr,"%s at line %d ,before token:%s\n",yaccProvideMessage,yylineno,yytext);
	flag_error = 1;
	return 0;
}
