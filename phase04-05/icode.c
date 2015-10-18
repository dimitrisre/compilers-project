#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "icode.h"
#include "stack/stack.h"


#define EXPAND_SIZE 30000
#define CURR_SIZE   (total*sizeof(Quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(Quad)+CURR_SIZE)

extern FILE *sym_file, *quad_ofile;
extern int yylineno;
extern int Scope;
extern char * file_name;
unsigned int tmp_Cnt  = 0; 

typedef struct quad Quad;

Stack_T  back = NULL;
Stack_T  cont_stack = NULL;
Stack_T  break_stack = NULL;
Stack_T  loop_stack = NULL;
Stack_T  ret_stack = NULL;
Stack_T  funct_stack = NULL;

Quad *quad_array = (Quad *) 0;
unsigned int total = 0;
int Currquad  = 0;

char *op_names[]= {

			"assign"       , "add" 			, "sub" 		,
			"mul"          , "div"   		, "mod" 		,
			"if_eq"		   , "if_noteq"  	, "if_lesseq"   ,
			"if_greatereq" , "if_less" 	    , "if_greater"  ,
			"jump"         , "call"         , "param"   	,
			"funcstart"	   , "funcend"      , "tablecreate" ,
			"nop" 	       , "tablegetelem" , "tablesetelem",
			"uminus"       , "and" 			, "or"  		,
			"not"          , "getretval"    , "ret"           
	        
};

char *bool_const[] = { "false" , "true" };


void insert_jump_point(int null_flag,enum stack_t st_t){

	int tmp = -1;
	if(st_t == back_s){
		if(back == NULL)
			back = newStack(1024,sizeof(int));
		push(&Currquad,back);
	}
	else if(st_t == break_s){

		if(break_stack == NULL)
			break_stack = newStack(1024,sizeof(int));
		
		if(null_flag == 1){
			push(&tmp,break_stack);
			return;
		}
		push(&Currquad,break_stack);
	}
	else{
		if(ret_stack == NULL){
			ret_stack = newStack(1024,sizeof(int));
		}
		if(null_flag == 1){
			push(&tmp,ret_stack);
			return;
		}
		push(&Currquad,ret_stack);

	}

}

void insert_cont_point(int *loop){
	if(cont_stack == NULL)
		cont_stack = newStack(1024,sizeof(int));
	push(loop,cont_stack);
}


int get_cont_point(int p_flag){
	int *index = (int *)pop(cont_stack);
	
	if(p_flag == 0){
		push(index,cont_stack);
	}

	if(getNumOfEls(cont_stack) == 0){
		freeStack(cont_stack);
		cont_stack = NULL;
	}

	return *index;
}



void insert_loop_point(int *loop){
	if(loop_stack == NULL)
		loop_stack = newStack(1024,sizeof(int));
	push(loop,loop_stack);
}


int get_loop_point(int p_flag){
	int *index = (int *)pop(loop_stack);
	
	if(p_flag == 0){
		push(index,loop_stack);
	}

	if(getNumOfEls(loop_stack) == 0){
		freeStack(loop_stack);
		loop_stack = NULL;
	}

	return *index;
}

void backpatch (enum stack_t st_t){

	int *index,tmp;


	if(st_t == back_s){
		
		index = (int *)pop(back);
		quad_array[*index-1].label = Currquad;
		if(getNumOfEls(back) == 0){
			freeStack(back);
			back=NULL;
		}

	}
	else if(break_stack){
		if(break_stack == NULL)
			return;

		while(*(index = (int *)pop(break_stack)) != -1){
	
			quad_array[*index-1].label = Currquad;
		}
		if(getNumOfEls(break_stack) == 0 ){
			
			freeStack(break_stack);
			break_stack = NULL;
		}
	}
	else{
		if(ret_stack == NULL)
			return;
		
		while(*(index = (int *)pop(ret_stack)) != -1){
			quad_array[*index-1].label = Currquad;
			tmp = *index-1;
		}
		quad_array[tmp].label++;
		if(getNumOfEls(ret_stack) == 0 ){
			
			freeStack(ret_stack);
			ret_stack = NULL;
		}

	}



}

int Num_of_StackEls(enum stack_t st_t){
	if(st_t == continue_s){
		if(cont_stack == NULL)
			return 0;
		return getNumOfEls(cont_stack);
	}
	else if(st_t == break_s){
		if(break_stack == NULL)
			return 0;
		return getNumOfEls(break_stack);
	}
	else{
		if(back == NULL)
			return 0;
		return getNumOfEls(back);
	}
}
struct expr * new_NillExpr(char *nill_k){
	
	struct expr *newExpr = new_expr(nil_e);
	
	newExpr -> st_val = strdup( nill_k );
	return newExpr;
	
}
struct expr * new_expr(enum expr_t et){
	
	struct expr * new_icode = (struct expr *)malloc(sizeof(struct expr));

	if( new_icode == NULL){
		fprintf(stderr,"Memory allocation error!!\n");
		exit(1);
	}
	
	new_icode -> e_type = et;
	new_icode ->next    = NULL;
	
	return new_icode;
}




struct expr * new_StrExpr(char *str){

	struct expr *newExpr = new_expr(conststring_e);
	
	

	newExpr -> st_val = strdup( str );
	return newExpr;
}



struct expr * new_IntExpr(int i){
	
	struct expr *newExpr = new_expr(intnum_e);
	
	


	newExpr -> e_type = intnum_e;
	newExpr -> i_val = i;
	return newExpr;
	

}



struct expr * new_FltExpr(double f){
	struct expr *newExpr = new_expr(floatnum_e);
	
	newExpr -> e_type = floatnum_e;
	newExpr -> d_val = f;
	return newExpr;

}



struct expr * new_BoolExpr(unsigned char b){
	
	struct expr *newExpr = new_expr(constbool_e);
	
	newExpr -> boolConst = b;
	return newExpr;
}



struct expr * new_VarE(S_entry sym){

	struct expr *newExpr = new_expr(var_e);
	

	newExpr -> sym = sym;

	return newExpr;
}



struct expr * new_FuncE( S_entry sym ){

	struct expr *newExpr ;
	
	if ( find_func(sym) == 3 ){
		newExpr = new_expr(libraryfunc_e);
	}
	else if(find_func(sym) == 2)
		newExpr = new_expr(programmfunc_e);
	else
		return NULL;
	

	newExpr -> sym = sym;

	return newExpr;
}



struct expr term_expr(enum iopcode op,struct expr *arg1 ){

	
	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

	if  ( arg1->e_type == intnum_e  || arg1->e_type == floatnum_e || arg1->e_type == var_e)
	 {

		 tmp = new_tmp_var();

		  if( !lookup(tmp,Scope,1) )
			insert(Scope,tmp,yylineno,1);
											 
		  sym = find_rec(tmp,Scope,1);

		  if( sym != NULL )
		 		temp_expr = new_VarE(sym);

	emit(op,arg1,NULL,temp_expr,0,yylineno);

	}

	else
		fprintf(stderr,"%s: line %d: --->   Error : Wrong type argument to Unary Operators\n",file_name,yylineno);
	
	return *temp_expr;									
}



struct expr  const_expr(enum iopcode op,struct expr *arg1){
		
	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

	if  ( arg1->e_type == intnum_e  || arg1->e_type == floatnum_e || arg1->e_type == conststring_e 
		  || arg1->e_type==constbool_e  )
	 {

		 tmp = new_tmp_var();

		  if( !lookup(tmp,Scope,1) )
			insert(Scope,tmp,yylineno,1);
											 
		  sym = find_rec(tmp,Scope,1);

		  if( sym != NULL )
		 		temp_expr = new_VarE(sym);

	emit(op,arg1,NULL,temp_expr,0,yylineno);

	}

	else
		fprintf(stderr,"%s: line %d: --->   Error : Wrong type argument to Unary Minus\n",file_name,yylineno);
	
	
	return *temp_expr;
	
}

struct expr lvalue_prefix(enum iopcode op,struct expr *arg1,struct expr* arg2){

	

	if (  arg1->e_type == var_e)

	     emit(op,arg1,arg2,arg1,0,yylineno);

	else
	  fprintf(stderr,"%s: line : %d --->   Error : Incompatible types in Operation\n",file_name,yylineno);
										

	return *arg1;
	
}

struct expr op_expr(enum iopcode op,struct expr *arg1 ,struct expr *arg2 ){

	
	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

	if ( ( arg1->e_type == intnum_e  || arg1->e_type == floatnum_e || arg1->e_type == var_e)
	      && ( arg2->e_type == intnum_e  || arg2->e_type == floatnum_e || arg2->e_type == var_e ) ){

		 tmp = new_tmp_var();

		  if( !lookup(tmp,Scope,1) )
			insert(Scope,tmp,yylineno,1);
											 
		  sym = find_rec(tmp,Scope,1);

		  if( sym != NULL )
		 		temp_expr = new_VarE(sym);

	emit(op,arg1,arg2,temp_expr,0,yylineno);


	}

	else
	  fprintf(stderr,"%s: line : %d --->   Error : Incompatible types in Operation\n",file_name,yylineno);
										

	return *temp_expr;
	
}

struct expr bool_oper(enum iopcode op,struct expr * arg1, struct expr* arg2){

	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

	if ( ( arg1->e_type == intnum_e  || arg1->e_type == floatnum_e 
		   || arg1->e_type == var_e )
	  && ( arg2->e_type == intnum_e  || arg2->e_type == floatnum_e 
		   || arg2->e_type == var_e ) ){
			
		 tmp = new_tmp_var();

		  if( !lookup(tmp,Scope,1) )
			insert(Scope,tmp,yylineno,1);
											 
		  sym = find_rec(tmp,Scope,1);

		  if( sym != NULL )
		 		temp_expr = new_VarE(sym);

	emit(op,arg1,arg2,NULL,Currquad+3,yylineno);	
	emit(assign,new_BoolExpr(0u),NULL,temp_expr,0,yylineno);
	emit(jump,NULL,NULL,NULL,Currquad+2,yylineno);
    emit(assign,new_BoolExpr(1u),NULL,temp_expr,0,yylineno);


	}

	else
	  fprintf(stderr,"%s: line : %d --->   Error : Incompatible types in Operation\n",file_name,yylineno);
										

	return *temp_expr;
}


struct expr eq_neq_oper(enum iopcode op,struct expr * arg1, struct expr* arg2){

	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

	if ( (arg1->e_type == intnum_e && arg2->e_type == intnum_e )       ||
		 (arg1->e_type == floatnum_e && arg2->e_type == floatnum_e )   ||
		 (arg1->e_type == conststring_e && arg2->e_type == conststring_e ) ||
		 (arg1->e_type == constbool_e && arg2->e_type == constbool_e )	 ||
		 (arg1->e_type == var_e && arg2->e_type == var_e )){
			
		 tmp = new_tmp_var();

		  if( !lookup(tmp,Scope,1) )
			insert(Scope,tmp,yylineno,1);
											 
		  sym = find_rec(tmp,Scope,1);

		  if( sym != NULL )
		 		temp_expr = new_VarE(sym);

	emit(op,arg1,arg2,NULL,Currquad+3,yylineno);	
	emit(assign,new_BoolExpr(0u),NULL,temp_expr,0,yylineno);
	emit(jump,NULL,NULL,NULL,Currquad+2,yylineno);
    emit(assign,new_BoolExpr(1u),NULL,temp_expr,0,yylineno);


	}

	else
	  fprintf(stderr,"%s: line : %d --->   Error : Incompatible types in Operation\n",file_name,yylineno);
										
	return *temp_expr;
	


}
struct expr andor_oper(enum iopcode op,struct expr * arg1, struct expr* arg2){
	char * tmp;
	S_entry sym;
 	struct expr *temp_expr;

				
	tmp = new_tmp_var();

	if( !lookup(tmp,Scope,1) )
		insert(Scope,tmp,yylineno,1);
											 
	  sym = find_rec(tmp,Scope,1);

	if( sym != NULL )
	  temp_expr = new_VarE(sym);

	emit(op,arg1,arg2,temp_expr,Currquad+3,yylineno);
	
	
	/*emit(assign,new_BoolExpr(0u),NULL,temp_expr,0,yylineno);
	emit(jump,NULL,NULL,NULL,Currquad+2,yylineno);
    emit(assign,new_BoolExpr(1u),NULL,temp_expr,0,yylineno);*/


						
	return *temp_expr;

}

void expand ( void ){

    Quad * p;
	assert( total == Currquad );

	 p = (Quad *) malloc(NEW_SIZE);

	if(p == NULL){
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}
	if ( quad_array ){
         
		
		memcpy(p,quad_array,CURR_SIZE);
		free(quad_array);
	}
	quad_array  = p;
	total += EXPAND_SIZE;
	
	
}

struct expr * Expr_cpy( struct expr * a , struct expr *b ){
	
	if ( b == NULL )
		return NULL;

	a = NULL;
    a = (struct expr *)malloc(sizeof(struct expr));

	if ( a == NULL ){
		fprintf(stderr,"\nAllocation in expr_cpy  Error!\n");
		exit(0); 
	}
	else{
		a->e_type = b->e_type;
		a->i_val  = b->i_val;
		a->d_val  = b->d_val;


		if ( b->st_val != NULL ){
			a->st_val = NULL;
			a->st_val = (char *)strdup( b->st_val );
		}
		else{
			a->st_val = NULL;
		}

		a->no_val = b->no_val;
		a->index  = b->index;
		a->next   = b->next;
		a->sym    = b->sym;
		a->boolConst = b->boolConst;

		return a;
	}

}

void emit(enum iopcode op, struct expr * arg1, struct expr * arg2,
		  struct expr * result, unsigned label, unsigned line)
{
	           
    Quad *p;
	
	if ( Currquad == total ){
			expand();
	}
	
	p= quad_array + Currquad++;


	p->arg1   = Expr_cpy(p->arg1,arg1);
	p->arg2   = Expr_cpy(p->arg2,arg2);
	p->result = Expr_cpy(p->result,result);
	
	p->op     = op;
	p->label  = label;
	p->line   = line;
	
	
	if(p->result != NULL && p->result->sym == NULL){
		Currquad--;
		free(p->arg1);
		free(p->arg2);
		free(p->result);
		
	}

}

struct expr * call_expr(struct expr * name , struct expr * elist_list ){

	struct expr * tmp;
	char * tmp_var;
	struct expr * new_tmp;
	S_entry sym;

	
	
	for(tmp=elist_list; tmp!=NULL; tmp=tmp->next)
		emit(param,NULL,NULL,tmp,0,yylineno);

	
	emit(call,NULL,NULL,name,0,yylineno);
	

	tmp_var = new_tmp_var();
										  
	if( !lookup( tmp_var, Scope, 1 ) ){
		insert( Scope, tmp_var, yylineno, 1 );
	}
	sym = find_rec( tmp_var , Scope, 1);

	if( sym != NULL )
		new_tmp = new_VarE( sym );

	emit(getretval,NULL,NULL,new_tmp,0,yylineno);

	return new_tmp;
}

void print_quads(){

	int i;
	char *res_find;
	for(i=0; i<Currquad; i++){

	   if(quad_array[i].op == nop){
			printf("\033[1;33m %d: <%s>\033[0m\n" ,i , op_names[quad_array[i].op]);
			continue;
	   }

		printf("\033[1;33m %d: <%s>\033[0m" ,i , op_names[quad_array[i].op]);
	   
	   if( quad_array[i].op == call ){

			if ( quad_array[i].result->e_type == programmfunc_e ||  quad_array[i].result->e_type == libraryfunc_e )
				printf("\033[1;31m <%s>\033[0m\n" , find_name(quad_array[i].result->sym,2));

			else if ( quad_array[i].result->e_type == var_e ||  quad_array[i].result->e_type == tableitem_e )
				printf("\033[1;31m <%s>\033[0m\n" , find_name(quad_array[i].result->sym,1));

			else
			  printf("\033[1;31m <empty> \033[0m\n");
				

			continue;
	   				
	   }
		
		if(quad_array[i].op == jump ){
			 printf("\033[1;36m <%u>\033[0m\n" , quad_array[i].label);
			 continue;

		}
		if( quad_array[i].result != NULL ){
		    if(quad_array[i].result -> e_type == var_e || quad_array[i].result -> e_type == tableitem_e ||quad_array[i].result -> e_type == newtable_e )  {
				printf("\033[1;31m <%s>\033[0m" , find_name(quad_array[i].result->sym,1));
						
			}
		}
		else if( quad_array[i].arg1->e_type == programmfunc_e ||  quad_array[i].arg1->e_type == libraryfunc_e )
						;		
		else
			  printf("\033[1;31m <empty> \033[0m");
		
		
		
		//Arg1
		if(quad_array[i].arg1 != NULL){

			if(quad_array[i].arg1->e_type == intnum_e )
				printf("\033[1;36m <%d> \033[0m" , quad_array[i].arg1->i_val);

			else if ( quad_array[i].arg1->e_type == floatnum_e )
				printf("\033[1;36m <%lf> \033[0m" , quad_array[i].arg1->d_val);

			else if ( quad_array[i].arg1->e_type == var_e  ||  quad_array[i].arg1->e_type == newtable_e 
					  || quad_array[i].arg1->e_type == tableitem_e)
				printf("\033[1;36m <%s> \033[0m" , find_name(quad_array[i].arg1->sym,1));
			
			else if( quad_array[i].arg1->e_type == constbool_e )
				printf("\033[1;36m <%s> \033[0m" , bool_const[quad_array[i].arg1->boolConst]);
			else if(quad_array[i].arg1->e_type == conststring_e)
				printf("\033[1;36m <%s> \033[0m" , quad_array[i].arg1->st_val);				
			else if( quad_array[i].arg1->e_type == programmfunc_e ||  quad_array[i].arg1->e_type == libraryfunc_e )
				printf("\033[1;36m <%s> \033[0m" , find_name(quad_array[i].arg1->sym,2));
				
				
			
		}
		else
			printf("\033[1;36m <empty> \033[0m");

		//Arg2
		if(quad_array[i].arg2 != NULL){
			if (quad_array[i].arg2->e_type == intnum_e )
				printf("\033[1;36m <%d> \033[0m " , quad_array[i].arg2->i_val);
			else if(quad_array[i].arg2->e_type == floatnum_e)
				printf("\033[1;36m <%lf> \033[0m" , quad_array[i].arg2->d_val);
			else if( quad_array[i].arg2->e_type == constbool_e )
				printf("\033[1;36m <%s> \033[0m" , bool_const[quad_array[i].arg2->boolConst]);
			else if ( quad_array[i].arg2->e_type == var_e ||  quad_array[i].arg2->e_type == newtable_e ||  quad_array[i].arg2->e_type == tableitem_e)
				printf("\033[1;36m <%s> \033[0m" , find_name(quad_array[i].arg2->sym,1));
			else if(quad_array[i].arg2->e_type == conststring_e)
				printf("\033[1;36m <%s> \033[0m" , quad_array[i].arg2->st_val);			
			else if( quad_array[i].arg2->e_type == programmfunc_e ||  quad_array[i].arg2->e_type == libraryfunc_e )
				printf("\033[1;36m <%s> \033[0m" , find_name(quad_array[i].arg2->sym,2));
		
				
		}
		else
			printf("\033[1;36m <empty> \033[0m");
		
		if( quad_array[i].op == if_less 	|| quad_array[i].op == if_lesseq    || 
		    quad_array[i].op == if_greater  || quad_array[i].op == if_greatereq || 
			quad_array[i].op == if_eq 		|| quad_array[i].op == if_noteq || 
			//quad_array[i].op == and 		|| quad_array[i].op == or ||
			quad_array[i].op == not){
			
			 printf("\033[1;36m <%u>\033[0m" , quad_array[i].label);
			
		}
		printf("\n");
	}
}
void print_to_file (){
		int i;
	char *res_find;
	for(i=0; i<Currquad; i++){

	   if(quad_array[i].op == nop){
			fprintf(quad_ofile,"%d: <%s>\n" ,i , op_names[quad_array[i].op]);
			continue;
	   }

		fprintf(quad_ofile,"%d: <%s> " ,i , op_names[quad_array[i].op]);
	   
	   if(quad_array[i].op == call){

		   	if ( find_name(quad_array[i].result->sym,2) != NULL )
				fprintf(quad_ofile," <%s>\n" , find_name(quad_array[i].result->sym,2));
			else
				fprintf(quad_ofile," <%s>\n" , find_name(quad_array[i].result->sym,1));
				
			continue;
	   				
	   }
		
		if(quad_array[i].op == jump ){
			 fprintf(quad_ofile," <%u>\n" , quad_array[i].label);
			 continue;

		}
		if(quad_array[i].result!=NULL){
		    if(quad_array[i].result -> e_type == var_e || quad_array[i].result -> e_type == tableitem_e ||quad_array[i].result -> e_type == newtable_e )  {
				fprintf(quad_ofile," <%s> " , find_name(quad_array[i].result->sym,1));
						
			}
		}
		else if( quad_array[i].arg1->e_type == programmfunc_e ||  quad_array[i].arg1->e_type == libraryfunc_e )
			;
	  
		else
			  fprintf(quad_ofile," <empty> ");
		
		
		
		//Arg1
		if(quad_array[i].arg1 != NULL){
			if(quad_array[i].arg1->e_type == intnum_e )
				fprintf(quad_ofile," <%d> " , quad_array[i].arg1->i_val);

			else if ( quad_array[i].arg1->e_type == floatnum_e )
				fprintf(quad_ofile," <%lf> " , quad_array[i].arg1->d_val);

			else if ( quad_array[i].arg1->e_type == var_e  ||  quad_array[i].arg1->e_type == newtable_e 
					  || quad_array[i].arg1->e_type == tableitem_e)
				fprintf(quad_ofile," <%s> " , find_name(quad_array[i].arg1->sym,1));
			
			else if( quad_array[i].arg1->e_type == constbool_e )
				fprintf(quad_ofile," <%s> " , bool_const[quad_array[i].arg1->boolConst]);
			else if(quad_array[i].arg1->e_type == conststring_e)
				fprintf(quad_ofile," <%s> " , quad_array[i].arg1->st_val);				
			else if( quad_array[i].arg1->e_type == programmfunc_e ||  quad_array[i].arg1->e_type == libraryfunc_e )
				fprintf(quad_ofile,"  <%s> " , find_name(quad_array[i].arg1->sym,2));
				
				
			
		}
		else
			fprintf(quad_ofile,"<empty> ");

		//Arg2
		if(quad_array[i].arg2 != NULL){
			if (quad_array[i].arg2->e_type == intnum_e )
				fprintf(quad_ofile," <%d>  " , quad_array[i].arg2->i_val);
			else if(quad_array[i].arg2->e_type == floatnum_e)
				fprintf(quad_ofile," <%lf>" , quad_array[i].arg2->d_val);
			else if( quad_array[i].arg2->e_type == constbool_e )
				fprintf(quad_ofile," <%s> " , bool_const[quad_array[i].arg2->boolConst]);
			else if ( quad_array[i].arg2->e_type == var_e ||  quad_array[i].arg2->e_type == newtable_e)
				fprintf(quad_ofile," <%s> " , find_name(quad_array[i].arg2->sym,1));
			else if(quad_array[i].arg2->e_type == conststring_e)
				fprintf(quad_ofile," <%s> " , quad_array[i].arg2->st_val);			
			else if( quad_array[i].arg2->e_type == programmfunc_e ||  quad_array[i].arg2->e_type == libraryfunc_e )
				fprintf(quad_ofile," <%s> " , find_name(quad_array[i].arg2->sym,2));
		}
		else
			fprintf(quad_ofile," <empty> ");
		
		if( quad_array[i].op == if_less 	|| quad_array[i].op == if_lesseq    || 
		    quad_array[i].op == if_greater  || quad_array[i].op == if_greatereq || 
			quad_array[i].op == if_eq 		|| quad_array[i].op == if_noteq || 
		//	quad_array[i].op == and 		|| quad_array[i].op == or ||
			quad_array[i].op == not){
			
			 fprintf(quad_ofile," <%u>" , quad_array[i].label);
			
		}
		fprintf(quad_ofile,"\n");
	}

}
char * new_tmp_var ( void ){
	
	char * prefix = (char *)malloc(sizeof(char)*4);
	char * name;
	int size = 0 ;
	

	tmp_Cnt++;

	name = (char *)malloc(100*sizeof(char));
    
	if(name == NULL){
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}
	prefix = strcpy(prefix,"#t_");
	name   = (char *)lltostr(tmp_Cnt,name);
	name   = strcat(prefix,name);
    
	size = strlen(name);
	name[size]='\0';
   	

	return name; 

}


void resetTemp( void ){

	tmp_Cnt = 0;
}

int getCurQuad ( void ){
	
	return Currquad;

}


