#ifndef _F_CODE_H_
#define _F_CODE_H_

#include "icode.h"
#include "symboltable.h"

#define MAXSIZE 300000

enum vmopcode{

			assign_v =0	 , add_v 	 	  , sub_v 		  ,
			mul_v        , div_v 	 	  , mod_v 		  ,
			jeq_v    	 , jne_v 		  ,
			jle_v        , jge_v 	 	  , jlt_v      	  ,
			jgt_v    	 , jump_v    	  , call_v        ,
			pusharg_v    , funcenter_v    ,
			funcexit_v	 , newtable_v	  , nop_v		  ,
			tablegetelem_v, tablesetelem_v, uminus_v      ,
			and_v 	 	  , or_v  		  ,	not_v        ,
			getretval_v    
			
		

};

enum vmarg_t{


	label_a    = 0,
	global_a   = 1,
	formal_a   = 2,
	local_a    = 3,
	number_a   = 4,
	string_a   = 5,
	bool_a     = 6,
	nil_a      = 7,
	userfunc_a = 8,
	libfunc_a  = 9,
	retval_a   = 10 

};

struct vmarg{

	enum vmarg_t type;
	unsigned val;
	S_entry sym;


};

struct instruction{

	enum vmopcode opcode;
	struct vmarg result;
	struct vmarg arg1;
	struct vmarg arg2;
	unsigned srcLine;


};

struct userfunc{

	unsigned address;
	unsigned localSize;
	char * id; 

};





struct instruction avm_incode[MAXSIZE];
double * numConsts;
char ** stringConsts;
struct userfunc * userFuncs[1000];
char ** nameLibFuncs;


void expand_array ( void * a , int who );

void final_emit(struct instruction t);
void generate_all(void);
void make_operand (struct expr * e, struct vmarg * arg );
void make_numberoperand (struct  vmarg * arg , double val );
void make_booloperand ( struct vmarg * arg , unsigned val );
void make_retvaloperand ( struct vmarg * arg );
void reset_operand ( struct vmarg * arg );
void add_incomplete_jump(unsigned instrNo , unsigned iaddress);
void patch_incomplete_jump(void);
void generate ( enum vmopcode op , struct quad *new_quad );
void generate_ASSIGN ( struct quad *new_quad );
void generate_ADD ( struct quad *new_quad );
void generate_SUB ( struct quad *new_quad );
void generate_MUL ( struct quad *new_quad );
void generate_DIV ( struct quad *new_quad );
void generate_MOD ( struct quad *new_quad );
void generate_UMINUS ( struct quad *new_quad );
void generate_AND(struct quad *new_quad);
void generate_OR(struct quad *new_quad);
void generate_NOT(struct quad *new_quad );

void generate_NEWTABLE ( struct quad *new_quad );
void generate_TABLEGETELEM ( struct quad *new_quad );
void generate_TABLESETELEM ( struct quad *new_quad );
void generate_NOP ( struct quad *new_quad );
void generate_JUMP ( struct quad *new_quad );
void generate_IF_EQ ( struct quad *new_quad );
void generate_IF_NOTEQ ( struct quad *new_quad );
void generate_IF_GREATER ( struct quad *new_quad );
void generate_IF_GREATEREQ ( struct quad *new_quad );
void generate_IF_LESS ( struct quad *new_quad );
void generate_IF_LESSEQ ( struct quad *new_quad );
void generate_relational( enum vmopcode op,struct quad *new_quad );
void generate_PARAM(struct quad *new_quad);
void generate_CALL(struct quad *new_quad);
void generate_GETRETVAL(struct quad *new_quad);
void generate_FUNCSTART(struct quad *new_quad);
void generate_RETURN(struct quad *new_quad);
void generate_FUNCEND(struct quad *new_quad);
void print_fcode(void);

void expand_array( void * , int who );
unsigned int nextinstructionlabel(void);


	



#endif


