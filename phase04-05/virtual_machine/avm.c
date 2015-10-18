#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#include <assert.h>
#include "avm.h"
#include "../binary_file.h"
#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE 4096
#define AVM_TABLE_HASHSIZE 211
#define MULTIPLIER 32
#define AVM_WIPEOUT(m) memset(&(m) ,0 ,sizeof(m))

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic


#define AVM_MAX_INSTRUCTIONS (unsigned) getretval_v
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1
#define avm_error printf
#define avm_warning printf

int flag = 0;


struct avm_memcell * stack[AVM_STACKSIZE];
extern int Scope;
unsigned char executionFinished = 0;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
unsigned totalActuals = 0;
char *bFilename;
int currlib = 0;
extern int totNC;
extern int totNS;
extern int totNL;
extern int totUF;
extern int totIN;
extern int totVA;

int func_declaration;
#define AVM_ENDING_PC codeSize

struct avm_memcell * ax , * bx , * cx;
struct avm_memcell * retval;

unsigned top = 4095 ,topsp=4094;

struct instruction *code ;
char **LibFuns,**strConsts;
double *numConsts;
struct userfunc ** UserFuns;


//extern void avm_warning(char *format,...);
void avm_calllibfunc(char * funcName);
void avm_callsaveenvironment(void);

void avm_assign (struct avm_memcell* lv,struct avm_memcell* rv);
//void avm_error(char *format,...);
char * avm_tostring(struct avm_memcell*);
struct userfunc avm_gefuncinfo(unsigned address);
typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc(char * id);
void avm_registerlibfunc(char *id,library_func_t addr);

struct avm_memcell * avm_tablegetelem (struct avm_table* table,struct avm_memcell* index);
void avm_tablesetelem(struct avm_table* table,struct avm_memcell* index, struct avm_memcell* content);

double consts_getnumber ( unsigned index );
char * consts_getstring ( unsigned index );
char * libfuncs_getused ( unsigned index );



char * number_tostring (struct avm_memcell*);
char * string_tostring (struct avm_memcell*);
char * bool_tostring (struct avm_memcell*);
char * table_tostring (struct avm_memcell*);
char * userfunc_tostring (struct avm_memcell*);
char * libfunc_tostring (struct avm_memcell*);
char * nil_tostring (struct avm_memcell*);
char * undef_tostring (struct avm_memcell*);

double add_impl(double x, double y);
double sub_impl(double x, double y);
double mul_impl(double x, double y);
double div_impl(double x, double y);
double mod_impl(double x, double y);

int func_enters[500];
unsigned char number_tobool (struct avm_memcell* m); 
unsigned char string_tobool (struct avm_memcell* m);
unsigned char bool_tobool (struct avm_memcell* m);
unsigned char table_tobool (struct avm_memcell* m);
unsigned char userfunc_tobool (struct avm_memcell* m);
unsigned char libfunc_tobool (struct avm_memcell* m);
unsigned char nil_tobool (struct avm_memcell* m);
unsigned char undef_tobool (struct avm_memcell* m);
unsigned char avm_tobool(struct avm_memcell* m);

void avm_memcellclear ( struct avm_memcell * m );
void avm_tabledestroy( struct avm_table * t );





char * (*tostringFuncs[])(struct avm_memcell*)={
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring

};




double (*arithmeticFuncs[])(double a,double b) = {

	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl

};


unsigned char (*toboolFuncs[])(struct avm_memcell *)={
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};



char * typeStrings[]= {
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};


struct lib_func *lib_funcs_table[13];




//Dialeksh 15
//mexri selida 6

void avm_initstack ( void ){

	unsigned int i;
	
	for ( i=0; i < AVM_STACKSIZE; ++i ){
		AVM_WIPEOUT(stack[i]);
		stack[i]= (struct avm_memcell *)malloc(sizeof(struct avm_memcell));

		stack[i]->type = undef_m;

	}

	for( i=AVM_STACKSIZE-1 ; i > AVM_STACKSIZE - 1 - totVA; i--){
		top -- ;
	
	}

}

struct avm_memcell * avm_translate_operand ( struct vmarg * arg , struct avm_memcell * reg ){


	switch ( arg->type ){

	case global_a:{
	
		return stack[ AVM_STACKSIZE - 1 - (arg->val) ];
	  }
				  
	case local_a:{
	
				 
		return stack[ topsp - (arg->val) ];
	}

	case formal_a:
		return stack[topsp + AVM_STACKENV_SIZE + 1 + (arg->val) ];

	case retval_a:
		//reg->type = undef_m;
		return retval;

	case number_a:
		reg->type  = number_m;
		reg->data.numVal = consts_getnumber(arg->val);
		return reg;

	case string_a:
		reg->type = string_m;
		reg->data.strVal = strdup(consts_getstring(arg->val));
		
		return reg;

	case bool_a:
		
		reg->type = bool_m;
		reg->data.boolVal = arg->val;
		return reg;

	case nil_a:
		reg->type = nil_m;
		return reg;

	case userfunc_a:
		reg->type = userfunc_m;
		reg->data.funcVal = funcTable[arg->val].address;
		return reg;

	case libfunc_a:
		reg->type = libfunc_m;
		reg->data.libfuncVal = libfuncs_getused(arg->val);
		return reg;

	default :
		assert(0);
	}

}


void avm_tableincrefcounter ( struct avm_table * t ){
	
	++t->refCounter;

}

/* Automatic garbage collection for tables when reference counter gets
 * zero.
 */


void avm_tabledecrefcounter ( struct avm_table * t ){
	
	assert( t->refCounter > 0 );
	
	if ( ! --t->refCounter )
		avm_tabledestroy(t);

}


void avm_tablebucketsinit ( struct avm_table_bucket ** p ){
	
	unsigned i=0;

	for ( i=0; i < AVM_TABLE_HASHSIZE; i++ )
		p[i] = (struct avm_table_bucket *)0;

}


/*  when a call is cleared , it has to destroy all dynamic data content
 *  or reset its reference to a table
 */

void avm_memcellclear ( struct avm_memcell * m ){
	
	void(*f)(struct avm_memcell *);

	if(m->type != undef_m){
		f = memclearFuncs[m->type];
		if(f)
			(*f)(m);
		m->type=undef_m;
	
	}
	
}


void avm_tablebucketdestroy( struct avm_table_bucket ** p ){

	unsigned i;
	struct avm_table_bucket * b ;
	struct avm_table_bucket * del;


	for ( i=0; i<AVM_TABLE_HASHSIZE; ++i ){

		for ( b = *p; b; ){

			del = b;
			b = b->next;
			avm_memcellclear(del->key);
			avm_memcellclear(del->value);
			free(del);
		}

		p[i] = (struct avm_table_bucket *)0;
	}
}

void avm_tabledestroy( struct avm_table * t ){

	avm_tablebucketdestroy(t->strIndexed);
	avm_tablebucketdestroy(t->numIndexed);

	free(t);
}
unsigned int hash(const char *key){
	
	unsigned int h;
	unsigned char *p;

	h=0;
	for(p=(unsigned char *)key;*p!='\0';p++){
		h=MULTIPLIER*h+*p;
	}
	return h%AVM_TABLE_HASHSIZE;
}
//dispatcher
unsigned char number_tobool (struct avm_memcell* m){ 
	return m->data.numVal != 0; 
}
unsigned char string_tobool (struct avm_memcell* m){
	return m->data.strVal[0] != 0; 
}
unsigned char bool_tobool (struct avm_memcell* m){ 
	return m->data.boolVal; 
}
unsigned char table_tobool (struct avm_memcell* m){ 
	return 1; 
}
unsigned char userfunc_tobool (struct avm_memcell* m){ 
	return 1;
}
unsigned char libfunc_tobool (struct avm_memcell* m){ 
	return 1;
}
unsigned char nil_tobool (struct avm_memcell* m){ 
	return 0;
}
unsigned char undef_tobool (struct avm_memcell* m){ 
	assert(0);
	return 0;
}


void execute_nop(struct instruction *instr){
	return;
}

void execute_cycle ( void ){

	unsigned oldPC;
	struct instruction *instr = code + pc;
	int func_daclaration = 0;

	
	if( executionFinished ){
		
		return;
	}
	else if( pc == AVM_ENDING_PC ){
		executionFinished = 1;
				
		return;
	}
	else{
		
		assert(pc < AVM_ENDING_PC );
		assert( instr->opcode >=0 );
		assert( instr->opcode <= AVM_MAX_INSTRUCTIONS);
		
		if( instr->srcLine ){
			currLine = instr -> srcLine;
		}

			
			/*if ( instr->opcode == funcenter_v && flag == 0 ){

				func_daclaration++;
				pc ++;
				
				while ( func_daclaration > 0 ){
					instr = code + pc;
					
					if ( instr->opcode == funcenter_v ){
						func_daclaration++;
					}
					else if ( instr->opcode == funcexit_v ){
						func_daclaration--;
					}
					pc++;
					instr = code + pc;
						
				}
				
			}
			else{*/
			
				oldPC = pc;		
				(*executeFuncs[instr->opcode])(instr);
		

			
		
				if(pc == oldPC){
					++pc;
				}
			//}
		
	}
	
}

void memclear_string (struct avm_memcell* m){
	
	assert(m->data.strVal);
	free(m->data.strVal);
}

void memclear_table (struct avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

void  execute_assign(struct instruction* instr){
	
	struct avm_memcell* lv = avm_translate_operand(&instr->result,(struct avm_memcell*)0);
	struct avm_memcell* rv = avm_translate_operand(&instr->arg1, ax);
	


	//assert(lv && (stack[0] <= lv && stack[top] >= lv || lv == retval));
	//assert(rv);



	avm_assign(lv,rv);

	

	
}


void avm_assign(struct avm_memcell* lv,struct avm_memcell *rv){


	if(lv == rv)
		return ;
	if(lv -> type == table_m &&
	   rv->type == table_m &&
	   lv->data.tableVal == rv->data.tableVal)
		return;
	
	if(rv->type == undef_m){
		avm_warning("assigning from 'undef' content!\n");
	
	}

	if ( lv->type < 0 || lv->type > 7 ) 
		lv->type = undef_m;

	avm_memcellclear(lv);

	memcpy(lv,rv,sizeof(struct avm_memcell));
	

	if(lv -> type == string_m){
		
		lv->data.strVal = strdup(rv->data.strVal);
	
 		
	}
	else if(lv->type == table_m){
		avm_tableincrefcounter(lv->data.tableVal);
	}
	
}

void execute_call(struct instruction *instr){
	char *s;
	struct avm_memcell* func = avm_translate_operand(&instr->result,ax);

	flag ++;
	
	assert(func);
	avm_callsaveenvironment();
	
	
	switch(func->type){

		case userfunc_m:{

			pc = func->data.funcVal;
		
			assert(pc < AVM_ENDING_PC);
			assert(code[pc].opcode == funcenter_v);
			break;
		}
		case string_m:	avm_calllibfunc(func->data.strVal); break;
		case libfunc_m:	avm_calllibfunc(func->data.libfuncVal);break;

		default:{
			s = avm_tostring(func);
			avm_error("call:cannot bind '%s' to function!",s);
			free(s);
			executionFinished = 1;
		}
	}
}

void avm_dec_top(void){

	if(top==0 || top>=4096){
		avm_error("stack_overflow");
		executionFinished = 1;
	}
	else{
		--top;
	}
}

void avm_push_envvalue(unsigned val){
	
	stack[top]->type = number_m;
	stack[top]->data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenvironment(void){
	
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top+totalActuals + 2);
	avm_push_envvalue(topsp);
}

struct userfunc avm_getfuncinfo(unsigned address){
	return funcTable[address];
}
void execute_funcenter(struct instruction * instr){

	struct userfunc funcInfo;
	struct avm_memcell *func = avm_translate_operand(&instr->result, ax);
	assert(func);
	assert(pc == func->data.funcVal);
	flag = 0;
	totalActuals = 0;
 	funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	
	
	if( (top=top - funcInfo.localSize)>=4096 ){
		avm_error("Stack overflow\n");
		executionFinished=1;
	}
}

unsigned avm_get_envvalue(unsigned i){
	unsigned val;
	assert(stack[i]->type == number_m);
	val = (unsigned)stack[i]->data.numVal;
	assert(stack[i]->data.numVal == ((double) val));
	return val;
	
}

void execute_funcexit(struct instruction *unused){
	unsigned oldTop = top;

	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(oldTop ++ <= top-1){
		avm_memcellclear(stack[oldTop]);
	}

	flag--;
}


void avm_calllibfunc (char * id){
	library_func_t f = avm_getlibraryfunc(id);
	if(!f){
		avm_error("unsupported lib func '%s' called",id);
		executionFinished = 1;
	}
	else{
		topsp = top;
		totalActuals = 0;
		(*f)();
		if(!executionFinished)
			execute_funcexit((struct instruction *)0);
	}
}

unsigned avm_totalactuals(void ){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

struct avm_memcell* avm_getactual (unsigned i){
	assert(i<avm_totalactuals());
	return stack[topsp+AVM_STACKENV_SIZE +1 + i];
}

void libfunc_print(void){
	unsigned i;
	char *s;
	struct avm_memcell * take;
	unsigned n = avm_totalactuals();
	
	for(i =0; i<n ; ++i){
		take=avm_getactual(i);
		if(take->type != number_m){
			s=avm_tostring(take);
			printf(s);
			printf("\n");
		}
		else{
			printf("%lf",take->data.numVal);
			printf("\n");
		}

		retval->type = number_m;
		retval->data.numVal = 0;
		
	//	free(s);
	}
}


void execute_pusharg (struct instruction *instr){

	struct avm_memcell* arg = avm_translate_operand(&instr->result,ax);
	assert(arg);

	avm_assign(stack[top],arg);
	++totalActuals;
	avm_dec_top();
}

char *avm_tostring(struct avm_memcell *m){
	
	assert(m->type >=0 && m->type <= undef_m);
	return (*tostringFuncs[m->type])(m);
}


void execute_arithmetic (struct instruction *instr){
	
	double (*op)(double,double);
	struct avm_memcell* lv = avm_translate_operand(&instr->result,(struct avm_memcell*)0);
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);

//	assert(lv);
//	assert( stack[0] <= lv );
//	assert( stack[top] > lv || lv==retval);
//	assert(rv1 && rv2);



	if(rv1->type != number_m || rv2->type != number_m){
		avm_error("line: %d -- not a number in arithmetic!\n",instr->srcLine);
		executionFinished = 1;
	}
	else{
		op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
		
	}
}

unsigned char avm_tobool(struct avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}


void execute_jeq (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)== avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1) == avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) == 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal == rv2->data.numVal);
		}
	}
	
	
	if(/*executionFinished &&*/ result)
		pc = instr->result.val;
	
	
	

	
}

void execute_jne (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)!= avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1)  != avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) != 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal != rv2->data.numVal);
		}
	}
	
	
	
	if(result)
		pc = instr->result.val;
	
	
	

	
}
void execute_jle (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)<= avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1)  <= avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) <= 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal <= rv2->data.numVal);
		}
	}
	
	
	
	if(result)
		pc = instr->result.val;
	
	
	

	
}

void execute_jlt (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)< avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1)  < avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) < 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal < rv2->data.numVal);
		}
	}
	
	
	
	if(result)
		pc = instr->result.val;
	
	
	

	
}

void execute_jge (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)>= avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1)  >= avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) >= 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal >= rv2->data.numVal);
		}
	}
	
	
	if(result)
		pc = instr->result.val;
	
	
	

	
}

void execute_jgt (struct instruction * instr){

	unsigned result = 0;
	struct avm_memcell* rv1 = avm_translate_operand(&instr->arg1, ax);
	struct avm_memcell* rv2 = avm_translate_operand(&instr->arg2, bx);
	
	assert(instr->result.type == label_a);
	if(rv1->type == undef_m || rv2->type == undef_m){
		
		avm_error("'undef ' involved in equality!");
	}
	else if(rv1->type == nil_m || rv2->type == nil_m){
		
		
		result = ((avm_tobool(rv1)> avm_tobool(rv2)));
	}
	else if(rv1->type != rv2->type){
		
		
		avm_error("%s == %s is illegal!",typeStrings[rv1->type],typeStrings[rv2->type]);
	}
	else if(rv1->type == bool_m || rv2->type == bool_m){
		
		
		
		result = ((avm_tobool(rv1)  > avm_tobool(rv2)));
	}
	else{
		if(rv1->type == string_m || rv2->type == string_m){
		
		result = (strcmp(avm_tostring(rv1),avm_tostring(rv2)) > 0);
	
		}
		else if(rv1 -> type == number_m || rv2 -> type == number_m){
			result =( rv1->data.numVal > rv2->data.numVal);
		}
	}
	
	
	
	if(result)
		pc = instr->result.val;
	
	
	

	
}

void execute_jump (struct instruction * instr){
	pc=instr->result.val;
 


}

void libfunc_typeof( void ){
	unsigned n = avm_totalactuals();

	if( n!= 1){
		avm_error("one argument (not %d) expected in 'typeof'!",n);
	}
	else{
		avm_memcellclear(retval);
		retval->type = string_m;
		retval->data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}
struct avm_table * avm_tablenew( void ){
	
	struct avm_table * t = (struct avm_table *)malloc(sizeof(struct avm_table));
	AVM_WIPEOUT(*t);
	t->refCounter = t->total = 0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);

	return t;
}
void execute_newtable(struct instruction *instr){

	struct avm_memcell* lv = avm_translate_operand(&instr->result,(struct avm_memcell*) 0);
//	assert(lv && (stack[0] <= lv && stack[top] > lv || lv==retval ));
	
	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(struct instruction* instr){
	
	struct avm_memcell* lv =  avm_translate_operand(&instr->result,(struct avm_memcell*)0);
	struct avm_memcell* t  =  avm_translate_operand(&instr->arg1,(struct avm_memcell*)0);
	struct avm_memcell* i  =  avm_translate_operand(&instr->arg2, ax);
	struct avm_memcell* content ;
	//assert(lv && (stack[0] <= lv && stack[top]>lv || lv==retval));
	//assert(t && stack[0] <= t && stack[top] > t);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;

	if(t->type != table_m){
		avm_error("illegal use of type %s as table!\n",typeStrings[t->type]);
	}
	else{
		content = avm_tablegetelem(t->data.tableVal,i);
		
		if(content)
			avm_assign(lv,content);
		else{
			char *ts = avm_tostring(t);
			char *is = avm_tostring(i);
			avm_warning("table element not found!\n");
			free(ts);
			free(is);
		}
	}


}

void execute_tablesetelem(struct instruction * instr){
	struct	avm_memcell *t = avm_translate_operand(&instr->result,(struct avm_memcell *)0);
	struct  avm_memcell *i = avm_translate_operand(&instr->arg1,ax);
	struct avm_memcell *c = avm_translate_operand(&instr->arg2, bx);

	//assert(t && stack[0] <= t && stack[top]>t );
	//assert(i && c);

	if(t->type != table_m )
		avm_error("illegal use of type %s as table!",typeStrings[t->type]);
	else
		avm_tablesetelem(t->data.tableVal,i,c);

}


void avm_initcodentables(char *bin_filename){

	
	codeSize = decode_binary( bin_filename);

	code = instr_table;
	numConsts = numTable;
	strConsts = strTable;
	LibFuns   = libFunTable;
}

void avm_initialize (char *bFilename){

	int i;
	avm_initcodentables(bFilename);
	
	avm_initstack();
	
	avm_registerlibfunc("print",libfunc_print);
	avm_registerlibfunc("typeof",libfunc_typeof);
}

void libfunc_totalarguments(void){
	unsigned p_topsp = avm_get_envvalue(topsp+AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(retval);

	if(!p_topsp){
		avm_error("'totalarguments' called outside a function");
		retval->type = nil_m;
	}
	else{
		retval->type = number_m;
		retval->data.numVal = avm_get_envvalue(p_topsp+AVM_NUMACTUALS_OFFSET);
	}

}


double add_impl(double x, double y){
	return x+y;
}
double sub_impl(double x, double y){
	return x-y;
}
double mul_impl(double x, double y){
	return x*y;
}
double div_impl(double x, double y){
	return x/y;
}
double mod_impl(double x, double y){

	return ((unsigned)x)%((unsigned)y);
}

char *libfuncs_getused(unsigned index){
	return LibFuns[index];
}
double consts_getnumber(unsigned index){
	return numConsts[index];
}
char *consts_getstring(unsigned index){
	return strConsts[index];
}


char * dtostr(double a,char *num){
	long ak = (long)a;
	long dek;
	double fl;
	char *dekstr;

	fl = a - ak;

	fl = fl *1000000000;
	dek = (long )fl;
	num = strdup(lltostr(ak,num));

	dekstr = strdup(lltostr(dek,dekstr));

	num=strcat(num,".");

	num = strcat(num,dekstr);
	return num;
	
}

char * number_tostring (struct avm_memcell* mc){
	char *num ;

	return dtostr(mc->data.numVal,num);
}

char * string_tostring (struct avm_memcell* mc){
	return mc->data.strVal;
}

char * bool_tostring (struct avm_memcell* mc){
	if(mc->data.boolVal == 0u){
		return "false";
	}
	return "true";
}
char * table_tostring (struct avm_memcell* mc){
	return NULL;
}
char * userfunc_tostring (struct avm_memcell* mc){
	return funcTable[mc->data.funcVal].id; 
}
char * libfunc_tostring (struct avm_memcell* mc){
	return mc->data.libfuncVal;
}
char * nil_tostring (struct avm_memcell* mc){
	return "nil";
}
char * undef_tostring (struct avm_memcell* mc){
	return "undef";
}

library_func_t avm_getlibraryfunc (char * id){
	
	int i;

	for(i=0 ; i<13 ; i++){
		if(strcmp(id,lib_funcs_table[i]->name)==0)
			return lib_funcs_table[i]->f;
	}
	return NULL;
}

void avm_registerlibfunc(char *id,library_func_t addr){
	lib_funcs_table[currlib]=(struct lib_func *)malloc(sizeof(struct lib_func));
	lib_funcs_table[currlib]->name = strdup(id);
	lib_funcs_table[currlib]->f = addr;
	currlib ++;
}

void execute_uminus (struct instruction* instr){
	return;
}

struct  avm_memcell * avm_tablegetelem (struct avm_table* table,struct avm_memcell* index){
	
	struct avm_table_bucket *head,*tmp;
	if(index->type==number_m){
	
		return (table->numIndexed[(int)index->data.numVal]->value);
	
	
	}
	else if(index->type==string_m){
		
		 head=table->strIndexed[hash(index->data.strVal)];
		 for(tmp=head; tmp!=NULL; tmp=tmp->next){
		 
		 	if(strcmp(tmp->key->data.strVal,index->data.strVal)==0)
				return tmp->value;
		 
		 }
	
		
	}
	return NULL;
}

void avm_tablesetelem(struct avm_table* table,struct avm_memcell* index, struct avm_memcell* content){
	
//An de ndouleyei antigrafh paidiwn
	struct avm_table_bucket * head,*new;
	
	if(index->type==number_m){
		//table->numIndexed[(int)index->data.numVal]->key=index;
		table->numIndexed[(int)index->data.numVal]=(struct avm_table_bucket *)malloc(sizeof(struct avm_table_bucket));
		
		table->numIndexed[(int)index->data.numVal]->value=content;
	
	
	}
	else if(index->type==string_m){
		
		

		new=(struct avm_table_bucket *)malloc(sizeof(struct avm_table_bucket));
		new->key=index;
		new->value=content;
		new->next = table->strIndexed[hash(index->data.strVal)];
		table->strIndexed[hash(index->data.strVal)]=new;
 
		 }
			
}
	

int main(int argc,char *argv[]){

	int i = 0;
	bFilename = strdup(argv[1]);
	ax = (struct avm_memcell *)malloc(sizeof(struct avm_memcell));
    bx = (struct avm_memcell *)malloc(sizeof(struct avm_memcell));
	cx = (struct avm_memcell *)malloc(sizeof(struct avm_memcell));
	retval = (struct avm_memcell *)malloc(sizeof(struct avm_memcell));

	
	avm_initialize (bFilename);
	
	
	codeSize=totIN;
	while(!executionFinished){
		execute_cycle();

	}


	return 0;
}
