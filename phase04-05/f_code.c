#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "f_code.h"
#include "icode.h"
#include "stack/stack.h"
#include "symboltable.h"

#define SIZE 1024
#define MAXSIZE 300000

extern struct quad * quad_array;
extern unsigned int total;
extern int yylineno;
extern int Currquad;
extern FILE *fcode_ofile;

unsigned int curr_incode = 0;
unsigned int quadCnt;

static unsigned int expand_size[] = { 1023,2053,4093,8191,16381,32771,65521 };
int expand_st = 0;
int expand_num = 0;
int expand_lib = 0;


struct incomplete_jump{

	unsigned instrNo; //the jump instuction number
	unsigned iaddress;//The i-code jump-target address
	struct incomplete_jump * next;


};



struct incomplete_jump * ij_head = (struct incomplete_jump *) 0;
unsigned ij_total = 0;


//typedef void (*genarator_func_t)(struct quad *);
/*generator_func_t*/
void (*generators[])(struct quad *) = {
    
	generate_ASSIGN, 
	generate_ADD ,
	generate_SUB ,
	generate_MUL ,
	generate_DIV ,
	generate_MOD ,
	generate_IF_EQ ,
	generate_IF_NOTEQ ,
	generate_IF_LESSEQ ,
	generate_IF_GREATEREQ ,
	generate_IF_LESS,
	generate_IF_GREATER ,
	generate_JUMP ,
	generate_CALL,
    generate_PARAM,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE ,	
    generate_NOP ,	
	generate_TABLEGETELEM ,	
	generate_TABLESETELEM ,
	generate_UMINUS,
	generate_AND ,
    generate_OR  ,
	generate_NOT ,
	generate_GETRETVAL,
	generate_RETURN




	
};


char *bool_names[2]={"false","true"};

unsigned totalNumConsts = 0;
unsigned totalStringConsts = 0;
unsigned totalNameLibFuncs = 0;
unsigned totalUserFuncs = 0;

unsigned consts_newstring (char * s);
unsigned consts_newnumber (double n);
unsigned libfuncs_newused (char * s);
unsigned userfuncs_add(char *,unsigned int, int );

Stack_T funcstack;	

char * opcode_names[] = {"assign"	 , "add" 	 	  , "sub" 	  ,
						 "mul"       , "div" 	 	  , "mod" 	  ,
						  "jeq"  	 	  , "jne" 	  ,
						 "jle"       , "jge" 	 	  , "jlt" 	  ,
						 "jgt"       , "jump"    	  , "call"	  ,
						 "pusharg"   , "funcenter",
						 "funcexit"	 , "newtable"	  ,	 "nop"	   ,
						 "tablegetelem" , "tablesetelem",
						 "uminus"    , "and" 	 	  , "or"  	  ,
   						 "not"       , "getretval"     
};
			
char * type_names[] = {  
	"label"  ,
	"global"  ,
	"formal",
	"local",
	"number" ,
	"string",
	"bool",
	"nil",
	"userfunc",
	"libfunc",
	"retval" 

};

void expand_array ( void * a , int who ){

	double * numbers;
	char   ** strings;
	char   ** library;
	//struct userfunc * userFuncs;

	
	int i = 0;

	if ( who == 1 ){

		if( expand_st > 6 )
			return ;
		
		strings = ( char ** )malloc( expand_size[expand_st] * sizeof(char *) );

 		if(strings == NULL){

			printf("Memory allocation error\n");
			return;
		}

		for (i=0; i<totalStringConsts; i++){

		strings[i] = strdup( stringConsts[i]);
		}
		free(stringConsts);
		stringConsts=strings;
		


	}
	else if ( who == 2 ){
		
		if( expand_num > 6 )
			return ;
	
		numbers = ( double * )malloc( expand_size[expand_num] * sizeof(double) );
	
		if(numbers == NULL){

			printf("Memory allocation error\n");
			return;
		}

		for (i=0; i<totalNumConsts; i++){
			numbers[i] = numConsts[i];
		}
		free(numConsts);
		numConsts=numbers;


	}
	else if ( who == 3 ){
		
		if( expand_lib > 6 )
			return ;
    	library = ( char ** )malloc( expand_size[expand_lib] * sizeof(char *) );

		if(library == NULL){

			printf("Memory allocation error\n");
			return;
		}

		for (i=0; i<totalNameLibFuncs; i++){
		library[i] =	strdup(nameLibFuncs[i]);
		}
		free(nameLibFuncs);
		nameLibFuncs=library;
	}
	else
		printf("\nError in argument!\n");





}
unsigned consts_newstring ( char * s ){
	 

	if ( totalStringConsts == 0 || totalStringConsts == expand_size[expand_st]-1 )
		expand_array( stringConsts , 1 );

	stringConsts[totalStringConsts] =strdup( s );
	totalStringConsts ++;
	
	return totalStringConsts - 1;

}
unsigned consts_newnumber (double  n ){
	 

	if ( totalNumConsts == 0 || totalNumConsts == expand_size[expand_num]-1 )
		expand_array( numConsts , 2 );

	numConsts[totalNumConsts] =  n ;
	totalNumConsts ++;
	
	return totalNumConsts - 1;

}
unsigned libfuncs_newused ( char * s ){
	 

	if ( totalNameLibFuncs == 0 || totalNameLibFuncs == expand_size[expand_lib]-1 )
		expand_array( nameLibFuncs , 3 );

    nameLibFuncs[totalNameLibFuncs] = strdup( s );
	totalNameLibFuncs ++;
	
	return totalNameLibFuncs - 1 ;

}

unsigned userfuncs_add ( char* s, unsigned int d, int f ){
	 
	struct userfunc * my_func = (struct userfunc *)malloc(sizeof(struct userfunc));
    
		my_func->id = strdup(s);
		my_func->address = d;
		my_func->localSize = f;

		userFuncs[totalUserFuncs] = my_func;
		totalUserFuncs ++;
		return totalUserFuncs - 1;

}


void make_operand (struct expr * e, struct vmarg * arg ){

	S_entry keep;

	
	if(e==NULL)
		return;
	switch ( e->e_type ){


	case var_e:
	case tableitem_e:
	case boolexpr_e:

	case newtable_e:{
			

			arg->val = return_field(e->sym,0);
			arg->sym = e->sym;

			switch ( return_field(e->sym,1) ){

					case programvar: arg->type = global_a;
									 arg->val = return_field(e->sym,0);
							 break;
					case functionlocal:
							 arg->type = local_a;
							 break;
					case formalarg:
							
							 arg->type = formal_a;
							 break;
					default:
						    break;
					
				}
			break;	
	}
	case constbool_e:{
            
			arg->val  = e->boolConst;
			arg->type = bool_a;
			break;
	}
	case conststring_e:{

			arg->val = consts_newstring(e->st_val);
			arg->type = string_a;
			break;
	}
					 
	case intnum_e:{
 
			arg->val = consts_newnumber(e->i_val);
			arg->type = number_a;
			break;
	}
	case floatnum_e:{
 
			arg->val = consts_newnumber(e->d_val);
			arg->type = number_a;
			break;
	}	  
	case programmfunc_e:{
			
			arg->type = userfunc_a;
			//arg->val = quad_array[quadCnt].taddress;
			//arg->val = userfuncs_add(return_name(e->sym),0,0);
			

			break;
	}
	case libraryfunc_e:{
			
			arg->type = libfunc_a;
			arg->val = libfuncs_newused( return_name(e->sym) );
			break;
	}
	case nil_e: arg->type = nil_a;
			break;
	default:
			break;
	}//switch (e-type


}


void make_numberoperand (struct  vmarg * arg , double val ){

	arg->val = consts_newnumber(val);
	arg->type = number_a;

}

void make_booloperand ( struct vmarg * arg , unsigned val ){

	arg->val = val;
	arg->type = bool_a;

}

void make_retvaloperand ( struct vmarg * arg ){

	arg->type = retval_a;
}


void generate_all(void){

unsigned int i;
    
	funcstack = newStack(1000,sizeof(struct userfunc *)); 
	for(i=0; i<Currquad; ++i){
		quadCnt=i;
		(*generators[quad_array[i].op])(quad_array+i);
    }
	patch_incomplete_jump();
}

void generate ( enum vmopcode op , struct quad *new_quad ){


	struct instruction t;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	reset_operand(&t.result);

	t.opcode = op;
	make_operand(new_quad->arg1,&t.arg1);
	make_operand(new_quad->arg2,&t.arg2);
	make_operand(new_quad->result , &t.result);

	new_quad->taddress = nextinstructionlabel();

    final_emit(t);

}


void generate_relational ( enum vmopcode op , struct quad *new_quad ){


	struct instruction t;
	t.opcode = op;

	if ( t.opcode != jump_v ){
		make_operand(new_quad->arg1,&t.arg1);
		make_operand(new_quad->arg2,&t.arg2);
	}
	else{
		reset_operand(&t.arg1);
		reset_operand(&t.arg2);

	}
	t.result.type = label_a;
	

	new_quad->taddress = nextinstructionlabel();

		
	
	if(new_quad->label <= quadCnt){
	   	t.result.val=quad_array[new_quad->label].taddress;
	}
	else{
		add_incomplete_jump(nextinstructionlabel(),new_quad->label);
	}
	   

    final_emit(t);
}


void add_incomplete_jump(unsigned instrNo,unsigned iaddress){

 struct incomplete_jump * new_jump,*tmp;
 

 	new_jump = (struct incomplete_jump *)malloc(sizeof(struct incomplete_jump));
    
	if(new_jump==NULL){
		printf("Memory allocation error\n");
		exit(0);
	}
	else{
    new_jump->instrNo=instrNo;
	new_jump->iaddress=iaddress;
	new_jump->next=NULL;
		
	}
  	if(ij_head==NULL){
	       	ij_head=new_jump;
					
 	}
	else{
   		new_jump->next = ij_head;
		ij_head = new_jump;
	}


	
}


void patch_incomplete_jump(void){

	struct incomplete_jump *tmp,*prev;

	
	  
	for(tmp=ij_head; tmp!=NULL; tmp=tmp->next){
			avm_incode[tmp->instrNo].result.val=quad_array[tmp->iaddress].taddress;
	
	}
}

void generate_ADD ( struct quad *new_quad ){


	generate( add_v , new_quad );

}

void generate_SUB ( struct quad *new_quad ){


	generate( sub_v , new_quad );

}
void generate_MUL ( struct quad *new_quad ){


	generate( mul_v , new_quad );

}
void generate_DIV ( struct quad *new_quad ){


	generate( div_v , new_quad );

}
void generate_MOD ( struct quad *new_quad ){


	generate( mod_v , new_quad );

}

void generate_NEWTABLE ( struct quad *new_quad ){


	generate( newtable_v , new_quad );

}
void generate_TABLEGETELEM ( struct quad *new_quad ){


	generate( tablegetelem_v , new_quad );

}
void generate_TABLESETELEM ( struct quad *new_quad ){


	generate( tablesetelem_v , new_quad );

}

void generate_ASSIGN ( struct quad *new_quad ){

	generate( assign_v , new_quad );
	

}
void generate_UMINUS ( struct quad *new_quad ){


	generate( uminus_v , new_quad );

}
/*void generate_art(struct quad *new_quad){

    generate(art_v,new_quad);
}*/
/*void generate_zoi(struct quad *new_quad){

    generate(zoi_v,new_quad);
}
*/
void generate_AND ( struct quad *new_quad ){

	struct instruction t;

	new_quad->taddress = nextinstructionlabel();

	t.opcode = jeq_v;
	make_operand(new_quad->arg1,&t.arg1);
	make_booloperand(&t.arg2,0);
	
	t.result.type = label_a;

	t.result.val = nextinstructionlabel()+4;

	final_emit(t);
	
	make_operand(new_quad->arg2,&t.arg1);
	t.result.val = nextinstructionlabel()+3;

	final_emit(t);
	
	t.opcode = assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);

	t.opcode = jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;
	
	final_emit(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);
	patch_incomplete_jump();
	
	


}
void generate_NOP (struct quad *new_quad){

	struct instruction t;
	t.opcode = nop_v;
	new_quad->taddress = nextinstructionlabel();
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	reset_operand(&t.result);
	
	final_emit(t);

}


void generate_JUMP ( struct quad *new_quad ){


	generate_relational( jump_v , new_quad );
	
}

void generate_IF_EQ ( struct quad *new_quad ){


	generate_relational( jeq_v , new_quad );
	

}

void generate_IF_NOTEQ ( struct quad *new_quad ){


	generate_relational( jne_v , new_quad );
}

void generate_IF_GREATER ( struct quad *new_quad ){


	generate_relational( jgt_v , new_quad );
}

void generate_IF_GREATEREQ ( struct quad *new_quad ){


	generate_relational( jge_v , new_quad );

}

void generate_IF_LESS ( struct quad *new_quad ){


	generate_relational( jlt_v , new_quad );

}

void generate_IF_LESSEQ ( struct quad *new_quad ){


	generate_relational( jle_v , new_quad );

}

void generate_NOT(struct quad *new_quad ){
	
	struct instruction t;
	
	new_quad->taddress = nextinstructionlabel();


	t.opcode = jeq_v;
	make_operand(new_quad->arg1,&t.arg1);
	make_booloperand(&t.arg2,0);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+3;

	final_emit(t);

	

	t.opcode = assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);

	t.opcode = jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;
	
	final_emit(t);
	
	t.opcode = assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);
   
	
}


unsigned int nextinstructionlabel(void){

   return curr_incode;
}

void reset_operand ( struct vmarg * arg ){
    arg->type=-1;
	
}

void generate_OR(struct quad *new_quad){
	struct instruction t;

	new_quad->taddress = nextinstructionlabel();

	t.opcode = jeq_v;
	make_operand(new_quad->arg1,&t.arg1);
	make_booloperand(&t.arg2,1);
	
	t.result.type = label_a;

	t.result.val = nextinstructionlabel()+4;

	final_emit(t);
	
	make_operand(new_quad->arg2,&t.arg1);
	t.result.val = nextinstructionlabel()+3;

	final_emit(t);
	
	t.opcode = assign_v;
	make_booloperand(&t.arg1,0);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);

	t.opcode = jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	t.result.val = nextinstructionlabel()+2;
	
	final_emit(t);

	t.opcode = assign_v;
	make_booloperand(&t.arg1,1);
	reset_operand(&t.arg2);
	make_operand(new_quad->result,&t.result);

	final_emit(t);
	patch_incomplete_jump();
	
	
}

void generate_PARAM(struct quad *new_quad){

	struct instruction t;

	new_quad->taddress = nextinstructionlabel();
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	reset_operand(&t.result);
	t.opcode = pusharg_v;
	make_operand(new_quad->result,&t.result);
	final_emit(t);
	
}

int find_index(char *name){
	int i = 0;
	for(i=0; i<totalUserFuncs; i++){
		if(strcmp(name,userFuncs[i]->id ) == 0){
			return i;
		}
		
	}
	return -1;
}
void generate_CALL(struct quad *new_quad){
	
	struct instruction t;
	char *name;
	int index;
	new_quad->taddress = nextinstructionlabel();
	if((index = find_index(find_name(new_quad->result->sym,2)))!=-1){
		t.result.val = index;

	}
	
	t.opcode = call_v;
	
	make_operand(new_quad->result,&t.result);
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	final_emit(t);
	
}

void generate_GETRETVAL(struct quad *new_quad){
	struct instruction t;

	new_quad->taddress = nextinstructionlabel();

	t.opcode = assign_v;
	make_operand(new_quad->result,&t.result);
	make_retvaloperand(&t.arg1);
	final_emit(t);
	
}


void generate_FUNCSTART(struct quad *new_quad){
/////////////PROSOXH STH STOIBA////////////////
	struct instruction t;
	S_entry f = new_quad->arg1->sym;

	//f->taddress = nextinstructionlabel();

	new_quad->taddress = nextinstructionlabel();
	
	t.result.val = userfuncs_add(return_name(f),new_quad->taddress,return_varsum(f));
	push((void *)f,funcstack);

	t.opcode = funcenter_v;

	reset_operand(&t.arg1);
	reset_operand(&t.arg2);

	make_operand(new_quad->arg1,&t.result);

	final_emit(t);
}

void generate_RETURN(struct quad *new_quad){
	struct instruction t;
    S_entry f;
	
	new_quad->taddress = nextinstructionlabel();
	t.opcode = assign_v;
	make_retvaloperand(&t.result);
	make_operand(new_quad->result , &t.arg1 );
	reset_operand(&t.arg2);
	final_emit(t);
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);

	//f = top(funcstack);

	//append(f.returnList , nextinstructionlabel());
	/*t.opcode = jump_v;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = label_a;
	*/
//	generate_relational(jump_v,new_quad);
	//final_emit(t);

}

void generate_FUNCEND(struct quad *new_quad){
	struct instruction t;
    S_entry f;
 
    f = pop(funcstack);
    //stack_backpatch(f.returnList, nextinstructionlabel());
    new_quad->taddress = nextinstructionlabel();
//	printf("name ----- > %s",find_name(new_quad->arg1->sym,2));
	t.result.val = find_index(find_name(new_quad->arg1->sym,2));

  	t.opcode = funcexit_v;

	reset_operand(&t.arg1);
	reset_operand(&t.arg2);

  	make_operand(new_quad->arg1 , &t.result );
   	final_emit(t);
}

void final_emit(struct instruction t){
	
    

	
	if ( curr_incode == MAXSIZE-1 ){
		printf("\n FULL TABLE  OF INSTRUCTIONS \n");
		exit(0);
	}
	
	t.srcLine = yylineno;
	avm_incode[curr_incode++] = t;


}


	
void print_fcode(void){
		int i;
		for(i=0; i<curr_incode; i++){
			fprintf(fcode_ofile,"%i : ",i);
			fprintf(fcode_ofile," %d(%s) \t",avm_incode[i].opcode,opcode_names[avm_incode[i].opcode]);

			if(avm_incode[i].result.type!=-1){
				fprintf(fcode_ofile," %d(%s), ",avm_incode[i].result.type,type_names[avm_incode[i].result.type]);
				if(avm_incode[i].result.type==number_a)
            		fprintf(fcode_ofile," %d:%lf \t",avm_incode[i].result.val,numConsts[avm_incode[i].result.val]);
				else if(avm_incode[i].result.type==string_a)
            		fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].result.val,stringConsts[avm_incode[i].result.val]);
				else if(avm_incode[i].result.type==libfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].result.val,nameLibFuncs[avm_incode[i].result.val]);
				else if(avm_incode[i].result.type==userfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].result.val,userFuncs[avm_incode[i].result.val]->id);
				else if(avm_incode[i].result.type==bool_a){
					fprintf(fcode_ofile," %s \t" ,bool_names[avm_incode[i].result.val]);
				}
				else if(avm_incode[i].result.type==global_a || avm_incode[i].result.type==local_a || avm_incode[i].result.type==formal_a)
					fprintf(fcode_ofile," %d:%s \t",avm_incode[i].result.val,find_name(avm_incode[i].result.sym,1));
			 	else if(avm_incode[i].result.type==label_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].result.val);
				else if(avm_incode[i].result.type==nil_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].result.val);

				else
					fprintf(fcode_ofile,"\t" );

			}
			if(avm_incode[i].arg1.type!=-1){
				fprintf(fcode_ofile," %d(%s), \t",avm_incode[i].arg1.type,type_names[avm_incode[i].arg1.type]);
				if(avm_incode[i].arg1.type==number_a)
            		fprintf(fcode_ofile," %d:%lf \t",avm_incode[i].arg1.val,numConsts[avm_incode[i].arg1.val]);
				else if(avm_incode[i].arg1.type==string_a)
            		fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg1.val,stringConsts[avm_incode[i].arg1.val]);
				else if(avm_incode[i].arg1.type==libfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg1.val,nameLibFuncs[avm_incode[i].arg1.val]);
				else if(avm_incode[i].arg1.type==userfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg1.val,userFuncs[avm_incode[i].arg1.val]->id);
				else if(avm_incode[i].arg1.type==bool_a){
					fprintf(fcode_ofile," %s \t" ,bool_names[avm_incode[i].arg1.val]);
				}
				else if(avm_incode[i].arg1.type==global_a || avm_incode[i].arg1.type==local_a || avm_incode[i].arg1.type==formal_a)
					fprintf(fcode_ofile," %d:%s \t",avm_incode[i].arg1.val,find_name(avm_incode[i].arg1.sym,1));
			 	else if(avm_incode[i].arg1.type==label_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].arg1.val);
				else if(avm_incode[i].arg1.type==nil_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].arg1.val);
				else
					fprintf(fcode_ofile,"\t" );


			}
			if(avm_incode[i].arg2.type!=-1){
				fprintf(fcode_ofile," %d(%s), \t",avm_incode[i].arg2.type,type_names[avm_incode[i].arg2.type]);
				if(avm_incode[i].arg2.type==number_a)
            		fprintf(fcode_ofile," %d:%lf \t",avm_incode[i].arg2.val,numConsts[avm_incode[i].arg2.val]);
				else if(avm_incode[i].arg2.type==string_a)
            		fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg2.val,stringConsts[avm_incode[i].arg2.val]);
				else if(avm_incode[i].arg2.type==libfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg2.val,nameLibFuncs[avm_incode[i].arg2.val]);
				else if(avm_incode[i].arg2.type==userfunc_a)
           			fprintf(fcode_ofile," %d:%s \t" ,avm_incode[i].arg2.val,userFuncs[avm_incode[i].arg2.val]->id);
				else if(avm_incode[i].arg2.type==bool_a){

            		fprintf(fcode_ofile," %s \t" ,bool_names[avm_incode[i].arg2.val]);
				}
				else if(avm_incode[i].arg2.type==global_a || avm_incode[i].arg2.type==local_a || avm_incode[i].arg2.type==formal_a )
					fprintf(fcode_ofile," %d:%s \t",avm_incode[i].arg2.val,find_name(avm_incode[i].arg2.sym,1));
			 	else if(avm_incode[i].arg2.type==label_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].arg2.val);
				else if(avm_incode[i].arg2.type==nil_a)
            		fprintf(fcode_ofile," %d \t" ,avm_incode[i].arg2.val);

				else
					fprintf(fcode_ofile,"\t" );


			}
			fprintf(fcode_ofile,"\n");


		}
	}
