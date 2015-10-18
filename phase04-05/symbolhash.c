#include"symboltable.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MULTIPLIER 32



extern char * func_name;
extern FILE * sym_file;
extern FILE * yyout;
int MaxScope=0;
unsigned int ScopeSpaceCounter = 1;
int func_Cnt = 0;
extern int oof_counter;
				
typedef struct varType{
	
	char *name;
	int scope;
	int formalArg;
	int decline;
	
}varType;


struct list {
	
	int  formal_offset;
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
	S_entry next;
	int offset;

};
struct sec_Hash{

	S_entry entry_ptr;

};
struct HashBucket{
	
	struct sec_Hash **ptr;
	int isActive;
	
}**ScopeTable;

int curHsAm  = -1;
int curHsAm2 =  0;
int progVars =  0;

/*A static array that contains the amounts of resizign the array in each case*/
static unsigned int HASH_AMOUNT[]={1023,2053,4093,8191,16381,32771,65521};
static unsigned int HASH_AMOUNT2[]={1023,2053,4093,8191,16381,32771,65521};

unsigned int hash(const char *key,unsigned int NHASH){
	
	unsigned int h;
	unsigned char *p;

	h=0;
	for(p=(unsigned char *)key;*p!='\0';p++){
		h=MULTIPLIER*h+*p;
	}
	return h%NHASH;
}

void Init_symbolTable(){
	insert(0,"print",0,P_LIBFUN);
	insert(0,"input",0,P_LIBFUN);
	insert(0,"tableindices",0,P_LIBFUN);
	insert(0,"tablelength",0,P_LIBFUN);
	insert(0,"tablecopy",0,P_LIBFUN);
	insert(0,"totalarguments",0,P_LIBFUN);
	insert(0,"argument",0,P_LIBFUN);
	insert(0,"typeof",0,P_LIBFUN);
	insert(0,"strtonum",0,P_LIBFUN);
	insert(0,"sqrt",0,P_LIBFUN);
	insert(0,"cos",0,P_LIBFUN);
	insert(0,"sin",0,P_LIBFUN);

}


struct HashBucket ** create_Hash ( int Hash_size ){
	
	int i = 0 ;
	struct HashBucket ** new;

	new = ( struct HashBucket ** )calloc( Hash_size , sizeof(struct HashBucket *) );

	for ( i=0; i<Hash_size; i++ ){

		new[i] = (struct HashBucket *)malloc( sizeof(struct HashBucket ));

		if ( new[i] == NULL ){
			fprintf(stderr,"Error in allocation\n");
			return NULL;
		}
		new[i]->ptr = NULL;
		new[i]->isActive=0;

	}
	if ( new == NULL ){
		fprintf(stderr,"\nAllocation Error in create_Hash\n");
		
	}

	
	return new;
}

struct sec_Hash ** createBucket( int size ){

	int i = 0 ;
	struct sec_Hash ** new;
	
	new = ( struct sec_Hash ** )calloc( size , sizeof( struct sec_Hash *) );


	for ( i=0; i < size; i++ ){

		new[i] = (struct sec_Hash *)malloc( sizeof(struct sec_Hash ));

		if ( new[i] == NULL ){
				fprintf(stderr,"Allocation Error!!\n");
				return NULL;
		}
		new[i]->entry_ptr = NULL;

	}
	if ( new == NULL ){
		fprintf(stderr,"\nAllocation Error in create_Hash\n");
	}
	
	return new;
	
}

S_entry  createSymbol( int v_f_type ,int Scope,int decline,char *name){


	S_entry  new ;
	
	
	new  =  ( S_entry )malloc( sizeof(struct symbolTableRecord ) );
	
	if ( new == NULL ){
		fprintf(stderr,"Allocation error \n");
		return NULL;
	}

	new->symbolType = v_f_type;
//	new->SSpace     = currScopeSpace();

	if ( v_f_type == P_VAR ){
		
		new->types.p_var = ( varType *)malloc(sizeof( varType ));

		new->types.p_var->name = (char *)malloc( sizeof(char)*(strlen(name)+1) );
		strcpy( new->types.p_var->name ,name);



		new->types.p_var->scope = Scope;

		new->types.p_var->decline = decline;
		
		new->isActive = 1;
		
		new->types.p_var->formalArg = 0;
		
		new->next = NULL;
		progVars ++;
		new->SSpace = currScopeSpace();

		if(new->SSpace == programvar)
			new->offset = oof_counter++;

		
	}
	else if ( v_f_type == P_FUN ){

		new->types.p_fun = ( funType *)malloc(sizeof( funType ));

		new->types.p_fun->name = strdup( name );

		new->types.p_fun->scope = Scope;

		new->types.p_fun->decline = decline;

		new->types.p_fun->args_sum = 0;

		new->types.p_fun->vars_sum = 0;

		new->isActive = 1;

		new->next = NULL;

		new->SSpace     = currScopeSpace();
	}
	else if( v_f_type == P_LIBFUN){
		
		new->types.p_fun = ( funType *)malloc(sizeof( funType ));

		new->types.p_fun->name = strdup( name );

		new->types.p_fun->scope = Scope;

		new->types.p_fun->decline = decline;

		new->types.p_fun->args_sum = 0;

		new->types.p_fun->vars_sum = 0;

		new->isActive = 1;

		new->next = NULL;
		new->SSpace = 4;
	}	
	return new;
		
	
}

int expand_hash(){

	struct HashBucket ** newEntry;
	int i;
	
	if(curHsAm>5)
		return 0;
	
	newEntry=create_Hash(HASH_AMOUNT[curHsAm+1]);
	
	if(newEntry!=NULL){
		
		
	    ++curHsAm;
		for(i=0; i<HASH_AMOUNT[curHsAm-1]; i++){
		     
			 newEntry[i]->ptr=ScopeTable[i]->ptr;
		}	
		free(ScopeTable);
		ScopeTable=newEntry;
		
		return 1;
	}

	else
		fprintf(stderr,"Memory Allocation error");

	
	return 0;
}



int insert ( int Scope , char * name , int line , int V_or_F ){

	
	unsigned int pos = 0;
	S_entry m_entry;
		   
	if ( curHsAm == -1 ){
		
	   ScopeTable = create_Hash( HASH_AMOUNT[++curHsAm] );
	  	   
	   if( ScopeTable == NULL ){
			return 0;
		}
	}
	
    while( MaxScope >= HASH_AMOUNT[ curHsAm ] ){
	    expand_hash();
		
		
	}

	if ( ScopeTable[Scope]->ptr == NULL ){
		
		ScopeTable[Scope]->ptr = createBucket( HASH_AMOUNT2[curHsAm2] );
		ScopeTable[Scope]->isActive=1;
		if( ScopeTable[Scope]->ptr == NULL ){
			return 0;
		}
	} 	

		
	pos = hash( name , HASH_AMOUNT2[curHsAm2] );
	ScopeTable[Scope]->isActive=1;

	if( ScopeTable[Scope]->ptr[pos]->entry_ptr == NULL ){
		
	 	ScopeTable[Scope]->ptr[pos]->entry_ptr = createSymbol( V_or_F,Scope,line,name );
	 	return 1;
	}
	 
	m_entry = createSymbol( V_or_F,Scope,line,name );
		 
	if( m_entry==NULL ){
	 	return 0;
	}
		 
	m_entry->next = ScopeTable[Scope]->ptr[pos]->entry_ptr;
	//m_entry->offset = progVars;
	ScopeTable[Scope]->ptr[pos]->entry_ptr = m_entry;
		 
	return 1;
		 
	
}

void print_list( S_entry head ){

	S_entry tmp;
	struct list *tmp1;
	for(tmp=head; tmp !=NULL; tmp=tmp->next ){
		
			if ( tmp->symbolType == 1 ){
				if(tmp->types.p_var->formalArg == 0){
					fprintf(sym_file,"VariableName = %s Scope = %d decline = %d isActive=%d\n", tmp->types.p_var->name, tmp->types.p_var->scope , tmp->types.p_var->decline ,tmp->isActive);
				}
			}
			else if ( tmp->symbolType == 2 ){
					
					fprintf(sym_file,"FunctionName = %s Scope = %d decline = %d isActive=%d\n", tmp->types.p_fun->name, tmp->types.p_fun->scope, tmp->types.p_fun->decline ,tmp->isActive);
					fprintf(sym_file,"FormalArguments:\n");
					for(tmp1=tmp->types.p_fun->args; tmp1!=NULL; tmp1=tmp1->next){
						fprintf(sym_file,"< %s >",tmp1->a_name);
					}
					fprintf(sym_file,"\n");
					
					
			}
			else if( tmp->symbolType == 3 ){
									
					fprintf(sym_file,"library Function = %s  \n", tmp->types.p_fun->name);
					
			}
			
		
	}

}
void print(){

	int i,j;
	S_entry entr;
	
	if(ScopeTable==NULL){
		return;
	}

	 
	for(i=0; i<HASH_AMOUNT[curHsAm]; i++){
	
		if( ScopeTable[i]->ptr != NULL){

			for(j=0; j<HASH_AMOUNT2[curHsAm2]; j++){
				
        	     if ( ScopeTable[i]->ptr[j]->entry_ptr != NULL){
                     
					 print_list(ScopeTable[i]->ptr[j]->entry_ptr);
								
			 	}
			}
	 	}
 	}

 
}

int lookup( char* name,int scope,int v_or_f){
    
       unsigned int pos;
	   S_entry entr,tmp;
	   


	if(ScopeTable==NULL){
		return 0;
	}

	if(scope>HASH_AMOUNT[curHsAm])
		return 0;
	if( (ScopeTable[scope]->isActive)==0)
		return 0;
	
      
	pos=hash(name,HASH_AMOUNT2[curHsAm2]);
	
	if ( ScopeTable[scope]->ptr == NULL ){
		return 0;
	}
	entr=ScopeTable[scope]->ptr[pos]->entry_ptr;
		
	if(entr==NULL)
		return 0;
		
	tmp=entr;
	if(v_or_f==1){
	   while(tmp!=NULL){
		 if(tmp->symbolType==1){
		 if ( tmp->types.p_var->name != NULL && tmp->isActive==1){
		 	if(strcmp(tmp->types.p_var->name,name)==0)
		    	return 1;
		 }
		 }
		 tmp=tmp->next;
	    }
			  return 0;
	}
    else if(v_or_f== 2 || v_or_f == 3){
	  while	(tmp!=NULL){
		if(tmp->symbolType == 2){
			if ( tmp->types.p_fun->name != NULL && tmp->isActive==1){
	    		if(strcmp(tmp->types.p_fun->name,name)==0)
	        		return 1;
			}
		}
		else if(tmp->symbolType == 3){
			if ( tmp->types.p_fun->name != NULL ){
	    		if(strcmp(tmp->types.p_fun->name,name)==0)
	        		return 1;
			}
		}

	    tmp=tmp->next;
	}
			  return 0;
	}
	return 0;
		
	
	

}

void Hide(int scope){
	S_entry tmp;
	int i;
	
	ScopeTable[scope]->isActive=0;
	for(i=0;i<HASH_AMOUNT2[curHsAm2];i++){
		if(ScopeTable[scope]->ptr!=NULL){
			  	for(tmp=ScopeTable[scope]->ptr[i]->entry_ptr;tmp!=NULL;tmp=tmp->next){
			
				tmp->isActive = 0;
			}
		}
	}
	
}


int insert_arguments( int scope ){

	struct list * head = NULL;
	struct list * new;
	int i , arg_cnt = 0;
	S_entry tmp;
	
	unsigned int h;
	
	if ( ScopeTable[scope]->ptr == NULL )
		return 0;
	if(ScopeTable[scope-1]->ptr==NULL){
		return 0;
	}
	
	// sundeoume thn lista twn arguments.
	// Diatrexoume ton hash tou scope .
	
	for( i=0; i<HASH_AMOUNT2[curHsAm2]; i++ ){
		
		for( tmp=ScopeTable[scope]->ptr[i]->entry_ptr; tmp!=NULL; tmp=tmp->next ){
			
			if( tmp->isActive == 1 ){
				
				tmp->types.p_var->formalArg = 1;
				new = (struct list *)malloc(sizeof(struct list));

				if ( new == NULL ){
					fprintf(stderr,"Allocation error\n");
					exit(1);
				}
				
				new->a_name=strdup(tmp->types.p_var->name);
				tmp->offset =  arg_cnt;
				new->next=head;
				head=new;
				arg_cnt ++;
			}
		}
	}
	


	//Vazoume sthn domh ths function th lista twn args ths.

	h = hash( func_name , HASH_AMOUNT2[curHsAm2] );
	
	if(ScopeTable[scope-1]->ptr[h]==NULL){
		return 0;
	}
	
	tmp = ScopeTable[scope-1]->ptr[h]->entry_ptr;
	
	while ( tmp != NULL ){

		if ( tmp->symbolType == 2 ){
						
			if ( strcmp(tmp->types.p_fun->name,func_name) == 0 ){
					
					tmp->types.p_fun->args = head;
					tmp->types.p_fun->args_sum = arg_cnt;

					if(tmp->types.p_fun->args!=NULL){
						return 1;
					}
					return 0;
			}	
		}
		tmp =tmp->next;
		
	}

}

void free_list(struct list *head){
	struct list *tmp,*next;

	for(tmp=head;tmp!=NULL;next=tmp->next,tmp=next){
		free(tmp);
	}
}

void destroy_symboltable(){
	int i,j;
	S_entry tmp,next;
	if(ScopeTable==NULL)
		return ;
	
	for(i=0;i<HASH_AMOUNT[curHsAm];i++){
		
		if(ScopeTable[i]!=NULL){
			
			if(ScopeTable[i]->ptr!=NULL){
				
				for(j=0;j<HASH_AMOUNT2[curHsAm2];j++){
				
					if(ScopeTable[i]->ptr[j]!=NULL){
					
						if(ScopeTable[i]->ptr[j]->entry_ptr!=NULL){
					
							for(tmp=ScopeTable[i]->ptr[j]->entry_ptr;tmp!=NULL;next=tmp->next,tmp=next){
								
								if(tmp->symbolType == 1){
									free(tmp->types.p_var->name);
									free(tmp->types.p_var);
									free(tmp);
								}
								else{
									free(tmp->types.p_fun->name);
									free(tmp->types.p_fun);
									free_list(tmp->types.p_fun->args);
									free(tmp);	
								}
								
							}
							
						}
						free(ScopeTable[i]->ptr[j]);
					}
				
				}
				free(ScopeTable[i]->ptr);
			}
			free(ScopeTable[i]);
		}
	}
	free(ScopeTable);
}

char * create_funcName(){

	char * prefix = (char *)malloc(sizeof(char)*4);
	char * name;
	int size = 0 ;
	
	func_Cnt++;

	name = (char *)malloc(100*sizeof(char));
    
	if( name == NULL){
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}
	prefix = strcpy(prefix,"tmp");
	name   = (char *)lltostr(func_Cnt,name);
	name   = strcat(prefix,name);
    
	size = strlen(name);
	name[size]='\0';
   	

	return name; 


	
}

void reset_fun_cnt(void){
	func_Cnt = 0;
}

int search_actFunc(int Scope ){
	
	
	int result = 0;
	int i=0,j=0;
	S_entry tmp;
	
	
	for( j=Scope-1; j>=0; j--){
		
		for ( i=0; i<HASH_AMOUNT[curHsAm]; i++){
			if(	ScopeTable[j]->ptr!=NULL	){
				if ( ScopeTable[j]->ptr[i] != NULL  ){

					for(tmp=ScopeTable[j]->ptr[i]->entry_ptr; tmp != NULL; tmp = tmp->next){
					
						if ( tmp->isActive == 1 &&  tmp->symbolType == 2 )
							return j;
					}
				
				}
			}

		}
	}
		return -1;
}


int count_funcVars(int Scope){
	int h,i,counter=0;
	S_entry tmp;
	char *tmp_f_name = strdup(func_name);
	
	if(	ScopeTable[Scope]->ptr==NULL ){
		return counter;
	}
	for(i=0; i<HASH_AMOUNT2[curHsAm2]; i++){
		
		if ( ScopeTable[Scope]->ptr[i] != NULL  ){

			for(tmp=ScopeTable[Scope]->ptr[i]->entry_ptr; tmp != NULL; tmp = tmp->next){
				
				if (  tmp->isActive == 1 &&  tmp->symbolType == 1 )
					
					tmp->offset = counter++;
					
				}
				
				
			}

	}


    return counter; 
	

}

int count_global_vars( void ){

	int i,j,counter = 0;
	S_entry tmp;

	if(ScopeTable == NULL ){
		return -1;
	}

	for(i=0; i<MaxScope; i++){
		
		if( ScopeTable[i]->ptr != NULL ){
			
			for(j=0; j<HASH_AMOUNT2[curHsAm2]; j++){
				
				for(tmp=ScopeTable[i]->ptr[j]->entry_ptr; tmp != NULL; tmp = tmp->next){
					if(tmp->SSpace == programvar){
						
						counter ++ ;
					
					}
				
				}
			
			}
		
		}
	
	}
	return counter;
}

void set_sumOfVars(int sum,int Scope){
	int h;
	S_entry tmp;
	
	h = hash( func_name , HASH_AMOUNT2[curHsAm2] );
    
	if(ScopeTable[Scope-2]==NULL || ScopeTable[Scope-2]->ptr==NULL)
		return; 
	
	
	if(ScopeTable[Scope-2]->ptr[h]==NULL){
		return;
	}

	tmp = ScopeTable[Scope-2]->ptr[h]->entry_ptr;
	
	while ( tmp != NULL ){

		if ( tmp->symbolType == 2 ){
						
			if ( strcmp(tmp->types.p_fun->name,func_name) == 0 ){
					
					tmp->types.p_fun->vars_sum = sum;
					break;
			}	
		}
		tmp =tmp->next;
		
	}

	



}

enum scopespace_t currScopeSpace(void){

	if ( ScopeSpaceCounter  == 1 ){
		return programvar;
	}
	else if ( ScopeSpaceCounter%2 == 0 ){
		return formalarg;
	}
	else
		return functionlocal;


}



S_entry find_refer(char *name,int scope, int v_or_f){
    unsigned int pos;
	S_entry entr,tmp;
	   


	pos=hash(name,HASH_AMOUNT2[curHsAm2]);
	
	entr=ScopeTable[scope]->ptr[pos]->entry_ptr;
		
			
	tmp=entr;
	
	if(v_or_f==1){
	   
		while(tmp!=NULL){
		
			if(tmp->symbolType==1){
		 
				if ( tmp->types.p_var->name != NULL && tmp->isActive==1){
		 	
					if(strcmp(tmp->types.p_var->name,name)==0)
		    	
						return tmp;
		 
				}
		 
			}
		 
			tmp=tmp->next;
	    
		}
		
		return NULL;
	}
    else if(v_or_f== 2 || v_or_f == 3){
	 
		while	(tmp!=NULL){
		
			if(tmp->symbolType == 2 || tmp->symbolType == 3){
			
				if ( tmp->types.p_fun->name != NULL && tmp->isActive==1){
	    		
					if(strcmp(tmp->types.p_fun->name,name)==0)
	        		
						return tmp;
				}
			}
	    
			tmp=tmp->next;
	  
		}
		
		return NULL;
	
	}
	
	return NULL;
		
	
	
}

S_entry find_rec( char *name, int Scope, int v_or_f ){
	int i,l_res;
	
	for( i = Scope; i >= 0; i-- ){
		
		if( ( l_res = lookup( name, i, v_or_f ) ) == 1 ){
			
			return find_refer( name, i, v_or_f );
		}
		
	}
	return NULL;
	
}

char *find_name(S_entry a, int v_or_f){
	if(v_or_f == 1){
		if(a!=NULL){
			if(a->types.p_var!=NULL)
		         return a->types.p_var->name;
		}
	}

	else if(v_or_f == 2 || v_or_f == 3){
		if(a!=NULL){
			if(a->types.p_fun!=NULL)
		        return a->types.p_fun->name;
		}
	}
	else
		return NULL;


}

int find_func(S_entry a){
	if(a != NULL){
		return a->symbolType;
	}
	
	return -1;
}

int return_field(S_entry a,int what){

	if ( a == NULL ){
		return 0;
	}
	else{
		if ( what == 0 )
			return a->offset;
		else if ( what == 1 )
			return a->SSpace;
		
	}
	

	return 0;
}


char * return_name( S_entry a ){

	if ( a == NULL )
		return NULL;
	else
		return a->types.p_fun->name;


	return NULL;
}

int return_varsum( S_entry a){
	if ( a == NULL )
		return -1;
	else
		return a->types.p_fun->vars_sum;


	return -1;
}

