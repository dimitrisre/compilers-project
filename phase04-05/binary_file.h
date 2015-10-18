#ifndef _BINARY_FILE_H_
#define _BINARY_FILE_H_
enum scopespace_t { programvar , functionlocal , formalarg };

typedef struct varType{
	
	char *name;
	int scope;
	int formalArg;
	int decline;
	
}varType;


struct list {

	char * a_name;
	struct list * next;
	
};

typedef struct funType{
	
	char *name;
	
	struct list *args;
	int args_sum;
	int vars_sum;
	int scope;
	int decline;

}funType;

enum sType  { P_VAR = 1 , P_FUN , P_LIBFUN };

struct symbolTableRecord{
	
	struct a{
		varType *p_var;
		funType *p_fun;
	}types;
	
	enum scopespace_t SSpace;
	enum sType symbolType;
	int isActive;
	struct symbolTableRecord *next;
	int offset;

};
typedef struct symbolTableRecord * S_entry;


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


typedef struct instruction * instruction;
typedef struct userfunc * userfunc;

double *numTable;
char   **strTable;
struct userfunc  * funcTable;
char   **libFunTable;
instruction instr_table;

void print_str_array(char **arr);


int create_binary( char *filename,struct userfunc ** userFuncs,char *NameLibFuncs[],char *stringConsts[],double *numConsts,
						instruction avm_incode,int num_of_programm_vars,unsigned int quadCnt, unsigned totalNumConsts,unsigned totalStringConsts,unsigned totalNameLibFuncs,unsigned totalUserFuncs);


FILE *binary_ofile;
int decode_binary(char *filename);//,double *numTable,char *strTable[],userfunc *funcTable,char *libFunTable[],instruction instr_table);
void print_str_array(char **arr);


#endif

