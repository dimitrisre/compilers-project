#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

enum scopespace_t { programvar , functionlocal , formalarg };

typedef struct expr Expr;
typedef struct symbolTableRecord * S_entry;

int insert(  int Scope , char * name , int line , int V_or_F  );

int Lookup( char * name , int scope , int v_or_f );

void Hide( int );

void print();

void Init_symbolTable();

void destroy_symboltable();

char * create_funcName( void );

void reset_fun_cnt(void);

enum scopespace_t currScopeSpace(void);

S_entry find_rec( char *, int , int  );

char * find_name( S_entry , int);

void set_sumOfVars(int sum,int Scope);

int find_func( S_entry );

int count_funcVars(int Scope);

int insert_arguments( int scope );

int return_field(S_entry a,int what);

char * return_name(S_entry a );

int return_varsum(S_entry a);

int count_global_vars( void );

#endif
