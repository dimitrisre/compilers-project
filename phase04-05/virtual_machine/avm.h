#ifndef _AVM_H_
#define _AVM_H_


#define AVM_TABLE_HASHSIZE 211



#define AVM_MAX_INSTRUCTIONS (unsigned) getretval_v

#include "../binary_file.h"





enum avm_memcell_t{

	number_m = 0,
	string_m = 1,
	bool_m   = 2,
	table_m  = 3,
	userfunc_m = 4,
	libfunc_m  = 5,
	nil_m    = 6,
	undef_m  = 7

};

struct avm_memcell{

	enum avm_memcell_t type;
	
	union{

		double numVal;
		char * strVal;
		unsigned  boolVal;
		struct avm_table * tableVal;
		unsigned funcVal;
		char * libfuncVal;

	}data;

};

struct avm_table_bucket{
	
	struct avm_memcell * key;
	struct avm_memcell * value;
	struct avm_table_bucket * next;
	
};


struct avm_table{
	
	unsigned refCounter;
	struct avm_table_bucket * strIndexed[AVM_TABLE_HASHSIZE];
	struct avm_table_bucket * numIndexed[AVM_TABLE_HASHSIZE];
	unsigned total;

};


#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic



extern void execute_assign (struct instruction*);
extern void execute_add (struct instruction*);
extern void execute_sub (struct instruction*);
extern void execute_mul (struct instruction*);
extern void execute_div (struct instruction*);
extern void execute_mod (struct instruction*);
extern void execute_jne (struct instruction*);
extern void execute_jle (struct instruction*);
extern void execute_jge (struct instruction*);
extern void execute_jlt (struct instruction*);
extern void execute_jgt (struct instruction*);
extern void execute_call (struct instruction*);
extern void execute_jeq (struct instruction*);
extern void execute_pusharg (struct instruction*);
extern void execute_funcenter (struct instruction*);
extern void execute_funcexit (struct instruction*);
extern void execute_newtable (struct instruction*);
extern void execute_tablegetelem (struct instruction*);
extern void execute_tablesetelem (struct instruction*);
extern void execute_nop (struct instruction*);
extern void execute_jump (struct instruction*);

void (*executeFuncs[])(struct instruction *)={
execute_assign, 
execute_add,
execute_sub,
execute_mul,
execute_div,
execute_mod,
execute_jeq,
execute_jne,
execute_jle,
execute_jge,
execute_jlt,
execute_jgt,
execute_jump,
execute_call,
execute_pusharg,
execute_funcenter,
execute_funcexit,
execute_newtable,
execute_nop,
execute_tablegetelem,
execute_tablesetelem

};

void memclear_string (struct avm_memcell* );
void memclear_table (struct avm_memcell *);

void (*memclearFuncs[])(struct avm_memcell *)={
	0,/*number*/
	memclear_string,
	0,/*bool*/
	memclear_table,
	0,/*userfunc*/
	0,/*livfunc*/
	0,/*nil*/
	0 /*undef*/
};

struct lib_func{
	char *name;
	void (*f)(void);
	
};

#endif
