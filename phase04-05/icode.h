#ifndef _ICODE_H_
#define _ICODE_H_

#include"symboltable.h"

enum iopcode{
			assign=0	 , add 	 		, sub 		 ,
			mul          , div_a 		, mod 		 ,
		    if_eq 		 , if_noteq     , if_lesseq  ,
			if_greatereq , if_less 	    , if_greater ,
			jump         , call         , param   	 , 
			funcstart	 , funcend      , tablecreate,
			nop		     , tablegetelem , tablesetelem,
			uminus       , and 	 		, or  		  ,
			not 		 , getretval    , ret
			
};


struct quad{
	
	enum iopcode op;
	struct expr * result;
	struct expr * arg1;
	struct expr * arg2;
	unsigned label;
	unsigned line;
	unsigned int taddress;

	
};

enum expr_t {

	var_e			, tableitem_e   , 
	programmfunc_e  , libraryfunc_e , 
	boolexpr_e	,
	newtable_e	,
	intnum_e		, floatnum_e	,
	constbool_e		, conststring_e	, 
	nil_e
};

enum stack_t {
	back_s , continue_s , break_s , ret_s ,funct_s
};

struct expr{

	enum expr_t   e_type;
	S_entry       sym;
	struct expr * index;
	unsigned char boolConst;
	int    i_val;
	double d_val;
	char * st_val;
	void * no_val;
	struct expr * next;
};	

void expand ( void );
void emit(enum iopcode , struct expr *, struct expr *, struct expr *, unsigned , unsigned );
char * new_tmp_var ( void );
void resetTemp( void );
struct expr * new_expr(enum expr_t );
struct expr * new_StrExpr(char *);
struct expr * new_IntExpr(int );
struct expr * new_FltExpr(double);
struct expr * new_BoolExpr(unsigned char);
struct expr * new_VarE(S_entry sym);
struct expr * new_FuncE(S_entry sym);
struct expr * link_elist(struct expr *head,struct expr *new);
struct expr * call_expr(struct expr * name , struct expr * elist_list );
struct expr * Expr_cpy( struct expr * a , struct expr *b );
struct expr * new_NillExpr(char *nill_k);

void resetTemp( void );
void print_quads(void);
struct expr op_expr(enum iopcode op,struct expr *arg1 ,struct expr *arg2 );
struct expr term_expr(enum iopcode op,struct expr *arg1); 
struct expr lvalue_prefix(enum iopcode op,struct expr *arg1,struct expr* arg2);
struct expr  const_expr(enum iopcode op,struct expr *arg1);
struct expr bool_oper(enum iopcode op,struct expr *arg1,struct expr *arg2);
struct expr andor_oper(enum iopcode op,struct expr * arg1, struct expr* arg2);
struct expr eq_neq_oper(enum iopcode op,struct expr * arg1, struct expr* arg2);
void insert_jump_point( int , enum stack_t );
void backpatch (enum stack_t st_t);
void insert_cont_point(int *loop);
int get_cont_point( int );
void insert_loop_point(int *loop);
int get_loop_point( int );
int getCurQuad ( void );
int Num_of_StackEls( enum stack_t );
void print_to_file ( void );

#endif
